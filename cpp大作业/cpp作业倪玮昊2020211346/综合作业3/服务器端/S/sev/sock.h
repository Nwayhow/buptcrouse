#ifndef SOCK_H
#define SOCK_H
#include"QThread"
#include"user.h"
#include"manager.h"
#include"dev.h"
#include"object.h"
#include <QTcpServer>
using namespace std;
#include"object.h"
#include <QTcpSocket>
#include<QObject>

class socketThread :public QThread
{
Q_OBJECT
public:
    string name;//当前使用该现场的用户
    int kind=0;//该线程是否是登录线程
    void write_ptr(qintptr p){ ptr=p; }//接收socketDescriptor
    string mes[1000];//指令
    int cons=0;//指令行数
   virtual void  run();
   //定义自己需要的方法或变量
   qintptr ptr;
   QTcpSocket * socket;//客户端的定义
   ~socketThread(){
       delete socket;
   }
   bool AllisNum(string str) const//判断输入的字符串是不是数字
   {
       for (int i = 0; i < str.size(); i++)
       {
           int tmp = (int)str[i];
           if (tmp >= 48 && tmp <= 57)
           {
               continue;
           }
           else
           {
               return false;
           }
       }
       return true;
   }
   void ays(int cons,string mes[100]){//分析指令
       findobject O;
       dev D;
       control B;
       account A;
       breakable C1;
        book C2;
         nomal C3;

       connect(&A,SIGNAL(look(string)),this,SLOT(myPrint(string)));
       connect(&B,SIGNAL(look(string)),this,SLOT(myPrint(string)));
       connect(&D,SIGNAL(look(string)),this,SLOT(myPrint(string)));
       connect(&O,SIGNAL(look(string)),this,SLOT(myPrint(string)));
       connect(&C1,SIGNAL(look(string)),this,SLOT(myPrint(string)));
       connect(&C2,SIGNAL(look(string)),this,SLOT(myPrint(string)));
       connect(&C3,SIGNAL(look(string)),this,SLOT(myPrint(string)));
       string index=mes[3];
       if(mes[0]=="1"){//**读取1代表进入用户模式:**
           A.login(mes[1],mes[2]);
           if(cons==4 && A.name!="0"){
               emit look(mes[1]);
               name=mes[1];
               kind=1;
           }
           if (index == "1" ) {//读取1进入发送快递,通过调用A.decmoney来发送快递.再更新数据并将金额转给管理员
               cout << "输入你发送的快递类型 1.易碎品 2.图书 3.普通物品" << endl;
               string index1=mes[4];
               if (index1 == "1") {//
                   C1.sent(A.name,mes[5],mes[6],mes[7],mes[8],A.money);
                   if(C1.price!=0) A.decmoney(C1.price);
                   A.re();

                   B.add(C1.price);
                   B.re();
               }
               else if (index1 == "2") {
                   C2.sent(A.name,mes[5],mes[6],mes[7],mes[8],A.money);
                   A.decmoney(C2.price);
                   A.re();

                   B.add(C2.price);
                   B.re();

               }
               else if (index1 == "3") {
                   C3.sent(A.name,mes[5],mes[6],mes[7],mes[8],A.money);
                   A.decmoney(C3.price);
                   A.re();
                   B.add(C3.price);
                   B.re();

               }
               else {
                   this->Print("不存在该物品");

               }

               return;

           }
           else if (index == "2") {//读取2进入接收快递,调用O.recevive并更新数据

               O.recevive(A.name,mes[4]);
               O.re();

           }
           else if (index == "3") {//读取3进入搜索快递,对非状态类型查找 调用A.findobject,对状态类型查找,调用O.serchunrece进行查找.

               if(mes[4]!="5" && mes[4]!="6" && mes[4]!="7" && mes[4]!="8") A.findobject(mes[4],mes[5]);
              else{
                   string j;
                  if(mes[4]=="5" ) j="未揽收";
                   if(mes[4]=="6" ) j="未接收";
                   if(mes[4]=="7" ) j="已签收";
                   if(mes[4]=="8" ) j="未确认";
                   O.serchunrece(A.name,j);
              }
                this->Print("查询结束");
           }
           else if (index == "5") {//进入充值


               if(AllisNum(mes[4])==false){
                   this->Print("输入的金额不是数字");
                   return;
               }
                int moeny=stoi(mes[4]);
               A.addmenoy(moeny);
               A.re();
           }
           else if (index == "7") {//进入修改用户资料
int k=stoi(mes[4]);
               A.check(A.accountname,A.password,stoi(mes[4]),mes[5]);
           }
           else if (index == "6") {//搜索个人信息
                   A.findmy();
           }
           else if (index == "4") {//搜索个人信息
                   A.seachmoney();
           }
         return;
       }
       else  if(mes[0]=="2"){
           B.login(mes[1],mes[2]);
          // if(cons==4 && B.money!=-1){
             //  emit look(mes[1]);
             //  name=mes[1];
             //  kind=1;
        //   }
           string index1=mes[3];
           if (index1 == "1") {//进入查找快递,通过调用B.manangeobjects实现
             this->Print("满足要求的快递有:\n");
               B.manangeobjects(mes[4],mes[5]);
               this->Print("查询完成\n");

           }
           else if (index1 == "2") {//进入查询快递和快递员,调用D.findev判断快递员是否存在,若存在则调用O.devsearch查看该快递员旗下的所有快递.
               int count1=D.findev(mes[4]) ;
               if(count1 == -1) {
                     this->Print("不存在该快递员");
                   return;
                }
                this->Print("该快递员揽收的快递有:\n");
               O.devsearch(D.name[count1]);
           }

           else if (index1 == "3") {//进入揽收快递,先调用D.findev看看是否有这个快递,再调用O.lanshou实现揽收并从管理员中扣费.
               int count1=D.findev(mes[4]);
               if(count1 == -1) {
                    this->Print("不存在该快递员\n");
                  return;
               }
               int m = O.lanshou(D.name[count1], mes[5]);
               B.dec(m);
               B.re();
           }
           else if (index1 == "4") {//进入添加删除快递员,读取1调D.createnewaccount添加快递员,读取2调用 D.findevac删除快递员
               cout << "输入1添加新快递员,输入2删除新快递员" << endl;
               if (mes[4] == "1") {
                   if(AllisNum(mes[9])==false){
                       this->Print("输入的金额不是数字");
                       return;
                   }
                    int m=stoi(mes[9]);

                   D.createnewaccount(mes[5],mes[6],mes[7],mes[8],mes[9]);
               }
               else {
                   cout << "输入你想删除的账号" << endl;
                   D.findevac(mes[5]);
               }
           }
           else if(index1=="5"){//查询没有分配快递员的快递和可供派遣快递
               this->Print("未分配快递员的快递有\n");
               cout << "未分配快递员的快递有" << endl;
               O.devsearch("0");//快递
               this->Print("可供派遣快递员有\n");
               D.search();//可供派遣快递员
           }
           else if(index1=="6"){//查看所有的用户以及个人信息
               this->Print("已注册的用户有:\n");
              A.findall();
           }
         return ;

       }
       else  if(mes[0]=="3"){
           string name;
           name = D.login(mes[1],mes[2]);
           //if(cons==4 && D.now!=-1){
              // emit look(mes[1]);
              // name=mes[1];
             //  kind=1;
          // }
           cout << "输入1查询快递 输入2揽收快递" << endl;
           if (mes[3] == "1") {//对快递进行查询,调用D.find查询

               if(mes[4]=="1" || mes[4]=="2" ||mes[4]=="3" || mes[4]=="4")D.find(name,mes[4],mes[5]);
               else{
                   if(mes[4]=="5"){
                       D.find(name,"5","已签收");
                   }
                   if(mes[4]=="6"){
                        D.find(name,"5","未确认");
                   }
                   if(mes[4]=="7"){
                        D.find(name,"5","未接收");
                   }
               }
               this->Print("查询结束\n");
           }
           if (mes[3] == "2") {//对未确认的揽收快递进行确认调用O.unlanshousaerc,状态变为未接收,同时间把运费一半转给快递员

               int money = O.unlanshousaerch(name,mes[4]);
              if(money!=-1) D.addmoney(D.account[D.now], money);
               D.re();

           }
       }
       else  if(mes[0]=="4"){//**输入4进入创建新账号**
           if(AllisNum(mes[5])==false){
               this->Print("输入的金额不是数字");
               return;
           }
            int m=stoi(mes[5]);
               A.createnewacount(mes[1],mes[2],mes[3],mes[4],m,mes[6]);


       }
       return ;


   }
   void Print(QString word) const{//将要输出的内容传递给客户端
        socket->write(word.toUtf8());
         socket->waitForBytesWritten(3000);

   }
private slots:
   void myPrint(string word) const{//将string转化为qstring
       cout<<"1"<<endl;
       Print( QString::fromStdString(word));

   }
   void watch1(string) const;
signals:
    void look(string) const;
     void look2(string) const;
};

#endif // SOCK_H

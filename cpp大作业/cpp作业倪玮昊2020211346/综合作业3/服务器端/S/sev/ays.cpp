#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"user.h"
#include"manager.h"
#include"dev.h"
#include"object.h"
#include <QTcpServer>
using namespace std;

void MainWindow::ays(int cons,string mes[100]){
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
    if(mes[0]=="1"){
        A.login(mes[1],mes[2]);
        if (index == "1" ) {
            if(cons!=9){
                this->Print("输入行数不对");
                return;
            }
            cout << "输入你发送的快递类型 1.易碎品 2.图书 3.普通物品" << endl;
            string index1=mes[4];
            if (index1 == "1") {
                C1.sent(A.name,mes[5],mes[6],mes[7],mes[8]);
                A.decmoney(C1.price);
                A.re();

                B.add(C1.price);
                B.re();
            }
            else if (index1 == "2") {
                C2.sent(A.name,mes[5],mes[6],mes[7],mes[8]);
                A.decmoney(C2.price);
                A.re();

                B.add(C2.price);
                B.re();

            }
            else if (index1 == "3") {
                C3.sent(A.name,mes[5],mes[6],mes[7],mes[8]);
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
        else if (index == "2") {
            if(cons!=5){
                this->Print("输入行数不对");
                return;
            }
            O.recevive(A.name,mes[4]);
            O.re();
             this->Print("签收成功");
        }
        else if (index == "3") {
            if(cons!=6){
                this->Print("输入行数不对");
                return;
            }
            A.findobject(mes[4],mes[5]);
             this->Print("查询结束");
        }
        else if (index == "4") {
            if(cons!=5){
                this->Print("输入行数不对");
                return;
            }
            int moeny=stoi(mes[4]);
            string t=to_string(moeny);
            if(t!=mes[4]){
                this->Print("输入的金额不是数字");
                return;
            }
            A.addmenoy(moeny);
            A.re();
        }
        else if (index == "5") {
            if(cons!=4){
                this->Print("输入行数不对");
                return;
            }
            A.seachmoney();
        }

      return;
    }
    else  if(mes[0]=="2"){
        B.login(mes[1],mes[2]);
        string index1=mes[3];
        if (index1 == "1") {
            if(cons!=6){
                this->Print("输入行数不对");
                return;
            }
            B.manangeobjects(mes[4],mes[5]);
            this->Print("查询完成");

        }
        else if (index1 == "2") {
            if(cons!=5){
                this->Print("输入行数不对");
                return;
            }
            O.devsearch(mes[4]);
        }
        else if (index1 == "3") {
            if(cons!=5){
                this->Print("输入行数不对");
                return;
            }

           if(D.findev(mes[4]) != 1) {
                 this->Print("不存在该快递员");
            }
            int m = O.lanshou(mes[4], mes[5]);
            B.dec(m);
            B.re();
        }
        else if (index1 == "4") {
            cout << "输入1添加新快递员,输入2删除新快递员" << endl;
            if (mes[4] == "1") {
                if(cons!=11){
                    this->Print("输入行数不对");
                    return;
                }
                int m=stoi(mes[9]);
                string t=to_string(m);
                if(t!=mes[9]){
                    this->Print("输入的金额不是数字");
                    return;
                }
                D.createnewaccount(mes[5],mes[6],mes[7],mes[8],mes[9]);
            }
            else {
                if(cons!=5){
                    this->Print("输入行数不对");
                    return;
                }
                cout << "现存账号有" << endl;
                D.searchac();
                cout << "输入你想删除的账号" << endl;
                D.findevac(mes[5]);
            }
        }
        else if(index1=="5"){
            cout << "未分配快递员的快递有" << endl;
            O.devsearch("0");//快递
            D.search();//可供派遣快递员
        }
      return ;

    }
    else  if(mes[0]=="3"){
        string name;
        name = D.login(mes[1],mes[2]);

        cout << "输入1查询快递 输入2揽收快递" << endl;
        if (mes[3] == "1") {
            if(cons!=6){
                this->Print("输入行数不对");
                return;
            }
            D.find(name,mes[4],mes[5]);
        }
        if (mes[3] == "2") {
            if(cons!=5){
                this->Print("输入行数不对");
                return;
            }
            int money = O.unlanshousaerch(name,mes[4]);
            D.addmoney(D.account[D.now], money);
            D.re();
        }
    }
    else  if(mes[0]=="4"){
            int m=stoi(mes[5]);
            string t=to_string(m);
            if(t!=mes[5]){
                this->Print("输入的金额不是数字");
                return;
            }
            A.createnewacount(mes[1],mes[2],mes[3],mes[4],m,mes[6]);


    }
    return ;


}

#ifndef DEV_H
#define DEV_H
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include "mainwindow.h"
#include "ui_mainwindow.h"
class dev :public QObject{
     Q_OBJECT
public:
    void pri(string word) const{//启动信号槽函数来调用sockthread类中的传递函数,把数据传给客户端
        emit look(word);
    }

    string account[1000];//记录用户名
    string password[100];//记录密码
    string name[1000];//记录姓名
    int rest[1000];//记录余额
    string phone[1000];//记录电话号码
    int now=-1;//目前账号对应数组下标
    int count = 0;//记录账号总数
    dev() {//将文本文档内容录入到数组中.
        ifstream ifs;
        ifs.open("deviler.txt", ios::in);
        string b;
        count = 0;
        while (ifs >> b) {
            account[count] = b;
            ifs >> b;
            password[count] = b;
            ifs >> b;
            name[count] = b;
            ifs >> b;
            phone[count] = b;
            ifs >> rest[count];
            count++;
        }
        ifs.close();
    }
    string login(string ac,string ac_password) {//通过打开存放用户数据的文档,比较账号和密码,如果验证成功则退出函数,否则继续对账户和密码进行输入.

        cout << "请输入您的账号和密码来完成登陆操作." << endl;

        for (int count1 = 0; count1 < count; count1++) {
            if (account[count1] == ac) {
                if (password[count1] == ac_password) {
                    pri("登录成功");
                    cout << "登陆成功";
                    now = count1;
                    return name[count1];
                }
                else break;
            }

        }
        pri("密码或账号错误，请再次输入；" );
        cout << "密码或账号错误，请再次输入；" << endl;
    }
    void createnewaccount(string ac,string ac_password,string newac_name,string newac_phone,string newac_money) {
//对快递员进行注册,先判断是否账户重复,若不重复则逐步输入各项信息完成注册功能
        cout << "请输入您的账号和密码来完成注册操作." << endl;

        for (int count1 = 0; count1 < count; count1++) {
            if (account[count1] == ac) {
                pri("账号有重复\n");
                cout << "账号有重复，请再次输入；" << endl;
                return;
            }

        }
        ofstream ofs;
        ofs.open("deviler.txt", ios::app);
        ofs << ac << endl;
        cout << "请输入您的密码来完成注册操作." << endl;

        ofs << ac_password << endl;
        cout << "请输入您的姓名来完成注册操作." << endl;

        ofs << newac_name << endl;
        cout << "请输入您的电话号码来完成注册操作." << endl;

        ofs << newac_phone << endl;
        cout << "请输入您的初始金额来完成注册操作." << endl;

        ofs << newac_money << endl;
        ofs.close();
        ifstream ifs;
        ifs.open("deviler.txt", ios::in);
        string b;
        count = 0;
        while (ifs >> b) {
            account[count] = b;
            ifs >> b;
            password[count] = b;
            ifs >> b;
            name[count] = b;
            ifs >> b;
            phone[count] = b;
            ifs >> rest[count];
            count++;
        }
        ifs.close();
        pri("注册成功\n");
    }

    void re() {//对用户数据进行再次读取(常用于在修改完文本内容后再次读取)
        ofstream ofs;
        ofs.open("deviler.txt", ios::out);
        for (int count1 = 0; count1 < count; count1++) {
            if (account[count1] != "0") {
                ofs << account[count1] << endl;
                ofs << password[count1] << endl;
                ofs << name[count1] << endl;
                ofs << phone[count1] << endl;
                ofs << rest[count1] << endl;
            }
        }
        ofs.close();
        ifstream ifs;
        ifs.open("deviler.txt", ios::in);
        string b;
        count = 0;
        while (ifs >> b) {
            account[count] = b;
            ifs >> b;
            password[count] = b;
            ifs >> b;
            name[count] = b;
            ifs >> b;
            phone[count] = b;
            ifs >> rest[count];
            count++;
        }
        ifs.close();
    }
    void search()  const{//搜索可被调遣的快递员的姓名
        cout << "可派遣的快递员有" << endl;
        for (int count1 = 0; count1 < count; count1++) {
              pri("快递员账号为:"+account[count1]+" ");
              pri("快递员姓名为:"+name[count1]+"\n");
        }
    }
    void findevac(string name1) {//对输入的快递员进行删除
        for (int count1 = 0; count1 < count; count1++) {
            if (account[count1] == name1) {
                account[count1] = "0";
                re();
                 pri("删除成功\n");
                cout << "删除成功" << endl;
                return;
            }
        }
        pri("不存在该快递员,重新输入");
        cout << "不存在该快递员,重新输入" << endl;
    }
    void searchac()  const{//搜索可被调遣的快递员的账号
        cout << "可派遣的快递员有" << endl;
        for (int count1 = 0; count1 < count; count1++) {
            cout << account[count1] << endl;
        }
    }
    void addmoney(string acc, int mon) {//对账户进行充值
        for (int count1 = 0; count1 < count; count1++) {
            if (account[count1] == acc) {
                rest[count1] = rest[count1] + mon;
                pri("转入账号"+to_string(mon)+"元\n");
            }
        }
    }
    int findev(string name1)  const{//确认是否存在该快递员
        for (int count1 = 0; count1 < count; count1++) {
            if (account[count1] == name1) {
                pri("快递员账号为:"+account[count1]+" ");
                pri("快递员姓名为:"+name[count1]+" ");
                 pri("快递员电话为:"+phone[count1]+" ");
                 string num= to_string(rest[count1]);
                  pri("快递员余额为:"+num+"\n");
                return count1;
            }
        }
        return -1;
    }
    void find(string name,string j,string time) const {//查询具体快递,且该快递必须快递员为本人,即相关快递,原理和前面类中的查找基本一致
        cout << "输入1根据发送人" << endl;
        cout << "输入1通过收件人姓名查询的快递 输入2通过时间查询快递 输入3通过寄件人查询快递 输入4通过快递单号查询快递(只能查询与自己有关的快递）输入5根据快递状态查询" << endl;

        if (j == "1") {
            cout << "输入你想查询的收件人 " << endl;
            fstream ifs;
            ifs.open("object.txt", ios::in);
            string b;
            cout << "历史快递:" << endl;
            while (ifs >> b) {
                string c = b;
                ifs >> b;
                string d = b;
                ifs >> b;
                string e = b;
                ifs >> b;
                string f = b;
                ifs >> b;
                string g = b;
                ifs >> b;
                string h = b;
                ifs >> b;
                string i = b;
                ifs >> b;
                string j = b;
                ifs >> b;
                if (e == time && (b == name)) {

                    pri("快递单号:" + c +" ");

                        pri("寄件人:" + d+" ");
                          pri("收件人:" + e+" ");
                            pri("物品描述:"+f+" ");
                              pri("收件地址:" + g+" ");
                                pri("发件时间:" + h +" ");
                           if (i == "未接收" || i == "未确认")       pri("发件状态:" +i+" " );
                                else   pri("收件时间:"+i+" ");
                           pri("物品种类:" + j+" ");
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b+"元\n" );
                    cout << "快递单号:" << c << endl;
                    cout << "寄件人:" << d << endl;
                    cout << "收件人:" << e << endl;
                    cout << "物品描述:" << f << endl;
                    cout << "收件地址:" << g << endl;
                    cout << "发件时间:" << h << endl;
                    if (i == "未接收" || i == "未确认")cout << "发件状态:" << i << endl;
                    else cout << "收件时间:" << i << endl;
                    cout << "物品种类:" << j << endl;
                    cout << "快递员为:" << b << endl;

                    cout << "运费为:" << b << endl;
                }

                else {
                    ifs >> b;
                }
            }
            ifs.close();
        }
        else if (j == "2") {
            cout << "输入你想查询的发件时间" << endl;
            int k = time.size();
            fstream ifs;
            ifs.open("object.txt", ios::in);
            string b;
            cout << "历史快递:" << endl;
            while (ifs >> b) {
                string c = b;
                ifs >> b;
                string d = b;
                ifs >> b;
                string e = b;
                ifs >> b;
                string f = b;
                ifs >> b;
                string g = b;
                ifs >> b;
                string h = b;
                ifs >> b;
                string i = b;
                ifs >> b;
                string j = b;
                ifs >> b;
                if (b.compare(0, k, time, 0, k) == 0 && (b == name)) {
                    pri("快递单号:" + c +" ");

                        pri("寄件人:" + d+" ");
                          pri("收件人:" + e+" ");
                            pri("物品描述:"+f+" ");
                              pri("收件地址:" + g+" ");
                                pri("发件时间:" + h +" ");
                           if (i == "未接收" || i == "未确认")       pri("发件状态:" +i+" " );
                                else   pri("收件时间:"+i+" ");
                           pri("物品种类:" + j+" ");
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b+"元\n" );
                    cout << "快递单号:" << c << endl;
                    cout << "寄件人:" << d << endl;

                    cout << "收件人:" << e << endl;

                    cout << "物品描述:" << f << endl;

                    cout << "收件地址:" << g << endl;

                    cout << "发件时间:" << h << endl;
                    if (i == "未接收" || i == "未确认")cout << "发件状态:" << i << endl;
                    else cout << "收件时间:" << i << endl;
                    cout << "物品种类:" << j << endl;
                    cout << "快递员为:" << b << endl;


                    cout << "运费为:" << b << endl;
                }

                else {
                    ifs >> b;

                }
            }
            ifs.close();
        }
        else if (j == "3") {
            cout << "输入你想查询的寄件人姓名" << endl;
            fstream ifs;
            ifs.open("object.txt", ios::in);
            string b;
            cout << "历史快递:" << endl;
            while (ifs >> b) {
                string c = b;
                ifs >> b;
                string d = b;
                ifs >> b;
                string e = b;
                ifs >> b;
                string f = b;
                ifs >> b;
                string g = b;
                ifs >> b;
                string h = b;
                ifs >> b;
                string i = b;
                ifs >> b;
                string j = b;
                ifs >> b;
                if (d == time && (b == name)) {
                    pri("快递单号:" + c +" ");

                        pri("寄件人:" + d+" ");
                          pri("收件人:" + e+" ");
                            pri("物品描述:"+f+" ");
                              pri("收件地址:" + g+" ");
                                pri("发件时间:" + h +" ");
                           if (i == "未接收" || i == "未确认")       pri("发件状态:" +i+" " );
                                else   pri("收件时间:"+i+" ");
                           pri("物品种类:" + j+" ");
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b+"元\n" );
                    cout << "快递单号:" << c << endl;

                }
                else {
                    ifs >> b;

                }

            }
            ifs.close();
        }
        else if (j == "4") {
            cout << "输入你想查询的快递单号" << endl;
            fstream ifs;
            ifs.open("object.txt", ios::in);
            string b;
            cout << "历史快递:" << endl;
            while (ifs >> b) {
                string c = b;
                ifs >> b;
                string d = b;
                ifs >> b;
                string e = b;
                ifs >> b;
                string f = b;
                ifs >> b;
                string g = b;
                ifs >> b;
                string h = b;
                ifs >> b;
                string i = b;
                ifs >> b;
                string j = b;
                ifs >> b;
                if (c == time && (b == name)) {
                    pri("快递单号:" + c +" ");

                        pri("寄件人:" + d+" ");
                          pri("收件人:" + e+" ");
                            pri("物品描述:"+f+" ");
                              pri("收件地址:" + g+" ");
                                pri("发件时间:" + h +" ");
                           if (i == "未接收" || i == "未确认")       pri("发件状态:" +i+" " );
                                else   pri("收件时间:"+i+" ");
                           pri("物品种类:" + j+" ");
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b+"元\n" );
                    cout << "快递单号:" << c << endl;

                }
                else {
                    ifs >> b;

                }
            }
        }
        else if (j == "5") {
            cout << "输入你想查询的状态(未确认or未接收or已签收)" << endl;
            fstream ifs;
            ifs.open("object.txt", ios::in);
            string b;
            cout << "历史快递:" << endl;
            if (time == "已签收") {
                while (ifs >> b) {
                                string c = b;
                                ifs >> b;
                                string d = b;
                                ifs >> b;
                                string e = b;
                                ifs >> b;
                                string f = b;
                                ifs >> b;
                                string g = b;
                                ifs >> b;
                                string h = b;
                                ifs >> b;
                                string i = b;
                                ifs >> b;
                                string j = b;
                                ifs >> b;
                                if ((i != "未接收" && i != "未确认")  && (b == name)) {
                                    pri("快递单号:" + c +" ");

                                        pri("寄件人:" + d+" ");
                                          pri("收件人:" + e+" ");
                                            pri("物品描述:"+f+" ");
                                              pri("收件地址:" + g+" ");
                                                pri("发件时间:" + h +" ");
                                           if (i == "未接收" || i == "未确认")       pri("发件状态:" +i+" " );
                                                else   pri("收件时间:"+i+" ");
                                           pri("物品种类:" + j+" ");
                                             pri("快递员为:" + b+" ");
                                             ifs >> b;
                                           pri("运费为:" + b+"元\n" );
                                    cout << "快递单号:" << c << endl;

                                }

                                else {
                                    ifs >> b;
                                }
                            }
            }

            else while (ifs >> b) {
                string c = b;
                ifs >> b;
                string d = b;
                ifs >> b;
                string e = b;
                ifs >> b;
                string f = b;
                ifs >> b;
                string g = b;
                ifs >> b;
                string h = b;
                ifs >> b;
                string i = b;
                ifs >> b;
                string j = b;
                ifs >> b;
                if (i == time && (b == name)) {
                    pri("快递单号:" + c +" ");

                        pri("寄件人:" + d+" ");
                          pri("收件人:" + e+" ");
                            pri("物品描述:"+f+" ");
                              pri("收件地址:" + g+" ");
                                pri("发件时间:" + h +" ");
                           if (i == "未接收" || i == "未确认")       pri("发件状态:" +i+" " );
                                else   pri("收件时间:"+i+" ");
                           pri("物品种类:" + j+" ");
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b+"元\n" );
                    cout << "快递单号:" << c << endl;

                }

                else {
                    ifs >> b;
                }
            }
            ifs.close();
        }
    }
signals:
    void look(string word) const;//作为信号函数把数据传给sockthread类中的函数
};
#endif // DEV_H

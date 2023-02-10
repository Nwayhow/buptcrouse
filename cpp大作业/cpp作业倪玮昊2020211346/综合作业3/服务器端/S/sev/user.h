#ifndef USER_H
#define USER_H

#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
class account :public QObject {
Q_OBJECT
public:

    string accountname="0";
    string password;
    string name="0";
    string phonenum;
    string money;
    string location;
    account() {

    }
    void findmy() const{//打印当前账号的个人信息
        pri("账号名为:" + accountname+"\n");
            pri("密码为:" + password+"\n");
              pri("姓名为:" + name+"\n");
                pri("电话号码为:"+phonenum+"\n");
                  pri("余额为:" + money+"元"+"\n");
                    pri("位置为:" + location+"\n" );
    }
    void pri(string word) const{//启动信号槽函数来调用sockthread类中的传递函数,把数据传给客户端
        emit look(word);
    }
    void findall() const{//打印全部用户信息
        ifstream ifs;
        ifs.open("account.txt", ios::in);
        string b;
        while (ifs >> b) {
            pri("账号名为:" + b+" ");
            ifs >> b;
             pri("密码为:" + b+" ");
            ifs >> b;
             pri("姓名为:" + b+" ");
            ifs >> b;
            pri("电话号码为:"+b+" ");
            ifs >> b;
             pri("余额为:" + b+"元"+" ");
            ifs >> b;
            pri("位置为:" + b+"\n" );
        }
         ifs.close();
    }
    void re() {//对用户数据进行再次读取(常用于在修改完文本内容后再次读取)
        ifstream ifs;
        ifs.open("account.txt", ios::in);
        string b;
        while (ifs >> b) {
            if (accountname.compare(b) == 0) {
                ifs >> b;
                password = b;
                ifs >> b;
                name = b;
                ifs >> b;
                phonenum = b;
                ifs >> b;
                money = b;
                ifs >> b;
                location = b;
                ifs.close();
            }
            else{
                ifs >> b;
                ifs >> b;
                ifs >> b;
                ifs >> b;
                ifs >> b;
            }
        }
 ifs.close();
    }

    int login(string ac,string ac_password) {//通过打开存放用户数据的文档,比较账号和密码,如果验证成功则退出函数,否则继续对账户和密码进行输入.
        cout << "请输入您的账号和密码来完成登陆操作." << endl;
        ifstream ifs;
        ifs.open("account.txt", ios::in);
        string b;
        while (ifs >> b) {
            if (ac.compare(b) == 0) {
                accountname = b;
                ifs >> b;
                if (ac_password.compare(b) == 0) {
                   pri("登录成功" );
                    cout << "登录成功" << endl;
                    password = b;
                    ifs >> b;
                    name = b;
                    ifs >> b;
                    phonenum = b;
                    ifs >> b;
                    money = b;
                    ifs >> b;
                    location = b;
                    ifs.close();
                    return 0;
                }
                else { pri("密码错误" );cout << "密码错误，请再次输入；" << endl; ifs.close();return 0; }
            }
            ifs >> b;
            ifs >> b;
            ifs >> b;
            ifs >> b;
            ifs >> b;

        }
         pri("密码错误" );
        cout << "密码错误，请再次输入；" << endl; ifs.close();
        return 0;


    }
    void createnewacount(string newac,string newac_password,string newac_name,string newac_phone,int newac_money,string newac_location) {
//对用户进行注册,先判断是否账户重复,若不重复则逐步输入各项信息完成注册功能
        cout << "请输入您的用户名来完成注册操作." << endl;
        ifstream ifs;
        ifs.open("account.txt", ios::in);
        string b;
        while (ifs >> b) {
            if (newac.compare(b) == 0) {
               pri("该用户已存在");
                cout << "该用户已存在" << endl; ifs.close();return;
            }
            ifs >> b;
            ifs >> b;
            ifs >> b;
            ifs >> b;
            ifs >> b;
        }
        ifs.close();
        ofstream ofs;
        ofs.open("account.txt", ios::app);
        ofs << newac << endl;
        cout << "请输入您的密码来完成注册操作." << endl;
        ofs << newac_password << endl;
        cout << "请输入您的姓名来完成注册操作." << endl;
        ofs << newac_name << endl;
        cout << "请输入您的电话号码来完成注册操作." << endl;
        ofs << newac_phone << endl;
        cout << "请输入您的初始金额来完成注册操作." << endl;
        ofs << newac_money << endl;
        cout << "请输入您的地址来完成注册操作." << endl;
        ofs << newac_location << endl;
        ofs.close();
         pri("注册成功\n");
    }
    int check(string ac,string ac_password,int change,string newdeal) {
        //修改账户其他信息,对修改信息进行确认,不起修改的作用,实质上通过调用changes完成修改
    cout << "请输入您的账号和密码来完成验证操作." << endl;
        ifstream ifs;
        ifs.open("account.txt", ios::in);
        string b;
        while (ifs >> b) {
            if (ac.compare(b) == 0) {
                accountname = b;
                ifs >> b;
                if (ac_password.compare(b) == 0) {
                    cout << "验证成功" << endl; ifs.close();
                    cout << "扣1更改密码 2更改姓名 3更改电话 4地址" << endl;
                    if (change != 1 && change != 2 && change != 3 && change != 4) {
                        pri("非法输入");
                        cout << "非法输入,请重新" << endl;
                    }

                    changes(change,newdeal);
                    return 0;
                }
                else {pri("密码错误"); cout << "密码有错误，请再次输入；" << endl; ifs.close();  }
            }
            ifs >> b;
            ifs >> b;
            ifs >> b;
            ifs >> b;
            ifs >> b;
        }
       pri("密码错误");
        cout << "密码错误，请再次输入；" << endl; ifs.close();
    }
    void changes(int work,string newdeal) {//work代表修改的项目,通过对文本文档修改来完成修改.
        string deal;

        if (work == 1) {
            cout << "输入你想更改的密码" << endl;
            deal = password;

            password = newdeal;
            ifstream ifs;
            string A;
            ifs.open("account.txt", ios::in);
            ofstream ofs;
            ofs.open("tem.txt", ios::out);
            while (ifs >> A) {
                string B = A;
                ofs << A << endl;
                ifs >> A;
                if (B != accountname) {
                    ofs << A << endl;
                }
                else { ofs << newdeal << endl; }
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
            }
            ifs.close();
            ofs.close();
            ifs.open("tem.txt", ios::in);
            ofs.open("account.txt", ios::out);
            while (ifs >> A) {
                ofs << A << endl;

            }
            ifs.close();
            ofs.close();
           pri("密码修改完成");
        }
        if (work == 2) {
            cout << "输入你想更改的姓名" << endl;
            deal = name;
            name = newdeal;
            ifstream ifs;
            string A;
            ifs.open("account.txt", ios::in);
            ofstream ofs;
            ofs.open("tem.txt", ios::out);
            while (ifs >> A) {
                string B = A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                if (B != accountname) {
                    ofs << A << endl;
                }
                else { ofs << newdeal << endl; }

                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
            }
            ifs.close();
            ofs.close();
            ifs.open("tem.txt", ios::in);
            ofs.open("account.txt", ios::out);
            while (ifs >> A) {
                ofs << A << endl;

            }
            ifs.close();
            ofs.close();
           pri("修改完成");
            cout << "修改完成" << endl;

        }
        if (work == 3) {
            cout << "输入你想更改的电话" << endl;
            deal = phonenum;
            phonenum = newdeal;
            ifstream ifs;
            string A;
            ifs.open("account.txt", ios::in);
            ofstream ofs;
            ofs.open("tem.txt", ios::out);
            while (ifs >> A) {
                string B = A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                if (B != accountname) {
                    ofs << A << endl;
                }
                else { ofs << newdeal << endl; }

                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
            }
            ifs.close();
            ofs.close();
            ifs.open("tem.txt", ios::in);
            ofs.open("account.txt", ios::out);
            while (ifs >> A) {
                ofs << A << endl;

            }
            ifs.close();
            ofs.close();
           pri("电话号码修改完成");
            cout << "电话号码修改完成" << endl;


        }
        if (work == 4) {
            cout << "输入你想更改的地址" << endl;
            deal = location;
            location = newdeal;
            ifstream ifs;
            string A;
            ifs.open("account.txt", ios::in);
            ofstream ofs;
            ofs.open("tem.txt", ios::out);
            while (ifs >> A) {
                string B = A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                ofs << A << endl;
                ifs >> A;
                if (B != accountname) {
                    ofs << A << endl;
                }
                else { ofs << newdeal << endl; }


            }
            ifs.close();
            ofs.close();
            ifs.open("tem.txt", ios::in);
            ofs.open("account.txt", ios::out);
            while (ifs >> A) {
                ofs << A << endl;

            }
            ifs.close();
            ofs.close();
           pri("地址修改完成");
            cout << "地址修改完成" << endl;

        }

    }
    void decmoney(int dec) {//对账户进行扣费,当余额不足时可以对用户进行提醒并进行充值
        int num = stoi(money);
        if (num < dec) {
           return;
        }
        num = num - dec;
        string num1 = to_string(num);
        ifstream ifs;
        string A;
        ifs.open("account.txt", ios::in);
        ofstream ofs;
        ofs.open("tem.txt", ios::out);
        while (ifs >> A) {
            string B = A;
            ofs << A << endl;
            ifs >> A;
            ofs << A << endl;
            ifs >> A;
            ofs << A << endl;
            ifs >> A;
            ofs << A << endl;

            ifs >> A;
            if (B != accountname) {
                ofs << A << endl;
            }
            else { ofs << num1 << endl; }
            ifs >> A;
            ofs << A << endl;

        }
        ifs.close();
        ofs.close();
        ifs.open("tem.txt", ios::in);
        ofs.open("account.txt", ios::out);
        while (ifs >> A) {
            ofs << A << endl;

        }
        ifs.close();
        ofs.close();
pri("扣费完成");
        cout << "扣费完成" << endl;
    }
    void addmenoy(int ad) {//对账户进行充值
        int num = stoi(money);
        cout << "输入你想充值的金额" << endl;
        num = num + ad;
        string num1 = to_string(num);
        ifstream ifs;
        string A;
        ifs.open("account.txt", ios::in);
        ofstream ofs;
        ofs.open("tem.txt", ios::out);
        while (ifs >> A) {
            string B = A;
            ofs << A << endl;
            ifs >> A;
            ofs << A << endl;
            ifs >> A;
            ofs << A << endl;
            ifs >> A;
            ofs << A << endl;

            ifs >> A;
            if (B != accountname) {
                ofs << A << endl;
            }
            else { ofs << num1 << endl; }
            ifs >> A;
            ofs << A << endl;

        }
        ifs.close();
        ofs.close();
        ifs.open("tem.txt", ios::in);
        ofs.open("account.txt", ios::out);
        while (ifs >> A) {
            ofs << A << endl;

        }
        ifs.close();
        ofs.close();
       pri("充值完成");
        cout << "充值完成" << endl;
    }
    void seachmoney() {//:搜索余额
       pri("余额为:"+money+"元");


    }

    void findobject(string j,string time) const {
//findobject():查询具体快递,且该快递必须收件人或寄件人必须有一个满足为目前账号,即相关快递
        cout << "输入1通过收件人姓名查询的快递 输入2通过时间查询快递 输入2通过寄件人查询快递 输入4通过快递单号查询快递(只能查询与自己有关的快递）" << endl;

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
        ifs>>b;
                if (e == time && (d == name || e == name)) {
                   pri("快递单号:" + c);
                       pri("寄件人:" + d);
                         pri("收件人:" + e);
                           pri("物品描述:"+b);
                            ifs>>b;
                             pri("收件地址:" + b);
                              ifs>>b;
                               pri("发件时间:" + b );
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")      pri("发件状态:" +b );
                                else  pri("收件时间:"+b);
                           ifs>>b;
                          pri("物品种类:" + b);
                           ifs>>b;
                            pri("快递员为:" + b);
                             ifs >> b;
                          pri("运费为:" + b +"\n");
                    cout << "快递单号:" << c << endl;

                }

                else {

                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
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
                if (b.compare(0, k, time, 0, k) == 0 && (d == name || e == name)) {
                   pri("快递单号:" + c);
                       pri("寄件人:" + d);
                         pri("收件人:" + e);
                           pri("物品描述:"+f);
                             pri("收件地址:" + g);
                               pri("发件时间:" + b );
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")      pri("发件状态:" +b );
                                else  pri("收件时间:"+b);
                           ifs>>b;
                          pri("物品种类:" + b);
                           ifs>>b;
                            pri("快递员为:" + b);
                             ifs >> b;
                          pri("运费为:" + b +"\n");
                    cout << "快递单号:" << c << endl;

                }

                else {
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
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
                string e = b;
                ifs >> b;
                if (e == time && (b == name || e == name)) {
                   pri("快递单号:" + c);
                       pri("寄件人:" + e);
                         pri("收件人:" + b);
                           ifs>>b;
                           pri("物品描述:"+b);
                             ifs>>b;
                             pri("收件地址:" + b);
                               ifs>>b;
                               pri("发件时间:" + b );
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")      pri("发件状态:" +b );
                                else  pri("收件时间:"+b);
                           ifs>>b;
                          pri("物品种类:" + b);
                           ifs>>b;
                            pri("快递员为:" + b);
                             ifs >> b;
                          pri("运费为:" + b +"\n");
                            pri("\n");
                    cout << "快递单号:" << c << endl;


                }
                else {
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
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
                string e = b;
                ifs >> b;
                if (c ==time && (b == name || e == name)) {
                   pri("快递单号:" + c);
                       pri("寄件人:" + e);
                         pri("收件人:" + b);
                           ifs>>b;
                           pri("物品描述:"+b);
                             ifs>>b;
                             pri("收件地址:" + b);
                               ifs>>b;
                               pri("发件时间:" + b );
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")      pri("发件状态:" +b );
                                else  pri("收件时间:"+b);
                           ifs>>b;
                          pri("物品种类:" + b);
                           ifs>>b;
                            pri("快递员为:" + b);
                             ifs >> b;
                          pri("运费为:" + b+"\n" );
                    cout << "快递单号:" << c << endl;


                }
                else {
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                    ifs >> b;
                }
            }
        }
        else { pri("无效输入"); cout << "无效输入" << endl; }


    }

signals:
    void look(string word) const;//作为信号函数把数据传给sockthread类中的函数
};


#endif // USER_H

#ifndef MANAGER_H
#define MANAGER_H

#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include "mainwindow.h"
#include "ui_mainwindow.h"
class control :public QObject{

     Q_OBJECT
public:
    string accountname;//管理员用户名
    string name;//姓名
    int money=-1;//余额
    string password;//密码
    void pri(string word) const{//启动信号槽函数来调用sockthread类中的传递函数,把数据传给客户端
        emit look(word);
    }
    control() {//将管理员信息从本地录入变量成员

        ifstream ifs;
        ifs.open("control.txt", ios::out);
        string b;
        while (ifs >> b) {
            accountname = b;
            ifs >> b;
            password = b;
            ifs >> b;
            name = b;
            ifs >> money;
        }
        ifs.close();
    }
    void login(string zhanghao,string mima) {//登录

        if (mima == password && zhanghao == accountname) {
             pri("登录成功" );
            cout << "登陆成功" << endl;
        }
        else {
           pri("用户名或者密码错误,重新输入" );
            cout << "用户名或者密码错误,重新输入";
            return;
        }
    }
    void re() {//对管理员数据进行再次读取(常用于在修改完文本内容后再次读取)
        ofstream ofs;
        ofs.open("control.txt", ios::out);
        string b;
        ofs << accountname << endl;
        ofs << password << endl;
        ofs << name << endl;
        ofs << money << endl;
        ofs.close();
        ifstream ifs;
        ifs.open("control.txt", ios::out);
        while (ifs >> b) {
            accountname = b;
            ifs >> b;
            password = b;
            ifs >> b;
            name = b;
            ifs >> money;
        }
        ifs.close();
    }
    void change(string zhanghao,string mima,string new1) {//修改管理员密码
        if (mima == password && zhanghao == accountname) {
            password =new1;
            re();
        }
        else {
              pri("用户名或者密码错误,重新输入" );
            cout << "用户名或者密码错误,重新";
        }
    }
    void manangeobjects(string j,string time)  const{
        //查询具体快递,不做限制,原理和account中的查找基本一致
        cout << "输入1通过收件人姓名查询的快递 输入2通过时间查询快递 输入3通过寄件人查询快递 输入4通过快递单号查询快递" << endl;
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

                if (e == time) {
                    pri("快递单号:" + c+" ");
                        pri("寄件人:" + d+" ");
                          pri("收件人:" + e+" ");
                            pri("物品描述:"+b+" ");
                            ifs>>b;
                              pri("收件地址:" + b+" ");
                              ifs>>b;
                                pri("发件时间:" + b +" ");
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")       pri("发件状态:" +b+" " );
                                else   pri("收件时间:"+b+" ");
                           ifs>>b;
                           pri("物品种类:" + b+" ");
                           ifs>>b;
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b +"元\n");
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
                if (b.compare(0, k, time, 0, k) == 0) {
                    pri("快递单号:" + c+" ");
                        pri("寄件人:" + d+" ");
                          pri("收件人:" + e+" ");
                            pri("物品描述:"+f+" ");
                              pri("收件地址:" + g+" ");
                                pri("发件时间:" + b+" " );
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")       pri("发件状态:" +b +" ");
                                else   pri("收件时间:"+b+" ");
                           ifs>>b;
                           pri("物品种类:" + b+" ");
                           ifs>>b;
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b +"元\n");
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
                if (e == time) {
                    pri("快递单号:" + c+" ");
                        pri("寄件人:" + e+" ");
                          pri("收件人:" + b+" ");
                           ifs>>b;
                            pri("物品描述:"+b+" ");
                             ifs>>b;
                              pri("收件地址:" + b+" ");
                               ifs>>b;
                                pri("发件时间:" + b+" " );
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")       pri("发件状态:" +b +" ");
                                else   pri("收件时间:"+b+" ");
                           ifs>>b;
                           pri("物品种类:" + b+" ");
                           ifs>>b;
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b +"元\n");
                    cout << "快递单号:" << c << endl;

                }
                else{ifs >> b;
                ifs >> b;
                ifs >> b;
                ifs >> b;
                ifs >> b;
                ifs >> b;
                ifs >> b;
                ifs >> b; }

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
                if (c == time) {
                    pri("快递单号:" + c+" ");
                        pri("寄件人:" + e+" ");
                          pri("收件人:" + b+" ");
                           ifs>>b;
                            pri("物品描述:"+b+" ");
                             ifs>>b;
                              pri("收件地址:" + b+" ");
                               ifs>>b;
                                pri("发件时间:" + b+" " );
                                ifs>>b;
                           if (b == "未接收" || b == "未揽收")       pri("发件状态:" +b+" " );
                                else   pri("收件时间:"+b+" ");
                           ifs>>b;
                           pri("物品种类:" + b+" ");
                           ifs>>b;
                             pri("快递员为:" + b+" ");
                             ifs >> b;
                           pri("运费为:" + b+"元\n");
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
        else { cout << "无效输入" << endl;  }


    }
    void add(int menoy) {//添加金额
        money = money + menoy;
    }
    void dec(int mon) {//减去金额
        money = money - mon;
    }
signals:
    void look(string word) const;//作为信号函数把数据传给sockthread类中的函数
};
#endif // MANAGER_H

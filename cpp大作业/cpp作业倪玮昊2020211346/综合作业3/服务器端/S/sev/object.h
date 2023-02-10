#ifndef OBJECT_H
#define OBJECT_H
#pragma once
#include<conio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#define byte win_byte_override
#include <windows.h>
#include <time.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <string>
#include"QString"
#include "mainwindow.h"
#include "ui_mainwindow.h"
class mytime {
public:
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Second;

    mytime() {
        struct tm t;
        time_t now;
        time(&now);
        localtime_s(&t, &now);
        Year = 1900 + t.tm_year;
        Month = 1 + t.tm_mon;
        Day = t.tm_mday;
        Hour = t.tm_hour;
        Minute = t.tm_min;
        Second = t.tm_sec;

    }

};
class findobject :public QObject{
     Q_OBJECT
public:
    void pri(string word) const{
        emit look(word);
    }

    string level;//物品类型
        int count = 0;//计数,用来记载物品数量
        int weight;//重量
        int price;//价格
        string a_sentuser[1000];//发送方
        string a_receiveuser[1000];//接收方
        string a_kinds[1000];//描述
        string a_num[1000];//数量
        string a_address[1000];//地址
        string a_stage[1000];//状态
        string a_level[1000];//类型
        string a_time[1000];//发送时间
        string dp[1000];//快递员
        int a_price[1000];//价格
    findobject() {//将文本文档内容录入到数组中.
        ifstream ifs;
        ifs.open("object.txt", ios::in);
        string b;
        count = 0;
        while (ifs >> b) {
            a_num[count] = b;
            ifs >> b;
            a_sentuser[count] = b;
            ifs >> b;
            a_receiveuser[count] = b;
            ifs >> b;
            a_kinds[count] = b;
            ifs >> b;
            a_address[count] = b;
            ifs >> b;
            a_time[count] = b;
            ifs >> b;
            a_stage[count] = b;
            ifs >> b;
            a_level[count] = b;
            ifs >> b;
            dp[count] = b;
            ifs >> a_price[count];

            count++;
        }
        ifs.close();
    }
    void prin(int k)  const{//打印订单具体内容
        string s=to_string(a_price[k]);
        pri( "订单号为:"+ a_num[k]+" ");
        pri("寄件人为:"+a_sentuser[k]+" ");
        pri( "收件人为:"+a_receiveuser[k]+" ");
        pri( "收件人地址为:"+a_address[k]+" ");
        pri("物品描述为:" +a_kinds[k] +" ");
        pri( "签收时间为:"+a_stage[k]+" ");
         pri("快递员为:"+s+" ");
        pri("快递员为:"+dp[k]+"\n");

    }
    void serchunrece(string name,string stage) const{//对订单状态分类进行查询
        pri( "查询的订单有:\n" );
        string d="已签收";
         string e="未接收";
          string f="未揽收";
          string g="未确认";
        if(stage!=d) for (int count1 = 0; count1 < count; count1++) {
            if ((name == a_receiveuser[count1] || name == a_sentuser[count1]) && a_stage[count1]==stage) {
                prin(count1);
            }
        }
        else{
            for (int count1 = 0; count1 < count; count1++) {
                        if ((name == a_receiveuser[count1] || name == a_sentuser[count1]) &&  a_stage[count1]!=f &&  a_stage[count1]!=e) {
                            prin(count1);
                        }
                    }
        }
    }
    void recevive(string name,string num1) {//打印没有签收的订单,调用yanzheng来判断订单是否存在或是否被签收,如果存在则调用qianshou来对订单进行签收.

        cout << "输入你想签收的快递单号" << endl;
        if (yanzheng(num1) == 0) {
             pri("快递号不存在或已接收,重新输入");
            cout << "快递号不存在或已接收,重新" << endl;
            return;

        }

        qianshou(num1);

    }
    int yanzheng(string num)  const{//判断订单是否存在或是否被签收
        string i="未接收";

        for (int count1 = 0; count1 < count; count1++) {
                if (num == a_num[count1] && i==a_stage[count1]){
                     pri( "已签收订单:"+a_num[count1] );
                     return 1;
                }

        }
        return 0;
    }
    void qianshou(string num) {//对订单进行签收.
        for (int count1 = 0; count1 < count; count1++) {
            if (num == a_num[count1]) {
                ostringstream oss;
                mytime receivetime;
                oss << receivetime.Year << "年" << receivetime.Month << "月" << receivetime.Day << "日" << receivetime.Hour << "时" << receivetime.Minute << "分" << receivetime.Second << "秒" ;
                string time1 = oss.str();
                a_stage[count1] = time1;
            }
        }


    }
    void devsearch(string name)  const{//对某一个快递员的全部快递进行查询
        for (int count1 = 0; count1 < count; count1++) {
            if (name== dp[count1]) {
                prin(count1);
            }
        }
         pri("查询完成\n");
        cout << "查询完成" << endl;
    }
    void re() {//将修改过后的数组内容写入文本文档
        ofstream ofs;
        ofs.open("object.txt", ios::out);
        for (int count1 = 0; count1 < count; count1++) {
            ofs << a_num[count1] << endl;
            ofs << a_sentuser[count1] << endl;
            ofs << a_receiveuser[count1] << endl;
            ofs << a_kinds[count1] << endl;
            ofs << a_address[count1] << endl;
            ofs << a_time[count1] << endl;
            ofs << a_stage[count1] << endl;
            ofs << a_level[count1] << endl;
            ofs << dp[count1] << endl;
            ofs << a_price[count1] << endl;
        }
        ofs.close();

    }
    int lanshou(string name,string num1) {//揽收快递并将快递费返回给原函数
        for (int count1 = 0; count1 < count; count1++) {
            if ("未揽收" == a_stage[count1] && a_num[count1] == num1) {
                dp[count1] = name;
                 a_stage[count1] = "未确认";
                re();
                 pri("快递员:"+name+"揽收快递"+num1+"完成"+"\n");
                return a_price[count1] / 2;
            }
        }
         pri("该单号已被揽收或不存在\n");
    }
    int unlanshousaerch(string name,string num1) {//先对未揽收且归在快递员名下的快递进行查询,再对快递揽收,同时将状态改为未接收
        int money;
        cout << "输入你想揽收的快递单号" << endl;
        for (int count1 = 0; count1 < count; count1++) {
            if (num1 == a_num[count1] && dp[count1]==name && a_stage[count1]=="未确认" ) {
                a_stage[count1] = "未接收";
                money = a_price[count1]- a_price[count1]/2;
                re();
                pri("确认成功\n");
                cout << "揽收成功" << endl;
                return money;
            }
        }
        pri("不存在名为: "+num1+" 的未确认订单\n");
        return -1;



    }
signals:
    void look(string word) const;//作为信号函数把数据传给sockthread类中的函数

};
class object :public QObject{
     Q_OBJECT
public:
    void pri(string word) const{//启动信号槽函数来调用sockthread类中的传递函数,把数据传给客户端
        emit look(word);
    }
    string level ;//物品类型
    int weight;//重量
    int price;//价格
    int count = 0;


    object() {

    }
    virtual int getprice() = 0;//计算价格
    virtual string getlevel() = 0;//根据物品类型确定运费要乘以的系数

    bool AllisNum(string str) const//判断字符串是不是数字
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
    void sent(string name,string receiveuser, string kinds,string address,string weight,string less) {
        //:name为寄出人的姓名,先对物品类型进行判断,通过不同的子类中的getprice来计算运费,通过 generCharArray()生成10位订单号,输入该快递所有信息,完成寄出.
        if(AllisNum(weight)==false){
            pri("输入的金额不是数字");
            return;
        }
       this->weight=stoi(weight);
        int les=stoi(less);

        string stage = "未揽收";
     string num=generCharArray();
        price = getprice();
        if(les<price){
            pri("余额不足,请充值");
            return;
        }
        level = getlevel();
        while (1) {
            ifstream ifs;
            ifs.open("object.txt", ios::in);
            string b;
            while (ifs >> b) {
                num = generCharArray();
                if (num.compare(b) == 0) {
                    continue;
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
                    ifs >> b;
                }
            }break;

        }
        ofstream ofs;
        ofs.open("object.txt", ios::app);
        ofs << num << endl;
        ofs << name << endl;
        ofs << receiveuser << endl;
        ofs << kinds << endl;
        ofs << address << endl;
        mytime senttime;
        ofs << senttime.Year << "年";
        ofs << senttime.Month << "月";
        ofs << senttime.Day << "日";
        ofs << senttime.Hour << "时";
        ofs << senttime.Minute << "分";
        ofs << senttime.Second << "秒" << endl;
        ofs << stage << endl;
        ofs << level << endl;
        ofs << "0" << endl;
        ofs << price << endl;
        pri("单号"+num+"寄出成功");
        cout << "寄出成功" << endl;


    }

    string generCharArray() const {
        int flag, i;
        char ch[11] = { NULL };//注意要多分配一个字节来保存字符串最后的结束符
        srand((unsigned)time(NULL));

        for (i = 0; i < 10; i++)
        {
            flag = rand() % 2;
            if (flag) ch[i] = '1' + rand() % 9;
            else ch[i] = '1' + rand() % 9;
        }
        ch[i] = '\0';
        return ch;
    }
signals:
    void look(string word) const;//作为信号函数把数据传给sockthread类中的函数

};
class breakable:public object {//getlevel返回易碎品,getprice乘以系数为8
    int getprice() {//
        return 8 * weight;
    }
    string getlevel() {
        return "易碎品";

    }
};
class book :public object {//getlevel返回图书,getprice乘以系数为2
    int getprice() {
        return 2 * weight;
    }
    string getlevel() {
        return "图书";

    }
};
class nomal :public object {//getlevel返回普通物品,getprice乘以系数为5
    int getprice() {
        return 5 * weight;
    }
    string getlevel () {
        return "普通物品";

    }
};
#endif // OBJECT_H

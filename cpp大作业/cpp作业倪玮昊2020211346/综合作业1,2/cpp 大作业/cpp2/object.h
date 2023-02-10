#pragma once
#include<conio.h>
#include <time.h>  
#include <stdlib.h>
#include <string.h>  
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<Windows.h>
#include <time.h>  
using namespace std;
#include<fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include <string>
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
class findobject {
public:
	string level;
	int count = 0;
	int weight;
	int price;
	string a_sentuser[1000];
	string a_receiveuser[1000];
	string a_kinds[1000];
	string a_num[1000];
	string a_address[1000];
	string a_stage[1000];
	string a_level[1000];
	string a_time[1000];
	string dp[1000];
	int a_price[1000];
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
	void prin(int k) {//打印订单具体内容
		cout << "订单号为" << a_num[k] << endl;
		cout << "寄件人为" << a_sentuser[k] << endl;
		cout << "收件人为" << a_receiveuser[k] << endl;
		cout << "收件人地址为" << a_address[k] << endl;
		cout << "物品描述为" << a_kinds[k] << endl;
		cout << "签收时间为" << a_stage[k] << endl;
		cout << "快递员为" << dp[k] << endl;
	}

	void recevive(string name) {//打印没有签收的订单
		cout << "未签收的订单有:" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			if (name == a_receiveuser[count1] && a_stage[count1]=="未接收") {
				prin(count1);
			}
		}
	start2:
		cout << "输入你想签收的快递单号" << endl;
		string num1;
		cin >> num1;
		if (yanzheng(num1) == 0) {
			cout << "快递号不存在或已接收,重新" << endl;
			goto start2;
		}
		qianshou(num1);

	}
	int yanzheng(string num) {//判断订单是否存在或是否被签收
		for (int count1 = 0; count1 < count; count1++) {
			if (num == a_num[count1]) {
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
				oss << receivetime.Year << "年" << receivetime.Month << "月" << receivetime.Day << "日" << receivetime.Hour << "时" << receivetime.Minute << "分" << receivetime.Second << "秒" << endl;
				string time1 = oss.str();
				a_stage[count1] = time1;
			}
		}


	}
	void devsearch(string name) {//对某一个快递员的全部快递进行查询
		for (int count1 = 0; count1 < count; count1++) {
			if (name== dp[count1]) {
				prin(count1);
			}
		}
		cout << "查询完成" << endl;
	}
	void re() {
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
	int lanshou(string name,string num1) {//揽收快递并将快递费返回给原函数
		for (int count1 = 0; count1 < count; count1++) {
			if ("未揽收" == a_stage[count1] && a_num[count1] == num1) {
				dp[count1] = name;
				re();
				cout << "分配完成" << endl;
				return a_price[count1] / 2;
			}
		}
	}
	int unlanshousaerch(string name) {//先对未揽收且归在快递员名下的快递进行查询,在对快递揽收,同时将状态改为未接收
		int money;
		cout << "未揽收的快递有" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			if ("未揽收" == a_stage[count1] && dp[count1]==name) {
				cout << a_num[count1]<<endl;
			}
		}
		cout << "输入你想揽收的快递单号" << endl;
		string num1;
		cin >> num1;
		for (int count1 = 0; count1 < count; count1++) {
			if (num1 == a_num[count1] ) {
				a_stage[count1] = "未接收";
				money = a_price[count1]- a_price[count1]/2;
			}
		}
		re();
		cout << "揽收成功" << endl;
		return money;
		
	}

};
class object {
public:
	string level ;
	int count = 0;
	int weight;
	int price;
	
	object() {
	
	}
	virtual int getprice() = 0;//计算价格
	virtual string getlevel() = 0;//根据物品类型确定运费要乘以的系数
	void sent(string name) {//name为寄出人的姓名,先对物品类型进行判断,通过不同的子类中的getprice来计算运费,通过 generCharArray()生成10位订单号,输入该快递所有信息,完成寄出.
		string receiveuser;
		string kinds;
		string num;
		string address;
		string stage = "未揽收";
		
		cout << "输入对寄出物品描述" << endl;
		cin >> kinds;
		cout << "输入对收件人姓名" << endl;
		cin >> receiveuser;
		cout << "输入对收件人地址" << endl;
		cin >> address;
		cout << "输入物品重量" << endl;
		cin >> weight;
		price = getprice();
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
		cout << "寄出成功" << endl;


	}

	string generCharArray() {//生成10位订单号
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

};
class breakable:public object {//易碎品子类
	int getprice() {
		return 8 * weight;
	}
	string getlevel() {
		return "易碎品";

	}
};
class book :public object {//图书子类
	int getprice() {
		return 2 * weight;
	}
	string getlevel() {
		return "图书";

	}
};
class nomal :public object {//普通物品子类
	int getprice() {
		return 5 * weight;
	}
	string getlevel () {
		return "普通物品";
		
	}
};
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
class dev {
public:
	string account[1000];
	string password[100];
	string name[1000];
	int rest[1000];
	string phone[1000];
	int now;
	int count = 0;
	dev(){//将文本文档内容录入到数组中.
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
	string login() {//通过打开存放用户数据的文档,比较账号和密码,如果验证成功则退出函数,否则继续对账户和密码进行输入.
	start2:
		cout << "请输入您的账号和密码来完成登陆操作." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == ac) {
				if (password[count1] == ac_password) {
					cout << "登陆成功";
					now = count1;
					return name[count1];
				}
				else break;
			}

		}
		cout << "密码或账号错误，请再次输入；" << endl;  goto start2;
	}
	void createnewaccount() {//对快递员进行注册,先判断是否账户重复,若不重复则逐步输入各项信息完成注册功能
	start2:
		cout << "请输入您的账号和密码来完成注册操作." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == ac) {
				cout << "账号有重复，请再次输入；" << endl;  goto start2;
			}

		}
		ofstream ofs;
		ofs.open("deviler.txt", ios::app);
		ofs << ac << endl;
		cout << "请输入您的密码来完成注册操作." << endl;
		string newac_password;
		cin >> setw(20) >> newac_password;
		ofs << newac_password << endl;
		cout << "请输入您的姓名来完成注册操作." << endl;
		string newac_name;
		cin >> setw(20) >> newac_name;
		ofs << newac_name << endl;
		cout << "请输入您的电话号码来完成注册操作." << endl;
		string newac_phone;
		cin >> setw(20) >> newac_phone;
		ofs << newac_phone << endl;
		cout << "请输入您的初始金额来完成注册操作." << endl;
		int newac_money;
		cin >> newac_money;
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
	}

	void re() {
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
	void search() const {//搜索可被调遣的快递员
		cout << "可派遣的快递员有" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			cout << name[count1] << endl;
		}
	}
	void findevac(string name1) {//对输入的快递员进行删除
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == name1) {
				account[count1] = "0";
				re();
				cout << "删除成功" << endl;
				return;
			}
		}
		cout << "不存在该快递员,重新输入" << endl;
	}
	void searchac() const {//搜索可被调遣的快递员的姓名
		cout << "可派遣的快递员有" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			cout << account[count1] << endl;
		}
	}
	void addmoney(string acc,int mon) {//对账户进行充值
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == acc) {
				rest[count1] = rest[count1] + mon;
			}
		}
	}
	int findev(string name1) const {//确认是否存在该快递员
		for (int count1 = 0; count1 < count; count1++) {
			if (name[count1] == name1) {
				return 1;
			}
		}
		return -1;
	}
	void find(string name) const {//查询具体快递,且该快递必须快递员为本人,即相关快递
		cout << "输入1根据发送人" << endl;
	start:
		string j;
		cout << "输入1通过收件人姓名查询的快递 输入2通过时间查询快递 输入2通过寄件人查询快递 输入4通过快递单号查询快递(只能查询与自己有关的快递）输入5根据快递状态查询" << endl;
		cin >> j;
		getchar();
		if (j == "1") {
			cout << "输入你想查询的收件人 " << endl;
			string time;
			cin >> time;
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
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << d << endl;
					cout << "收件人:" << e << endl;
					cout << "物品描述:" << f << endl;
					cout << "收件地址:" << g << endl;
					cout << "发件时间:" << h << endl;
					if (i == "未接收" || i == "未揽收")cout << "发件状态:" << i << endl;
					else cout << "收件时间:" << i << endl;
					cout << "物品种类:" << j << endl;
					cout << "快递员为:" << b << endl;
					ifs >> b;
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
			char k1[100];
			gets_s(k1);
			int k = strlen(k1);
			string time = k1;
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
				if (b.compare(0, k, time, 0, k) == 0 && (b == name )) {
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << d << endl;

					cout << "收件人:" << e << endl;

					cout << "物品描述:" << f << endl;

					cout << "收件地址:" << g << endl;

					cout << "发件时间:" << h<< endl;
					if (i == "未接收" || i == "未揽收")cout << "发件状态:" << i << endl;
					else cout << "收件时间:" << i << endl;
					cout << "物品种类:" << j << endl;
					cout << "快递员为:" << b << endl;
					ifs >> b;
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
			string name;
			cin >> name;
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
				if (e == name && (b == name )) {
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << d << endl;

					cout << "收件人:" << e << endl;

					cout << "物品描述:" << f << endl;

					cout << "收件地址:" << g << endl;

					cout << "发件时间:" << h << endl;
					if (i == "未接收" || i == "未揽收")cout << "发件状态:" << i << endl;
					else cout << "收件时间:" << i << endl;
					cout << "物品种类:" << j << endl;
					cout << "快递员为:" << b << endl;
					ifs >> b;
					cout << "运费为:" << b << endl;
				}
				else {
					ifs >> b;
				
				}

			}
			ifs.close();
		}
		else if (j == "4") {
			cout << "输入你想查询的快递单号" << endl;
			string num;
			cin >> num;
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
				if (c == num && (b == name )) {
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << d << endl;

					cout << "收件人:" << e << endl;

					cout << "物品描述:" << f << endl;

					cout << "收件地址:" << g << endl;

					cout << "发件时间:" << h << endl;
					if (i == "未接收" || i == "未揽收")cout << "发件状态:" << i << endl;
					else cout << "收件时间:" << i << endl;
					cout << "物品种类:" << j << endl;
					cout << "快递员为:" << b << endl;
					ifs >> b;
					cout << "运费为:" << b << endl;
				}
				else {
					ifs >> b;
			
				}
			}
		}
		else if (j == "5") {
		cout << "输入你想查询的状态(未揽收or未接收or已签收)" << endl;
		string time;
		cin >> time;
		fstream ifs;
		ifs.open("object.txt", ios::in);
		string b;
		cout << "历史快递:" << endl;
		if (time == "已签收") {
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
			if (i != "未接收" && i!="未揽收" && (b == name)) {
				cout << "快递单号:" << c << endl;
				cout << "寄件人:" << d << endl;
				cout << "收件人:" << e << endl;
				cout << "物品描述:" << f << endl;
				cout << "收件地址:" << g << endl;
				cout << "发件时间:" << h << endl;
				if (i == "未接收" || i == "未揽收")cout << "发件状态:" << i << endl;
				else cout << "收件时间:" << i << endl;
				cout << "物品种类:" << j << endl;
				cout << "快递员为:" << b << endl;
				ifs >> b;
				cout << "运费为:" << b << endl;
			}

			else {
				ifs >> b;
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
				cout << "快递单号:" << c << endl;
				cout << "寄件人:" << d << endl;
				cout << "收件人:" << e << endl;
				cout << "物品描述:" << f << endl;
				cout << "收件地址:" << g << endl;
				cout << "发件时间:" << h << endl;
				if (i == "未接收" || i == "未揽收")cout << "发件状态:" << i << endl;
				else cout << "收件时间:" << i << endl;
				cout << "物品种类:" << j << endl;
				cout << "快递员为:" << b << endl;
				ifs >> b;
				cout << "运费为:" << b << endl;
			}

			else {
				ifs >> b;
			}
		}
		ifs.close();
		}
	}
};
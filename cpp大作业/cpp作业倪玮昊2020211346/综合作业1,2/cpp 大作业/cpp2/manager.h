
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
class control {
private:
	string accountname;
	string name;
	int money;
	string password;
public:
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
	void login() {//登录
	start:
		cout << "输入账号号码和密码" << endl;
		string zhanghao;
		string mima;
		cout << "账号";
		cin >> zhanghao;
		cout << "密码";
		cin >> mima;
		if (mima == password && zhanghao == accountname) {
			cout << "登陆成功" << endl;
		}
		else {
			cout << "用户名或者密码错误,重新"; goto start;
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
	void change() {//修改管理员密码
	start:
		cout << "输入账号号码和密码" << endl;
		string zhanghao;
		string mima;
		cout << "账号";
		cin >> zhanghao;
		cout << "密码";
		cin >> mima;
		if (mima == password && zhanghao == accountname) {
			cout << "验证成功 输入新密码 " << endl;
			cout << "密码";
			cin >> mima;
			password = mima;
			re();
		}
		else {
			cout << "用户名或者密码错误,重新"; goto start;
		}
	}
	void manangeobjects() const {//:查询具体快递,不做限制,原理和account中的查找基本一致
	start:
		string j;
		cout << "输入1通过收件人姓名查询的快递 输入2通过时间查询快递 输入3通过寄件人查询快递 输入4通过快递单号查询快递" << endl;
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

				if (e == time) {
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << d << endl;
					cout << "收件人:" << e << endl;
					ifs >> b;
					cout << "物品描述:" << b << endl;
					ifs >> b;
					cout << "收件地址:" << b << endl;
					ifs >> b;
					cout << "发件时间:" << b << endl;
					ifs >> b;
					if (b == "未接收" || b == "未揽收")cout << "发件状态:" << b << endl;
					else cout << "收件时间:" << b << endl;
					ifs >> b;
					cout << "物品种类:" << b << endl;
					ifs >> b;
					cout << "快递员为:" << b << endl;
					ifs >> b;
					cout << "运费为:" << b << endl;
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
				if (b.compare(0, k, time, 0, k) == 0) {
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << d << endl;

					cout << "收件人:" << e << endl;

					cout << "物品描述:" << f << endl;

					cout << "收件地址:" << g << endl;

					cout << "发件时间:" << b << endl;
					ifs >> b;
					if (b == "未接收" || b == "未揽收")cout << "发件状态:" << b << endl;
					else cout << "收件时间:" << b << endl;
					ifs >> b;
					cout << "物品种类:" << b << endl;
					ifs >> b;
					cout << "快递员为:" << b << endl;
					ifs >> b;
					cout << "运费为:" << b << endl;
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
			string name;
			cin >> name;
			fstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			cout << "历史快递:" << endl;
			while (ifs >> b) {
				string c = b;
				ifs >> b;
				string e = b;
				ifs >> b;
				if (e == name) {
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << e << endl;
					cout << "收件人:" << b << endl;
					ifs >> b;
					cout << "物品描述:" << b << endl;
					ifs >> b;
					cout << "收件地址:" << b << endl;
					ifs >> b;
					cout << "发件时间:" << b << endl;
					ifs >> b;
					if (b == "未接收" || b=="未揽收")cout << "发件状态:" << b << endl;
					else cout << "收件时间:" << b << endl;
					ifs >> b;
					cout << "物品种类:" << b << endl;
					ifs >> b;
					cout << "快递员为:" << b << endl;
					ifs >> b;
					cout << "运费为:" << b << endl;
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
			string num;
			cin >> num;
			fstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			cout << "历史快递:" << endl;
			while (ifs >> b) {
				string c = b;
				ifs >> b;
				string e = b;
				ifs >> b;
				if (c == num) {
					cout << "快递单号:" << c << endl;
					cout << "寄件人:" << e << endl;
					cout << "收件人:" << b << endl;
					ifs >> b;
					cout << "物品描述:" << b << endl;
					ifs >> b;
					cout << "收件地址:" << b << endl;
					ifs >> b;
					cout << "发件时间:" << b << endl;
					ifs >> b;
					if (b == "未接收" || b == "未揽收")cout << "发件状态:" << b << endl;
					else cout << "收件时间:" << b << endl;
					ifs >> b;
					cout << "物品种类:" << b << endl;
					ifs >> b;
					cout << "快递员为:" << b << endl;
					ifs >> b;
					cout << "运费为:" << b << endl;
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
		else { cout << "无效输入" << endl; goto start; }


	}
	void add(int menoy) {//添加金额
		money = money + menoy;
	}
	void dec(int mon) {//减去金额
		money = money - mon;
	}
};
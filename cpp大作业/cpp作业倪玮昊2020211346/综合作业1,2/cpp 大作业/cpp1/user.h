
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include <string>
class account {
public:
	string accountname;//用户名
	string password;//密码
	string name;//姓名
	string phonenum;//电话号
	string money;//余额
	string location;//位置

	account() {
	start:
		cout << "选择你的身份" << endl;
		cout << "1.老用户  2.新用户 3.修改密码" << endl;
		string identity;
		cin >> identity;
		if (identity == "1") {
			login();//登录
		}
		else if (identity == "2") {
			createnewacount();//创建新用户
			login();
		}
		else if (identity == "3") {
			check();//修改密码
			login();//修改密码后紧接着登录
		}
		else { cout << "不合法输入，请重新"; goto start; }

	}

	int login() {//登录
	start2:
		cout << "请输入您的账号和密码来完成登陆操作." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;//输入密码
		ifstream ifs;
		ifs.open("account.txt", ios::in);
		string b;
		while (ifs >> b) {//打开存放用户数据的文档,比较账号和密码
			if (ac.compare(b) == 0) {
				accountname = b;
				ifs >> b;
				if (ac_password.compare(b) == 0) { 
					cout << "登录成功" << endl; 
					password = b;
					ifs >> b;
					name= b;
					ifs >> b;
					phonenum = b;
					ifs >> b;
					money = b;
					ifs >> b;
					location = b;
					ifs.close();
					return 0; }
				else { cout << "密码错误，请再次输入；" << endl; ifs.close(); goto start2; }
			}
			ifs >> b;
			ifs >> b;
			ifs >> b;
			ifs >> b;

		}
		ifs.close();
		cout << "密码错误，请再次输入；" << endl; ifs.close(); goto start2;


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
			}

		}


	void createnewacount() {
	start1:
		cout << "请输入您的用户名来完成注册操作." << endl;
		string newac;
		cin >> setw(20) >> newac;
		ifstream ifs;
		ifs.open("account.txt", ios::in);
		string b;
		while (ifs >> b) {//判断是否账户重复
			if (newac.compare(b) == 0) {
				cout << "该用户已存在" << endl; ifs.close();
				goto start1;
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
		cin >>  newac_money;
		ofs << newac_money << endl;
		cout << "请输入您的地址来完成注册操作." << endl;
		string newac_location;
		cin >> setw(20) >> newac_location;
		ofs << newac_location << endl;
		ofs.close();
	}
	int check() {//修改账户其他信息
	start2:
		cout << "请输入您的账号和密码来完成验证操作." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		ifstream ifs;
		ifs.open("account.txt", ios::in);
		string b;
		while (ifs >> b) {//输入账户和密码进行确定
			if (ac.compare(b) == 0) {
				accountname = b;
				ifs >> b;
				if (ac_password.compare(b) == 0) {
					cout << "验证成功" << endl; ifs.close();
					int change;
					cout << "扣1更改密码 2更改姓名 3更改电话 4地址"<<endl;
					cin >> change;
					if (change != 1 && change != 2 && change != 3 && change != 4) {
						cout << "非法输入,请重新" << endl;
					}
					changes(change);//修改
					return 0;
				}
				else{ cout << "密码有错误，请再次输入；" << endl; ifs.close(); goto start2; }
			}
			ifs >> b;
			ifs >> b;
			ifs >> b;
			ifs >> b;

		}
		ifs.close();
		cout << "密码错误，请再次输入；" << endl; ifs.close(); goto start2;
	}
		void changes(int work) {//修改内容
			string deal;
			string newdeal;
			if (work == 1) {
				cout << "输入你想更改的密码" << endl;
				deal = password;
				cin >> newdeal;
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
				cout << "修改完成" << endl;
			}
			if(work==2) {
				cout << "输入你想更改的姓名" << endl;
				deal = name;
				cin >> newdeal;
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
				cout << "修改完成" << endl;

			}
			if(work==3) {
				cout << "输入你想更改的电话" << endl;
				deal = phonenum;
				cin >> newdeal;
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
				cout << "修改完成" << endl;


			}
			if(work==4) {
				cout << "输入你想更改的地址" << endl;
				deal = location;
				cin >> newdeal;
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
				cout << "修改完成" << endl;

			}
			
		}
		void decmoney() {//对账户进行扣费,当余额不足时可以对用户进行提醒并进行充值
			int num = stoi(money);
			if (num < 15) {
				cout << "余额不足请充值" << endl;
				addmenoy();
			}
			num = num - 15;
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
				if (B != accountname) {//匹配到当前账号
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
			cout << "扣费完成" << endl;
		}
		void addmenoy() {//对账户进行充值
			int num = stoi(money);
			cout << "输入你想充值的金额" << endl;
			int ad;
			cin >> ad;
			num = num + ad;
			string num1 = to_string(num );
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
			cout << "充值完成" << endl;
		}
		void seachmoney() {//搜索余额
			cout << "余额为" <<money<< endl;
		}

		void findobject() const {//查询内容
		start:
			string j;
			cout << "输入1通过收件人姓名查询的快递 输入2通过时间查询快递 输入2通过寄件人查询快递 输入4通过快递单号查询快递(只能查询与自己有关的快递）" << endl;
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

					if (e == time && (d == name || e==name) ) {//收件人或寄件人必须有一个满足为目前账号
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
						if (b == "未接收")cout << "发件状态:" << b << endl;
						else cout << "收件时间:" << b << endl;
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
					if (b.compare(0, k, time, 0, k) == 0 && (d == name || e == name)) {//收件人或寄件人必须有一个满足为目前账号
						cout << "快递单号:" << c << endl;//模糊匹配
						cout << "寄件人:" << d << endl;

						cout << "收件人:" << e << endl;

						cout << "物品描述:" << f << endl;

						cout << "收件地址:" << g << endl;

						cout << "发件时间:" << b << endl;
						ifs >> b;
						if (b == "未接收")cout << "发件状态:" << b << endl;
						else cout << "收件时间:" << b << endl;
					}

					else ifs >> b;

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
					if (e == name && (b == name || e == name)) {//收件人或寄件人必须有一个满足为目前账号
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
						if (b == "未接收")cout << "发件状态:" << b << endl;
						else cout << "收件时间:" << b << endl;
					}
					else {
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
					if (c == num && (b == name || e == name)) {//收件人或寄件人必须有一个满足为目前账号
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
						if(b=="未接收")cout << "发件状态:" << b << endl;
						else cout << "收件时间:" << b << endl;
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
			else { cout << "无效输入" << endl; return; }

		
		}
	

};


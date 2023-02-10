#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
int createnewacount() {
	ifstream ifs;
	ifs.open("account.txt", ios::in);
	string b;
	if (ifs >> b) {
		cout << "系统已存在账号，请联系管理员删除" << endl; ifs.close();
		return -1;
	}

	ifs.close();
	cout << "请输入您的用户名和密码来完成注册操作." << endl;
	string newac;
	cin >> setw(20) >> newac;
	string newac_password;
	cin >> setw(20) >> newac_password;
	ofstream ofs;
	ofs.open("account.txt", ios::app);
	ofs << newac<< endl;
	ofs << newac_password<< endl;
	ofs.close();
	return -1;
}
int login() {
start2:
	cout << "输入1继续输入，输入其他返回之前界面" << endl;
	string order;
	cin >> order;
	if (order != "1") return -1;
	cout << "请输入您的账号和密码来完成登陆操作." << endl;
	string ac;
	cin >> setw(20) >> ac;
	extern string nowaccount;
	string ac_password;
	cin >> setw(20) >> ac_password;
	ifstream ifs;
	ifs.open("account.txt", ios::in);
	string b;
	while (ifs >> b) {
		if (ac.compare(b) == 0) {
			ifs >> b;
			if (ac_password.compare(b) == 0) { cout << "登录成功" << endl; ifs.close(); nowaccount=ac; return 0; }
			else { cout << "密码错误，请再次输入；"<<endl; ifs.close(); goto start2;  }
		}
		ifs >> b;
		
	}
	cout << "密码错误，请再次输入；" << endl; ifs.close(); goto start2;

	return -1;
}
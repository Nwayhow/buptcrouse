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
		cout << "ϵͳ�Ѵ����˺ţ�����ϵ����Աɾ��" << endl; ifs.close();
		return -1;
	}

	ifs.close();
	cout << "�����������û��������������ע�����." << endl;
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
	cout << "����1�������룬������������֮ǰ����" << endl;
	string order;
	cin >> order;
	if (order != "1") return -1;
	cout << "�����������˺ź���������ɵ�½����." << endl;
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
			if (ac_password.compare(b) == 0) { cout << "��¼�ɹ�" << endl; ifs.close(); nowaccount=ac; return 0; }
			else { cout << "����������ٴ����룻"<<endl; ifs.close(); goto start2;  }
		}
		ifs >> b;
		
	}
	cout << "����������ٴ����룻" << endl; ifs.close(); goto start2;

	return -1;
}
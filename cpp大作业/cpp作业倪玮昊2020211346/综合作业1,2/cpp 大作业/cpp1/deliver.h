#pragma once
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
class devliver {
	string account[1000];
	string password[100];
	string name[1000];
	int rest[1000];
	string phone[1000];
	string now;
	int count = 0;
	devliver() {
		ifstream ifs;
		ifs.open("deliver.txt", ios::in);
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
	}
	void login() {
	start2:
		cout << "�����������˺ź���������ɵ�½����." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == ac) {
				if (password[count1] == ac_password) {
					cout << "��½�ɹ�";
					now = count1;
					return;
				}
				else break;
			}

		}
		cout << "������˺Ŵ������ٴ����룻" << endl;  goto start2;
	}
	void createnewaccount() {
	start2:
		cout << "�����������˺ź����������ע�����." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == ac) {
				cout << "�˺����ظ������ٴ����룻" << endl;  goto start2;
			}

		}
		ofstream ofs;
		ofs.open("deviler.txt", ios::app);
		ofs << ac << endl;
		cout << "�������������������ע�����." << endl;
		string newac_password;
		cin >> setw(20) >> newac_password;
		ofs << newac_password << endl;
		cout << "�������������������ע�����." << endl;
		string newac_name;
		cin >> setw(20) >> newac_name;
		ofs << newac_name << endl;
		cout << "���������ĵ绰���������ע�����." << endl;
		string newac_phone;
		cin >> setw(20) >> newac_phone;
		ofs << newac_phone << endl;
		cout << "���������ĳ�ʼ��������ע�����." << endl;
		int newac_money;
		cin >> newac_money;
		ofs << newac_money << endl;
		ofs.close();

	}
	string fenpei(int money) {

	
		while (1) {
			cout << "���������ɳ��Ŀ��Ա" << endl;
			string man;
			cin >> man;
			for (int count1 = 0; count1 < count; count1++) {
				if (account[count1] == man) {
					rest[count1] = rest[count1] + money;
					re();
					return name[count1];
				}
			}
			cout << "�Ƿ����룬������������Ա" << endl;
		}
	}
	void re() {
		ofstream ofs;
		ofs.open("dev.txt", ios::out);
		for (int count1 = 0; count1 < count; count1++) {
			ofs << account[count] << endl;
			ofs << password[count] << endl;
			ofs << name[count] << endl;
			ofs << phone[count] << endl;
			ofs << rest[count] << endl;
		}
		ofs.close();
	}
	void search() {
		cout << "����ǲ�Ŀ��Ա��" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			cout << name[count1] << endl;
		}
	}
	
};
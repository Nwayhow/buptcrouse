#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
void downloadhomework() {
	ifstream ifs;
	getchar();
start:
	cout << "你想下载的作业是" << endl;
	char s[100];
	gets_s(s);
	string p = s;
	string b;
	ifs.open("homework.txt", ios::in);
	int l = 0;
	while (ifs >> b) {
		if (b == "end") {
			while (ifs >> b) {
				if (b == p) {
					l = 1; break;
				}
			}
			break;
		}
	}
	ifs.close();
	if (l == 0) {
		cout << "该作业不在已提交作业之列,请重新输入" << endl;
		goto start;
	}
	char j = '2';
	yasuo(j, s);

}
void upload() {
	ifstream ifs;
start:
	cout << "你想更新的作业是" << endl;
	char s[100];
	gets_s(s);
	string p = s;
	string b;
	ifs.open("homework.txt", ios::in);

	int l = 0;
	while (ifs >> b) {
		if (b == "end") {
			while (ifs >> b) {
				if (b == p) {
					l = 1; break;
				}
			}
			break;
		}
	}
	ifs.close();
	if (l == 0) {
		cout << "该作业不在已提交作业之列,请重新输入" << endl;
		goto start;
	}
	char j = '1';
	yasuo(j, s);
}
void findomework() {
	cout << "你想查询的作业是" << endl;
	char s[100];
	gets_s(s);
	searchhomework(s);
}
void puthomework() {
	ifstream ifs;
	string b;
	getchar();
	start:
	cout << "你想提交的作业是" << endl;
	char s[100];
	gets_s(s);
	string p = s;
	ifs.open("homework.txt", ios::in);
	int l = 0;
	while (ifs >> b) {
		if (b == "end") {
			break;
		}
		else if (b == p) {
			l = 1;
		}
	}
	ifs.close();
	if (l == 0) {
		cout << "该作业不在未提交作业之列,请重新输入" << endl;
		goto start;
	}
	char j = '1';
	yasuo(j,s);
	delputhomework(p);

}

void controlhomework() {
	
	string j;
	
	while (1) {
		cout << "输入1查询已上交作业和未上交作业 输入2上传作业 输入3下载已经上传的作业 输入4更新已有作业" << endl;
		cin >> j;
		if (j == "1") findomework();
		else if (j == "2") puthomework();
		else if (j == "3") downloadhomework();
		else if (j == "4") upload();
		else break;
	}
}
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
	cout << "�������ص���ҵ��" << endl;
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
		cout << "����ҵ�������ύ��ҵ֮��,����������" << endl;
		goto start;
	}
	char j = '2';
	yasuo(j, s);

}
void upload() {
	ifstream ifs;
start:
	cout << "������µ���ҵ��" << endl;
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
		cout << "����ҵ�������ύ��ҵ֮��,����������" << endl;
		goto start;
	}
	char j = '1';
	yasuo(j, s);
}
void findomework() {
	cout << "�����ѯ����ҵ��" << endl;
	char s[100];
	gets_s(s);
	searchhomework(s);
}
void puthomework() {
	ifstream ifs;
	string b;
	getchar();
	start:
	cout << "�����ύ����ҵ��" << endl;
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
		cout << "����ҵ����δ�ύ��ҵ֮��,����������" << endl;
		goto start;
	}
	char j = '1';
	yasuo(j,s);
	delputhomework(p);

}

void controlhomework() {
	
	string j;
	
	while (1) {
		cout << "����1��ѯ���Ͻ���ҵ��δ�Ͻ���ҵ ����2�ϴ���ҵ ����3�����Ѿ��ϴ�����ҵ ����4����������ҵ" << endl;
		cin >> j;
		if (j == "1") findomework();
		else if (j == "2") puthomework();
		else if (j == "3") downloadhomework();
		else if (j == "4") upload();
		else break;
	}
}
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
void setnotice() {
	string b;
	cout << "�����㶨����������: 1����һ�� 2����ÿ��һ�� 3����ÿ��һ��" << endl;
	string index;
	cin >> index;
	ofstream ofs;
	ofs.open("notice.txt", ios::app);
	ofs << index << endl;
	cout << "��������ʱ��" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "�������ӱ�ע" << endl;
	cin >> b;
	ofs << b << endl;
	ofs.close();
	noticestart();
	
}

int findclash(string time) {
	extern myclas clas[100];
	extern int count5;
	fstream ifs;
	string A;
	ifs.open("act.txt", ios::in);
	while (ifs >> A) {
		if (A == time) {
			ifs >> A;
			ifs >> A;
			cout << "�»��" << time << "��" << A << "������ͻ" << endl;
			ifs.close();
			return 2;
		}
		else { 
			ifs >> A; ifs >> A;
		}
	}
	ifs.close();
	for (int count = 0; count < count5; count++) {
		if (clas[count].time == time) {
			cout << "�»��" << time << "��γ�" << clas[count].name << "������ͻ" << endl;
			return 3;
		}
	}
	return 1;
}
void personact(string act) {
	int index = 0;
	cout << "����1���"<<act<<"��ѯ ����2���" <<act<< endl;
	cin >> index;
	if (index == 1) {
		cout << "���������ѯ�Ļ" << endl;
		char s[100];
		gets_s(s);
		cout << "���" << endl;
		searchactive(s,act);
	}
	if (index == 2) {
		start:
		cout << "����������ӵĻʱ��" << endl;
		string time;
		cin >> time;
		int k = findclash(time);
		if ( k!=1) {
			if (k == 3) {
				cout << "ѧ���޷��Կγ̽����޸�ʱ��,����ϵ������и��Ļ���������ʱ��" << endl;
				goto start;
			}
			string judge;
			cout << "���������������  ��1��ԭ�г�ͻ�����ɾ��" << endl;
			cin >> judge;
			if (judge != "1") goto start;
			else change(time);
		};
		ofstream ofs;
		ofs.open("act.txt", ios::app);
		
		ofs << time << endl;
		ofs << act<< endl;
		cout << "��������" << endl;
		string namenew;
		cin >> namenew;
		ofs <<namenew << endl;
		ofs.close();
	}
}

void function2() {
	//1.���˻��ѯ
	//2.������ѯ
	//3.���ӵ��趨
	int index = 0;
	cout << "����1�Ը��˻��ѯ ����2�Լ�����ѯ ����3��������"<<endl;
	cin >> index;
	if (index == 1) personact("���˻");
	if (index == 2) personact("����");
	if (index == 3) setnotice();
}
//������Ϣ
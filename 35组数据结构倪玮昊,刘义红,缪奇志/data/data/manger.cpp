#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
void changeclass() {
start:
	extern myclas clas[100];
	extern int count5;
	cout << "��������ı�Ŀγ�" << endl;
	string n;
	cin >> n;
	int count;
	for (count = 0; count < count5; count++) {
		if (n == clas[count].name) {
			break;
		}
		if (n != clas[count].name && count == count5-1) {
			cout << "�ÿγ̲����ڣ�������";
			goto start;
		}
	}
start1:
	cout << "����1�Կ��Եص��ʱ������޸� ����2�Կγ��Ͽ�ʱ��͵ص�����޸�" << endl;
	string j;
	cin >> j;
	if (j == "1") {
			cout << "ԭ�ȿ���ʱ��Ϊ" << clas[count].timeofexam << endl;
			cout << "�޸�ʱ��Ϊ" << endl;
			string m;
			cin >> m;
			for (int count1 = 0; count1 < count5; count1++) {
				if (clas[count1].timeofexam == m) {
					cout << "����ʱ���ͻ,����������"; goto start1;
				}
			}
			change(m);
			clas[count].timeofexam = m;
		cout << "ԭ�ȿ��Խ���Ϊ" << clas[count].buildingofexam << endl;
		cout << "�޸Ľ���Ϊ" << endl;
		cin >> clas[count].buildingofexam;
		cout << "ԭ�ȿ��Խ���Ϊ" << clas[count].classroomofexam << endl;
		cout << "�޸Ľ���Ϊ" << endl;
		cin >> clas[count].classroomofexam;


	}
	else if (j == "2") {
			cout << "ԭ���Ͽ�ʱ��Ϊ" << clas[count].time << endl;
			cout << "�޸�ʱ��Ϊ" << endl;
			string m;
			cin >> m;
			for (int count1 = 0; count1 < count5; count1++) {
				if (clas[count1].time == m) {
					cout << "����ʱ���ͻ,����������"; goto start1;
				}
			}
			change(m);
			clas[count].time = m;
			cout << "ԭ���Ͽν���Ϊ" << clas[count].buliding << endl;
			cout << "�޸Ľ���Ϊ" << endl;
			cin >> clas[count].buliding;
			cout << "ԭ���Ͽν���Ϊ" << clas[count].classroom << endl;
			cout << "�޸Ľ���Ϊ" << endl;
			cin >> clas[count].classroom;
			cout << "�޸ĳɹ�" << endl;
		}


	else {
		cout << "�Ƿ�����" << endl;
		goto start;
	}
	ofstream ofs;
	string A;
	ofs.open("class.txt", ios::out);
	for (int count1 = 0; count1 < count5; count1++) {
		ofs<<clas[count1].name<<endl;
		ofs << clas[count1].time << endl;
		ofs << clas[count1].campus << endl;
		ofs << clas[count1].buliding << endl;
		ofs << clas[count1].classroom << endl;
		ofs << clas[count1].timeofexam << endl;
		ofs << clas[count1].buildingofexam << endl;
		ofs << clas[count1].classroomofexam << endl;
		ofs << clas[count1].stage << endl;
		ofs << clas[count1].group << endl;
	}
	ofs.close();
	myclasss();
}
void addclass() {
	extern myclas clas[100];
	extern int count5;
	start1:
	cout << "����������ӿγ̵�ʱ��" << endl;
	string m;
	cin >> m;
	for (int count1 = 0; count1 < count5; count1++) {
		if (clas[count1].time == m) {
			cout << "����ʱ���ͻ,����������"; goto start1;
		}
	}
	change(m);
	string b;
	ofstream ofs;
	ofs.open("class.txt", ios::app);
	cout << "����γ�����" << endl;
	cin >> b;
	ofs << b<<endl;
	b = m;
	ofs << b << endl;
	cout << "����У��" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "�����Ͽν���" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "�����Ͽν���" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "���뿼��ʱ��" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "���뿼�Խ�ѧ¥" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "���뿼�Խ���" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "�����ѧ״̬" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "����γ�Ⱥ" << endl;
	cin >> b;
	ofs << b << endl;
	ofs.close();
	myclasss();

}

void themodeofcontorl() {
	cout << "����1����û�����  ����3�ı�γ̻���ʱ��͵�ַ ����4��ӿγ�"<<endl;
	int order;
	cin >> order;
	if (order == 1) {
		ofstream ofs;
		
		ofs.open("account.txt", ios::out);
		ofs.close();
	}

	if (order == 3) {
		changeclass();
	}
	if (order == 4) {
		addclass();
	}

}

int control() {
	extern string contorlaccount;
	extern string contorl_paaword;
start3:
	cout << "����1�������룬������������֮ǰ����" << endl;
	string order;
	cin >> order;
	if (order != "1") return -1;
	string A = "";
	string B = "";
		cout << "�������Ա�˺�:" << endl;
		cin >> setw(20) >> A;
		cout << "�������Ա����:" << endl;
		cin >> setw(20) >> B;
		if (A.compare(contorlaccount) == 0 && B.compare(contorl_paaword) == 0);
		else { cout << "�˺Ż����������" << endl; goto start3; }
	
	themodeofcontorl();
	return -1;

}

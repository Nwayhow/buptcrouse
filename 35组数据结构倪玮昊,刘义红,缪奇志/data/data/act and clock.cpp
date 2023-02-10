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
	cout << "输入你定的闹钟类型: 1代表一次 2代表每周一次 3代表每天一次" << endl;
	string index;
	cin >> index;
	ofstream ofs;
	ofs.open("notice.txt", ios::app);
	ofs << index << endl;
	cout << "输入闹钟时间" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入闹钟备注" << endl;
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
			cout << "新活动在" << time << "与活动" << A << "发生冲突" << endl;
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
			cout << "新活动在" << time << "与课程" << clas[count].name << "发生冲突" << endl;
			return 3;
		}
	}
	return 1;
}
void personact(string act) {
	int index = 0;
	cout << "输入1输出"<<act<<"查询 输入2添加" <<act<< endl;
	cin >> index;
	if (index == 1) {
		cout << "输入你想查询的活动" << endl;
		char s[100];
		gets_s(s);
		cout << "活动有" << endl;
		searchactive(s,act);
	}
	if (index == 2) {
		start:
		cout << "输入你想添加的活动时间" << endl;
		string time;
		cin >> time;
		int k = findclash(time);
		if ( k!=1) {
			if (k == 3) {
				cout << "学生无法对课程进行修改时间,请联系管理进行更改或重新输入时间" << endl;
				goto start;
			}
			string judge;
			cout << "按任意键重新输入  扣1对原有冲突活动进行删除" << endl;
			cin >> judge;
			if (judge != "1") goto start;
			else change(time);
		};
		ofstream ofs;
		ofs.open("act.txt", ios::app);
		
		ofs << time << endl;
		ofs << act<< endl;
		cout << "输入活动名称" << endl;
		string namenew;
		cin >> namenew;
		ofs <<namenew << endl;
		ofs.close();
	}
}

void function2() {
	//1.个人活动查询
	//2.集体活动查询
	//3.闹钟的设定
	int index = 0;
	cout << "输入1对个人活动查询 输入2对集体活动查询 输入3设置闹钟"<<endl;
	cin >> index;
	if (index == 1) personact("个人活动");
	if (index == 2) personact("集体活动");
	if (index == 3) setnotice();
}
//课内信息
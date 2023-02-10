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
	cout << "输入你想改变的课程" << endl;
	string n;
	cin >> n;
	int count;
	for (count = 0; count < count5; count++) {
		if (n == clas[count].name) {
			break;
		}
		if (n != clas[count].name && count == count5-1) {
			cout << "该课程不存在，请重新";
			goto start;
		}
	}
start1:
	cout << "输入1对考试地点和时间进行修改 输入2对课程上课时间和地点进行修改" << endl;
	string j;
	cin >> j;
	if (j == "1") {
			cout << "原先考试时间为" << clas[count].timeofexam << endl;
			cout << "修改时间为" << endl;
			string m;
			cin >> m;
			for (int count1 = 0; count1 < count5; count1++) {
				if (clas[count1].timeofexam == m) {
					cout << "发生时间冲突,请重新输入"; goto start1;
				}
			}
			change(m);
			clas[count].timeofexam = m;
		cout << "原先考试建筑为" << clas[count].buildingofexam << endl;
		cout << "修改建筑为" << endl;
		cin >> clas[count].buildingofexam;
		cout << "原先考试教室为" << clas[count].classroomofexam << endl;
		cout << "修改教室为" << endl;
		cin >> clas[count].classroomofexam;


	}
	else if (j == "2") {
			cout << "原先上课时间为" << clas[count].time << endl;
			cout << "修改时间为" << endl;
			string m;
			cin >> m;
			for (int count1 = 0; count1 < count5; count1++) {
				if (clas[count1].time == m) {
					cout << "发生时间冲突,请重新输入"; goto start1;
				}
			}
			change(m);
			clas[count].time = m;
			cout << "原先上课建筑为" << clas[count].buliding << endl;
			cout << "修改建筑为" << endl;
			cin >> clas[count].buliding;
			cout << "原先上课教室为" << clas[count].classroom << endl;
			cout << "修改教室为" << endl;
			cin >> clas[count].classroom;
			cout << "修改成功" << endl;
		}


	else {
		cout << "非法输入" << endl;
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
	cout << "输入你想添加课程的时间" << endl;
	string m;
	cin >> m;
	for (int count1 = 0; count1 < count5; count1++) {
		if (clas[count1].time == m) {
			cout << "发生时间冲突,请重新输入"; goto start1;
		}
	}
	change(m);
	string b;
	ofstream ofs;
	ofs.open("class.txt", ios::app);
	cout << "输入课程名称" << endl;
	cin >> b;
	ofs << b<<endl;
	b = m;
	ofs << b << endl;
	cout << "输入校区" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入上课建筑" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入上课教室" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入考试时间" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入考试教学楼" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入考试教室" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入教学状态" << endl;
	cin >> b;
	ofs << b << endl;
	cout << "输入课程群" << endl;
	cin >> b;
	ofs << b << endl;
	ofs.close();
	myclasss();

}

void themodeofcontorl() {
	cout << "输入1清除用户数据  输入3改变课程或考试时间和地址 输入4添加课程"<<endl;
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
	cout << "输入1继续输入，输入其他返回之前界面" << endl;
	string order;
	cin >> order;
	if (order != "1") return -1;
	string A = "";
	string B = "";
		cout << "输入管理员账号:" << endl;
		cin >> setw(20) >> A;
		cout << "输入管理员密码:" << endl;
		cin >> setw(20) >> B;
		if (A.compare(contorlaccount) == 0 && B.compare(contorl_paaword) == 0);
		else { cout << "账号或者密码错误" << endl; goto start3; }
	
	themodeofcontorl();
	return -1;

}

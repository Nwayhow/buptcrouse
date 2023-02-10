#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include"head.h"
#include <thread>
#include <time.h>  
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
void setime() {
	extern int week;
	extern int hour;
	struct tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	week = t.tm_wday;
	hour = t.tm_hour;
}
void clocknotice(string time) {
	extern note notice[100];
	extern int count7;
	for (int count = 0; count < count7; count++) {
		if (notice[count].type == "1") {
			if (time == notice[count].time) {
				cout << time << "的闹钟生效" << "(仅一次)备注为" << notice[count].kind << endl;
				notice[count].type = "0";
			}
			
		}
		if (notice[count].type == "2") {
			if (time== notice[count].time) {
				cout << time << "的闹钟生效" << "(每周)备注为" << notice[count].kind << endl;
			}
		}
		if (notice[count].type == "3") {
			int judge=time.compare(6, 2, notice[count].time, 0, 2);

			if (judge==0) {
				cout << time << "的闹钟生效"<<"(每日)备注为"<<notice[count].kind<<endl;
			}
		}
		ofstream ofs;
		ofs.open("notice.txt", ios::out);
		for (int count = 0; count < count7; count++) {
			ofs << notice[count].type << endl;
			ofs << notice[count].time << endl;
			ofs << notice[count].kind << endl;
		}
		ofs.close();
		noticestart();
	}

}
void myPrint() {
	extern int week;
	extern int hour;
	extern char j;
	extern string time1;
	while (1) {

		if (j == 's') {
			Sleep(10 * 1000);
		
		}
		if (j == '2') {
			Sleep(2 * 1000);
	
		}
		if (j == '3') {
			Sleep(500);
		}
		if (j == 's' || j == '2' || j == '3') {
			hour = hour + 1;
			if (hour % 24 == 0) {
				hour = 0;
				week = (week + 1) % 7;
			}
			string day;
			if (week == 0) day = "日";
			if (week ==1) day = "一";
			if (week == 2) day = "二";
			if (week == 3) day = "三";
			if (week == 4) day = "四";
			if (week == 5) day = "五";
			if (week == 6) day = "六";
			ostringstream oss;
			oss<< "星期" << day  << hour << "：00" ;
			time1 = oss.str();
			cout << time1<<endl;
			clocknotice(time1);
		}
	}
}
int main() {
	extern char j;
	setime();
	init();
	myclasss();
	buildact();
	noticestart();
	cout << "输入s原速进行 输入1进入程序 输入2加速5倍 输入3加速20倍" << endl;
	thread myThread(myPrint);
	while (1) {
		bool wheIsnew = false;
		cin>>j;
		if (j == '1') {
			cout << "1.老用户  2.新用户  3.管理员" << endl;
			int identity;
			cin >> identity;
			if (identity == 1) {
				int order = login();
				if (order == -1) {
				}
				if (order == 0)  systemall();
			}
			if (identity == 2) {
				int order = createnewacount();

			}

			if (identity == 3) {
				int order = control();
				if (order == -1) {
				}
			}
			if (identity == 4) {
				systemall();
			}
			j = 's';
		}
	}
	}

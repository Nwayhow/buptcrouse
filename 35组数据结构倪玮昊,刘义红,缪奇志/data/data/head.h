
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
void function1();
void function2();
void function3();
int createnewacount();
int login();
void themodeofcontorl();
int control();
void systemall();
void square();
void Dijkstra(int sign, int startpoint, int sign1, int endpoint);
void change(string time);
using namespace std;
class buildings {
public:
	char buildingname[100];
	int campus = 0;
	int index = 0;
	string name = {};
	void printff() {
		cout << "该建筑名称为" <<name << endl;
	}

};
void init();
class myclas {
public:
	string name ;
	string time;
	string campus;
	string buliding;
	string classroom;
	string timeofexam;
	string buildingofexam;
	string classroomofexam;
	string stage;
	string group;
	char classname[1000];
	char timename[1000];
	char buildingname[1000];
	void printff() {
		cout << "课程名为" << name << endl;
		cout << "上课时间为" <<time<< endl;
		cout << "上课及考试校区为" <<campus << endl;
		cout << "上课地点为" << buliding<<classroom << endl;
		cout << "考试时间为" << timeofexam << endl;
		cout << "考试地点为" << buildingofexam<<classroomofexam << endl;
		cout << "教学进度为" << stage << endl;
		cout << "课程群为" << group << endl;
	
	}
};
class myact {
public:

	string time;
	string kind;
	string name;
	char actname[100];
	void printff() {
		cout << "该活动时间为" << time << endl;
		cout << "活动类型为" << kind << endl;
		cout << "活动名称为" << name<< endl;
	

	}
};
class note {
public:
	string type;
	string time;
	string kind;
	void printff() {
		cout << "闹钟种类为" << time << endl;
		cout << "闹钟时间为" << kind << endl;
		cout << "闹钟备注为" << kind << endl;
	}
};
class homework {
public:
	char name[100];
	int stage;
	void printff() {
		cout << "作业名称为" << name << endl;
		if(stage==1)cout << "未完成"  << endl;
		if(stage == 2)cout << "已完成" << endl;
	}
};
void buildact();
void myclasss();
void personact(string act);
int yasuo(char j,char s[]);
void controlhomework();
int findclash(string time);
void setnotice();
void noticestart();
void delputhomework(string p);
void searchclass(char son[100]);
void searchactive(char son[100], string kind);
void searchtime(char son[100]);
void searchbuilding(char son[100],string campus);
void searchhomework(char son[100]);
void searchway(char son[100], int campus);
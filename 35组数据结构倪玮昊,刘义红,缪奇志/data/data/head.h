
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
		cout << "�ý�������Ϊ" <<name << endl;
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
		cout << "�γ���Ϊ" << name << endl;
		cout << "�Ͽ�ʱ��Ϊ" <<time<< endl;
		cout << "�Ͽμ�����У��Ϊ" <<campus << endl;
		cout << "�Ͽεص�Ϊ" << buliding<<classroom << endl;
		cout << "����ʱ��Ϊ" << timeofexam << endl;
		cout << "���Եص�Ϊ" << buildingofexam<<classroomofexam << endl;
		cout << "��ѧ����Ϊ" << stage << endl;
		cout << "�γ�ȺΪ" << group << endl;
	
	}
};
class myact {
public:

	string time;
	string kind;
	string name;
	char actname[100];
	void printff() {
		cout << "�ûʱ��Ϊ" << time << endl;
		cout << "�����Ϊ" << kind << endl;
		cout << "�����Ϊ" << name<< endl;
	

	}
};
class note {
public:
	string type;
	string time;
	string kind;
	void printff() {
		cout << "��������Ϊ" << time << endl;
		cout << "����ʱ��Ϊ" << kind << endl;
		cout << "���ӱ�עΪ" << kind << endl;
	}
};
class homework {
public:
	char name[100];
	int stage;
	void printff() {
		cout << "��ҵ����Ϊ" << name << endl;
		if(stage==1)cout << "δ���"  << endl;
		if(stage == 2)cout << "�����" << endl;
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
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
void search() {
	extern myclas clas[100];
	extern int count5;
	start:
	cout << "输入课程名称：" << endl;
	char s[100];
	gets_s(s);
	cout << "课程有" << endl;
	searchclass(s);
}
void function3() {
	cout << "输入1进行课程信息查询";
	int index;
cin >> index;
	if (index == 1) search();

}
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
	cout << "����γ����ƣ�" << endl;
	char s[100];
	gets_s(s);
	cout << "�γ���" << endl;
	searchclass(s);
}
void function3() {
	cout << "����1���пγ���Ϣ��ѯ";
	int index;
cin >> index;
	if (index == 1) search();

}
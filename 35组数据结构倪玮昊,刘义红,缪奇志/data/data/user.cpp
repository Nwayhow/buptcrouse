#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"

void systemall() {
	printf("��ӭ�������½�ѧ����ϵͳ������������ʹ�õĹ��ܣ�\n");
	int function;
	printf("����1������ѡ��γ̵�������\n");
	printf("����2������ѡ�������Ϣ����Ͳ�ѯ\n");
	printf("����3������ѡ��γ���Ϣ����Ͳ�ѯ\n");
	printf("����4������ѡ����ҵ�Ĳ�ѯ���Ͻ�\n");
	cin >> function;
	if (function == 1) {
		function1();
	}
	else if (function == 2) {
		function2();
	}
	else if (function == 3) {
		function3();
	}
	else if (function == 4) {
		controlhomework();
	}
}

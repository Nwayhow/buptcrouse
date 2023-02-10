#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"

void systemall() {
	printf("欢迎进入线下教学辅助系统，请输入您想使用的功能：\n");
	int function;
	printf("输入1代表您选择课程导航功能\n");
	printf("输入2代表您选择课外信息管理和查询\n");
	printf("输入3代表您选择课程信息管理和查询\n");
	printf("输入4代表您选择作业的查询与上交\n");
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

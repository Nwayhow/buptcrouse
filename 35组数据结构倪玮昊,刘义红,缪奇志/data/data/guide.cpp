#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include<ctime>
#include <time.h>
#include <stdlib.h>
#include"head.h"
void guideway(int way) {
	extern int campus1[50][50];
	extern int campus2[50][50];
	extern buildings building[100];
	srand((int)time(0));
	if (way == 3) {
		cout << "本部实时拥挤度为" << endl;
		for (int count = 0; count < 50; count++) {
			for (int count1 = count; count1 < 50; count1++) {
				if (campus1[count][count1] != 10000) {
					double r = ((rand() % (6)) + 5);
					cout << building[count].name << "到" << building[count1].name << "的拥挤度为" << (double)r/10 << endl;
					double r1 = 10*campus1[count][count1] / r;
					campus1[count][count1] = (int)r1;
					campus1[count1][count] = campus1[count][count1];
				}
			}
		}
		cout << "沙河实时拥挤度为" << endl;
		for (int count = 0; count < 50; count++) {
			for (int count1 = count; count1 < 50; count1++) {
				if (campus2[count][count1] != 10000) {
					double r = ((rand() % (6)) + 5);
					cout << building[count + 50].name << "到" << building[count1 + 50].name << "的拥挤度为" << r/10 << endl;
					double r1 = 10*campus2[count][count1] / r;
					campus2[count][count1] =(int) r1;
					campus2[count1][count] = campus2[count][count1];
				}
			}
		}
	}
	if (way == 2) {
		campus1[0][6] = 2;
		campus1[6][10] = 2;
		campus1[10][15] = 2;
		campus1[15][19] = 2;
		campus1[19][24] = 2;
		campus1[24][30] = 2;
		campus1[0][1] = 2;
		campus1[1][2] = 2;
		campus1[2][3] = 2;
		campus1[3][4] = 2;
		campus1[2][7] = 2;
		campus1[7][12] = 2;
		campus1[12][17] = 2;
		campus1[17][20] = 2;
		campus1[20][21] = 2;
		campus1[21][22] = 2;
		campus1[4][9] = 2;
		campus1[9][13] = 2;
		campus1[13][18] = 2;
		campus1[18][22] = 2;
		campus1[35][36] = 2;
		campus1[36][37] = 2;
		campus1[37][38] = 2;
		campus1[38][39] = 2;
		campus1[39][49] = 2;
		campus1[35][43] = 2;
		campus1[43][44] = 2;
		campus1[44][45] = 2;
		campus1[45][46] = 2;
		campus1[46][47] = 2;
		campus1[47][48] = 2;
		campus1[48][49] = 2;
		for (int con = 0; con < 50; con++) {
			for (int con1 = con; con1 < 50; con1++) {
				campus1[con1][con] = campus1[con][con1];
			}
		}
		campus2[0][6] = 2;
		campus2[6][10] = 2;
		campus2[10][15] = 2;
		campus2[15][19] = 2;
		campus2[19][24] = 2;
		campus2[24][30] = 2;
		campus2[0][1] = 2;
		campus2[1][2] = 2;
		campus2[2][3] = 2;
		campus2[3][4] = 2;
		campus2[2][7] = 2;
		campus2[7][12] = 2;
		campus2[12][17] = 2;
		campus2[17][20] = 2;
		campus2[20][21] = 2;
		campus2[21][22] = 2;
		campus2[4][9] = 2;
		campus2[9][13] = 2;
		campus2[13][18] = 2;
		campus2[18][22] = 2;
		campus2[35][36] = 2;
		campus2[36][37] = 2;
		campus2[37][38] = 2;
		campus2[38][39] = 2;
		campus2[39][49] = 2;
		campus2[35][43] = 2;
		campus2[43][44] = 2;
		campus2[44][45] = 2;
		campus2[45][46] = 2;
		campus2[46][47] = 2;
		campus2[47][48] = 2;
		campus2[48][49] = 2;
		for (int con = 0; con < 50; con++) {
			for (int con1 = con; con1 < 50; con1++) {
				campus2[con1][con] = campus2[con][con1];
			}
		}


	}
}
void function1() {
	extern int count5;
	extern buildings building[100];
	int index = 0;
	printf("输入1代表您使用课程名称进行路径规划\n");
	printf("输入2代表您使用上课时间进行路径规划\n");
	printf("输入3代表您使用上课地点进行路径规划\n");
	cin >> index;
	int startpoint;
	int endpoint;
	extern myclas clas[100];
	string campus;
start:
	int sign = 1;
	int sign1 = 1;
	string endway="";
	cout << "输入出发校区：沙河 or 西土城" << endl;

	cin >> campus;
	if (campus == "沙河") sign = 2;
	else if (campus == "西土城");
	else {
		cout << "输入错误，重新输入" << endl;
		goto start;
	}
	cout << "输入出发位置：（假装有图）" << endl;
	char s[100];
	getchar();
	gets_s(s);
	cout << "符合条件的位置有" << endl;
	searchway(s,sign);
	cout << "输入确切位置" << endl;
	string startway;
	cin>>startway;
	if (sign == 1) {
		for (int count = 0; count < 50; count++) {
			if (startway == building[count].name) {
				startpoint = count; break;
			}
			if (count == 49 && startway != building[count].name) {
				cout << "输入错误，重新输入" << endl; goto start;
			}
		}
	}
	else {
		for (int count = 50; count < 100; count++) {
			if (startway == building[count].name) {
				startpoint = count - 50; break;
			}
			if (count == 99 && startway != building[count].name) {
				cout << "输入错误，重新输入" << endl; goto start;
			}
		}
	}
start1:

	if (index == 1) {
		cout << "输入课程名称：" << endl;
		char s[100];
		getchar();
		gets_s(s);
		cout << "符合条件的课程信息有有" << endl;
		searchclass(s);
		cout << "输入确切课程对应位置" << endl;
	}
	else if (index == 2) {
		cout << "输入上课时间（格式如：星期一10：00）：" << endl;
		char s[100];
		getchar();
		gets_s(s);
		cout << "符合条件的课程信息有有" << endl;
		searchtime(s);
		cout << "输入确切课程对应位置" << endl;
	}
	else if (index == 3) {
		cout << "输入目的地校区：沙河 or 西土城" << endl;
		string campus1;
		cin >> campus1;
		if (campus1 == "沙河") sign1 = 2;
		else if (campus1 == "西土城");
		else {
			cout << "输入错误，重新输入" << endl;
			goto start1;
		}
		cout << "输入目的地位置：（假装有图）" << endl;
		char s[100];
		getchar();
		gets_s(s);
		cout << "符合条件的课程信息有有" << endl;
		searchbuilding(s,campus);
		cout << "输入确切课程对应位置" << endl;
		
	}
	cin >> endway;
		if (sign1 == 1) {
			for (int count = 0; count < 50; count++) {
				if (endway == building[count].name) {
					endpoint = count; break;
				}
				if (count == 49 && endway != building[count].name) {
					cout << "输入错误，重新输入" << endl; goto start1;
				}
			}
		}
		else {
			for (int count = 50; count < 100; count++) {
				if (endway == building[count].name) {
					endpoint = count - 50; break;
				}
				if (count == 99 && endway != building[count].name) {
					cout << "输入错误，重新输入" << endl; goto start1;
				}
			}
		}
		cout << "选择你的导航方式1.正常导航 2.骑车 3.考虑拥挤度 " << endl;
		int way;
		cin >> way;
		guideway(way);
		Dijkstra(sign, startpoint,sign1, endpoint);
		square();
		

	}


	

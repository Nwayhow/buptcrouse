#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include<string.h>
#include"head.h"
int findmin(int D[],int S[]) {
	int min = 10000;
	int minnum = -1;
	for (int count = 0; count < 50; count++) {
		if (D[count] < min && D[count]!=0 && S[count]!=1) {
			min = D[count];
			minnum = count;
		}
	}
	return minnum;
}
void Dijkstra(int sign, int startpoint, int sign1, int endpoint){
	extern buildings building[100];
	extern int campus1[50][50];
	extern int campus2[50][50];
	
	if (sign == 1 && sign1 == 2) {
		if(startpoint!=0) Dijkstra(1, startpoint, 1, 0);
		cout << "����40���ӳ��̵���ɳ��У������"<<endl;
		if (endpoint != 0) Dijkstra(2, 0, 2, endpoint);
	}
	if ((sign == 2 && sign1 == 2)) {
		int S1[50];
		int D[50];
		int P[50];
		for (int con = 0; con < 50; con++) {
			P[con] = startpoint;
			S1[con] = 0;
		}
		P[startpoint] = -1;
		for (int count = 0; count < 50; count++) {
			D[count] = campus2[startpoint][count];
		}
		S1[startpoint] = 1;
		for (int count = 0; count < 50; count++) {
			int minnum = findmin(D, S1);

			if(minnum>=0) S1[minnum] = 1;
			for (int con1 = 0; con1 < 50; con1++) {
				if (S1[con1] == 0 && (D[con1] > (D[minnum] + campus2[minnum][con1]))) {
					D[con1] = D[minnum] + campus2[minnum][con1];
					P[con1] = minnum;

				}
			}
		}
	
		int way[50];
		int con2 = 0;
		int pre = P[endpoint];
		while (pre != -1) {
			way[con2] = pre;
			con2++;
			pre = P[pre];
		}
		cout << "��" << building[startpoint + 50].name << "����" ;
		int con3;
		for (con3 = con2 - 2; con3 >= 0; con3--) {
			if (campus2[way[con3 + 1]][way[con3]] == 2) {
				cout << "�����г�";
			}
			cout << "����" << campus2[way[con3 + 1]][way[con3]] << "����";
			cout << " ���� " << building[way[con3]+50].name << " ��";
		}
		if (campus2[way[con3 + 1]][endpoint] == 2) cout << "�����г�";
		cout << "����" << campus2[way[con3 + 1]][endpoint]<< "����";
		cout << "����" << building[endpoint+50].name<< endl;
	
		

	}
	if ((sign == 1 && sign1 == 1 )) {
		int S[50];
		int D[50];
		int P[50];
		for (int con = 0; con < 50; con++) {
			P[con] = startpoint;
			S[con] = 0;
		}
		P[startpoint] = -1;
		for (int count = 0; count < 50; count++) {
			D[count] = campus1[startpoint][count];
		}
		S[startpoint] = 1;
		for (int count = 0; count < 50; count++) {
			int minnum=findmin(D,S);
			if (minnum >= 0) S[minnum] = 1;
			for (int con1 = 0; con1 < 50; con1++) {
				if (S[con1] == 0 && D[con1] > D[minnum] + campus1[minnum][con1]) {
					D[con1] = D[minnum] + campus1[minnum][con1];
					P[con1] = minnum;
				}
			}
		}
		int way[50];
		int con2 = 0;
		int pre = P[endpoint];
		while (pre != -1) {
			way[con2] = pre;
			con2++;
			pre = P[pre];
		}
		cout << "��" << building[startpoint].name << "����";
		int con3;
		for (con3 = con2 - 2; con3 >= 0; con3--) {
			if (campus1[way[con3 + 1]][way[con3]] == 2) {
				cout << "�����г�";
			}
			cout << "����" << campus1[way[con3 + 1]][way[con3]] << "����";
			cout << " ���� " << building[way[con3] ].name << " ��";
		}
		if (campus1[way[con3 + 1]][endpoint] == 2) cout << "�����г�";
			cout << "����" << campus1[way[con3+1]][endpoint] << "����";
		cout << "����" << building[endpoint ].name << endl;
	
	}
	if (sign ==2 && sign1 == 1) {
		if (startpoint != 0) Dijkstra(2, startpoint, 2, 0);
		cout << "����40���ӳ��̵���������У������" << endl;
		if (endpoint != 0)  Dijkstra(1, 0, 1, endpoint);
	}
	square();
}

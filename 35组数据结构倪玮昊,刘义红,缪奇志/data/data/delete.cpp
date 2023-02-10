#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
void delputhomework(string p) {
	ifstream ifs;
	string A;
	ifs.open("homework.txt", ios::in);
	ofstream ofs;
	ofs.open("tem.txt", ios::out);
	while (ifs >> A) {
		if (A == p) {

		}
		else { ofs << A << endl; }
	}
	ifs.close();
	ofs.close();
	ifs.open("tem.txt", ios::in);
	ofs.open("homework.txt", ios::out);
	while (ifs >> A) {
		ofs << A << endl;
	}
	ifs.close();
	ofs.close();
	ofs.open("homework.txt", ios::app);
	ofs << p << endl;
	ofs.close();

}
void change(string time) {
	ifstream ifs;
	string A;
	ifs.open("act.txt", ios::in);
	ofstream ofs;
	ofs.open("tem.txt", ios::out);
	while (ifs >> A) {
		if (A != time) {
			ofs << A << endl;
			ifs >> A;
			ofs << A << endl;
			ifs >> A;
			ofs << A << endl;
		}
		else { ifs >> A; ifs >> A; }
	}
	ifs.close();
	ofs.close();
	ifs.open("tem.txt", ios::in);
	ofs.open("act.txt", ios::out);
	while (ifs >> A) {
		ofs << A << endl;
		ifs >> A;
		ofs << A << endl;
		ifs >> A;
		ofs << A << endl;

	}
	ifs.close();
	ofs.close();
	return;


}
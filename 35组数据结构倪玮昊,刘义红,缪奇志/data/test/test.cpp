//#include<stdafx.h>
#include<iostream>
#include<stdio.h> 
#include<fstream>
#include<vector>
#include<string>
#include<stack>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 

using namespace std;


int main()
{
	char son[100];
	ostringstream oss;
	ifstream ifs;
	ifs.open("qt.txt", ios::in);
	ifs >> son;
	ifs.close();
	ofstream ofs;
	ofs.open(son, ios::out);
	ofs << son;
	ofs.close();
	
	
	cout << son;



	return 0;
}
#pragma once
#include<conio.h>
#include <time.h>  
#include <stdlib.h>
#include <string.h>  
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<Windows.h>
#include <time.h>  
using namespace std;
#include<fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include <string>
class mytime {
public:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
	
	mytime() {
		struct tm t;
		time_t now;
		time(&now);
		localtime_s(&t, &now);
		Year = 1900 + t.tm_year;
		Month = 1 + t.tm_mon;
		Day = t.tm_mday;
		Hour = t.tm_hour;
		Minute = t.tm_min;
		Second = t.tm_sec;

	}

};
class findobject {
public:
	string level;
	int count = 0;
	int weight;
	int price;
	string a_sentuser[1000];
	string a_receiveuser[1000];
	string a_kinds[1000];
	string a_num[1000];
	string a_address[1000];
	string a_stage[1000];
	string a_level[1000];
	string a_time[1000];
	string dp[1000];
	int a_price[1000];
	findobject() {//���ı��ĵ�����¼�뵽������.
		ifstream ifs;
		ifs.open("object.txt", ios::in);
		string b;
		count = 0;
		while (ifs >> b) {
			a_num[count] = b;
			ifs >> b;
			a_sentuser[count] = b;
			ifs >> b;
			a_receiveuser[count] = b;
			ifs >> b;
			a_kinds[count] = b;
			ifs >> b;
			a_address[count] = b;
			ifs >> b;
			a_time[count] = b;
			ifs >> b;
			a_stage[count] = b;
			ifs >> b;
			a_level[count] = b;
			ifs >> b;
			dp[count] = b;
			ifs >> a_price[count];

			count++;
		}
		ifs.close();
	}
	void prin(int k) {//��ӡ������������
		cout << "������Ϊ" << a_num[k] << endl;
		cout << "�ļ���Ϊ" << a_sentuser[k] << endl;
		cout << "�ռ���Ϊ" << a_receiveuser[k] << endl;
		cout << "�ռ��˵�ַΪ" << a_address[k] << endl;
		cout << "��Ʒ����Ϊ" << a_kinds[k] << endl;
		cout << "ǩ��ʱ��Ϊ" << a_stage[k] << endl;
		cout << "���ԱΪ" << dp[k] << endl;
	}

	void recevive(string name) {//��ӡû��ǩ�յĶ���
		cout << "δǩ�յĶ�����:" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			if (name == a_receiveuser[count1] && a_stage[count1]=="δ����") {
				prin(count1);
			}
		}
	start2:
		cout << "��������ǩ�յĿ�ݵ���" << endl;
		string num1;
		cin >> num1;
		if (yanzheng(num1) == 0) {
			cout << "��ݺŲ����ڻ��ѽ���,����" << endl;
			goto start2;
		}
		qianshou(num1);

	}
	int yanzheng(string num) {//�ж϶����Ƿ���ڻ��Ƿ�ǩ��
		for (int count1 = 0; count1 < count; count1++) {
			if (num == a_num[count1]) {
				return 1;
			}
		}
		return 0;
	}
	void qianshou(string num) {//�Զ�������ǩ��.
		for (int count1 = 0; count1 < count; count1++) {
			if (num == a_num[count1]) {
				ostringstream oss;
				mytime receivetime;
				oss << receivetime.Year << "��" << receivetime.Month << "��" << receivetime.Day << "��" << receivetime.Hour << "ʱ" << receivetime.Minute << "��" << receivetime.Second << "��" << endl;
				string time1 = oss.str();
				a_stage[count1] = time1;
			}
		}


	}
	void devsearch(string name) {//��ĳһ�����Ա��ȫ����ݽ��в�ѯ
		for (int count1 = 0; count1 < count; count1++) {
			if (name== dp[count1]) {
				prin(count1);
			}
		}
		cout << "��ѯ���" << endl;
	}
	void re() {
		ofstream ofs;
		ofs.open("object.txt", ios::out);
		for (int count1 = 0; count1 < count; count1++) {
			ofs << a_num[count1] << endl;
			ofs << a_sentuser[count1] << endl;
			ofs << a_receiveuser[count1] << endl;
			ofs << a_kinds[count1] << endl;
			ofs << a_address[count1] << endl;
			ofs << a_time[count1] << endl;
			ofs << a_stage[count1] << endl;
			ofs << a_level[count1] << endl;
			ofs << dp[count1] << endl;
			ofs << a_price[count1] << endl;
		}
		ofs.close();
		ifstream ifs;
		ifs.open("object.txt", ios::in);
		string b;
		count = 0;
		while (ifs >> b) {
			a_num[count] = b;
			ifs >> b;
			a_sentuser[count] = b;
			ifs >> b;
			a_receiveuser[count] = b;
			ifs >> b;
			a_kinds[count] = b;
			ifs >> b;
			a_address[count] = b;
			ifs >> b;
			a_time[count] = b;
			ifs >> b;
			a_stage[count] = b;
			ifs >> b;
			a_level[count] = b;
			ifs >> b;
			dp[count] = b;
			ifs >> a_price[count];

			count++;
		}
		ifs.close();
	}
	int lanshou(string name,string num1) {//���տ�ݲ�����ݷѷ��ظ�ԭ����
		for (int count1 = 0; count1 < count; count1++) {
			if ("δ����" == a_stage[count1] && a_num[count1] == num1) {
				dp[count1] = name;
				re();
				cout << "�������" << endl;
				return a_price[count1] / 2;
			}
		}
	}
	int unlanshousaerch(string name) {//�ȶ�δ�����ҹ��ڿ��Ա���µĿ�ݽ��в�ѯ,�ڶԿ������,ͬʱ��״̬��Ϊδ����
		int money;
		cout << "δ���յĿ����" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			if ("δ����" == a_stage[count1] && dp[count1]==name) {
				cout << a_num[count1]<<endl;
			}
		}
		cout << "�����������յĿ�ݵ���" << endl;
		string num1;
		cin >> num1;
		for (int count1 = 0; count1 < count; count1++) {
			if (num1 == a_num[count1] ) {
				a_stage[count1] = "δ����";
				money = a_price[count1]- a_price[count1]/2;
			}
		}
		re();
		cout << "���ճɹ�" << endl;
		return money;
		
	}

};
class object {
public:
	string level ;
	int count = 0;
	int weight;
	int price;
	
	object() {
	
	}
	virtual int getprice() = 0;//����۸�
	virtual string getlevel() = 0;//������Ʒ����ȷ���˷�Ҫ���Ե�ϵ��
	void sent(string name) {//nameΪ�ĳ��˵�����,�ȶ���Ʒ���ͽ����ж�,ͨ����ͬ�������е�getprice�������˷�,ͨ�� generCharArray()����10λ������,����ÿ��������Ϣ,��ɼĳ�.
		string receiveuser;
		string kinds;
		string num;
		string address;
		string stage = "δ����";
		
		cout << "����Լĳ���Ʒ����" << endl;
		cin >> kinds;
		cout << "������ռ�������" << endl;
		cin >> receiveuser;
		cout << "������ռ��˵�ַ" << endl;
		cin >> address;
		cout << "������Ʒ����" << endl;
		cin >> weight;
		price = getprice();
		level = getlevel();
		while (1) {
			ifstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			while (ifs >> b) {
				num = generCharArray();
				if (num.compare(b) == 0) {
					continue;
				}
				else {
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
				}
			}break;

		}
		ofstream ofs;
		ofs.open("object.txt", ios::app);
		ofs << num << endl;
		ofs << name << endl;
		ofs << receiveuser << endl;
		ofs << kinds << endl;
		ofs << address << endl;
		mytime senttime;
		ofs << senttime.Year << "��";
		ofs << senttime.Month << "��";
		ofs << senttime.Day << "��";
		ofs << senttime.Hour << "ʱ";
		ofs << senttime.Minute << "��";
		ofs << senttime.Second << "��" << endl;
		ofs << stage << endl;
		ofs << level << endl;
		ofs << "0" << endl;
		ofs << price << endl;
		cout << "�ĳ��ɹ�" << endl;


	}

	string generCharArray() {//����10λ������
		int flag, i;
		char ch[11] = { NULL };//ע��Ҫ�����һ���ֽ��������ַ������Ľ�����
		srand((unsigned)time(NULL));

		for (i = 0; i < 10; i++)
		{
			flag = rand() % 2;
			if (flag) ch[i] = '1' + rand() % 9;
			else ch[i] = '1' + rand() % 9;
		}
		ch[i] = '\0';
		return ch;
	}

};
class breakable:public object {//����Ʒ����
	int getprice() {
		return 8 * weight;
	}
	string getlevel() {
		return "����Ʒ";

	}
};
class book :public object {//ͼ������
	int getprice() {
		return 2 * weight;
	}
	string getlevel() {
		return "ͼ��";

	}
};
class nomal :public object {//��ͨ��Ʒ����
	int getprice() {
		return 5 * weight;
	}
	string getlevel () {
		return "��ͨ��Ʒ";
		
	}
};
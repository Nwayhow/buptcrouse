#include<conio.h>
#include <time.h>  
#include <stdlib.h>
#include <string.h>  
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
#include<Windows.h>
#include <time.h>  
using namespace std;
#include<fstream>
#include <iomanip>
class mytime {//,ͨ������tm�ṹ����ʵ�ֶԵ�ǰʱ��Ķ�ȡ
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
		localtime_s(&t,&now);
		Year = 1900 + t.tm_year;
		Month = 1 +t.tm_mon;
		Day = t.tm_mday;
		Hour = t.tm_hour;
		Minute = t.tm_min;
		Second = t.tm_sec;

	}

};
class object {
public:
	

	string sentuser;//���ͷ�
	string receiveuser;//���շ�
	string kinds;//����
	string num;//������
	string address;//��ַ
	string stage = "δ����";//״̬
	void sent(string name) {//�ĳ���Ʒ
		cout << "����Լĳ���Ʒ����" << endl;
		cin >> kinds;
		cout << "������ռ�������" << endl;
		cin >> receiveuser;
		cout << "������ռ��˵�ַ" << endl;
		cin >> address;
		sentuser = name;
		while (1) {
			ifstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			while (ifs >> b) {
				num = generCharArray();//����10λ�����
				if (num.compare(b) == 0) {//ȷ��û�������ظ�����
					continue;
				}
				else {
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
		ofs << num<<endl;
		ofs << sentuser<<endl;
		ofs << receiveuser<<endl;
		ofs << kinds<<endl;
		ofs << address<<endl;
		mytime senttime;
		ofs << senttime.Year<<"��";
		ofs << senttime.Month<<"��";
		ofs << senttime.Day<<"��";
		ofs << senttime.Hour<<"ʱ";
		ofs << senttime.Minute<<"��";
		ofs << senttime.Second << "��" << endl;
		ofs << stage<<endl;//ƴ��ʱ��

	}
	void recevive(string name) {//���տ��
		receiveuser = name;
			ifstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			string tem_num;
			string tem_sen;
			cout << "δǩ�յĶ�����:" << endl;//��չʾһ��û��ǩ�յĶ���
			while (ifs >> b) {
				string k = b;
				ifs >> b;
				ifs >> b;
				if (name.compare(b) == 0) {
					
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					if (b == "δ����") {
						cout << k << endl;
					}
				}
				else {
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
				}

			}
			start2:
			cout << "��������ǩ�յĿ�ݵ���" << endl;
			string num1;
			cin >> num1;
			if (yanzheng(num1) == 0) {//��֤�����Ƿ���ڻ��Ƿ�����
				cout << "��ݺŲ����ڻ��ѽ���" << endl;
				return;
			}
			change(num1);//�޸Ķ���״̬

	}
	int yanzheng(string num) const{//��֤�����Ƿ���ڻ��Ƿ�����
		ifstream ifs;
		ifs.open("object.txt", ios::in);
		string b;
		string tem_num;
		string tem_sen;
		while (ifs >> b) {
			if (num.compare(b) == 0) {
				ifs >> b;
				ifs >> b;
				ifs >> b;
				ifs >> b;
				ifs >> b;
				ifs >> b;
				if (b == "δ����") return 1;
				else return 0;
			}
			else {
				ifs >> b;
				ifs >> b;
				ifs >> b;
				ifs >> b;
				ifs >> b;
				ifs >> b;
			}

		}
		return 0;
	}
	void change(string num) const{//�޸�״̬
		ifstream ifs;
		string A;
		ifs.open("object.txt", ios::in);
		ofstream ofs;
		ofs.open("tem.txt", ios::out);//�Ȱ��޸Ĺ�������д����ʱ�ļ�
		while (ifs >> A) {
			if (A != num) {
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
			}
			else {
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				mytime receivetime;
				ofs << receivetime.Year<<"��";
				ofs << receivetime.Month<<"��";
				ofs << receivetime.Day<<"��";
				ofs << receivetime.Hour<<"ʱ";
				ofs << receivetime.Minute<<"��";
				ofs << receivetime.Second<<"��"<<endl;//¼��ʱ��

			}
		}
		ifs.close();
		ofs.close();
		ifs.open("tem.txt", ios::in);
		ofs.open("object.txt", ios::out);
		while (ifs >> A) {//�ٴ���ʱ�ļ�д����
			ofs << A << endl;


		}
		ifs.close();
		ofs.close();


	}
	
	string generCharArray()const {
		int flag, i;
		char ch[11] = { NULL };//ע��Ҫ�����һ���ֽ��������ַ������Ľ�����
		srand((unsigned)time(NULL));//�����������

		for (i = 0; i < 10; i++)
		{
			flag = rand() % 2;
			if (flag) ch[i] = '1' + rand() % 9;//������0��9
			else ch[i] = '1' + rand() % 9;
		}
		ch[i] = '\0';

		
		return ch;
	}

};

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
class mytime {//,通过调用tm结构体来实现对当前时间的读取
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
	

	string sentuser;//发送方
	string receiveuser;//接收方
	string kinds;//描述
	string num;//订单号
	string address;//地址
	string stage = "未接收";//状态
	void sent(string name) {//寄出物品
		cout << "输入对寄出物品描述" << endl;
		cin >> kinds;
		cout << "输入对收件人姓名" << endl;
		cin >> receiveuser;
		cout << "输入对收件人地址" << endl;
		cin >> address;
		sentuser = name;
		while (1) {
			ifstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			while (ifs >> b) {
				num = generCharArray();//生成10位随机数
				if (num.compare(b) == 0) {//确定没有生成重复订单
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
		ofs << senttime.Year<<"年";
		ofs << senttime.Month<<"月";
		ofs << senttime.Day<<"日";
		ofs << senttime.Hour<<"时";
		ofs << senttime.Minute<<"分";
		ofs << senttime.Second << "秒" << endl;
		ofs << stage<<endl;//拼接时间

	}
	void recevive(string name) {//接收快递
		receiveuser = name;
			ifstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			string tem_num;
			string tem_sen;
			cout << "未签收的订单有:" << endl;//先展示一遍没有签收的订单
			while (ifs >> b) {
				string k = b;
				ifs >> b;
				ifs >> b;
				if (name.compare(b) == 0) {
					
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					if (b == "未接收") {
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
			cout << "输入你想签收的快递单号" << endl;
			string num1;
			cin >> num1;
			if (yanzheng(num1) == 0) {//验证订单是否存在或是否被验收
				cout << "快递号不存在或已接收" << endl;
				return;
			}
			change(num1);//修改订单状态

	}
	int yanzheng(string num) const{//验证订单是否存在或是否被验收
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
				if (b == "未接收") return 1;
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
	void change(string num) const{//修改状态
		ifstream ifs;
		string A;
		ifs.open("object.txt", ios::in);
		ofstream ofs;
		ofs.open("tem.txt", ios::out);//先把修改过的内容写入临时文件
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
				ofs << receivetime.Year<<"年";
				ofs << receivetime.Month<<"月";
				ofs << receivetime.Day<<"日";
				ofs << receivetime.Hour<<"时";
				ofs << receivetime.Minute<<"分";
				ofs << receivetime.Second<<"秒"<<endl;//录入时间

			}
		}
		ifs.close();
		ofs.close();
		ifs.open("tem.txt", ios::in);
		ofs.open("object.txt", ios::out);
		while (ifs >> A) {//再从临时文件写回来
			ofs << A << endl;


		}
		ifs.close();
		ofs.close();


	}
	
	string generCharArray()const {
		int flag, i;
		char ch[11] = { NULL };//注意要多分配一个字节来保存字符串最后的结束符
		srand((unsigned)time(NULL));//随机种子生成

		for (i = 0; i < 10; i++)
		{
			flag = rand() % 2;
			if (flag) ch[i] = '1' + rand() % 9;//控制在0到9
			else ch[i] = '1' + rand() % 9;
		}
		ch[i] = '\0';

		
		return ch;
	}

};

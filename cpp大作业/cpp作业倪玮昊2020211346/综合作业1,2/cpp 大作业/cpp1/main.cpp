#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include"user.h"
#include"manager.h"
#include"object.h"
int main() {
	cout << "选择你的身份输入1选择普通用户 2.选择管理员" << endl;
	string index;
	cin >> index;
	while (1) {
		if (index == "1") {
			account A; //login createnew
			cout << "输入1发送快递 2接收快递 3查询快递 4充值 5查询余额 输入6退出" << endl;
			string index;
			
			while (1) {
				cin >> index;
				object C;
				if (index == "1") {
					C.sent(A.name);//发送快递
					A.decmoney();//扣费
					A.re();//刷新账户
					control B;//管理员声明
					B.add();//管理员加钱
					B.re();//刷新管理员
				}
				else if (index == "2") {
					C.recevive(A.name);//接收快递
					
				}
				else if (index == "3") {
					A.findobject();//发现物品
				}
				else if (index == "4") {
					A.addmenoy();//充值
					A.re();
				}
				else if (index == "5") {
					A.seachmoney();//搜索余额
				}
				else if (index == "2") {
					break;
				}
				else  {
					cout << "无效输入重新输入" << endl;
				}
			}

		}
		else if (index == "2") {
			control B;
			B.login();
		
			cout << "输入1查询快递 输入2退出" << endl;
			string index;
		
			while (1) {
				cin >> index;
				if (index == "1" ) {
					B.manangeobjects();//搜索快递
				}
				else if (index == "2") {
					break;
				}
				else {
					cout << "无效输入重新输入" << endl;
				}
			}
		}
		else {
			cout << "无效输入重新输入" << endl;
		}
	}


}

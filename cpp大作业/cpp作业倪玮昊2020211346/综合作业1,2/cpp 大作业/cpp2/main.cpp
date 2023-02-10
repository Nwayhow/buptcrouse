#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include"user.h"
#include"manager.h"
#include"dev.h"
#include"object.h"
int main() {
	cout << "选择你的身份输入1选择普通用户 2.选择管理员 3选择快递员" << endl;
	string index;
	cin >> index;
	while (1) {
		findobject O;//声明找快递
		dev D;//声明快递员
		if (index == "1") {
			account A; //login createnew
			cout << "输入1发送快递 2接收快递 3查询快递 4充值 5查询余额 输入6退出" << endl;
			string index;
			while (1) {

				cin >> index;
				if (index == "1") {
					cout << "输入你发送的快递类型 1.易碎品 2.图书 3.普通物品" << endl;
					string index;
					while (1) {
						cin >> index;
						if (index == "1") {

							breakable C;
							C.sent(A.name);//发送快递
							A.decmoney(C.price);//扣费
							A.re();//刷新账号
							control B;
							B.add(C.price);//给管理员加钱
							B.re();//刷新管理员数据
						}
						else if (index == "2") {
							book C;
							C.sent(A.name);
							A.decmoney(C.price);
							A.re();
							control B;
							B.add(C.price);
							B.re();
				
						}
						else if (index == "3") {
							nomal C;
							C.sent(A.name);
							A.decmoney(C.price);
							A.re();
							control B;
							B.add(C.price);
							B.re();
					
						}
						else {
							cout << "无效输入" << endl;
							break;
						}

					}

				}
				else if (index == "2") {
					O.recevive(A.name);//接收快递递
					O.re();
					cout << "签收成功" << endl;
				}
				else if (index == "3") {
					A.findobject();//查找快递
					cout << "查询结束" << endl;
				}
				else if (index == "4") {
					A.addmenoy();//充值
					A.re();
				}
				else if (index == "5") {
					A.seachmoney();//查余额
				}
				else if (index == "6") {
					break;
				}
				else {
					cout << "无效输入重新输入" << endl;
				}
			}

		}
		else if (index == "2") {
			control B;
			B.login();
			cout << "输入1查询快递 输入2查看所有快递员 输入3为快递指派快递员 输入4添加或删除快递员 输入5退出" << endl;
			string index;
			while (1) {
				cin >> index;
				if (index == "1") {
					B.manangeobjects();//查询快递
					cout << "查询完成" << endl;
				}
				else if (index == "2") {
					D.search();//查询快递员
					string name;
					cout << "输入你想查询的快递员" << endl;
					cin >> name;
					O.devsearch(name);//查询快递员具体信息
				}
				else if (index == "3") {
					cout << "未分配快递员的快递有" << endl;
					O.devsearch("0");//查询快递员具体信息
					string num;
					cout << "输入你想处理的订单号" << endl;
					cin >> num;
					D.search();//搜索快递
					string name;
					cout << "输入你想分配的快递员" << endl;
					cin >> name;
					while (D.findev(name) != 1) {//观察是否存在该快递员
						cout << "不存在该快递员,重新输入" << endl;
						cin >> name;
					}
					int m = O.lanshou(name, num);//揽收快递
					B.dec(m);
					B.re();
				}
				else if (index == "4") {
					cout << "输入1添加新用户,输入2删除就用户" << endl;
					string i;
					cin >> i;
					if (i == "1") {
						D.createnewaccount();
					}
					else {
						cout << "现存账号有" << endl;
						D.searchac();
						cout << "输入你想删除的账号" << endl;
						string name;
						cin >> name;
						D.findevac(name);
						

					}
				}
				else {
					cout << "无效输入重新输入" << endl;
				}
			}
		}
		else if (index == "3") {
		
		string name;
		 name = D.login();

		cout << "输入1查询快递 输入2揽收快递" << endl;
		string index;
		cin >> index;
		if (index == "1") {
			D.find(name);
		}
		if (index == "2") {
			int money = O.unlanshousaerch(name);//揽收快递,同时返回金额
			D.addmoney(D.account[D.now], money);//转账进入自己账号
			D.re();
		}
}
		else {
		cout << "无效输入重新输入" << endl;
		}
	}

}
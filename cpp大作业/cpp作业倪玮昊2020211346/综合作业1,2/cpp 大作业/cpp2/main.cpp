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
	cout << "ѡ������������1ѡ����ͨ�û� 2.ѡ�����Ա 3ѡ����Ա" << endl;
	string index;
	cin >> index;
	while (1) {
		findobject O;//�����ҿ��
		dev D;//�������Ա
		if (index == "1") {
			account A; //login createnew
			cout << "����1���Ϳ�� 2���տ�� 3��ѯ��� 4��ֵ 5��ѯ��� ����6�˳�" << endl;
			string index;
			while (1) {

				cin >> index;
				if (index == "1") {
					cout << "�����㷢�͵Ŀ������ 1.����Ʒ 2.ͼ�� 3.��ͨ��Ʒ" << endl;
					string index;
					while (1) {
						cin >> index;
						if (index == "1") {

							breakable C;
							C.sent(A.name);//���Ϳ��
							A.decmoney(C.price);//�۷�
							A.re();//ˢ���˺�
							control B;
							B.add(C.price);//������Ա��Ǯ
							B.re();//ˢ�¹���Ա����
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
							cout << "��Ч����" << endl;
							break;
						}

					}

				}
				else if (index == "2") {
					O.recevive(A.name);//���տ�ݵ�
					O.re();
					cout << "ǩ�ճɹ�" << endl;
				}
				else if (index == "3") {
					A.findobject();//���ҿ��
					cout << "��ѯ����" << endl;
				}
				else if (index == "4") {
					A.addmenoy();//��ֵ
					A.re();
				}
				else if (index == "5") {
					A.seachmoney();//�����
				}
				else if (index == "6") {
					break;
				}
				else {
					cout << "��Ч������������" << endl;
				}
			}

		}
		else if (index == "2") {
			control B;
			B.login();
			cout << "����1��ѯ��� ����2�鿴���п��Ա ����3Ϊ���ָ�ɿ��Ա ����4��ӻ�ɾ�����Ա ����5�˳�" << endl;
			string index;
			while (1) {
				cin >> index;
				if (index == "1") {
					B.manangeobjects();//��ѯ���
					cout << "��ѯ���" << endl;
				}
				else if (index == "2") {
					D.search();//��ѯ���Ա
					string name;
					cout << "���������ѯ�Ŀ��Ա" << endl;
					cin >> name;
					O.devsearch(name);//��ѯ���Ա������Ϣ
				}
				else if (index == "3") {
					cout << "δ������Ա�Ŀ����" << endl;
					O.devsearch("0");//��ѯ���Ա������Ϣ
					string num;
					cout << "�������봦��Ķ�����" << endl;
					cin >> num;
					D.search();//�������
					string name;
					cout << "�����������Ŀ��Ա" << endl;
					cin >> name;
					while (D.findev(name) != 1) {//�۲��Ƿ���ڸÿ��Ա
						cout << "�����ڸÿ��Ա,��������" << endl;
						cin >> name;
					}
					int m = O.lanshou(name, num);//���տ��
					B.dec(m);
					B.re();
				}
				else if (index == "4") {
					cout << "����1������û�,����2ɾ�����û�" << endl;
					string i;
					cin >> i;
					if (i == "1") {
						D.createnewaccount();
					}
					else {
						cout << "�ִ��˺���" << endl;
						D.searchac();
						cout << "��������ɾ�����˺�" << endl;
						string name;
						cin >> name;
						D.findevac(name);
						

					}
				}
				else {
					cout << "��Ч������������" << endl;
				}
			}
		}
		else if (index == "3") {
		
		string name;
		 name = D.login();

		cout << "����1��ѯ��� ����2���տ��" << endl;
		string index;
		cin >> index;
		if (index == "1") {
			D.find(name);
		}
		if (index == "2") {
			int money = O.unlanshousaerch(name);//���տ��,ͬʱ���ؽ��
			D.addmoney(D.account[D.now], money);//ת�˽����Լ��˺�
			D.re();
		}
}
		else {
		cout << "��Ч������������" << endl;
		}
	}

}
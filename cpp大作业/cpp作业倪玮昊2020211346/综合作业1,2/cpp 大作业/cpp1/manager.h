
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
class control {
private:
	string accountname;//����Ա�û���
	string name;//����
	int money;//���
	string password;//����
public:
	control() {//��ʼ��
		ifstream ifs;
		ifs.open("control.txt", ios::out);
		string b;
		while (ifs >> b) {
			accountname = b;
			ifs >> b;
			password = b;
			ifs >> b;
			name = b;
			ifs >> money;
		}
		ifs.close();
	}
	void login() {//��¼
		
		
		start:
		cout << "����1��½ ����2�޸����� ����3�˳�" << endl;
		string index;
		
		while (1) {
			cin >> index;
			if (index == "1") {
				string zhanghao;
				string mima;
				cout << "�˺�";
				cin >> zhanghao;
				cout << "����";
				cin >> mima;
				if (mima == password && zhanghao == accountname) {
					cout << "��½�ɹ�" << endl;
					break;
				}
				else {
					cout << "�û��������������,����"; goto start;
				}

			}
			else if (index == "2") {
				change();
			}
			else if (index == "3") {
				break;
			}
			else  {
				cout << "��Ч������������" << endl;
			}
		}
		
	}
	void re() {//�Թ���Ա���ݽ����ٴζ�ȡ(���������޸����ı����ݺ��ٴζ�ȡ)
		ofstream ofs;
		ofs.open("control.txt", ios::out);
		string b;
		ofs << accountname<<endl;
		ofs << password << endl;
		ofs << name << endl;
		ofs << money << endl;
		ofs.close();
		ifstream ifs;
		ifs.open("control.txt", ios::out);
		while (ifs >> b) {
			accountname = b;
			ifs >> b;
			password = b;
			ifs >> b;
			name = b;
			ifs >> money;
		}
		ifs.close();
	}
	void change() {//�޸Ĺ���Ա����
		start:
		cout << "�����˺ź��������" << endl;
		string zhanghao;
		string mima;
		cout << "�˺�";
		cin >> zhanghao;
		cout << "����";
		cin >> mima;
		if (mima == password && zhanghao == accountname) {
			cout << "��֤�ɹ� ���������� " << endl;
			cout << "����";
			cin >> mima;
			password = mima;
			re();
		}
		else {
			cout << "�û��������������,����"; goto start;
		}
	}
	void manangeobjects() const{//��ѯ������,��������
	start:
		string j;
		cout << "����1ͨ���ռ���������ѯ�Ŀ�� ����2ͨ��ʱ���ѯ��� ����2ͨ���ļ��˲�ѯ��� ����4ͨ����ݵ��Ų�ѯ��� ����5�˳�" << endl;
		cin >> j;
		getchar();
		if (j == "1") {
			cout << "���������ѯ���ռ��� " << endl;
			string time;
			cin >> time;
			fstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			cout << "��ʷ���:" << endl;
			while (ifs >> b) {
				string c = b;
				ifs >> b;
				string d = b;
				ifs >> b;
				string e = b;

				if (e == time ){
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << d << endl;
					cout << "�ռ���:" << e << endl;
					ifs >> b;
					cout << "��Ʒ����:" << b << endl;
					ifs >> b;
					cout << "�ռ���ַ:" << b << endl;
					ifs >> b;
					cout << "����ʱ��:" << b << endl;
					ifs >> b;
					if (b == "δ����")cout << "����״̬:" << b << endl;
					else cout << "�ռ�ʱ��:" << b << endl;
				}

				else {
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
				}
			}
			ifs.close();
		}
		else if (j == "2") {
			cout << "���������ѯ�ķ���ʱ��" << endl;
			char k1[100];
			gets_s(k1);
			int k = strlen(k1);
			string time = k1;
			fstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			cout << "��ʷ���:" << endl;
			while (ifs >> b) {
				string c = b;
				ifs >> b;
				string d = b;
				ifs >> b;
				string e = b;
				ifs >> b;
				string f = b;
				ifs >> b;
				string g = b;
				ifs >> b;
				if (b.compare(0, k, time, 0, k) == 0 ) {
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << d << endl;

					cout << "�ռ���:" << e << endl;

					cout << "��Ʒ����:" << f << endl;

					cout << "�ռ���ַ:" << g << endl;

					cout << "����ʱ��:" << b << endl;
					ifs >> b;
					if (b == "δ����")cout << "����״̬:" << b << endl;
					else cout << "�ռ�ʱ��:" << b << endl;
				}

				else ifs >> b;

			}
			ifs.close();
		}
		else if (j == "3") {
			cout << "���������ѯ�ļļ�������" << endl;
			string name;
			cin >> name;
			fstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			cout << "��ʷ���:" << endl;
			while (ifs >> b) {
				string c = b;
				ifs >> b;
				string e = b;
				ifs >> b;
				if (e == name ) {
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << e << endl;
					cout << "�ռ���:" << b << endl;
					ifs >> b;
					cout << "��Ʒ����:" << b << endl;
					ifs >> b;
					cout << "�ռ���ַ:" << b << endl;
					ifs >> b;
					cout << "����ʱ��:" << b << endl;
					ifs >> b;
					if (b == "δ����")cout << "����״̬:" << b << endl;
					else cout << "�ռ�ʱ��:" << b << endl;
				}
				else {
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
				}


			}
			ifs.close();
		}
		else if (j == "4") {
			cout << "���������ѯ�Ŀ�ݵ���" << endl;
			string num;
			cin >> num;
			fstream ifs;
			ifs.open("object.txt", ios::in);
			string b;
			cout << "��ʷ���:" << endl;
			while (ifs >> b) {
				string c = b;
				ifs >> b;
				string e = b;
				ifs >> b;
				if (c == num ) {
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << e << endl;
					cout << "�ռ���:" << b << endl;
					ifs >> b;
					cout << "��Ʒ����:" << b << endl;
					ifs >> b;
					cout << "�ռ���ַ:" << b << endl;
					ifs >> b;
					cout << "����ʱ��:" << b << endl;
					ifs >> b;
					if (b == "δ����")cout << "����״̬:" << b << endl;
					else cout << "�ռ�ʱ��:" << b << endl;
				}
				else {
					ifs >> b;
					ifs >> b;
					ifs >> b;
					ifs >> b;
				}

			}
		}
		else if (j == "5") {
		return;
				}
		else { cout << "��Ч����" << endl; goto start; }

		
	}
	void add() {//��ӽ��
		money = money + 15;
	}
};
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
class dev {
public:
	string account[1000];
	string password[100];
	string name[1000];
	int rest[1000];
	string phone[1000];
	int now;
	int count = 0;
	dev(){//���ı��ĵ�����¼�뵽������.
		ifstream ifs;
		ifs.open("deviler.txt", ios::in);
		string b;
		count = 0;
		while (ifs >> b) {
			account[count] = b;
			ifs >> b;
			password[count] = b;
			ifs >> b;
			name[count] = b;
			ifs >> b;
			phone[count] = b;
			ifs >> rest[count];
			count++;
		}
		ifs.close();
	}
	string login() {//ͨ���򿪴���û����ݵ��ĵ�,�Ƚ��˺ź�����,�����֤�ɹ����˳�����,����������˻��������������.
	start2:
		cout << "�����������˺ź���������ɵ�½����." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == ac) {
				if (password[count1] == ac_password) {
					cout << "��½�ɹ�";
					now = count1;
					return name[count1];
				}
				else break;
			}

		}
		cout << "������˺Ŵ������ٴ����룻" << endl;  goto start2;
	}
	void createnewaccount() {//�Կ��Ա����ע��,���ж��Ƿ��˻��ظ�,�����ظ��������������Ϣ���ע�Ṧ��
	start2:
		cout << "�����������˺ź����������ע�����." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == ac) {
				cout << "�˺����ظ������ٴ����룻" << endl;  goto start2;
			}

		}
		ofstream ofs;
		ofs.open("deviler.txt", ios::app);
		ofs << ac << endl;
		cout << "�������������������ע�����." << endl;
		string newac_password;
		cin >> setw(20) >> newac_password;
		ofs << newac_password << endl;
		cout << "�������������������ע�����." << endl;
		string newac_name;
		cin >> setw(20) >> newac_name;
		ofs << newac_name << endl;
		cout << "���������ĵ绰���������ע�����." << endl;
		string newac_phone;
		cin >> setw(20) >> newac_phone;
		ofs << newac_phone << endl;
		cout << "���������ĳ�ʼ��������ע�����." << endl;
		int newac_money;
		cin >> newac_money;
		ofs << newac_money << endl;
		ofs.close();
		ifstream ifs;
		ifs.open("deviler.txt", ios::in);
		string b;
		count = 0;
		while (ifs >> b) {
			account[count] = b;
			ifs >> b;
			password[count] = b;
			ifs >> b;
			name[count] = b;
			ifs >> b;
			phone[count] = b;
			ifs >> rest[count];
			count++;
		}
		ifs.close();
	}

	void re() {
		ofstream ofs;
		ofs.open("deviler.txt", ios::out);
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] != "0") {
			ofs << account[count1] << endl;
			ofs << password[count1] << endl;
			ofs << name[count1] << endl;
			ofs << phone[count1] << endl;
			ofs << rest[count1] << endl;
		}
		}
		ofs.close();
		ifstream ifs;
		ifs.open("deviler.txt", ios::in);
		string b;
		count = 0;
		while (ifs >> b) {
			account[count] = b;
			ifs >> b;
			password[count] = b;
			ifs >> b;
			name[count] = b;
			ifs >> b;
			phone[count] = b;
			ifs >> rest[count];
			count++;
		}
		ifs.close();
	}
	void search() const {//�����ɱ���ǲ�Ŀ��Ա
		cout << "����ǲ�Ŀ��Ա��" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			cout << name[count1] << endl;
		}
	}
	void findevac(string name1) {//������Ŀ��Ա����ɾ��
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == name1) {
				account[count1] = "0";
				re();
				cout << "ɾ���ɹ�" << endl;
				return;
			}
		}
		cout << "�����ڸÿ��Ա,��������" << endl;
	}
	void searchac() const {//�����ɱ���ǲ�Ŀ��Ա������
		cout << "����ǲ�Ŀ��Ա��" << endl;
		for (int count1 = 0; count1 < count; count1++) {
			cout << account[count1] << endl;
		}
	}
	void addmoney(string acc,int mon) {//���˻����г�ֵ
		for (int count1 = 0; count1 < count; count1++) {
			if (account[count1] == acc) {
				rest[count1] = rest[count1] + mon;
			}
		}
	}
	int findev(string name1) const {//ȷ���Ƿ���ڸÿ��Ա
		for (int count1 = 0; count1 < count; count1++) {
			if (name[count1] == name1) {
				return 1;
			}
		}
		return -1;
	}
	void find(string name) const {//��ѯ������,�Ҹÿ�ݱ�����ԱΪ����,����ؿ��
		cout << "����1���ݷ�����" << endl;
	start:
		string j;
		cout << "����1ͨ���ռ���������ѯ�Ŀ�� ����2ͨ��ʱ���ѯ��� ����2ͨ���ļ��˲�ѯ��� ����4ͨ����ݵ��Ų�ѯ���(ֻ�ܲ�ѯ���Լ��йصĿ�ݣ�����5���ݿ��״̬��ѯ" << endl;
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
				ifs >> b;
				string f = b;
				ifs >> b;
				string g = b;
				ifs >> b;
				string h = b;
				ifs >> b;
				string i = b;
				ifs >> b;
				string j = b;
				ifs >> b;
				if (e == time && (b == name)) {
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << d << endl;
					cout << "�ռ���:" << e << endl;
					cout << "��Ʒ����:" << f << endl;
					cout << "�ռ���ַ:" << g << endl;
					cout << "����ʱ��:" << h << endl;
					if (i == "δ����" || i == "δ����")cout << "����״̬:" << i << endl;
					else cout << "�ռ�ʱ��:" << i << endl;
					cout << "��Ʒ����:" << j << endl;
					cout << "���ԱΪ:" << b << endl;
					ifs >> b;
					cout << "�˷�Ϊ:" << b << endl;
				}

				else {
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
				string h = b;
				ifs >> b;
				string i = b;
				ifs >> b;
				string j = b;
				ifs >> b;
				if (b.compare(0, k, time, 0, k) == 0 && (b == name )) {
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << d << endl;

					cout << "�ռ���:" << e << endl;

					cout << "��Ʒ����:" << f << endl;

					cout << "�ռ���ַ:" << g << endl;

					cout << "����ʱ��:" << h<< endl;
					if (i == "δ����" || i == "δ����")cout << "����״̬:" << i << endl;
					else cout << "�ռ�ʱ��:" << i << endl;
					cout << "��Ʒ����:" << j << endl;
					cout << "���ԱΪ:" << b << endl;
					ifs >> b;
					cout << "�˷�Ϊ:" << b << endl;
				}

				else {
					ifs >> b;
				
				}
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
				string d = b;
				ifs >> b;
				string e = b;
				ifs >> b;
				string f = b;
				ifs >> b;
				string g = b;
				ifs >> b;
				string h = b;
				ifs >> b;
				string i = b;
				ifs >> b;
				string j = b;
				ifs >> b;
				if (e == name && (b == name )) {
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << d << endl;

					cout << "�ռ���:" << e << endl;

					cout << "��Ʒ����:" << f << endl;

					cout << "�ռ���ַ:" << g << endl;

					cout << "����ʱ��:" << h << endl;
					if (i == "δ����" || i == "δ����")cout << "����״̬:" << i << endl;
					else cout << "�ռ�ʱ��:" << i << endl;
					cout << "��Ʒ����:" << j << endl;
					cout << "���ԱΪ:" << b << endl;
					ifs >> b;
					cout << "�˷�Ϊ:" << b << endl;
				}
				else {
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
				string d = b;
				ifs >> b;
				string e = b;
				ifs >> b;
				string f = b;
				ifs >> b;
				string g = b;
				ifs >> b;
				string h = b;
				ifs >> b;
				string i = b;
				ifs >> b;
				string j = b;
				ifs >> b;
				if (c == num && (b == name )) {
					cout << "��ݵ���:" << c << endl;
					cout << "�ļ���:" << d << endl;

					cout << "�ռ���:" << e << endl;

					cout << "��Ʒ����:" << f << endl;

					cout << "�ռ���ַ:" << g << endl;

					cout << "����ʱ��:" << h << endl;
					if (i == "δ����" || i == "δ����")cout << "����״̬:" << i << endl;
					else cout << "�ռ�ʱ��:" << i << endl;
					cout << "��Ʒ����:" << j << endl;
					cout << "���ԱΪ:" << b << endl;
					ifs >> b;
					cout << "�˷�Ϊ:" << b << endl;
				}
				else {
					ifs >> b;
			
				}
			}
		}
		else if (j == "5") {
		cout << "���������ѯ��״̬(δ����orδ����or��ǩ��)" << endl;
		string time;
		cin >> time;
		fstream ifs;
		ifs.open("object.txt", ios::in);
		string b;
		cout << "��ʷ���:" << endl;
		if (time == "��ǩ��") {
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
			string h = b;
			ifs >> b;
			string i = b;
			ifs >> b;
			string j = b;
			ifs >> b;
			if (i != "δ����" && i!="δ����" && (b == name)) {
				cout << "��ݵ���:" << c << endl;
				cout << "�ļ���:" << d << endl;
				cout << "�ռ���:" << e << endl;
				cout << "��Ʒ����:" << f << endl;
				cout << "�ռ���ַ:" << g << endl;
				cout << "����ʱ��:" << h << endl;
				if (i == "δ����" || i == "δ����")cout << "����״̬:" << i << endl;
				else cout << "�ռ�ʱ��:" << i << endl;
				cout << "��Ʒ����:" << j << endl;
				cout << "���ԱΪ:" << b << endl;
				ifs >> b;
				cout << "�˷�Ϊ:" << b << endl;
			}

			else {
				ifs >> b;
			}
		}
	
		else while (ifs >> b) {
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
			string h = b;
			ifs >> b;
			string i = b;
			ifs >> b;
			string j = b;
			ifs >> b;
			if (i == time && (b == name)) {
				cout << "��ݵ���:" << c << endl;
				cout << "�ļ���:" << d << endl;
				cout << "�ռ���:" << e << endl;
				cout << "��Ʒ����:" << f << endl;
				cout << "�ռ���ַ:" << g << endl;
				cout << "����ʱ��:" << h << endl;
				if (i == "δ����" || i == "δ����")cout << "����״̬:" << i << endl;
				else cout << "�ռ�ʱ��:" << i << endl;
				cout << "��Ʒ����:" << j << endl;
				cout << "���ԱΪ:" << b << endl;
				ifs >> b;
				cout << "�˷�Ϊ:" << b << endl;
			}

			else {
				ifs >> b;
			}
		}
		ifs.close();
		}
	}
};
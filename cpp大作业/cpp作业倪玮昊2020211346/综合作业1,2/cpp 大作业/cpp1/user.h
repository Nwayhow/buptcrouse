
#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include <string>
class account {
public:
	string accountname;//�û���
	string password;//����
	string name;//����
	string phonenum;//�绰��
	string money;//���
	string location;//λ��

	account() {
	start:
		cout << "ѡ��������" << endl;
		cout << "1.���û�  2.���û� 3.�޸�����" << endl;
		string identity;
		cin >> identity;
		if (identity == "1") {
			login();//��¼
		}
		else if (identity == "2") {
			createnewacount();//�������û�
			login();
		}
		else if (identity == "3") {
			check();//�޸�����
			login();//�޸����������ŵ�¼
		}
		else { cout << "���Ϸ����룬������"; goto start; }

	}

	int login() {//��¼
	start2:
		cout << "�����������˺ź���������ɵ�½����." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;//��������
		ifstream ifs;
		ifs.open("account.txt", ios::in);
		string b;
		while (ifs >> b) {//�򿪴���û����ݵ��ĵ�,�Ƚ��˺ź�����
			if (ac.compare(b) == 0) {
				accountname = b;
				ifs >> b;
				if (ac_password.compare(b) == 0) { 
					cout << "��¼�ɹ�" << endl; 
					password = b;
					ifs >> b;
					name= b;
					ifs >> b;
					phonenum = b;
					ifs >> b;
					money = b;
					ifs >> b;
					location = b;
					ifs.close();
					return 0; }
				else { cout << "����������ٴ����룻" << endl; ifs.close(); goto start2; }
			}
			ifs >> b;
			ifs >> b;
			ifs >> b;
			ifs >> b;

		}
		ifs.close();
		cout << "����������ٴ����룻" << endl; ifs.close(); goto start2;


	}
	void re() {//���û����ݽ����ٴζ�ȡ(���������޸����ı����ݺ��ٴζ�ȡ)
		ifstream ifs;
		ifs.open("account.txt", ios::in);
		string b;
		while (ifs >> b) {
			if (accountname.compare(b) == 0) {
				ifs >> b;
					password = b;
					ifs >> b;
					name = b;
					ifs >> b;
					phonenum = b;
					ifs >> b;
					money = b;
					ifs >> b;
					location = b;
					ifs.close();
				}
			}

		}


	void createnewacount() {
	start1:
		cout << "�����������û��������ע�����." << endl;
		string newac;
		cin >> setw(20) >> newac;
		ifstream ifs;
		ifs.open("account.txt", ios::in);
		string b;
		while (ifs >> b) {//�ж��Ƿ��˻��ظ�
			if (newac.compare(b) == 0) {
				cout << "���û��Ѵ���" << endl; ifs.close();
				goto start1;
			}
			ifs >> b;
			ifs >> b;
			ifs >> b;
			ifs >> b;
			ifs >> b;
		}
		ifs.close();
		ofstream ofs;
		ofs.open("account.txt", ios::app);
		ofs << newac << endl;
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
		cin >>  newac_money;
		ofs << newac_money << endl;
		cout << "���������ĵ�ַ�����ע�����." << endl;
		string newac_location;
		cin >> setw(20) >> newac_location;
		ofs << newac_location << endl;
		ofs.close();
	}
	int check() {//�޸��˻�������Ϣ
	start2:
		cout << "�����������˺ź������������֤����." << endl;
		string ac;
		cin >> setw(20) >> ac;
		string ac_password;
		cin >> setw(20) >> ac_password;
		ifstream ifs;
		ifs.open("account.txt", ios::in);
		string b;
		while (ifs >> b) {//�����˻����������ȷ��
			if (ac.compare(b) == 0) {
				accountname = b;
				ifs >> b;
				if (ac_password.compare(b) == 0) {
					cout << "��֤�ɹ�" << endl; ifs.close();
					int change;
					cout << "��1�������� 2�������� 3���ĵ绰 4��ַ"<<endl;
					cin >> change;
					if (change != 1 && change != 2 && change != 3 && change != 4) {
						cout << "�Ƿ�����,������" << endl;
					}
					changes(change);//�޸�
					return 0;
				}
				else{ cout << "�����д������ٴ����룻" << endl; ifs.close(); goto start2; }
			}
			ifs >> b;
			ifs >> b;
			ifs >> b;
			ifs >> b;

		}
		ifs.close();
		cout << "����������ٴ����룻" << endl; ifs.close(); goto start2;
	}
		void changes(int work) {//�޸�����
			string deal;
			string newdeal;
			if (work == 1) {
				cout << "����������ĵ�����" << endl;
				deal = password;
				cin >> newdeal;
				password = newdeal;
				ifstream ifs;
				string A;
				ifs.open("account.txt", ios::in);
				ofstream ofs;
				ofs.open("tem.txt", ios::out);
				while (ifs >> A) {
					string B = A;
					ofs << A << endl;
					ifs >> A;
					if (B != accountname) {
						ofs << A << endl;
					}
					else { ofs << newdeal << endl; }
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
				}
				ifs.close();
				ofs.close();
				ifs.open("tem.txt", ios::in);
				ofs.open("account.txt", ios::out);
				while (ifs >> A) {
					ofs << A << endl;

				}
				ifs.close();
				ofs.close();
				cout << "�޸����" << endl;
			}
			if(work==2) {
				cout << "����������ĵ�����" << endl;
				deal = name;
				cin >> newdeal;
				name = newdeal;
				ifstream ifs;
				string A;
				ifs.open("account.txt", ios::in);
				ofstream ofs;
				ofs.open("tem.txt", ios::out);
				while (ifs >> A) {
					string B = A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					if (B != accountname) {
						ofs << A << endl;
					}
					else { ofs << newdeal << endl; }
					
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
				}
				ifs.close();
				ofs.close();
				ifs.open("tem.txt", ios::in);
				ofs.open("account.txt", ios::out);
				while (ifs >> A) {
					ofs << A << endl;

				}
				ifs.close();
				ofs.close();
				cout << "�޸����" << endl;

			}
			if(work==3) {
				cout << "����������ĵĵ绰" << endl;
				deal = phonenum;
				cin >> newdeal;
				phonenum = newdeal;
				ifstream ifs;
				string A;
				ifs.open("account.txt", ios::in);
				ofstream ofs;
				ofs.open("tem.txt", ios::out);
				while (ifs >> A) {
					string B = A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					if (B != accountname) {
						ofs << A << endl;
					}
					else { ofs << newdeal << endl; }
					
					ifs >> A;
					ofs << A << endl;
					ifs >> A;
					ofs << A << endl;
				}
				ifs.close();
				ofs.close();
				ifs.open("tem.txt", ios::in);
				ofs.open("account.txt", ios::out);
				while (ifs >> A) {
					ofs << A << endl;

				}
				ifs.close();
				ofs.close();
				cout << "�޸����" << endl;


			}
			if(work==4) {
				cout << "����������ĵĵ�ַ" << endl;
				deal = location;
				cin >> newdeal;
				location = newdeal;
				ifstream ifs;
				string A;
				ifs.open("account.txt", ios::in);
				ofstream ofs;
				ofs.open("tem.txt", ios::out);
				while (ifs >> A) {
					string B = A;
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
					if (B != accountname) {
						ofs << A << endl;
					}
					else { ofs << newdeal << endl; }
					
					
				}
				ifs.close();
				ofs.close();
				ifs.open("tem.txt", ios::in);
				ofs.open("account.txt", ios::out);
				while (ifs >> A) {
					ofs << A << endl;

				}
				ifs.close();
				ofs.close();
				cout << "�޸����" << endl;

			}
			
		}
		void decmoney() {//���˻����п۷�,������ʱ���Զ��û��������Ѳ����г�ֵ
			int num = stoi(money);
			if (num < 15) {
				cout << "�������ֵ" << endl;
				addmenoy();
			}
			num = num - 15;
			string num1 = to_string(num);
			ifstream ifs;
			string A;
			ifs.open("account.txt", ios::in);
			ofstream ofs;
			ofs.open("tem.txt", ios::out);
			while (ifs >> A) {
				string B = A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				
				ifs >> A;
				if (B != accountname) {//ƥ�䵽��ǰ�˺�
					ofs << A << endl;
				}
				else { ofs << num1 << endl; }
				ifs >> A;
				ofs << A << endl;

			}
			ifs.close();
			ofs.close();
			ifs.open("tem.txt", ios::in);
			ofs.open("account.txt", ios::out);
			while (ifs >> A) {
				ofs << A << endl;

			}
			ifs.close();
			ofs.close();
			cout << "�۷����" << endl;
		}
		void addmenoy() {//���˻����г�ֵ
			int num = stoi(money);
			cout << "���������ֵ�Ľ��" << endl;
			int ad;
			cin >> ad;
			num = num + ad;
			string num1 = to_string(num );
			ifstream ifs;
			string A;
			ifs.open("account.txt", ios::in);
			ofstream ofs;
			ofs.open("tem.txt", ios::out);
			while (ifs >> A) {
				string B = A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;
				ifs >> A;
				ofs << A << endl;

				ifs >> A;
				if (B != accountname) {
					ofs << A << endl;
				}
				else { ofs << num1 << endl; }
				ifs >> A;
				ofs << A << endl;

			}
			ifs.close();
			ofs.close();
			ifs.open("tem.txt", ios::in);
			ofs.open("account.txt", ios::out);
			while (ifs >> A) {
				ofs << A << endl;

			}
			ifs.close();
			ofs.close();
			cout << "��ֵ���" << endl;
		}
		void seachmoney() {//�������
			cout << "���Ϊ" <<money<< endl;
		}

		void findobject() const {//��ѯ����
		start:
			string j;
			cout << "����1ͨ���ռ���������ѯ�Ŀ�� ����2ͨ��ʱ���ѯ��� ����2ͨ���ļ��˲�ѯ��� ����4ͨ����ݵ��Ų�ѯ���(ֻ�ܲ�ѯ���Լ��йصĿ�ݣ�" << endl;
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

					if (e == time && (d == name || e==name) ) {//�ռ��˻�ļ��˱�����һ������ΪĿǰ�˺�
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
					if (b.compare(0, k, time, 0, k) == 0 && (d == name || e == name)) {//�ռ��˻�ļ��˱�����һ������ΪĿǰ�˺�
						cout << "��ݵ���:" << c << endl;//ģ��ƥ��
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
					if (e == name && (b == name || e == name)) {//�ռ��˻�ļ��˱�����һ������ΪĿǰ�˺�
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
					if (c == num && (b == name || e == name)) {//�ռ��˻�ļ��˱�����һ������ΪĿǰ�˺�
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
						if(b=="δ����")cout << "����״̬:" << b << endl;
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
			else { cout << "��Ч����" << endl; return; }

		
		}
	

};


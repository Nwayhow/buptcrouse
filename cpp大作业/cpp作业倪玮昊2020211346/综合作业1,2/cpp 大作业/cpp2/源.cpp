cout << "ѡ������������1ѡ����ͨ�û� 2.ѡ�����Ա 3ѡ����Ա" << endl;
string index;
cin >> index;
while (1) {
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
						C.sent(A.name);
						C.re();
						A.decmoney(C.price);
						A.re();
						control B;
						B.add(C.price);
					}
					else if (index == "2") {
						book C;
						C.sent(A.name);
						C.re();
					}
					else if (index == "3") {
						nomal C;
						C.sent(A.name);
						C.re();
					}
					else {
						cout << "��Ч����" << endl;
						break;
					}

				}

			}
			else if (index == "2") {
				nomal B;
				B.recevive(A.name);
				B.re();
			}
			else if (index == "3") {
				A.findobject();
			}
			else if (index == "4") {
				A.addmenoy();
				A.re();
			}
			else if (index == "5") {
				A.seachmoney();
			}
			else if (index == "2") {
				break;
			}
			else {
				cout << "��Ч������������" << endl;
			}
		}

	}
	else if (index == "2") {
		control B;

		cout << "����1��ѯ��� ����2�鿴���п��Ա ����3Ϊ���ָ�ɿ��Ա ����4�˳�" << endl;
		string index;
		while (1) {
			cin >> index;
			if (index == "1") {
				B.manangeobjects();
			}
			if (index == "2") {
				dev D;
				D.search();
				nomal C;
				string name;
				cout << "���������ѯ�Ŀ��Ա" << endl;
				cin >> name;
				C.deliversaerch(name);
			}
			if (index == "3") {
				dev D;
				D.search();
				nomal C;
				C.unlanshousaerch();
				string num;
				cout << "�������봦��Ķ�����" << endl;
				cin >> num;
				string name;
				cout << "�����������Ŀ��Ա" << endl;
				cin >> name;
				int k = C.lanshou(num, name);
				B.dec(k - (k / 2));
				B.re();
				D.addmoney(name, (k / 2));
				D.re();
			}
			else if (index == "4") {
				break;
			}
			else {
				cout << "��Ч������������" << endl;
			}
		}
	}
	else {
		cout << "��Ч������������" << endl;
	}
}
cout << "选择你的身份输入1选择普通用户 2.选择管理员 3选择快递员" << endl;
string index;
cin >> index;
while (1) {
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
						cout << "无效输入" << endl;
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
				cout << "无效输入重新输入" << endl;
			}
		}

	}
	else if (index == "2") {
		control B;

		cout << "输入1查询快递 输入2查看所有快递员 输入3为快递指派快递员 输入4退出" << endl;
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
				cout << "输入你想查询的快递员" << endl;
				cin >> name;
				C.deliversaerch(name);
			}
			if (index == "3") {
				dev D;
				D.search();
				nomal C;
				C.unlanshousaerch();
				string num;
				cout << "输入你想处理的订单号" << endl;
				cin >> num;
				string name;
				cout << "输入你想分配的快递员" << endl;
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
				cout << "无效输入重新输入" << endl;
			}
		}
	}
	else {
		cout << "无效输入重新输入" << endl;
	}
}
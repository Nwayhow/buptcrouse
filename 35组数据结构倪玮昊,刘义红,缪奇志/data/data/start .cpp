#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
using namespace std;

void myclasss() {
	extern int count5 ;
	count5 = 0;
	extern myclas clas[100];
	ifstream ifs;
	ifs.open("class.txt", ios::in);
	string b;
	while (ifs >> clas[count5].classname) {
		clas[count5].name = clas[count5].classname;
		ifs >> clas[count5].timename;
		clas[count5].time = clas[count5].timename;
		ifs >> b;
		clas[count5].campus = b;
		ifs >> clas[count5].buildingname;
		clas[count5].buliding = clas[count5].buildingname;
		ifs >> b;
		clas[count5].classroom = b;
		ifs >> b;
		clas[count5].timeofexam = b;
		ifs >> b;
		clas[count5].buildingofexam = b;
		ifs >> b;
		clas[count5].classroomofexam = b;
		ifs >> b;
		clas[count5].stage = b;
		ifs >> b;
		clas[count5].group = b;
		count5++;
	}

	ifs.close();


}
void buildact() {
	extern int count6;
	extern myact act[100];
	count6 = 0;
	ifstream ifs;
	ifs.open("act.txt", ios::in);
	string b;
	while (ifs >> act[count6].actname) {
		act[count6].time = act[count6].actname;
		ifs >> b;
		act[count6].kind = b;
		ifs >> b;
		act[count6].name = b;
		count6++;
	}
	ifs.close();

}
void square() {
	extern buildings building[100];
	extern int campus1[50][50];
	extern int campus2[50][50];
	ifstream ifs;
	ifs.open("shahe.txt", ios::in);
	for (int con = 0; con < 50; con++) {
		for (int con1 = con; con1 < 50; con1++) {
			ifs >> campus2[con][con1];
			campus2[con1][con] = campus2[con][con1];
		}
	}
	ifs.close();

	ifs.open("benbu.txt", ios::in);
	for (int con = 0; con < 50; con++) {
		for (int con1 = con; con1 < 50; con1++) {
			ifs >> campus1[con][con1];
			campus1[con1][con] = campus1[con][con1];
		}
	}
	ifs.close();

	
}
void init()
{
	extern buildings building[100];
	building[0] = { "�����Ǳ���",1,1 };
	building[1] = { "��ϯ���Уѵʯ",1,2 };
	building[2] = { "��¥",1,3 };
	building[3] = { "��ѧ¥һ",1,4 };
	building[4] = { "��ѧ¥��",1,5 };
	building[5] = { "��ѧ����",1,6 };
	building[6] = { "ѧ����Ԣ",1,7 };
	building[7] = { "ѧ�Ĺ�Ԣ",1,8 };
	building[8] = { "�ۺ�ʳ��",1,9 };
	building[9] = { "�̹�ʳ��",1,10 };
	building[10] = { "������",1,11 };
	building[11] = { "ѧ�������",1,12 };
	building[13] = { "���д�¥",1,14 };
	building[14] = { "ͼ���",1,15 };
	building[15] = { "�׶�԰",1,16 };
	building[16] = { "��ѧ¥��",1,17 };
	building[17] = { "��ѧ¥��",1,18 };
	building[12] = { "��ѧ¥��",1,13 };
	building[18] = { "��ë���",1,19 };
	building[19] = { "�����",1,20 };
	building[20] = { "��Ӿ��",1,21 };
	building[21] = { "�����ѧԺ¥",1,22 };
	building[22] = { "���ӹ���ѧԺ¥",1,23 };
	building[23] = { "���簲ȫѧԺ¥",1, 24};
	building[24] = { "��ѧԺѧԺ¥",1, 25};
	building[25] = { "��ݮԺѧԺ¥",1,26 };
	building[26] = { "����ѧԺ¥",1,27 };
	building[27] = { "����¥A",1,28 };
	building[28] = { "����¥B",1,29 };
	building[29] = { "����¥C",1,30 };
	building[30] = { "����¥D",1,31 };
	building[31] = { "��ѧ����Ԣ",1,32 };
	building[32] = { "���ʽ�������",1,33 };
	building[33] = { "�˶���",1,34 };
	building[34] = { "��ѧ¥��",1,35 };
	building[35] = { "��ѧ¥��",1,36 };
	building[36] = { "��ѧ¥ʮ",1,37 };
	building[37] = { "��ʳ��",1,38 };
	building[38] = { "��ʳ��",1,39 };
	building[39] = { "��ѧʵ������",1,40 };
	building[40] = { "���´�",1,41 };
	building[41] = { "����¥",1,42 };
	building[42] = { "ʵ��¥",1,43 };
	building[43] = { "������",1,44 };
	building[44] = { "УҽԺ",1,45 };
	building[45] = { "���վ",1,46 };
	building[46] = { "��ʳ��",1,47 };
	building[47] = { "УҽԺ",1,48 };
	building[48] = { "���վ",1,49 };
	building[49] = { "����������",1,50 };
	building[50] = { "ɳ�ӱ���",2,1 };
	building[51] = { "ʯ��",1,2 };
	building[52] = { "��¥",2,3 };
	building[53] = { "��ѧ¥һ",2,4 };
	building[54] = { "��ѧ¥��",2,5 };
	building[55] = { "��ѧ����",2,6 };
	building[56] = { "ѧ����Ԣ",2,7 };
	building[57] = { "ѧ�Ĺ�Ԣ",2,8 };
	building[58] = { "�ۺ�ʳ��",2,9 };
	building[59] = { "�̹�ʳ��",2,10 };
	building[60] = { "������",2,11 };
	building[61] = { "ѧ�������",2,12 };
	building[63] = { "���д�¥",2,14 };
	building[64] = { "ͼ���",2,15 };
	building[65] = { "�׶�԰",2,16 };
	building[66] = { "��ѧ¥��",2,17 };
	building[67] = { "��ѧ¥��",2,18 };
	building[62] = { "��ѧ¥��",2,13 };
	building[68] = { "��ë���",2,19 };
	building[69] = { "�����",2,20 };
	building[70] = { "��Ӿ��",2,21 };
	building[71] = { "ͨ��ѧԺ¥",2,22 };
	building[72] = { "�˹�����ѧԺ¥",2,23 };
	building[73] = { "�������ѧԺ¥",2, 24 };
	building[74] = { "�����",2, 25 };
	building[75] = { "��ͼ���",2,26 };
	building[76] = { "ʵ��¥��",2,27 };
	building[77] = { "����¥A",2,28 };
	building[78] = { "����¥B",2,29 };
	building[79] = { "����¥C",2,30 };
	building[80] = { "����¥D",2,31 };
	building[81] = { "��ѧ����Ԣ",1,32 };
	building[82] = { "���ʽ�������",2,33 };
	building[83] = { "�˶���",2,34 };
	building[84] = { "��ѧ¥��",2,35 };
	building[85] = { "��ѧ¥��",2,36 };
	building[86] = { "��ѧ¥��",2,37 };
	building[87] = { "��ʳ��",2,38 };
	building[88] = { "��ʳ��",2,39 };
	building[89] = { "��ѧʵ������",2,40 };
	building[90] = { "���´�",2,41 };
	building[91] = { "����¥",2,42 };
	building[92] = { "ʵ��¥",2,43 };
	building[93] = { "������",2,44 };
	building[94] = { "УҽԺ",2,45 };
	building[95] = { "���վ",2,46 };
	building[96] = { "��ʳ��",2,47 };
	building[97] = { "УҽԺ",2,48 };
	building[98] = { "���վ",2,49 };
	building[99] = { "ɳ������",2,50 };
	for (int con = 0; con < 100; con++) {
		building[con].name = building[con].buildingname;
	}
	square();
}
void noticestart() {
	extern note notice[100];
	extern int count7;
	count7 = 0;
	ifstream ifs;
	ifs.open("notice.txt", ios::in);
	string b;
	while (ifs >> b) {
		notice[count7].type = b;
		ifs >> b;
		notice[count7].time = b;
		ifs >> b;
		notice[count7].kind = b;
		count7++;
	}
	ifs.close();

}
void homeworkstart() {
	extern homework myhomework[1000];
	extern int count8;
	ifstream ifs;
	ifs.open("homework.txt", ios::in);
	count8 = 0;
	string b;
	while (ifs >> myhomework[count8].name ) {
		string b = myhomework[count8].name;
		if (b == "end")break;
		myhomework[count8].stage = 1;
		count8++;
	}
	while (ifs >> myhomework[count8].name) {
		myhomework[count8].stage = 2;
		count8++;
	}
	ifs.close();
}


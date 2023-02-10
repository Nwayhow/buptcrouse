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
	building[0] = { "西土城北门",1,1 };
	building[1] = { "主席像和校训石",1,2 };
	building[2] = { "主楼",1,3 };
	building[3] = { "教学楼一",1,4 };
	building[4] = { "教学楼二",1,5 };
	building[5] = { "科学会堂",1,6 };
	building[6] = { "学二公寓",1,7 };
	building[7] = { "学四公寓",1,8 };
	building[8] = { "综合食堂",1,9 };
	building[9] = { "教工食堂",1,10 };
	building[10] = { "体育馆",1,11 };
	building[11] = { "学生活动中心",1,12 };
	building[13] = { "科研大楼",1,14 };
	building[14] = { "图书馆",1,15 };
	building[15] = { "幼儿园",1,16 };
	building[16] = { "教学楼五",1,17 };
	building[17] = { "教学楼六",1,18 };
	building[12] = { "教学楼七",1,13 };
	building[18] = { "羽毛球馆",1,19 };
	building[19] = { "篮球馆",1,20 };
	building[20] = { "游泳馆",1,21 };
	building[21] = { "计算机学院楼",1,22 };
	building[22] = { "电子工程学院楼",1,23 };
	building[23] = { "网络安全学院楼",1, 24};
	building[24] = { "理学院学院楼",1, 25};
	building[25] = { "树莓院学院楼",1,26 };
	building[26] = { "邮政学院楼",1,27 };
	building[27] = { "宿舍楼A",1,28 };
	building[28] = { "宿舍楼B",1,29 };
	building[29] = { "宿舍楼C",1,30 };
	building[30] = { "宿舍楼D",1,31 };
	building[31] = { "留学生公寓",1,32 };
	building[32] = { "国际交流中心",1,33 };
	building[33] = { "运动场",1,34 };
	building[34] = { "教学楼八",1,35 };
	building[35] = { "教学楼九",1,36 };
	building[36] = { "教学楼十",1,37 };
	building[37] = { "二食堂",1,38 };
	building[38] = { "三食堂",1,39 };
	building[39] = { "教学实验中心",1,40 };
	building[40] = { "办事处",1,41 };
	building[41] = { "行政楼",1,42 };
	building[42] = { "实验楼",1,43 };
	building[43] = { "出版社",1,44 };
	building[44] = { "校医院",1,45 };
	building[45] = { "快递站",1,46 };
	building[46] = { "南食堂",1,47 };
	building[47] = { "校医院",1,48 };
	building[48] = { "快递站",1,49 };
	building[49] = { "西土城南门",1,50 };
	building[50] = { "沙河北门",2,1 };
	building[51] = { "石碑",1,2 };
	building[52] = { "主楼",2,3 };
	building[53] = { "教学楼一",2,4 };
	building[54] = { "教学楼二",2,5 };
	building[55] = { "科学会堂",2,6 };
	building[56] = { "学二公寓",2,7 };
	building[57] = { "学四公寓",2,8 };
	building[58] = { "综合食堂",2,9 };
	building[59] = { "教工食堂",2,10 };
	building[60] = { "体育馆",2,11 };
	building[61] = { "学生活动中心",2,12 };
	building[63] = { "科研大楼",2,14 };
	building[64] = { "图书馆",2,15 };
	building[65] = { "幼儿园",2,16 };
	building[66] = { "教学楼五",2,17 };
	building[67] = { "教学楼六",2,18 };
	building[62] = { "教学楼七",2,13 };
	building[68] = { "羽毛球馆",2,19 };
	building[69] = { "篮球馆",2,20 };
	building[70] = { "游泳馆",2,21 };
	building[71] = { "通信学院楼",2,22 };
	building[72] = { "人工智能学院楼",2,23 };
	building[73] = { "马克主义学院楼",2, 24 };
	building[74] = { "大会堂",2, 25 };
	building[75] = { "新图书馆",2,26 };
	building[76] = { "实验楼二",2,27 };
	building[77] = { "宿舍楼A",2,28 };
	building[78] = { "宿舍楼B",2,29 };
	building[79] = { "宿舍楼C",2,30 };
	building[80] = { "宿舍楼D",2,31 };
	building[81] = { "留学生公寓",1,32 };
	building[82] = { "国际交流中心",2,33 };
	building[83] = { "运动场",2,34 };
	building[84] = { "教学楼八",2,35 };
	building[85] = { "教学楼四",2,36 };
	building[86] = { "教学楼三",2,37 };
	building[87] = { "二食堂",2,38 };
	building[88] = { "三食堂",2,39 };
	building[89] = { "教学实验中心",2,40 };
	building[90] = { "办事处",2,41 };
	building[91] = { "行政楼",2,42 };
	building[92] = { "实验楼",2,43 };
	building[93] = { "出版社",2,44 };
	building[94] = { "校医院",2,45 };
	building[95] = { "快递站",2,46 };
	building[96] = { "南食堂",2,47 };
	building[97] = { "校医院",2,48 };
	building[98] = { "快递站",2,49 };
	building[99] = { "沙河南门",2,50 };
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


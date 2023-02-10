#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
#include<fstream>
#include <iomanip>
#include"head.h"
class x {
public:
    int data;
    int way;
};

void BubbleSort(x arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j].way > arr[j + 1].way)
            {
                int temp;
                temp = arr[j + 1].way;
                arr[j + 1] = arr[j];
                arr[j].way = temp;
            }
        }
    }

}

void get_nextval(const char* T, int next[])
{
    // 求模式串T的next函数值并存入数组 next。
    int j = 0, k = -1;
    next[0] = -1;
    while (T[j/*+1*/] != '\0')
    {
        if (k == -1 || T[j] == T[k])
        {
            ++j; ++k;
            if (T[j] != T[k])
                next[j] = k;
            else
                next[j] = next[k];
        }// if
        else
            k = next[k];
    }// while
 ////这里是我加的显示部分
// for(int  i=0;i<j;i++)
    //{
    //     cout<<next[i];
    //}
    //cout<<endl;
}


//下面是KMP模式匹配程序，各位可以用他验证。记得加入上面的函数
int KMP(const char* Text, const char* Pattern) //const 表示函数内部不会改变这个参数的值。
{
    if (!Text || !Pattern || Pattern[0] == '\0' || Text[0] == '\0')//
        return -1;//空指针或空串，返回-1。
    int len = 0;
    const char* c = Pattern;
    while (*c++ != '\0')//移动指针比移动下标快。
    {
        ++len;//字符串长度。
    }
    int* next = new int[len + 1];
    get_nextval(Pattern, next);//求Pattern的next函数值

    int index = 0, i = 0, j = 0;
    while (Text[i] != '\0' && Pattern[j] != '\0')
    {
        if (Text[i] == Pattern[j])
        {
            ++i;// 继续比较后继字符
            ++j;
        }
        else
        {
            index += j - next[j];
            if (next[j] != -1)
                j = next[j];// 模式串向右移动
            else
            {
                j = 0;
                ++i;
            }
        }
    }//while

    delete[]next;
    if (Pattern[j] == '\0')
        return index;// 匹配成功
    else
        return -1;
}

void searchclass(char son[100]) {
	extern myclas clas[100];
    extern int count5;
    int con1 = 0;
    x arr[1000];
    for (int con = 0; con < count5; con++) {
        int i = 0;
        i = KMP(clas[con].classname, son);
        if (i != -1) {  
            arr[con1].way = i;
            arr[con1].data = con;
            con1++;
        }
 
    }
    BubbleSort(arr, con1);
    for (int i = 0; i < con1; i++) {
        clas[arr[i].data].printff();
    }
}
void searchactive(char son[100],string kind) {
    extern int count6;
	extern myact act[100];
    int con1 = 0;
    x arr[1000];
    for (int con = 0; con < count6; con++) {
        int i = 0;
        i = KMP(act[con].actname, son);
        if (i != -1) {
            arr[con1].way = i;
            arr[con1].data = con;
            con1++;
        }
    }
    BubbleSort(arr, con1);
    for (int i = 0; i < con1; i++) {
        act[arr[i].data].printff();
    }
}
void searchtime(char son[100]) {
	extern myclas clas[100];
    extern int count5;
    int con1 = 0;
    x arr[1000];
    for (int con = 0; con < count5; con++) {
        int i = 0;
        i = KMP(clas[con].timename, son);
        if (i != -1) {
            arr[con1].way = i;
            arr[con1].data = con;
            con1++;
        }
     
    }
    BubbleSort(arr, con1);
    for (int i = 0; i < con1; i++) {
        clas[arr[i].data].printff();
    }

}
void searchbuilding(char son[100], string campus) {
	extern myclas clas[100];
    extern int count5;
    int con1 = 0;
    x arr[1000];
    for (int con = 0; con < count5; con++) {
        int i = 0;
        i = KMP(clas[con].buildingname, son);
        if (i != -1 && campus==clas[con].campus) {
            arr[con1].way = i;
            arr[con1].data = con;
            con1++;
        }
    }
    BubbleSort(arr, con1);
    for (int i = 0; i < con1; i++) {
        clas[arr[i].data].printff();
    }
}
void searchhomework(char son[100]) {
	extern homework myhomework[1000];
    extern int count8;
    int con1 = 0;
    x arr[1000];
    for (int con = 0; con < count8; con++) {
        int i = 0;
        i = KMP(myhomework[con].name, son);
        if (i != -1) {
            arr[con1].way = i;
            arr[con1].data = con;
            con1++;
        }
     
    }
    BubbleSort(arr, con1);
    for (int i = 0; i < con1; i++) {
        myhomework[arr[i].data].printff();
    }
}
void searchway(char son[100],int campus) {
	extern buildings building[100];
    int t;
    int con1 = 0;
    x arr[1000];
    if (campus == 1) t = 0;
    else t = 50;
    
    for (int con = t; con < 100; con++) {
        int i = 0;
        i = KMP(building[con].buildingname, son);
        if (i != -1) {
            arr[con1].way = i;
            arr[con1].data = con;
            con1++;
        }
       
    }
    BubbleSort(arr, con1);
    for (int i = 0; i < con1; i++) {
        building[arr[i].data].printff();
    }
}



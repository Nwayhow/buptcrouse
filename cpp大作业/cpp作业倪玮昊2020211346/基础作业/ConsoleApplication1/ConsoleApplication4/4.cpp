#include <iostream>
#include<stdlib.h>
#include <string>
#include <string.h >
#include<time.h>
using namespace std;
int panduan(char  nums[1000]) {
    for (int count = 0; count < strlen(nums); count++) {
        if (nums[count] < '0' || nums[count] >'9') {
            return -1;
        }
       
    }
    return 1;
}
int main()
{
    cout << "输入1-1000的整数" << endl;
    char  nums[1000];
    srand((unsigned)time(NULL));
    int price = rand() % 1000 + 1;

    cout << price<<endl;
    do {
        cin >> nums;
       
        while (panduan(nums) == -1 ) {
            cout << "不符合规范重新输入" << endl;
            cin >> nums;
        } 

            while (stoi(nums) < 1 || stoi(nums) > 1000) {
                cout << "不符合规范重新输入" << endl;
                cin >> nums;
            }
        int num = stoi(nums);
        if (num > price) cout << "大于价格" << endl;
        else if (num < price) cout << "小于价格" << endl;
        else break;
    }while (1);
    cout << "已得到价格为" << price << endl;
}


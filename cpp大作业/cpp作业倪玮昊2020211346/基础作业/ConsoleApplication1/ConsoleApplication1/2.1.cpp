#include<iostream>
#include<cmath>
using namespace std;
class Point {
public:
	Point() {
		cout << "输入点的横纵坐标" << endl;
		cin >>  x >> y;
	}
	
	int backx() { return x; }
	int backy() { return y; }
	~Point()
	{

		cout << "Point析构函数调用" << endl;
	}
private:
	int x=0;
	int y=0;
};
class circle {
private:
	Point s_point;
	int r;
public:
	circle() {
		cout << "输入点的半径" << endl;
		cin >> r ;
	}
	Point backp() { return s_point; }
	int backr() { return r; }
	int caldistance(Point p) {
		return (s_point.backx() - p.backx()) * (s_point.backx() - p.backx()) + (s_point.backy() - p.backy()) * (s_point.backy() - p.backy());
	}
	~circle()
	{
		cout<<"circle析构函数调用"<<endl;
	}
};

int main(void) {
	circle A, B;

	if ((A.backr() + B.backr())* (A.backr() + B.backr()) > A.caldistance(B.backp())) { cout << "yes"<<endl; }
	else { cout << "no"<<endl; }
}

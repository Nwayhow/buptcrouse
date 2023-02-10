#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
class Shape {
public:
	double a, b;
	double area;
	virtual void cal()  = 0;
	void output() {
		cout << fixed << setprecision(2) << area << endl;
	}
	Shape() {
		cout<< "调用父函数构造函数" << endl;
	}
	virtual  ~Shape()
	{
		cout << "调用父函数析构函数" << endl;
	}

};
class matrix :public Shape {
public:
	matrix() {
		
	};
	matrix(int c,int d) {
		cout << "调用matrix构造函数" << endl;
		a = c;
		b = d;
	}
	void cal() {
		area =  a * b;
		Shape::output();
	};

	~matrix() {
		cout << "调用matrix析构函数" << endl;
	}

};
class circle :public Shape {
public:
	circle(int c) {
		cout << "调用circle构造函数" << endl;
		a = c;
	}
	void cal() {
		area = a * a * 3.14;
		Shape::output();
	};
	~circle() {
		cout << "调用circle析构函数" << endl;
	}
};
class square :public matrix {
public:
	square(int c) {
		cout << "调用square构造函数" << endl;
		a = c;
		b = a;
	}
	~square() {
		cout << "调用square析构函数" << endl;
	}
};
int main()
{
	int c, d;
	cout << "输入矩形的长宽";
	cin >> c >> d;
	Shape *A=new matrix(c,d);
	A->cal();
	delete A;
	cout << "输入圆的半径";
	cin >> c;
	Shape* B = new circle(c);
	B->cal();
	delete B;
	cout << "输入正方形的边长";
	cin >> c;
	matrix* C= new square(c);
	C->cal();
	delete C;
}


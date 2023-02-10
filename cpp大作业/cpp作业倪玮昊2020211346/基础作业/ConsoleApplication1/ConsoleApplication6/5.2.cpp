#include<iostream>
#include<cmath>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point& operator++() {
		x++;
		y++;
		return *this;
	}
	Point operator++(int) {
		Point B = *this;
		x++;
		y++;
		return B;
	}
	Point& operator--() {
		x--;
		y--;
		return *this;
	}
	Point operator--(int) {
		Point B = *this;
		x--;
		y--;
		return B;
	}
	Point() {
		cin >> x >> y;
	}
	int backx() { return x; }
	int backy() { return y; }
	~Point()
	{
	}
};
ostream& operator<<(ostream& cout, Point A) {
	cout << A.backx()<<' ' << A.backy() << endl;
	return cout;
}

int main(void) {
	Point A;
	cout <<"++A为:" << ++A << endl;
	cout << "经历过运算后的A:" << A << endl;
	cout <<"A++为"<< A++ << endl;
	cout << "经历过运算后的A:" << A << endl;
	cout <<"--A为:" << --A << endl;
	cout << "经历过运算后的A:" << A << endl;
	cout <<"A--为:"<< A-- << endl;
	cout << "经历过运算后的A:" << A << endl;
}

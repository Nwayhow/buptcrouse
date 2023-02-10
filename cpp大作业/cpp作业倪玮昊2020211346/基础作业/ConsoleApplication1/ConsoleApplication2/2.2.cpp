#include<iostream>
using namespace std;
int line, row;
class square {
 private:
	int line, row;
	
public:
	int** A;
	square(int m,int n) {
		line = m;
		row = n;
		A = new int* [line];
		for (int count = 0; count < line; count++) {
				A[count] = new int[row];
		}
		
	}
	void start() {
		for (int count = 0; count < line; count++) {
			for (int count1 = 0; count1 < row; count1++) {
				cin >> A[count][count1];
			}
		}
	}
	~square()
	{
		cout << "调用析构" << endl;
		for (int i = 0; i < line ; i++)
		{
			delete[]A[i];
		}
		delete[]A;
	}

	square(const square& p) {
		cout << "调用拷贝构造" << endl;
		line = p.line;
		row = p.row;
		A = new int* [line];
		for (int count = 0; count < line; count++) {
			A[count] = new int[row];
		}
		for (int count = 0; count < line; count++) {
			for (int count1 = 0; count1 < row; count1++) {
				A[count][count1]=p.A[count][count1];
			}
		}
	
	}
	void output() {
		for (int count = 0; count < 4; count++) {
			for (int count1 = 0; count1 < 5; count1++) {
				cout << A[count][count1] << ' ';
			}
			cout << endl;
		}

	}
	void add(square p,square q) {
		cout << "A1+A2为" << endl;
		for (int count = 0; count < line; count++) {
			for (int count1 = 0; count1 < row; count1++) {
				A[count][count1] = q.A[count][count1] + p.A[count][count1];
			}

		}
		output();
	}
	void sub(square p, square q) {
		cout << "A1-A2为" << endl;
		for (int count = 0; count < line; count++) {
			for (int count1 = 0; count1 < row; count1++) {
				A[count][count1] = p.A[count][count1] - q.A[count][count1] ;
			}
		}
		output();
	}
	square& operator=(square& A1)//ob == ob1
	{

	}


};
int main() {
	cout << "输入数组横纵" << endl;
	cin >> line >> row;
	square pA1(line, row);
	square pA2(line, row);
	square pA3(line, row);
	cout << "输入矩阵A1" << endl;
	pA1.start();
	cout << "输入矩阵A2" << endl;
	pA2.start();
	pA3.add(pA1,pA2);
	pA3.sub(pA1,pA2);
	cout << "new方法" << endl;
	cout << "输入数组横纵" << endl;
	cin >> line >> row;
	square *pA4=new square (line, row);
	square *pA5 = new square(line, row);
	square *pA6 = new square(line, row);
	cout << "输入矩阵A1" << endl;
	pA4->start();
	cout << "输入矩阵A2" << endl;
	pA5->start();
	pA6->add(pA1, pA2);
	pA6->sub(pA1, pA2);
	delete pA5;
	delete pA4;
	delete pA6;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE	256

typedef int elemtype;

struct tuple
{
	int i;
	int j;
	elemtype v;
};

struct sparsematrix
{
	int row;
	int column;
	int num;
	tuple data[MAXSIZE];
};


void InputMaxtrix(sparsematrix& M, const char* name);	// 输入稀疏矩阵			   
bool MatrixAddition(sparsematrix M1, sparsematrix M2, sparsematrix& sum);	// 判断矩阵是否能相加，如果能则将结果存储在sum中
int SearchElement(sparsematrix M, int i, int j);	// 返回M[i][j]的值
bool MatrixMultiplication(sparsematrix M1, sparsematrix M2, sparsematrix& mul); // 判断矩阵是否能相乘，如果能则将结果存储在mul中
void PrintMatrix(sparsematrix M);	// 输出稀疏矩阵

int main(void)
{
	sparsematrix A, B, C;
	InputMaxtrix(A, "A");
	InputMaxtrix(B, "B");
	if (MatrixAddition(A, B, C))
	{
		printf("\n矩阵A为：\n");
		PrintMatrix(A);
		printf("\n矩阵B为：\n");
		PrintMatrix(B);
		printf("\n矩阵A和矩阵B相加的结果矩阵C为：\n");
		PrintMatrix(C);
	}
	if (MatrixMultiplication(A, B, C))
	{
		printf("\n矩阵A为：\n");
		PrintMatrix(A);
		printf("\n矩阵B为：\n");
		PrintMatrix(B);
		printf("\n矩阵A和矩阵B相乘的结果矩阵C为：\n");
		PrintMatrix(C);
	}
	printf("%d", C.num);
	system("pause");
	return 0;
}


// 输入稀疏矩阵 
void InputMaxtrix(sparsematrix& M, const char* name)
{
	printf("请依次输入矩阵%s的行R，列C和非零元素个数N（以空格隔开）：", name);
	while (scanf("%d%d%d", &(M.row), &(M.column), &(M.num)) != 3 || M.row <= 0 || M.column <= 0 || M.num < 0 || M.row * M.column < M.num)
	{
		printf("输入错误，请重新输入：");
	}
	int pos = 0;
	int ti, tj;
	elemtype tv;
	while (pos != M.num)
	{
		printf("请依次输入元素所在的行i，列j和非零元素的值v（行列下标由1始，以空格隔开，一行一组，以先行后列递增顺序输入）：\n");
		int flag = scanf("%d%d%d", &ti, &tj, &tv);
		while (getchar() != '\n') // 清空缓冲区
		{
			continue;
		}
		while (flag != 3 || ti < 1 || ti > M.row || tj < 1 || tj > M.column || tv == 0)
		{
			printf("输入错误，请从上一行的数据开始重新往下输入：\n");
			flag = scanf("%d%d%d", &ti, &tj, &tv);
			while (getchar() != '\n') // 清空缓冲区
			{
				continue;
			}
		}
		(M.data[pos]).i = ti;
		(M.data[pos]).j = tj;
		(M.data[pos]).v = tv;
		pos++;
	}
	printf("输入完成，成功存储矩阵%s！\n", name);
}

// 判断矩阵是否能相加，如果能则将结果存储在sum中
bool MatrixAddition(sparsematrix M1, sparsematrix M2, sparsematrix& sum)
{
	printf("\n");
	if (M1.row != M2.row && M1.column != M2.column)
	{
		printf("二者行列均不同，无法相加!\n");
		return false;
	}
	else if(M1.row != M2.row && M1.column == M2.column)
	{
		printf("二者列相同但行不同，无法相加!\n");
		return false;
	}
	else if (M1.row == M2.row && M1.column != M2.column)
	{
		printf("二者行相同但列不同，无法相加!\n");
		return false;
	}
	sum.row = M1.row;
	sum.column = M1.column;
	sum.num = 0;
	int M1_pos = 0, M2_pos = 0;
	while (M1_pos != M1.num && M2_pos != M2.num)
	{
		tuple T1 = M1.data[M1_pos], T2 = M2.data[M2_pos];
		if ((T1.i < T2.i) || (T1.i == T2.i && T1.j < T2.j))	// M1的元素T1次序靠前
		{
			sum.data[sum.num] = T1;
			sum.num++;
			M1_pos++;
		}
		else if (T1.i == T2.i && T1.j == T2.j)	// M1和M2在同一位置有数
		{
			sum.data[sum.num].i = T1.i;
			sum.data[sum.num].j = T1.j;
			sum.data[sum.num].v = T1.v + T2.v;
			sum.num++;
			M1_pos++;
			M2_pos++;
		}
		else  // M2的元素T2次序靠前  
		{
			sum.data[sum.num] = T2;
			sum.num++;
			M2_pos++;
		}
	}
	while(M1_pos != M1.num)	// M1还未遍历结束，则M1剩下元素存入sum
	{
		sum.data[sum.num++] = M1.data[M1_pos++];
	}
	while (M2_pos != M2.num)	// M2还未遍历结束，则M1剩下元素存入sum	
	{
		sum.data[sum.num++] = M2.data[M2_pos++];
	}
	return true;
}

// 返回M[i][j]的值
int SearchElement(sparsematrix M, int i, int j)
{
	int pos = 0;
	while (pos < M.num && M.data[pos].i <= i)
	{
		if (M.data[pos].i == i && M.data[pos].j == j)	//如果找到就返回非零元素值
			return M.data[pos].v;
		pos++;
	}
	return 0;	//	否则返回0
}

// 判断矩阵是否能相乘，如果能则将结果存储在mul中
bool MatrixMultiplication(sparsematrix M1, sparsematrix M2, sparsematrix& mul)
{
	if (M1.column != M2.row)
	{
		printf("二者无法相乘！\n");
		return false;
	}
	mul.row = M1.row;
	mul.column = M2.column;
	mul.num = 0;
	if (M1.num != 0 || M2.num != 0)
	{
		for (int i = 1; i <= mul.row; i++)
		{
			for (int j = 1; j <= mul.column; j++)
			{
				int temp = 0;	// 存储A[i][k] * B[k][j]求和
				for (int k = 1; k <= M1.column; k++)
				{
					temp += SearchElement(M1, i, k) * SearchElement(M2, k, j);
				}
				if (temp != 0)	// 添加非零元素
				{
					mul.data[mul.num].i = i;
					mul.data[mul.num].j = j;
					mul.data[mul.num].v = temp;
					mul.num++;
				}
			}
		}
	}
	return true;
}

// 输出稀疏矩阵
void PrintMatrix(sparsematrix M)
{
	int pos = 0;
	for (int i = 1; i <= M.row; i++)
	{
		for (int j = 1; j <= M.column; j++)
		{
			if (pos < M.num && i == M.data[pos].i && j == M.data[pos].j)	//在data中，是非零元素
				printf("%d	", M.data[pos++].v);
			else														   //不在data中，为0
				printf("%d	", 0);
		}
		printf("\n");
	}
}
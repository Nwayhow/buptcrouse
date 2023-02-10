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


void InputMaxtrix(sparsematrix& M, const char* name);	// ����ϡ�����			   
bool MatrixAddition(sparsematrix M1, sparsematrix M2, sparsematrix& sum);	// �жϾ����Ƿ�����ӣ�������򽫽���洢��sum��
int SearchElement(sparsematrix M, int i, int j);	// ����M[i][j]��ֵ
bool MatrixMultiplication(sparsematrix M1, sparsematrix M2, sparsematrix& mul); // �жϾ����Ƿ�����ˣ�������򽫽���洢��mul��
void PrintMatrix(sparsematrix M);	// ���ϡ�����

int main(void)
{
	sparsematrix A, B, C;
	InputMaxtrix(A, "A");
	InputMaxtrix(B, "B");
	if (MatrixAddition(A, B, C))
	{
		printf("\n����AΪ��\n");
		PrintMatrix(A);
		printf("\n����BΪ��\n");
		PrintMatrix(B);
		printf("\n����A�;���B��ӵĽ������CΪ��\n");
		PrintMatrix(C);
	}
	if (MatrixMultiplication(A, B, C))
	{
		printf("\n����AΪ��\n");
		PrintMatrix(A);
		printf("\n����BΪ��\n");
		PrintMatrix(B);
		printf("\n����A�;���B��˵Ľ������CΪ��\n");
		PrintMatrix(C);
	}
	printf("%d", C.num);
	system("pause");
	return 0;
}


// ����ϡ����� 
void InputMaxtrix(sparsematrix& M, const char* name)
{
	printf("�������������%s����R����C�ͷ���Ԫ�ظ���N���Կո��������", name);
	while (scanf("%d%d%d", &(M.row), &(M.column), &(M.num)) != 3 || M.row <= 0 || M.column <= 0 || M.num < 0 || M.row * M.column < M.num)
	{
		printf("����������������룺");
	}
	int pos = 0;
	int ti, tj;
	elemtype tv;
	while (pos != M.num)
	{
		printf("����������Ԫ�����ڵ���i����j�ͷ���Ԫ�ص�ֵv�������±���1ʼ���Կո������һ��һ�飬�����к��е���˳�����룩��\n");
		int flag = scanf("%d%d%d", &ti, &tj, &tv);
		while (getchar() != '\n') // ��ջ�����
		{
			continue;
		}
		while (flag != 3 || ti < 1 || ti > M.row || tj < 1 || tj > M.column || tv == 0)
		{
			printf("������������һ�е����ݿ�ʼ�����������룺\n");
			flag = scanf("%d%d%d", &ti, &tj, &tv);
			while (getchar() != '\n') // ��ջ�����
			{
				continue;
			}
		}
		(M.data[pos]).i = ti;
		(M.data[pos]).j = tj;
		(M.data[pos]).v = tv;
		pos++;
	}
	printf("������ɣ��ɹ��洢����%s��\n", name);
}

// �жϾ����Ƿ�����ӣ�������򽫽���洢��sum��
bool MatrixAddition(sparsematrix M1, sparsematrix M2, sparsematrix& sum)
{
	printf("\n");
	if (M1.row != M2.row && M1.column != M2.column)
	{
		printf("�������о���ͬ���޷����!\n");
		return false;
	}
	else if(M1.row != M2.row && M1.column == M2.column)
	{
		printf("��������ͬ���в�ͬ���޷����!\n");
		return false;
	}
	else if (M1.row == M2.row && M1.column != M2.column)
	{
		printf("��������ͬ���в�ͬ���޷����!\n");
		return false;
	}
	sum.row = M1.row;
	sum.column = M1.column;
	sum.num = 0;
	int M1_pos = 0, M2_pos = 0;
	while (M1_pos != M1.num && M2_pos != M2.num)
	{
		tuple T1 = M1.data[M1_pos], T2 = M2.data[M2_pos];
		if ((T1.i < T2.i) || (T1.i == T2.i && T1.j < T2.j))	// M1��Ԫ��T1����ǰ
		{
			sum.data[sum.num] = T1;
			sum.num++;
			M1_pos++;
		}
		else if (T1.i == T2.i && T1.j == T2.j)	// M1��M2��ͬһλ������
		{
			sum.data[sum.num].i = T1.i;
			sum.data[sum.num].j = T1.j;
			sum.data[sum.num].v = T1.v + T2.v;
			sum.num++;
			M1_pos++;
			M2_pos++;
		}
		else  // M2��Ԫ��T2����ǰ  
		{
			sum.data[sum.num] = T2;
			sum.num++;
			M2_pos++;
		}
	}
	while(M1_pos != M1.num)	// M1��δ������������M1ʣ��Ԫ�ش���sum
	{
		sum.data[sum.num++] = M1.data[M1_pos++];
	}
	while (M2_pos != M2.num)	// M2��δ������������M1ʣ��Ԫ�ش���sum	
	{
		sum.data[sum.num++] = M2.data[M2_pos++];
	}
	return true;
}

// ����M[i][j]��ֵ
int SearchElement(sparsematrix M, int i, int j)
{
	int pos = 0;
	while (pos < M.num && M.data[pos].i <= i)
	{
		if (M.data[pos].i == i && M.data[pos].j == j)	//����ҵ��ͷ��ط���Ԫ��ֵ
			return M.data[pos].v;
		pos++;
	}
	return 0;	//	���򷵻�0
}

// �жϾ����Ƿ�����ˣ�������򽫽���洢��mul��
bool MatrixMultiplication(sparsematrix M1, sparsematrix M2, sparsematrix& mul)
{
	if (M1.column != M2.row)
	{
		printf("�����޷���ˣ�\n");
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
				int temp = 0;	// �洢A[i][k] * B[k][j]���
				for (int k = 1; k <= M1.column; k++)
				{
					temp += SearchElement(M1, i, k) * SearchElement(M2, k, j);
				}
				if (temp != 0)	// ��ӷ���Ԫ��
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

// ���ϡ�����
void PrintMatrix(sparsematrix M)
{
	int pos = 0;
	for (int i = 1; i <= M.row; i++)
	{
		for (int j = 1; j <= M.column; j++)
		{
			if (pos < M.num && i == M.data[pos].i && j == M.data[pos].j)	//��data�У��Ƿ���Ԫ��
				printf("%d	", M.data[pos++].v);
			else														   //����data�У�Ϊ0
				printf("%d	", 0);
		}
		printf("\n");
	}
}
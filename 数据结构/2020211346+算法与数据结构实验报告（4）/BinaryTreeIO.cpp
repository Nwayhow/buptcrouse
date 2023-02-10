#include <stdio.h>
#include <stdlib.h>

typedef char EleType;

typedef struct BTnode
{
	EleType data;
	BTnode* lc;
	BTnode* rc;
}* BiTree;


void PreInitial(BiTree& T, bool& Error); // ����������������������Error�ж������Ƿ�Ƿ�
int GetHeight(BiTree T);                // �����߶�
void LevelOutput(BiTree T,int H);	   // ���������������̬
void Clear(BiTree& T);				  // ���������


int main()
{
	BiTree T = NULL;
	bool ERROR = false;
	printf("������һ����������ַ����У���*��ʾ�սڵ㣬Сд��ĸ��ʾ�ڵ����ݣ�������û�г���*��Сд��ĸ��������ַ�����\n");
	PreInitial(T, ERROR);
	int h = GetHeight(T);
	LevelOutput(T, h);
	Clear(T);
	return 0;
}

// ����������������
void PreInitial(BiTree& T, bool& Error) // Error�ж������ַ��Ƿ�Ƿ�
{
	if (Error)
		return;
	EleType e = getchar();
	if (e == '*')
		return;
	else if (e <'a'||e>'z')
	{
		Error = true;
		return;
	}
	if (!T)
	{
		T = (BTnode*)malloc(sizeof(BTnode));
		T->data = e;
		T->lc = NULL;
		T->rc = NULL;
		PreInitial(T->lc, Error);
		PreInitial(T->rc, Error);
	}
}

// �����߶�
int GetHeight(BiTree T)
{
	if (!T)
		return 0;
	int len1 = GetHeight(T->lc) + 1;
	int len2 = GetHeight(T->rc) + 1;
	return len1 >= len2 ? len1 : len2;
}

// ���������������̬
void LevelOutput(BiTree T, int H)
{
	if (!T)
	{
		printf("�ö�����Ϊ��");
		return;
	}
	printf("�ö������ṹ���£�\n");
	int pow2[100] = { 1 };
	for (int i = 1; i <= H; i++)
		pow2[i] = pow2[i - 1] * 2;
	int space = pow2[H];
	BTnode** temp = (BTnode** )malloc(sizeof(BTnode* ) * pow2[H]);
	temp[1] = T;
	for (int i = 0; i < H - 1; i++)
	{
		for (int j = pow2[i]; j < pow2[i + 1]; j++)
		{
			if (temp[j])
			{
				temp[2 * j] = temp[j]->lc;
				temp[2 * j + 1] = temp[j]->rc;
			}
			else
			{
				temp[2 * j] = NULL;
				temp[2 * j + 1] = NULL;
			}
		}
	}
	putchar('\n');
	for (int i = 0; i < H; i++)
	{
		for (int j = pow2[i]; j < pow2[i + 1]; j++)
		{
			for (int k = 0; k < space - 1;  k++)	// ����ո񣨸�ʽ��
				putchar(' ');
			if (temp[j]) 
				putchar(temp[j]->data);
			else
				putchar(' ');
			for (int k = 0; k < space; k++)	      // ����ո񣨸�ʽ��
				putchar(' ');
		}
		putchar('\n');
		space /= 2;
	}
}


void Clear(BiTree& T) // ���������
{
	if (!T)
		return;
	if (T->lc)
		Clear(T->lc);
	if (T->rc)
		Clear(T->rc);
	free(T);
	T = NULL;
}
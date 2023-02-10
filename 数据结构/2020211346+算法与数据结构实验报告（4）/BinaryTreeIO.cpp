#include <stdio.h>
#include <stdlib.h>

typedef char EleType;

typedef struct BTnode
{
	EleType data;
	BTnode* lc;
	BTnode* rc;
}* BiTree;


void PreInitial(BiTree& T, bool& Error); // 先序遍历构造二叉树，参数Error判断输入是否非法
int GetHeight(BiTree T);                // 求树高度
void LevelOutput(BiTree T,int H);	   // 层序输出二叉树形态
void Clear(BiTree& T);				  // 清除二叉树


int main()
{
	BiTree T = NULL;
	bool ERROR = false;
	printf("请输入一个先序遍历字符序列（用*表示空节点，小写字母表示节点数据，序列中没有除了*和小写字母外的其他字符）：\n");
	PreInitial(T, ERROR);
	int h = GetHeight(T);
	LevelOutput(T, h);
	Clear(T);
	return 0;
}

// 先序遍历构造二叉树
void PreInitial(BiTree& T, bool& Error) // Error判断输入字符是否非法
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

// 求树高度
int GetHeight(BiTree T)
{
	if (!T)
		return 0;
	int len1 = GetHeight(T->lc) + 1;
	int len2 = GetHeight(T->rc) + 1;
	return len1 >= len2 ? len1 : len2;
}

// 层序输出二叉树形态
void LevelOutput(BiTree T, int H)
{
	if (!T)
	{
		printf("该二叉树为空");
		return;
	}
	printf("该二叉树结构如下：\n");
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
			for (int k = 0; k < space - 1;  k++)	// 输出空格（格式）
				putchar(' ');
			if (temp[j]) 
				putchar(temp[j]->data);
			else
				putchar(' ');
			for (int k = 0; k < space; k++)	      // 输出空格（格式）
				putchar(' ');
		}
		putchar('\n');
		space /= 2;
	}
}


void Clear(BiTree& T) // 清除二叉树
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
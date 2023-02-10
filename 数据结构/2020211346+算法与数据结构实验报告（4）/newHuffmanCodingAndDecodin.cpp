#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEAFSIZE 300                 // 一个字节最多有256个取值，即256个叶子结点，LEAFSIZE不小于256即可
#define TREESIZE 2 * LEAFSIZE - 1   // 哈夫曼树只有度2/0的结点，TREESIZE = 2 * LEAFSIZE -1 
#define READSIZE 1024 			   // 每次从文件中读取的字节数	
#define CODESIZE 28				  // 哈夫曼编码最长位数
#define NAMESIZE 128			 // 文件名（文件路径名）

// 哈夫曼树结点
struct HuffmanNode
{
	char data; 					  // 每八位二进制视作一个字符读入，最后不足八位的再另外视为一个字符
	long long weight;
	int parent, lchild, rchild;
};

// 哈夫曼树
struct HuffmanTree
{
	HuffmanNode node[TREESIZE - 1];
	int len;
};

// 数据（单字符对应的数值）和哈夫曼编码的匹配结点
typedef struct MapNode
{
	char data;
	char Bin[CODESIZE + 1];		// 存二进制串
};

// 基于哈夫曼树得到的数据和哈夫曼编码的一整组匹配
struct Map
{
	MapNode node[LEAFSIZE];
	int len;
};

// 文件操作中存储源文件，中间文件，目标文件的字段使用
static char source[READSIZE], temp[READSIZE * CODESIZE + CODESIZE + 8], dest[READSIZE * CODESIZE + CODESIZE + 8];

// H是哈夫曼树，HuffmanCodeMap是字符和哈夫曼编码的匹配
static HuffmanTree H;
static Map HuffmanCodeMap;

static bool Init(char* filename);		//	初始化哈夫曼树结点
static void CreatHaffmanTree(void);	 //	构建完整的哈夫曼树	
static void SearchNode(int Range, int& pos1, int& pos2);	//	构建哈夫曼树中寻找已有结点中权值最小的两个结点
static void CreatHaffmanCodeMap(int root, char TempCode[CODESIZE + 1], int len);		//	得到哈夫曼编码匹配
static bool Encode(char* sourcefile, char* destfile);		 // 编码
static bool Decode(char* sourcefile, char* destfile);		//  解码
static void PrintMessage(void);		//	输出哈夫曼树和哈夫曼编码匹配的信息
static void ClearBuffer();		   //   清除缓冲区



int main(void)
{
	HuffmanCodeMap.len = 0;
	bool OK = true;	// 判断是否正确读入文件，若未能正确读入则直接结束程序
	char TempCode[CODESIZE + 1]; // 在CreatHaffmanCodeMap中临时存储在该节点对应的编码（该节点不是叶子结点则TempCode就不是有效编码）
	memset(TempCode, 0, sizeof(TempCode));
	char sourcefile[NAMESIZE], encodefile[NAMESIZE], decodefile[NAMESIZE];	// 各个文件的文件名（文件路径名）
	printf("欢迎使用本压缩程序！");
	while (1)
	{
		printf("\n本程序可选功能如下：\n1.压缩文件\n2.解压文件\n3.退出\n请选择(1/2/3)：");
		char choice = getchar();
		ClearBuffer();
		if (choice == '1')
		{
			printf("请将待编码文件移动至与本程序同目录下，并输入待编码文件名：");
			scanf("%s", sourcefile);
			getchar();
			OK = Init(sourcefile);
			if (!OK)
				continue;
			CreatHaffmanTree();
			CreatHaffmanCodeMap(H.len - 1, TempCode, 0);
			printf("请命名压缩文件（不超过%d个字符）：", NAMESIZE);
			scanf("%s", encodefile);
			getchar();
			OK = Encode(sourcefile, encodefile);
			if (!OK)
				continue;
			PrintMessage();

		}
		else if (choice == '2')
		{
			printf("请将待编码文件移动至与本程序同目录下，并输入待编码文件名：");
			scanf("%s", sourcefile);
			getchar();
			printf("请命名解压文件（不超过%d个字符）：", NAMESIZE);
			scanf("%s", decodefile);
			getchar();
			OK = Decode(sourcefile, decodefile);
			if (!OK)
				continue;
		}
		else if (choice == '3')
			break;
		else
			printf("输入错误，无法实现任何功能！\n");
	}
	printf("\n成功退出！欢迎下次使用！");
	return 0;
}

//	初始化哈夫曼树结点
static bool Init(char* filename)
{
	H.len = 0;
	FILE* fptr = fopen(filename, "rb");
	if (fptr == NULL)
	{
		printf("找不到待编码的目标文件！\n");
		return false;
	}
	fseek(fptr, 0, SEEK_END);
	long long count = ftell(fptr);	// 除去结尾的EOF
	fseek(fptr, 0, SEEK_SET);
	while (count)
	{
		int size = count >= READSIZE ? READSIZE : count;
		fread(source, sizeof(char), size, fptr);
		for (int i = 0; i < size; i++)
		{
			bool find = false;
			for (int j = 0; j < H.len; j++)
				if (H.node[j].data == source[i])
				{
					H.node[j].weight++;
					find = true;
					break;
				}
			if (!find)
			{
				H.node[H.len].data = source[i];
				H.node[H.len].weight = 1;
				H.node[H.len].lchild = H.node[H.len].rchild = H.node[H.len].parent = -1;
				H.len++;
			}
		}
		count -= size;
	}
	fclose(fptr);
	return true;
}

//	构建完整的哈夫曼树	
static void CreatHaffmanTree()
{
	int count = H.len - 1; // 哈夫曼树只有度为2/0的结点，num(d=2) = num(d=0) - 1
	while (count--)
	{
		int pos1, pos2;
		SearchNode(H.len, pos1, pos2);
		H.node[H.len].lchild = pos1, H.node[H.len].rchild = pos2, H.node[H.len].parent = -1;
		H.node[H.len].weight = H.node[pos1].weight + H.node[pos2].weight;
		H.node[pos1].parent = H.node[pos2].parent = H.len;
		H.len++;
	}
}

//	构建哈夫曼树中寻找已有结点中权值最小的两个结点
static void SearchNode(int Range, int& pos1, int& pos2)
{
	pos1 = -1, pos2 = -1;	//权值上pos1为最小,pos2第二小
	for (int i = 0; i < Range; i++)
	{
		// 有双亲的结点不能作为根节点被合并
		if (H.node[i].parent != -1)
			continue;
		// 新结点权值比已有的两个小
		if (pos1 == -1 || H.node[pos1].weight > H.node[i].weight)
			pos2 = pos1, pos1 = i;
		// 新结点权值在两个结点的权值之间
		else if (pos2 == -1 || (H.node[pos1].weight < H.node[i].weight && H.node[i].weight < H.node[pos2].weight))
			pos2 = i;
	}
	return;
}

//	得到哈夫曼编码匹配
static void CreatHaffmanCodeMap(int root, char TempCode[CODESIZE + 1], int len)
{
	if (H.node[root].lchild == -1 && H.node[root].rchild == -1)
	{
		HuffmanCodeMap.node[HuffmanCodeMap.len].data = H.node[root].data;
		strcpy(HuffmanCodeMap.node[HuffmanCodeMap.len].Bin, TempCode);
		HuffmanCodeMap.len++;
	}
	if (H.node[root].lchild != -1)
	{
		TempCode[len] = '0';
		CreatHaffmanCodeMap(H.node[root].lchild, TempCode, len + 1);
		TempCode[len] = 0;
	}
	if (H.node[root].rchild != -1)
	{
		TempCode[len] = '1';
		CreatHaffmanCodeMap(H.node[root].rchild, TempCode, len + 1);
		TempCode[len] = 0;
	}
	return;
}

// 编码
static bool Encode(char* sourcefile, char* destfile)
{
	FILE* fptrS = fopen(sourcefile, "rb");
	FILE* fptrD = fopen(destfile, "wb");
	if (fptrS == NULL || fptrD == NULL)
	{
		printf("文件名出现错误，编码失败！\n");
		if (fptrS)
			fclose(fptrS);
		if (fptrD)
			fclose(fptrD);
		return false;
	}
	fwrite(&H, sizeof(HuffmanTree), 1, fptrD);	// 存入哈夫曼树，方便后续解码
	memset(source, 0, sizeof(source));
	memset(temp, 0, sizeof(temp));
	memset(dest, 0, sizeof(dest));
	fseek(fptrS, 0, SEEK_END);
	long long count = ftell(fptrS);	// 除去EOF的所有字符
	fseek(fptrS, 0, SEEK_SET);
	while (count > 0)
	{
		int size = count > READSIZE ? READSIZE : count;
		fread(source, sizeof(char), size, fptrS);
		for (int i = 0; i < size; i++)
		{
			char ch = source[i];
			for (int j = 0; j < HuffmanCodeMap.len; j++)
				if (HuffmanCodeMap.node[j].data == ch)
				{
					strcat(temp, HuffmanCodeMap.node[j].Bin);
					break;
				}
		}
		int templen = strlen(temp), destlen = 0;
		int rev = templen % 8;
		for (int i = 0; i < templen / 8; i++)
		{
			int ch = 0;
			for (int j = 0; j < 8; j++)		// 低地址高位的二进制码==>0-255==>字符
				if (j)
					ch = ch * 2 + (temp[8 * i + j] - '0');
				else
					ch = ch * 2 - (temp[8 * i + j] - '0');
			dest[destlen++] = (char)ch;
		}
		fwrite(dest, sizeof(char), destlen, fptrD);
		count -= size;
		char copy[10];						   // 不足八位的留着下次循环补齐
		for (int i = 0; i < rev; i++)
			copy[i] = temp[templen - rev + i];
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < rev; i++)
			temp[i] = copy[i];
		memset(source, 0, sizeof(source));
		memset(dest, 0, sizeof(dest));
	}
	int rev = strlen(temp);
	if (rev)
	{
		int ch = 0;
		for (int i = rev; i < 8; i++)		// 后面应该补8-rev个'0'
			temp[i] = '0';
		for (int i = 0; i < 8; i++)
			if (i)
				ch = ch * 2 + (temp[i] - '0');
			else
				ch = ch * 2 - (temp[i] - '0');
		dest[0] = (char)ch;
		fwrite(dest, sizeof(char), 1, fptrD);
	}
	fputc((char)rev, fptrD);			  // 存储最后数位剩余的信息，多占一个字节
	printf("压缩成功！压缩文件为%s\n", destfile);
	fclose(fptrS);
	fclose(fptrD);
	return true;
}

//  解码
static bool Decode(char* sourcefile, char* destfile)
{
	FILE* fptrS = fopen(sourcefile, "rb");
	FILE* fptrD = fopen(destfile, "wb");
	if (fptrS == NULL || fptrD == NULL)
	{
		printf("文件名出现错误，解码失败！\n");
		if (fptrS)
			fclose(fptrS);
		if (fptrD)
			fclose(fptrD);
		return false;
	}
	memset(source, 0, sizeof(source));
	memset(temp, 0, sizeof(temp));
	memset(dest, 0, sizeof(dest));
	fseek(fptrS, -1, SEEK_END);       // 定位到辅助信息处，倒数顺序：EOF 辅助信息 存储的最后一位(可能只有部分有用)
	long long count = ftell(fptrS);  // count为有用信息的字节数(最后几个bit可能为无效信息)
	int rev = (int)fgetc(fptrS);	// 最后一个字节的有效比特位数
	fseek(fptrS, 0, SEEK_SET);
	fread(&H, sizeof(HuffmanTree), 1, fptrS);
	count -= ftell(fptrS);
	while (count)				  // 若feof(fptr)则count=0
	{
		int size = count > READSIZE ? READSIZE : count;
		fread(source, sizeof(char), size, fptrS);
		for (int i = 0; i < size; i++)
		{
			int ch = (unsigned char)source[i];
			char copy[10];
			memset(copy, 0, sizeof copy);
			for (int j = 7; j >= 0; j--)			//最先输出低位,低位在高地址
			{
				copy[j] = '0' + (ch % 2);
				ch = ch / 2;
			}
			strcat(temp, copy);
		}
		int templen = strlen(temp), destlen = 0;
		int index = 0;
		while (templen - index >= CODESIZE)
		{
			int root = H.len - 1;
			while (H.node[root].lchild != -1 && H.node[root].rchild != -1)
			{
				if (temp[index] == '0')
					root = H.node[root].lchild;
				else if (temp[index] == '1')
					root = H.node[root].rchild;
				index++;
			}
			dest[destlen++] = H.node[root].data;
		}
		fwrite(dest, sizeof(char), destlen, fptrD);
		count -= size;
		char copy[CODESIZE];
		for (int i = 0; i < templen - index; i++)    // 不足CODESIZE位的留着下次循环再找
			copy[i] = temp[index + i];
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < templen - index; i++)
			temp[i] = copy[i];
		memset(source, 0, sizeof(source));
		memset(dest, 0, sizeof(dest));
	}
	int templen = strlen(temp) - (8 - rev);		// 8-rev位是人工添加的‘0’，是无效信息
	int index = 0, destlen = 0;
	while (index < templen)
	{
		int root = H.len - 1;
		while (H.node[root].lchild != -1 && H.node[root].rchild != -1)
		{
			if (temp[index] == '0')
				root = H.node[root].lchild;
			else if (temp[index] == '1')
				root = H.node[root].rchild;
			index++;
		}
		dest[destlen++] = H.node[root].data;
	}
	fwrite(dest, sizeof(char), destlen, fptrD);
	printf("解压成功！解压文件为%s\n", destfile);
	fclose(fptrS);
	fclose(fptrD);
	return true;
}

//	输出哈夫曼树和哈夫曼编码匹配的信息
static void PrintMessage(void)
{
	printf("构造的哈夫曼树有%d个结点，其中叶子结点有%d个，如下所示：\n", H.len, (H.len + 1) / 2);
	printf("node\t\tdata\t\tweight\t\tlchild\t\trchild\t\tparent\n");
	for (int i = 0; i < H.len; i++)
		printf("%d\t\t%d\t\t%ld\t\t%d\t\t%d\t\t%d\n", i, i <= (H.len / 2) ? H.node[i].data : 256, H.node[i].weight, H.node[i].lchild, H.node[i].rchild, H.node[i].parent);
	printf("生成的哈夫曼编码如下：\n");
	printf("data\t\tcode\n");
	for (int i = 0; i < HuffmanCodeMap.len; i++)
		printf("%d\t\t%s\n", HuffmanCodeMap.node[i].data, HuffmanCodeMap.node[i].Bin);
	return;
}

// 清除缓冲区
static void ClearBuffer()
{
	while (getchar() != '\n');
}



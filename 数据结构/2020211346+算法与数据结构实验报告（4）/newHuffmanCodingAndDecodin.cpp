#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEAFSIZE 300                 // һ���ֽ������256��ȡֵ����256��Ҷ�ӽ�㣬LEAFSIZE��С��256����
#define TREESIZE 2 * LEAFSIZE - 1   // ��������ֻ�ж�2/0�Ľ�㣬TREESIZE = 2 * LEAFSIZE -1 
#define READSIZE 1024 			   // ÿ�δ��ļ��ж�ȡ���ֽ���	
#define CODESIZE 28				  // �����������λ��
#define NAMESIZE 128			 // �ļ������ļ�·������

// �����������
struct HuffmanNode
{
	char data; 					  // ÿ��λ����������һ���ַ����룬������λ����������Ϊһ���ַ�
	long long weight;
	int parent, lchild, rchild;
};

// ��������
struct HuffmanTree
{
	HuffmanNode node[TREESIZE - 1];
	int len;
};

// ���ݣ����ַ���Ӧ����ֵ���͹����������ƥ����
typedef struct MapNode
{
	char data;
	char Bin[CODESIZE + 1];		// ������ƴ�
};

// ���ڹ��������õ������ݺ͹����������һ����ƥ��
struct Map
{
	MapNode node[LEAFSIZE];
	int len;
};

// �ļ������д洢Դ�ļ����м��ļ���Ŀ���ļ����ֶ�ʹ��
static char source[READSIZE], temp[READSIZE * CODESIZE + CODESIZE + 8], dest[READSIZE * CODESIZE + CODESIZE + 8];

// H�ǹ���������HuffmanCodeMap���ַ��͹����������ƥ��
static HuffmanTree H;
static Map HuffmanCodeMap;

static bool Init(char* filename);		//	��ʼ�������������
static void CreatHaffmanTree(void);	 //	���������Ĺ�������	
static void SearchNode(int Range, int& pos1, int& pos2);	//	��������������Ѱ�����н����Ȩֵ��С���������
static void CreatHaffmanCodeMap(int root, char TempCode[CODESIZE + 1], int len);		//	�õ�����������ƥ��
static bool Encode(char* sourcefile, char* destfile);		 // ����
static bool Decode(char* sourcefile, char* destfile);		//  ����
static void PrintMessage(void);		//	������������͹���������ƥ�����Ϣ
static void ClearBuffer();		   //   ���������



int main(void)
{
	HuffmanCodeMap.len = 0;
	bool OK = true;	// �ж��Ƿ���ȷ�����ļ�����δ����ȷ������ֱ�ӽ�������
	char TempCode[CODESIZE + 1]; // ��CreatHaffmanCodeMap����ʱ�洢�ڸýڵ��Ӧ�ı��루�ýڵ㲻��Ҷ�ӽ����TempCode�Ͳ�����Ч���룩
	memset(TempCode, 0, sizeof(TempCode));
	char sourcefile[NAMESIZE], encodefile[NAMESIZE], decodefile[NAMESIZE];	// �����ļ����ļ������ļ�·������
	printf("��ӭʹ�ñ�ѹ������");
	while (1)
	{
		printf("\n�������ѡ�������£�\n1.ѹ���ļ�\n2.��ѹ�ļ�\n3.�˳�\n��ѡ��(1/2/3)��");
		char choice = getchar();
		ClearBuffer();
		if (choice == '1')
		{
			printf("�뽫�������ļ��ƶ����뱾����ͬĿ¼�£�������������ļ�����");
			scanf("%s", sourcefile);
			getchar();
			OK = Init(sourcefile);
			if (!OK)
				continue;
			CreatHaffmanTree();
			CreatHaffmanCodeMap(H.len - 1, TempCode, 0);
			printf("������ѹ���ļ���������%d���ַ�����", NAMESIZE);
			scanf("%s", encodefile);
			getchar();
			OK = Encode(sourcefile, encodefile);
			if (!OK)
				continue;
			PrintMessage();

		}
		else if (choice == '2')
		{
			printf("�뽫�������ļ��ƶ����뱾����ͬĿ¼�£�������������ļ�����");
			scanf("%s", sourcefile);
			getchar();
			printf("��������ѹ�ļ���������%d���ַ�����", NAMESIZE);
			scanf("%s", decodefile);
			getchar();
			OK = Decode(sourcefile, decodefile);
			if (!OK)
				continue;
		}
		else if (choice == '3')
			break;
		else
			printf("��������޷�ʵ���κι��ܣ�\n");
	}
	printf("\n�ɹ��˳�����ӭ�´�ʹ�ã�");
	return 0;
}

//	��ʼ�������������
static bool Init(char* filename)
{
	H.len = 0;
	FILE* fptr = fopen(filename, "rb");
	if (fptr == NULL)
	{
		printf("�Ҳ����������Ŀ���ļ���\n");
		return false;
	}
	fseek(fptr, 0, SEEK_END);
	long long count = ftell(fptr);	// ��ȥ��β��EOF
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

//	���������Ĺ�������	
static void CreatHaffmanTree()
{
	int count = H.len - 1; // ��������ֻ�ж�Ϊ2/0�Ľ�㣬num(d=2) = num(d=0) - 1
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

//	��������������Ѱ�����н����Ȩֵ��С���������
static void SearchNode(int Range, int& pos1, int& pos2)
{
	pos1 = -1, pos2 = -1;	//Ȩֵ��pos1Ϊ��С,pos2�ڶ�С
	for (int i = 0; i < Range; i++)
	{
		// ��˫�׵Ľ�㲻����Ϊ���ڵ㱻�ϲ�
		if (H.node[i].parent != -1)
			continue;
		// �½��Ȩֵ�����е�����С
		if (pos1 == -1 || H.node[pos1].weight > H.node[i].weight)
			pos2 = pos1, pos1 = i;
		// �½��Ȩֵ����������Ȩֵ֮��
		else if (pos2 == -1 || (H.node[pos1].weight < H.node[i].weight && H.node[i].weight < H.node[pos2].weight))
			pos2 = i;
	}
	return;
}

//	�õ�����������ƥ��
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

// ����
static bool Encode(char* sourcefile, char* destfile)
{
	FILE* fptrS = fopen(sourcefile, "rb");
	FILE* fptrD = fopen(destfile, "wb");
	if (fptrS == NULL || fptrD == NULL)
	{
		printf("�ļ������ִ��󣬱���ʧ�ܣ�\n");
		if (fptrS)
			fclose(fptrS);
		if (fptrD)
			fclose(fptrD);
		return false;
	}
	fwrite(&H, sizeof(HuffmanTree), 1, fptrD);	// ������������������������
	memset(source, 0, sizeof(source));
	memset(temp, 0, sizeof(temp));
	memset(dest, 0, sizeof(dest));
	fseek(fptrS, 0, SEEK_END);
	long long count = ftell(fptrS);	// ��ȥEOF�������ַ�
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
			for (int j = 0; j < 8; j++)		// �͵�ַ��λ�Ķ�������==>0-255==>�ַ�
				if (j)
					ch = ch * 2 + (temp[8 * i + j] - '0');
				else
					ch = ch * 2 - (temp[8 * i + j] - '0');
			dest[destlen++] = (char)ch;
		}
		fwrite(dest, sizeof(char), destlen, fptrD);
		count -= size;
		char copy[10];						   // �����λ�������´�ѭ������
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
		for (int i = rev; i < 8; i++)		// ����Ӧ�ò�8-rev��'0'
			temp[i] = '0';
		for (int i = 0; i < 8; i++)
			if (i)
				ch = ch * 2 + (temp[i] - '0');
			else
				ch = ch * 2 - (temp[i] - '0');
		dest[0] = (char)ch;
		fwrite(dest, sizeof(char), 1, fptrD);
	}
	fputc((char)rev, fptrD);			  // �洢�����λʣ�����Ϣ����ռһ���ֽ�
	printf("ѹ���ɹ���ѹ���ļ�Ϊ%s\n", destfile);
	fclose(fptrS);
	fclose(fptrD);
	return true;
}

//  ����
static bool Decode(char* sourcefile, char* destfile)
{
	FILE* fptrS = fopen(sourcefile, "rb");
	FILE* fptrD = fopen(destfile, "wb");
	if (fptrS == NULL || fptrD == NULL)
	{
		printf("�ļ������ִ��󣬽���ʧ�ܣ�\n");
		if (fptrS)
			fclose(fptrS);
		if (fptrD)
			fclose(fptrD);
		return false;
	}
	memset(source, 0, sizeof(source));
	memset(temp, 0, sizeof(temp));
	memset(dest, 0, sizeof(dest));
	fseek(fptrS, -1, SEEK_END);       // ��λ��������Ϣ��������˳��EOF ������Ϣ �洢�����һλ(����ֻ�в�������)
	long long count = ftell(fptrS);  // countΪ������Ϣ���ֽ���(��󼸸�bit����Ϊ��Ч��Ϣ)
	int rev = (int)fgetc(fptrS);	// ���һ���ֽڵ���Ч����λ��
	fseek(fptrS, 0, SEEK_SET);
	fread(&H, sizeof(HuffmanTree), 1, fptrS);
	count -= ftell(fptrS);
	while (count)				  // ��feof(fptr)��count=0
	{
		int size = count > READSIZE ? READSIZE : count;
		fread(source, sizeof(char), size, fptrS);
		for (int i = 0; i < size; i++)
		{
			int ch = (unsigned char)source[i];
			char copy[10];
			memset(copy, 0, sizeof copy);
			for (int j = 7; j >= 0; j--)			//���������λ,��λ�ڸߵ�ַ
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
		for (int i = 0; i < templen - index; i++)    // ����CODESIZEλ�������´�ѭ������
			copy[i] = temp[index + i];
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < templen - index; i++)
			temp[i] = copy[i];
		memset(source, 0, sizeof(source));
		memset(dest, 0, sizeof(dest));
	}
	int templen = strlen(temp) - (8 - rev);		// 8-revλ���˹���ӵġ�0��������Ч��Ϣ
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
	printf("��ѹ�ɹ�����ѹ�ļ�Ϊ%s\n", destfile);
	fclose(fptrS);
	fclose(fptrD);
	return true;
}

//	������������͹���������ƥ�����Ϣ
static void PrintMessage(void)
{
	printf("����Ĺ���������%d����㣬����Ҷ�ӽ����%d����������ʾ��\n", H.len, (H.len + 1) / 2);
	printf("node\t\tdata\t\tweight\t\tlchild\t\trchild\t\tparent\n");
	for (int i = 0; i < H.len; i++)
		printf("%d\t\t%d\t\t%ld\t\t%d\t\t%d\t\t%d\n", i, i <= (H.len / 2) ? H.node[i].data : 256, H.node[i].weight, H.node[i].lchild, H.node[i].rchild, H.node[i].parent);
	printf("���ɵĹ������������£�\n");
	printf("data\t\tcode\n");
	for (int i = 0; i < HuffmanCodeMap.len; i++)
		printf("%d\t\t%s\n", HuffmanCodeMap.node[i].data, HuffmanCodeMap.node[i].Bin);
	return;
}

// ���������
static void ClearBuffer()
{
	while (getchar() != '\n');
}



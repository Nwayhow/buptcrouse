#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x7fffffffffffffff
#define VertexSize 128

// �ڽӱ�ı�
struct Edge
{
	long long weight;
	int adjvex;
	Edge* nextedge;
};

//  �ڽӱ�Ķ���
struct Vertex
{
	int data;
	Edge* firstedge;
};

static long long ShortestPath[VertexSize + 1][VertexSize + 1];	// �����·�����ȣ�0ΪδѰ��/�Ի�·��Ϊ0��-1Ϊ�Ҳ����������
static bool StructGraph(Vertex*& V, int& VertexNum);				 // ����ͼ
static long long GetMaximumShortestPath(Vertex* V, int VertexNum);	// �õ��������·������
static long long DFSShortestPath(Vertex* V, int VertexNum, int st, int ed);	// ���st��ed���·������
static void Output(Vertex* V, int VertexNum, long long len);			   // �������
 


int main(void)
{
	Vertex* V = NULL;
	int VertexNum;
	if (!StructGraph(V, VertexNum))
		return 0;
	long long MaximumShoterestLength = GetMaximumShortestPath(V, VertexNum);
	Output(V, VertexNum, MaximumShoterestLength);
	return 0;
}

static bool StructGraph(Vertex*& V, int& VertexNum)
{
	printf("�����������޻�ͼ���������");
	scanf("%d", &VertexNum);
	while (VertexNum < 0)
	{
		printf("����Ƿ������������룺");
		scanf("%d", &VertexNum);
	}
	V = (Vertex*)malloc(sizeof(Vertex) * (VertexNum + 1));
	if (!V)
	{
		printf("����������࣬����ռ䲻�㣡\n");
		return false;
	}
	for (int i = 1; i <= VertexNum; i++)
		V[i].firstedge = NULL;
	printf("����������ÿ���ߣ�\n1.�㼯�и�����������Ϊ1��%d\n2.�ߵĸ�ʽΪ��ʼ�� �յ� Ȩ�ء�\n3.�ԡ�0 0 0����Ϊ��������\n���뿪ʼ��\n", VertexNum);
	int st, ed;
	long long weight;
	scanf("%d %d %lld", &st, &ed, &weight);
	while (st || ed || weight)
	{
		if (1 <= st && st <= VertexNum && 1 <= ed && ed <= VertexNum && weight > 0)
		{
			Edge* edge = (Edge*)malloc(sizeof(Edge));
			if (!edge)
			{
				printf("�������࣬����ռ䲻�㣡\n");
				return false;
			}
			edge->adjvex = ed;
			edge->weight = weight;
			edge->nextedge = V[st].firstedge;
			V[st].firstedge = edge;
		}
		else
			printf("����ı߷Ƿ������������루���������ȷ���Ա��棩��\n");
		scanf("%d %d %lld", &st, &ed, &weight);
	}
	return true;
}

static long long GetMaximumShortestPath(Vertex* V, int VertexNum)
{
	memset(ShortestPath, 0, sizeof(ShortestPath));
	long long len = -1, cmp;
	for (int i = 1; i <= VertexNum; i++)
		for (int j = 1; j <= VertexNum; j++)
		{
			if (i == j)
				continue;
			if (ShortestPath[i][j])
				cmp = ShortestPath[i][j];
			else
				cmp = DFSShortestPath(V, VertexNum, i, j);
			if (cmp != INF && len < cmp)
				len = cmp;
		}
	return len;
}

static long long DFSShortestPath(Vertex* V, int VertexNum, int st, int ed)
{
	if (st == ed)
		return 0;
	if (ShortestPath[st][ed])
		return ShortestPath[st][ed];
	long long ans = INF;
	for (Edge* edge = V[st].firstedge; edge; edge = edge->nextedge)
	{
		int pos = edge->adjvex;
		long long partlen = DFSShortestPath(V, VertexNum, pos, ed);
		if (partlen == INF)
			continue;
		else
		{
			long long templen = edge->weight + partlen;
			if (templen < ans)
				ans = templen;
		}
	}
	ShortestPath[st][ed] = ans;
	return ans;
}

static void Output(Vertex* V, int VertexNum, long long len)
{
	printf("ͼ����̾�����Զ��·������Ϊ%lld!\nʼ��\t�յ�\n", len);
	for (int i = 1; i <= VertexNum; i++)
		for (int j = 1; j <= VertexNum; j++)
		{
			if (i == j)
				continue;
			if (ShortestPath[i][j] == len)
				printf("%d\t%d\n", i, j);
		}
	return;
}


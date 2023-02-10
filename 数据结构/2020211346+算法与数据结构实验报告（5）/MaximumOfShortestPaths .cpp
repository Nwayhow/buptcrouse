#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x7fffffffffffffff
#define VertexSize 128

// 邻接表的边
struct Edge
{
	long long weight;
	int adjvex;
	Edge* nextedge;
};

//  邻接表的顶点
struct Vertex
{
	int data;
	Edge* firstedge;
};

static long long ShortestPath[VertexSize + 1][VertexSize + 1];	// 存最短路径长度，0为未寻找/自环路径为0，-1为找不到（无穷大）
static bool StructGraph(Vertex*& V, int& VertexNum);				 // 创建图
static long long GetMaximumShortestPath(Vertex* V, int VertexNum);	// 得到最大的最短路径长度
static long long DFSShortestPath(Vertex* V, int VertexNum, int st, int ed);	// 求从st到ed最短路径长度
static void Output(Vertex* V, int VertexNum, long long len);			   // 处理输出
 


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
	printf("请输入有向无环图顶点个数：");
	scanf("%d", &VertexNum);
	while (VertexNum < 0)
	{
		printf("输入非法！请重新输入：");
		scanf("%d", &VertexNum);
	}
	V = (Vertex*)malloc(sizeof(Vertex) * (VertexNum + 1));
	if (!V)
	{
		printf("顶点个数过多，分配空间不足！\n");
		return false;
	}
	for (int i = 1; i <= VertexNum; i++)
		V[i].firstedge = NULL;
	printf("请依次输入每条边：\n1.点集中各个点请命名为1到%d\n2.边的格式为“始点 终点 权重”\n3.以“0 0 0”作为结束输入\n输入开始！\n", VertexNum);
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
				printf("边数过多，分配空间不足！\n");
				return false;
			}
			edge->adjvex = ed;
			edge->weight = weight;
			edge->nextedge = V[st].firstedge;
			V[st].firstedge = edge;
		}
		else
			printf("输入的边非法！请重新输入（已输入的正确边仍保存）：\n");
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
	printf("图中最短距离最远的路径长度为%lld!\n始点\t终点\n", len);
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


#define _CRT_SECURE_NO_WARNINGS 1
#define MAX  1000
#include<stdio.h>
#include<stdlib.h>
#define TypeDate  char
typedef struct Graph
{
	TypeDate* verx;//存放顶点
	int**arc;//权值
	int verxnum, arcnum;//顶点个数，边的个数
}Graph;
//图的初始化
Graph* GraphInit(int verxnum)
{
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->verx = (TypeDate*)malloc(sizeof(TypeDate) * verxnum);
	G->arc = (int**)malloc(sizeof(int*) * verxnum);
	for (int i = 0; i < verxnum; i++)
	{
		G->arc[i] =(int*) malloc(sizeof(int) * verxnum);
	}
	G->verxnum = verxnum;
	G->arcnum = 0;
	return G;
}
//图的创建
void GraphCreate(Graph* G, TypeDate* verx, int(* arc)[4])
{
	for (int i = 0; i < G->verxnum; i++)
	{
		G->verx[i] = verx[i];
		for (int j = 0; j < G->verxnum; j++)
		{
			G->arc[i][j] = arc[i][j];//*(*(p+i)+j),*(p+i*G->verxnum+j)
			if (G->arc[i][j] != 0&& G->arc[i][j]!=2222225)
			{
				G->arcnum++;
			}
		}
	}
	G->arcnum /= 2;
}
//图的遍历
void DFS(Graph* G, int* visted, int index)
{
	printf("%c", G->verx[index]);
	visted[index] = 1;
	for (int i = 0; i < G->verxnum; i++)
	{
		if (G->arc[index][i] == 1 && !visted[i])
			DFS(G, visted, i);
	}
}
typedef struct shortEage
{
	int adjves;//存放邻接点
	int lowcast;//存放最小路径
}Eage;

int minEage(Eage* s, int verxnum)//再shortEage数组里面找最小的权
{
	int k=1;
	int i = 1;
	int min = 2222225;
	for (i; i < verxnum; i++)
	{
		if (min > s[i].lowcast && s[i].lowcast !=0)
		{
			min = s[i].lowcast;
			k = i;
		}
	}
	return k;
}
void outputMST(Eage* s, int k,TypeDate*verxs)
{
	printf("(%c,%c)%d", verxs[s[k].adjves], verxs[k], s[k].lowcast);
}
void Prime(Graph* G, int start,TypeDate*verxs)
{
    Eage shortEage[MAX];
	int i;
	for ( i= 0; i < G->verxnum; i++)
	{
		shortEage[i].lowcast = G->arc[start][i];
		shortEage[i].adjves = start;
	}
	shortEage[start].lowcast = 0;
	int all = 0;
	for (i = 0; i < G->verxnum - 1; i++)
	{
		int k = minEage(shortEage,G->verxnum);
		outputMST(shortEage, k,verxs);
		all += shortEage[k].lowcast;
		shortEage[k].lowcast = 0;
		for (int j = 0; j < G->verxnum; j++)
		{
			if (G->arc[k][j] < shortEage[j].lowcast && G->arc[k][j]!=0)
			{
				shortEage[j].lowcast = G->arc[k][j];
				shortEage[j].adjves = k;
			}
		}
	}
	printf(" %d", all);
}
int main()
{
	int verx = 4;
	Graph* G = GraphInit(verx);
	TypeDate verxs[4] = { 'a','b','c','d' };
	int arc[4][4] = { {0, 8, 2222225, 12},
				  {8, 0, 15, 16},
				  {2222225, 15, 0, 2222225},
				  {12, 16, 2222225, 0} };
	GraphCreate(G,verxs,arc);
	Prime(G, 0,verxs);
	return 0;
}

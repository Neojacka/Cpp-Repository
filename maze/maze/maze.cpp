#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef struct path
{
	int x;
	int y;
}PT;
typedef PT StackDate;
typedef struct StackNode
{
	StackDate * a;
    int capacity;
	int top;
}Stack;
void StackInit(Stack* st)
{
	st->a = NULL;
	st->top = st->capacity = 0;
}
void StackPush(Stack* st, StackDate x)
{
	assert(st);
	if (st->capacity == st->top)
	{
		int newcapacity = st->capacity == 0 ? 4 : st->capacity * 2;
		StackDate* tmp = (StackDate*)realloc(st->a, sizeof(StackDate) * newcapacity);
		if (tmp == NULL)
		{
			return;
		}
		else
		{
			st->a = tmp;
			st->capacity = newcapacity;
		}
	}
	st->a[st->top++] = x;
}
void StackPop(Stack* st)
{
	assert(st);
	assert(st->top > 0);
	st->top--;
}
StackDate StackTop(Stack* st)
{
	assert(st);
	StackDate top = st->a[st->top-1];
	return top;
}
void StackDestory(Stack* st)
{
	assert(st);
	free(st->a);
	st->top = 0;
	st->capacity = 0;
}
bool StackEmpty(Stack* st)
{
	assert(st);
	return st->top == 0;
}
Stack path;
void Printpath(Stack* path)
{
	Stack rpath;
	StackInit(&rpath);
	//先把路径反转存储
	while (!StackEmpty(path))
	{
		StackPush(&rpath, StackTop(path));
		StackPop(path);
	}
	//打印路径
	while (!StackEmpty(&rpath))
	{
		StackDate cur = StackTop(&rpath);
		printf("(%d,%d)\n", cur.x, cur.y);
		StackPop(&rpath);
	}
	StackDestory(&rpath);
}
bool Ispass(int** maze, int N, int M, PT cul)
{
	if (cul.x >= 0 && cul.x < N && cul.y >= 0 && cul.y < M && maze[cul.x][cul.y] == 0)
		return true;
	else
		return false;
}
bool Getmazepath(int** maze, int N, int M, PT cul)
{
	StackPush(&path, cul);
	if (cul.x == N - 1 && cul.y == M - 1)
		return true;
	PT next;
	//标记找过的路径
	maze[cul.x][cul.y] = 2;
	//四个方向探索
	//向上探索
	next = cul;
	next.x -= 1;
	if (Ispass(maze, N, M, next))
	{
		//如果一个方向可以则其他方向不要探索
		if(Getmazepath(maze,N,M,next))
			return true;
	}
	//向下探索
	next = cul;
	next.x += 1;
	if (Ispass(maze, N, M, next))
	{
		if (Getmazepath(maze, N, M, next))
			return true;
	}
	//向左探索
	next = cul;
	next.y -= 1;
	if (Ispass(maze, N, M, next))
	{
		if (Getmazepath(maze, N, M, next))
			return true;
	}
	//向右探索
	next = cul;
	next.y += 1;
	if (Ispass(maze, N, M, next))
	{
		if (Getmazepath(maze, N, M, next))
			return true;
	}
	//四个方向都不行
	StackPop(&path);
	return false;
}
int main()
{
	int N, M,i;
	while (scanf("%d %d", &N, &M) != EOF)
  {
	//创建动态二维数组
	int** maze = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
	{
		maze[i] = (int*)malloc(sizeof(int) * M);
	}
	//导入迷宫
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < M; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}
	StackInit(&path);
	PT inter = { 0,0 };
	if (Getmazepath(maze, N, M, inter))
		Printpath(&path);
	else
		printf("NOT Find");
	StackDestory(&path);
	//销毁动态二维数组
	for (i = 0; i < N; i++)
	{
		free(maze[i]);
		maze[i] = NULL;
	}
	free(maze);
	maze = NULL;
   }

	return 0;
}
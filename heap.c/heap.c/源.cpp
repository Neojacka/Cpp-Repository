#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//升序建大堆
//降序建小堆
typedef struct heap
{
	int* a;
	int size;
	int capacity;
}heap;
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//向下探索法
void heapdown(int* a, int n, int root)
{
	int partent = root;
	int child = partent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[partent])
		{
			swap(&a[child], &a[partent]);
			partent = child;
			child = partent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void heapsort(int* a, int n)
{
	//建堆
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		heapdown(a, n, i);
	}
	//排序
	int end = n - 1;
	while (end >= 0)
	{
		swap(&a[0], &a[end]);
		//再继续选次小
		heapdown(a, end, 0);
		end--;
	}
}
//向上探索法
void heapup(int* a, int sz, int child)
{
	int partent = (child - 1) / 2;
	while (partent >= 0)
	{
		if (a[child] < a[partent])
		{
			swap(&a[child], &a[partent]);
			child = partent;
			partent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void heapInit(heap*p,int* a, int n)
{
	p->a = (int*)malloc(sizeof(a[0]) * n);
	memcpy(p->a, a, sizeof(a[0]) * n);
	p->size = n;
	p->capacity = 0;
	//建堆
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		heapdown(p->a,p->size, i);
	}
	int end = n - 1;
	while (end >= 0)
	{
		swap(&a[0], &a[end]);
		//再继续选次小
		heapdown(a, end, 0);
		end--;
	}
}
//进堆
void heappush(heap* p, int x)
{
	if (p->size == p->capacity)
	{
		p->capacity *= 2;
		int* tmp = (int*)realloc(p->a,sizeof(int)*p->capacity);
		 p->a = tmp;
	}
	p->a[p->size++] = x;
	heapup(p->a, p->size, p->size - 1);
}
//出堆
void heappop(heap* p)
{
	swap(&p->a[p->size - 1], &p->a[0]);
	p->size--;
	heapdown(p->a, p->size, 0);
}
int heaptop(heap* php)
{
	assert(php);
	assert(php->a > 0);
	return php->a[0];
}
//销毁堆
void heapdestory(heap* php)
{
	free(php->a);
	php->capacity;
	php->a = NULL;
	php->capacity = php->size = 0;

}
int main()
{
	int arr[] = { 12,43,634,74,14,64,1,5,8,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	heap hp;
	heapsort(arr, sz);
	//heapInit(&hp,arr,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
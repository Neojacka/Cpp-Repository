#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//��������
void insertsort(int* a, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
//ϣ������O(n^1.3~n^2)
void shellsort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap % 3 + 1;//��֤�����gapһ����1
		//gap=1���ǲ�������
		int i;
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//ѡ������O(n^2)
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void selectsort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		//������[begin��end]����С���
		int maxi, mini,i;
		maxi = mini = begin;
		for (i = begin + 1; i <= end ; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&a[end], &a[maxi]);
        begin++;
		end--;
	}
}
//������
void adjust(int* a, int n, int root)
{
	int partent = root;
	int child = 2 * partent + 1;
	while (child < n)
	{
		if (child+1<n && a[child + 1] >a[child])
		{
			child++;
		}
		if (a[child] > a[partent])
		{
			swap(&a[child], &a[partent]);
			partent = child;
			child = 2 * partent + 1;
		}
		else
		{
			break;
		}
	}
}
void heapsort(int* a, int n)
{
	int i;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		adjust(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[end], &a[0]);
		adjust(a, end, 0);
		end--;
	}
}
//ð������
void bubble(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int i;
		int exchage = 0;
		for (i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i - 1], &a[i]);
				exchage = 1;
			}
		}
		if (exchage == 0)
		{
			break;
		}
		end--;
	}
}
//������
//����ָ�뷨
int partsort1(int* a, int begin, int end)
{
	int king = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= a[king])
		{
			begin++;
		}
		while (begin<end && a[end]>=a[king])
		{
			end--;
		}
		swap(&a[begin], &a[end]);
	}
	swap(&a[begin], &a[king]);
	return begin;
}
//�ڿӷ�
int partsort2(int* a, int begin, int end)
{
	//�ڿ�
	//�ӵ�λ�þ���˵����λ�õ�ֵ�������ˣ����Ա�����
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//����ҵ���key�������beginλ���γ��µĿ�
		a[end] = a[begin];
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//�ұ��ҵ���keyС������endλ���γ��µĿ�
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}
//����ָ��
int partsort3(int* a, int begin, int end)
{
	//��һ����׼
	int key = end;
    //pre�൱��С��ͷ
	int pre = begin - 1;
	//cur�൱�ڴ��ͷ
	int cur = begin;
	//���ͷ������ǰ��
	while (cur<end)
	{
		if (a[cur] < a[key] && ++pre != cur)
		{
			//�ҵ�С�𳵲��ֽ�����С�𳵵�ͷ
			swap(&a[pre], &a[cur]);
		}
		cur++;
	}
	//�ָ�
	swap(&a[++pre], &a[key]);
	return pre;
}
void quicksort(int* a, int begin, int right)
{
	if (begin >= right)
		return;
	int div = partsort2(a, begin, right);
	quicksort(a, begin, div - 1);
	quicksort(a, div + 1, right);
}
//�鲢����
//�ݹ�д��
void mergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int i = begin1;
	int begin = begin1, end = end2;
	while (begin1 <=end1 && begin2 <=end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1) 
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (i = begin; i<= end; i++)
	{
		a[i] = tmp[i];
	}
}
void _merge(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_merge(a, begin, mid, tmp);
	_merge(a, mid + 1, end, tmp);
	//�鲢[begin,mid]��[mid+1,end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (i = begin; i <= end; i++)
	{
		a[i] = tmp[i];
	}

}
void mergesort1(int* a, int n)
{
	
	int* tmp = (int*)malloc(sizeof(int) * n);
	_merge(a, 0, n-1, tmp);
	free(tmp);
}
void mergesort2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);  
	int gap = 1;
	while (gap < n)
	{
		int i;
		for (i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i,  end1 = i + gap - 1;
			int begin2 = i + gap,  end2 = i + 2 * gap - 1;
			//���ֻ��һ��Ͳ���Ҫ�ϲ�
			if (begin2 >= n)
			{
				break;
			}
			//����ϲ�ʱ�ڶ���Խ��
			if (end2 >= n)
			{
				end2 =n- 1;
			}
			mergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
	free(tmp);
}
void printfArr(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	int a[] = { 9,2,42,3,51,51,75,37,28,67,127,28,163,73,0,39,10 };
	int sz = sizeof(a) / sizeof(a[0]);
	heapsort(a,sz);
	printfArr(a, sz);

}
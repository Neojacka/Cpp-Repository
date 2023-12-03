#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void getnext(char* sub, int* next, int len)
{
	//sub的前两个元素对应的k必然为这两个
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int k=0;//当前一项的k
	//前两个元素已经确定了k，只需要从第三个元素开始
	while (i < len)
	{
		//根据p[i]=p[k]->p[i+1]=k+1;(i与k对应，然而在这里我们的i是后一个元素
		//0  1  2  3   4(i)
		//a  b  a  a   b
 // next[]-1 0  0 k(1) ?
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];//回退
		}
	}
}
int KMP(char* str, char* sub, int lenstr, int lensub, int pos)
{
	assert(str && sub);
	if (pos < 0|| pos>lenstr)
		return -1;
	if (lensub == 0 || lenstr==0)
		return -1;
	int* next = (int*)malloc(sizeof(int) * lensub);
	getnext(sub, next,lensub);
    int i = pos;//主串开始的位置
	int j = 0;
	
	while (i < lenstr && j < lensub)
	{
		if (j == -1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j >= lensub)
		return i - j;
	return -1;
}
int main()
{
	char str[] = "abcabdabcdab";
	char sub[] = "bdab";
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	int pos = KMP(str, sub, lenstr, lensub, 0);
	printf("%d", pos);
	return 0;

}
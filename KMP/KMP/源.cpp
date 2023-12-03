#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void getnext(char* sub, int* next, int len)
{
	//sub��ǰ����Ԫ�ض�Ӧ��k��ȻΪ������
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int k=0;//��ǰһ���k
	//ǰ����Ԫ���Ѿ�ȷ����k��ֻ��Ҫ�ӵ�����Ԫ�ؿ�ʼ
	while (i < len)
	{
		//����p[i]=p[k]->p[i+1]=k+1;(i��k��Ӧ��Ȼ�����������ǵ�i�Ǻ�һ��Ԫ��
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
			k = next[k];//����
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
    int i = pos;//������ʼ��λ��
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
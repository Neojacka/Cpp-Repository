#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include <stdio.h>
//#include <math.h>
//#define PI 3.1415926535897932384626
//int main() 
//{
//    int n = 0;
//    scanf("%d", &n);
//    double ret, k;
//    ret = sin(n * PI / 180); // 将角度转换为弧度
//    k = cos(n * PI / 180);
//    printf("%.2lf %.2lf", ret, k);
//    return 0;
//}
//#include<stdio.h>
//int main() {
//    int startHour, startMinute, endHour, endMinute;
//    scanf("%d %d %d %d", &startHour, &startMinute, &endHour, &endMinute);
//    int startTime = startHour * 60 + startMinute; // 将开始训练的时间转换为分钟表示
//    int endTime = endHour * 60 + endMinute; // 将结束训练的时间转换为分钟表示
//    int totalMinutes = endTime - startTime; // 计算训练的总时间（单位为分钟）
//    int hours = totalMinutes / 60; // 提取小时部分
//    int minutes = totalMinutes % 60; // 提取分钟部分
//    printf("%d时%d分\n", hours, minutes); // 输出结果
//    return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//    char months[12][10] = { "January", "February", "March", "April", "May", "June",
//                           "July", "August", "September", "October", "November", "December" };
//    int num;
//    int ret;
//
//    while ((ret = scanf("%d", &num)) == 1 && num >= 1 && num <= 12)
//    {
//        printf("%s\n", months[num - 1]);
//    }
//
//    return 0;
//}
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int* Arrcount = (int*)malloc(sizeof(int) * 1000);
//	memset(Arrcount, 0, sizeof(int)*1000);
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		int num;
//		scanf("%d", &num);
//		Arrcount[num]++;
//	}
//	for (i = 0; i <=1000; i++)
//	{
//		if (Arrcount[i] >= 2)
//		{
//			printf("%d\n", i);
//		}
//	}
//	free(Arrcount);
//	Arrcount = NULL;
//	return 0;
//}
//int main()
//{
//	int i,n;
//	float all=0,score,grades,regrades;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%f %f %f", &score, &grades, &regrades);
//		if (grades >= 60 || regrades >= 60)
//		{
//			all += score;
//		}
//	}
//	printf("%.1f", all);
//	return 0;
//}
//#include<stdio.h>
//typedef struct students
//{
//	char num[100];
//	char name[100];
//	float grades[3];
//}students;
//void input(students* s, int N)
//{
//	int i;
//	for (i = 0; i < N; i++)
//	{
//		scanf("%s %s %f %f %f", &s[i].num, &s[i].name, &s[i].grades[0], 
//			&s[i].grades[1], &s[i].grades[2]);
//	}
//}
//void print(students* s, int N) 
//{
//	int i;
//	for (i = 0; i < N; i++)
//	{
//		printf("%s %s %.1f %.1f %.1f", s[i].num, s[1].name, s[i].grades[0], s[i].grades[1], s[i].grades[2]);
//	}
//}
//int main()
//{
//	students student[100];
//	int N;
//	scanf("%d", &N);
//	input(student,N);
//	print(student, N);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct Students
//{
//	char num[1000];
//	char name[1000];
//	float grades;
//}Students;
//typedef struct List
//{
//	Students student;
//	struct List* next;
//}List;
//List*  input(int n,List**head)
//{
//	if (n == 0)
//	{
//		return NULL;
//	}
//
//	while (n)
//	{
//		List* newnode = (List*)malloc(sizeof(List));
//		scanf("%s %s %f", &newnode->student.num,
//			&newnode->student.name, &newnode->student.grades);
//		newnode->next = NULL;
//
//		if (*head == NULL)
//		{
//			*head = newnode;
//		}
//		else
//		{
//			if ( strcmp((*head)->student.num ,newnode->student.num)>0)
//			{
//				newnode->next = *head;
//				*head = newnode;
//			}
//			else
//			{
//			  List* pre = *head;
//			  while (pre->next != NULL && strcmp(pre->next->student.num , newnode->student.num)<0)
//			  {
//				pre = pre->next;
//			  }
//			  newnode->next = pre->next;
//			  pre->next = newnode;
//			}
//		}
//		n--;
//	}
//	return *head;
//}
//
//void print(List* s1, List* s2)
//{
//	List* cur1 = s1;
//	List* cur2 = s2;
//	List* next1= NULL;
//	List* next2 = NULL;
//	while (cur1 != NULL && cur2 != NULL)
//	{
//		next1 = cur1->next;
//		next2 = cur2->next;
//		if (strcmp(cur1->student.num,cur2->student.num)<0)
//		{
//			printf("%s %s %.1f\n", cur1->student.num, cur1->student.name, cur1->student.grades);
//			cur1=next1;
//		}
//		else
//		{
//			printf("%s %s %.1f\n", cur2->student.num, cur2->student.name, cur2->student.grades);
//			cur2=next2;
//		}
//	}
//	while (cur1)
//	{
//		next1 = cur1->next;
//		printf("%s %s %.1f\n", cur1->student.num, cur1->student.name, cur1->student.grades);
//		cur1=next1;
//	}
//	while (cur2)
//	{
//		next2 = cur2->next;
//		printf("%s %s %.1f\n", cur2->student.num, cur2->student.name, cur2->student.grades);
//		cur2=next2;
//	}
//
//}
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	List* head1 = NULL;
//	List* head2 = NULL;
//	List* s1 = input(n,&head1);
//	List* s2 = input(m,&head2);
//	print(s1, s2);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//typedef struct Qlist
//{
//	int* a;
//	int head;
//	int tail;
//	int k;
//}Qlist;
//void QlistInit(Qlist* qu, int n)
//{
//	qu->a = (int*)malloc(sizeof(int) * (n + 1));
//	qu->head = qu->tail = 0;
//	qu->k = n;
//}
//bool QlistEmpty(Qlist* qu)
//{
//	return qu->head == qu->tail;
//}
//bool QlistFull(Qlist* qu)
//{
//	return (qu->tail + 1)%(qu->k+1) == qu->head;
//}
//void QlistPush(Qlist* qu, int x)
//{
//	if (QlistFull(qu))
//	{
//		return;
//	}
//	qu->a[qu->tail] = x;
//	qu->tail++;
//	qu->tail %= (qu->k + 1);
//}
//int QlistPop(Qlist* qu)
//{
//	if (QlistEmpty(qu))
//	{
//		return false;
//	}
//	int top = qu->a[qu->head++];
//	qu->head %= (qu->k + 1);
//	return top;
//}
//void QlistDestory(Qlist* qu)
//{
//	free(qu->a);
//	qu->a = NULL;
//	qu->head = qu->tail = qu->k = 0;
//}
//
//int main()
//{
//	int i, n, m;
//	scanf("%d", &n);
//	int count = 0;
//	Qlist qu;
//	QlistInit(&qu, n);
//	char ch[4] = { '甲','乙','丙','丁' };
//	for (i = 0; i <4; i++)
//	{
//		QlistPush(&qu, ch[i]);
//	}
//	while (n)
//	{
//		count++;
//		if (count%10 !=7 && count%7 !=0)
//		{
//			QlistPush(&qu, QlistPop(&qu));
//		}
//		else
//		{
//			
//		}
//
//	}
//	printf("%d", QlistPop(&qu));
//	QlistDestory(&qu);
//	return 0;
//}
#include<stdio.h>
//typedef struct Students
//{
//	char num[1000];
//	char name[1000];
//	float Chinese;
//	float Math;
//	float English;
//}Students;
//int main()
//{
//	int N,i,j;
//	Students st[1000];
//	float Cave = 0, Mave = 0, Eave = 0;
//	float max_source;
//	float sum[1000];
//	scanf("%d", &N);
//	for (i = 0; i < N; i++)
//	{
//		scanf("%s %s %f %f %f", st[i].num, st[i].name, 
//			&st[i].Chinese, &st[i].Math, &st[i].English);
//		Cave += st[i].Chinese;
//		Mave += st[i].Math;
//		Eave += st[i].English;
//		sum[i]  += st[i].Chinese + st[i].Math + st[i].English;
//	}
//	max_source = sum[0];
//	j = 0;
//	for (i = 1; i < N; i++)
//	{
//		if (sum[i] > max_source)
//		{
//			max_source = sum[i];
//			j = i;
//		}
//	}
//	printf("Chinese Average:%.1f\n", Cave/N);
//	printf("Math Average:%.1f\n", Mave / N);
//	printf("English Average:%.1f\n", Eave / N);
//	printf("Student with highest total score:%s %s %.1f %.1f %.1f", st[j].num, st[j].name,
//		st[j].Chinese, st[j].Math, st[j].English);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct students
//{
//	int id;
//	char name[22];
//	int source[100];
//	int sum;
//}students;
//int cmp(const void* e1, const void* e2)
//{
//	students* s1 = (students*)e1;
//	students* s2 = (students*)e2;
//	if (s2->sum != s1->sum)
//		return s2->sum - s1->sum;
//	else
//		return s1->id - s2->id;
//}
//int main()
//{
//	int n, i, j, m;
//
//	scanf("%d %d", &n, &m);
//	students* student = (students*)malloc(sizeof(students) * n);
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d %s", &student[i].id, &student[i].name);
//		student[i].sum = 0;   // 初始化sum值
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &student[i].source[j]);
//			student[i].sum += student[i].source[j];
//		}
//	}
//
//	qsort(student, n, sizeof(students), cmp);
//	int rank = 1;
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%d %s ", student[i].id, student[i].name);
//		for (j = 0; j < m; j++)
//		{
//			printf("%d ", student[i].source[j]);
//		}
//		printf("sum = %d ", student[i].sum);
//
//		if (i > 0 && student[i].sum < student[i - 1].sum)  // 判断前面是否有学生的分数高
//		{
//			rank = i + 1; // 学生名次更新
//		}
//		printf("ranking = %d\n", rank);
//	}
//
//	free(student);  // 释放动态分配的内存
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e2 - *(int*)e1;
//}
//int main()
//
//{
//	int n;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	int i;
//	int max = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (max <arr[i])
//		{
//			max = arr[i];
//		}
//	}
//    int* Arrcount = (int*)malloc(sizeof(int) *max);
//    memset(Arrcount, 0, sizeof(int) * max);
//    for (i = 0; i < n; i++)
//	{
//		Arrcount[arr[i]-1]++;
//	}
//	int maxi = 0;
//	for (i = 0; i < max; i++)
//	{
//		if (Arrcount[i] >= maxi)
//		{
//			maxi = Arrcount[i];
//		}
//	}
//	for (i = 0; i < max; i++)
//	{
//		if (Arrcount[i] == maxi)
//		{
//			printf("%d\n",i+1);
//		}
//	}
//	
//	free(Arrcount);
//	free(arr);
//	arr = NULL;
//	Arrcount = NULL;
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int contain7(int n) 
//{
//    while (n != 0) 
//    {
//        if (n % 10 == 7) 
//        {
//            return 1;
//        }
//        n /= 10;
//    }
//    return 0;
//}
//
//int main()
//{
//    char st[4][10] = { "甲","乙","丙","丁" };
//    long long int n;
//    long long int j = 1, i = 0, count = 0;
//    scanf("%lld", &n);
//    long long int* arrcount = (long long int*)malloc(sizeof(long long int) * 4);
//    memset(arrcount, 0, sizeof(long long int) * 4);
//    while (count < n)
//    {
//        i %= 4;
//        if (j % 7 == 0 || contain7(j))
//        {
//            arrcount[i]++;
//        }
//        else
//            count++;
//        j++;
//        i++;
//    }
//    for (i = 0; i < 4; i++)
//    {
//        printf("%s:%lld\n", st[i], arrcount[i]);
//    }
//    free(arrcount); // 记得释放动态分配的内存
//    return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int cmp(const void* e1, const void* e2) 
//{
//    return strcmp((char*)e1, (char*)e2);
//}
//int main() {
//    //二维数组存字符串 
//    char str_arr[3][100];
//    int i;
//    for (i = 0; i < 3; i++) {
//        fgets(str_arr[i], 100, stdin);
//        int len = strlen(str_arr[i]);
//        if (str_arr[i][len - 1] == '\n') 
//            str_arr[i][len - 1] = '\0'; // 删除换行符
//    }
//    qsort(str_arr, 3, sizeof(str_arr[0]), cmp);
//
//    for (i = 0; i < 3; i++) 
//    {
//        printf("%s\n", str_arr[i]);
//    }
//
//    return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int cmp(const void* e1, const void* e2)
//{
//	return (*(int*)e2 - *(int*)e1);
//}
//int main()
//{
//	int arr[3];
//	int i;
//	for (i = 0; i < 3; i++)
//
//	{
//		scanf("%d", &arr[i]);
//	}
//	char str[4];
//	scanf("%s", str);
//	qsort(arr, 3, sizeof(arr[0]), cmp);
//	if (strcmp(str, "ABC") == 0)
//
//	{
//		for (i = 2; i >= 0; i--)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	else if (strcmp(str, "CAB") == 0)
//	{
//		int tmp = arr[1];
//		arr[1] = arr[2];
//		arr[2] = tmp;
//		for (i = 0; i < 3; i++)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//void find(char* p, int n)
//{
//    if (p == NULL)
//        return;
//    for (int i = 0; i < n; i++)
//    {
//        int j;
//        for (j = 0; j < n; j++)
//        {
//            if (i != j && p[i] == p[j])
//            {
//                break;
//            }
//        }
//        if (j == n)
//        {
//            printf("%c", p[i]);
//            return;
//        }
//    }
//    printf("no");
//}
//int main()
//{
//    char str[1000000];
//    scanf("%s", str);
//    int len = strlen(str);
//    find(str, len);
//    return 0;
//}
//void removeDuplicates(int* nums, int numsSize) 
//{
//    int i = 0;
//    int j = 0, count = 0;
//    while (j < numsSize)
//    {
//        if (nums[i] == nums[j] && j < numsSize)
//        {
//            j++;
//            count++;
//        }
//        else
//        {
//            if (count > 2)
//            {
//                i += 2;
//                nums[i] = nums[j];
//            }
//            else
//            {
//                i += count;
//                nums[i] = nums[j];
//                
//            }
//            count = 0;
//        }
//    }
//   /* return i + 1;*/
//}
//int main()
//{
//    int arr[] = { 0,0,1,1,1,1,2,3,3 };
//    removeDuplicates(arr, sizeof(arr));
//}
//double Findmid(int* arr, int n)
//{
//    if (n % 2 != 0)
//    {
//        return arr[n / 2];
//    }
//    else
//        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
//}
//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//    int i = 0, j = 0, m = 0;
//    int arr[1000];
//    while (i < nums1Size && nums2Size)
//    {
//        if (nums1[i] < nums2[j])
//        {
//            arr[m++] = nums1[i++];
//        }
//        else
//        {
//            arr[m++] = nums2[j++];
//        }
//    }
//    while (i < nums1Size)
//    {
//        arr[m++] = nums1[i++];
//    }
//    while (j < nums2Size)
//    {
//        arr[m++] = nums2[j++];
//    }
//    double mid = Findmid(arr, m);
//    return mid;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("***********************************\n");
//	printf("****1.开始游戏*******0.退出游戏****\n");
//	printf("***********************************\n");
//}
//void game()
//{
//	int num = rand() % 100;
//	int input;
//	int n = 3;
//    printf("游戏开始\n");
//	while (n--)
//	{
//		printf("请输入数字>:");
//       scanf("%d", &input);
//	   if (input < num)
//	   {
//		   printf("猜小了\n");
//	   }
//	   else if (input > num)
//	   {
//		   printf("猜大了\n");
//	   }
//	   else
//	   {
//		   printf("恭喜你猜对了\n");
//		   break;
//	   }
//	}
//	
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//    int input;
//	do 
//	{
//		menu();
//		printf("请选择>:");
//	    scanf("%d", &input);
//	    switch (input)
//	    {
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//	    }
//	} while (input);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d*%d=%2d", i,j,i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b, r;
//	scanf("%d %d", &a, &b);
//	while (r = a % b)
//	{
//		a = b;
//		b = r;
//	}
//	printf("%d", b);
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int isprime(int i)
//{
//	for (int j = 2; j <= sqrt(i); j++)
//	{
//		if (i % j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int count = 0;
//	for (int i = 100; i <= 200; i++)
//	{
//		if (isprime(i))
//		{
//			printf("%d ",i);
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < n - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (i + 1) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
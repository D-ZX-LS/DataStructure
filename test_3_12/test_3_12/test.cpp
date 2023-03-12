#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>

//快速排序
//hoare版本(左右指针法)
//void swap_int(int* a, int* b)
//{
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
// 
//void Quick_Sort(int* arr,int begin,int end)
//{
//	//递归结束条件
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int left = begin;
//	int right = end;
//	//选左边为pivot
//	int pivot = arr[left];
//	while (left < right)
//	{
//		//右指针先走，找比pivot小的数
//		while (arr[right] >= pivot && left < right)
//		{
//			right--;
//		}
//		//左指针找比pivot大的数
//		while (arr[left] <= pivot && left < right)
//		{
//			left++;
//		}
//		if (left < right)
//		{
//			swap_int(&arr[left], &arr[right]);
//		}
//	}
//	swap_int(&arr[begin], &arr[right]);
//	//左子序列递归排序
//	Quick_Sort(arr, begin, right - 1);
//	//右子序列递归排序
//	Quick_Sort(arr, left+1, end);
//}


//挖坑法(递归版本)
//void swap_int(int* a, int* b)
//{
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void Quick_Sort(int* arr,int begin,int end)
//{
//	//递归结束条件
//	if (begin >= end)
//	{
//		return;
//	}
//	//保留坑位的值
//	int pivot = arr[begin];
//
//	int left = begin;
//	int right = end;
//	while (left < right)
//	{
//		//left为坑位，右指针找比pivot小的数
//		while (arr[right] >= pivot && left < right)
//		{
//			right--;
//		}
//		//交换坑位
//		swap_int(&arr[left], &arr[right]);
//
//		//right为坑位，左指针找比pivot大的数
//		while (arr[left] <= pivot && left < right)
//		{
//			left++;
//		}
//		//交换坑位
//		swap_int(&arr[left], &arr[right]);
//	}
//	//将pivot放入坑位中
//	arr[right] = pivot;
//
//	//递归
//	Quick_Sort(arr,begin, right - 1);
//	Quick_Sort(arr, left + 1, end);
//}


//快慢指针法(实际上是下标)
//void swap_int(int* a, int* b)
//{
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void Quick_Sort(int* arr, int begin, int end)
//{
//	//递归结束条件
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int pivot = arr[begin];
//	//定义快慢指针(实际上是下标)
//	int slow = begin;//slow记录的是可交换位置的前一个
//	int fast = begin + 1;
//
//	while (fast <= end)
//	{
//		if (arr[fast] < pivot)
//		{
//			slow++;//slow先++，跳到可交换位置
//			swap_int(&arr[fast], &arr[slow]);
//		}
//		fast++;
//	}
//	//交换arr[slow]和arr[begin]
//	swap_int(&arr[slow], &arr[begin]);
//
//	//递归
//	Quick_Sort(arr, begin, slow - 1);
//	Quick_Sort(arr, slow + 1,end);
//}


#include<assert.h>

//非递归版本(借助栈来实现)
//单趟排序
//可以使用上面三种方法(hoare,挖坑法，快慢指针法)的任意一种改造，返回pivot元素的下标
//这里用hoare

//void swap_int(int* a, int* b)
//{
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int PartSort(int* arr, int begin, int end)
//{
//	int left = begin;
//	int right = end;
//
//	int pivot = begin;
//
//	while (left < right)
//	{
//		while (arr[right] >= arr[pivot]&& left < right)
//		{
//			right--;
//		}
//
//		while (arr[left] <= arr[pivot] && left < right)
//		{
//			left++;
//		}
//
//		if (left < right)
//		{
//			swap_int(&arr[left], &arr[right]);
//		}
//	} 
//	swap_int(&arr[right], &arr[pivot]);
//	
//	return right;
//}
//
//typedef struct stack
//{
//	int* stack;
//	int size;
//	int capacity;
//}Stack;
//
//void StackInit(Stack* ps)
//{
//	assert(ps);
//
//	ps->stack = NULL;
//	ps->size = ps->capacity = 0;
//}
//
//void CheckCapacity(Stack* ps)
//{
//	assert(ps);
//
//	if (ps->size == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 20 : 4 * ps->capacity;
//		int* ptmp = (int*)realloc(ps->stack, newcapacity * sizeof(int));
//		if (ptmp == NULL)
//		{
//			printf("realloc failed");
//			exit(-1);
//		}
//		ps->stack = ptmp;
//		ps->capacity = newcapacity;
//	}
//}
//
//void StackPush(Stack* ps,int x)
//{
//	assert(ps);
//	assert(ps->stack);
//
//	CheckCapacity(ps);
//	ps->stack[ps->size] = x;
//	ps->size++;
//}
//
//int StackPop(Stack* ps)
//{
//	assert(ps);
//	assert(ps->stack);
//	assert(ps->size > 0);
//
//	ps->size--;
//	int top = ps->stack[ps->size];
//
//	return top;
//}
//
////借助栈实现非递归版本(此处使用C语言实现栈)
//void Quick_Sort(int* arr, int begin, int end)
//{
//	//建立栈
//	Stack s1;
//	//初始化
//	StackInit(&s1);
//	//检测容量
//	CheckCapacity(&s1);
//	//左右区间入栈
//	StackPush(&s1,begin);
//	StackPush(&s1,end);
//
//	while (s1.size > 0)
//	{
//		int right = StackPop(&s1);//取区间最右值
//		int left = StackPop(&s1);//取区间最左值
//
//        int pivot = PartSort(arr, left, right);
//
//		//左区间入栈
//		if (left < pivot-1)
//		{
//			StackPush(&s1, left);
//			StackPush(&s1, pivot - 1);
//		}
//		//右区间入栈
//		if (right > pivot + 1)
//		{
//			StackPush(&s1, pivot + 1);
//			StackPush(&s1, right);
//		}
//
//	}
//
//}
//
//int main()
//{
//	int arr[10] = { 6,2,9,0,3,7,5,6,4,8 };
//	Quick_Sort(arr, 0, 9);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//C中qsort函数的使用
//int cmp_int(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//    int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", arr[i]);
//
//    }
//    return 0;
//}


//C++中的sort函数的使用
//sort(要排序数组的起始地址，要排序数组的结束地址(最后一个要排序的地址)，排序的方法)

//1.没有第三个参数，默认从小到大
//#include<iostream>
//#include<algorithm>
//
//using  namespace std;
//
//int main()
//{
//	int arr1[10] = { 6,2,9,0,3,7,5,6,4,8 };
//	char arr2[10] = "ourtgfnsw";
//
//	sort(arr2,arr2+9);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}

//2.通过自己实现compare函数增加第三个参数实现从大到小排序

//#include<iostream>
//#include<algorithm>
//
//using  namespace std;
//
//bool compare(int a, int b)
//{
//	return a > b;
//}
//
//int main()
//{
//	int arr1[10] = { 6,2,9,0,3,7,5,6,4,8 };
//	char arr2[10] = "ourtgfnsw";
//
//	sort(arr2, arr2 + 9, compare);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}

//3.通过调用C++的库函数来实现compare函数
#include<iostream>
#include<algorithm>

using  namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int arr1[10] = { 6,2,9,0,3,7,5,6,4,8 };
	char arr2[10] = "ourtgfnsw";

	sort(arr2, arr2 + 9,less<char>());//从小到大排序

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%c ", arr2[i]);
	}
	printf("\n");

	sort(arr1, arr1 + 10, greater<int>());//从大到小排序

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>

//��������
//hoare�汾(����ָ�뷨)
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
//	//�ݹ��������
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int left = begin;
//	int right = end;
//	//ѡ���Ϊpivot
//	int pivot = arr[left];
//	while (left < right)
//	{
//		//��ָ�����ߣ��ұ�pivotС����
//		while (arr[right] >= pivot && left < right)
//		{
//			right--;
//		}
//		//��ָ���ұ�pivot�����
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
//	//�������еݹ�����
//	Quick_Sort(arr, begin, right - 1);
//	//�������еݹ�����
//	Quick_Sort(arr, left+1, end);
//}


//�ڿӷ�(�ݹ�汾)
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
//	//�ݹ��������
//	if (begin >= end)
//	{
//		return;
//	}
//	//������λ��ֵ
//	int pivot = arr[begin];
//
//	int left = begin;
//	int right = end;
//	while (left < right)
//	{
//		//leftΪ��λ����ָ���ұ�pivotС����
//		while (arr[right] >= pivot && left < right)
//		{
//			right--;
//		}
//		//������λ
//		swap_int(&arr[left], &arr[right]);
//
//		//rightΪ��λ����ָ���ұ�pivot�����
//		while (arr[left] <= pivot && left < right)
//		{
//			left++;
//		}
//		//������λ
//		swap_int(&arr[left], &arr[right]);
//	}
//	//��pivot�����λ��
//	arr[right] = pivot;
//
//	//�ݹ�
//	Quick_Sort(arr,begin, right - 1);
//	Quick_Sort(arr, left + 1, end);
//}


//����ָ�뷨(ʵ�������±�)
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
//	//�ݹ��������
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int pivot = arr[begin];
//	//�������ָ��(ʵ�������±�)
//	int slow = begin;//slow��¼���ǿɽ���λ�õ�ǰһ��
//	int fast = begin + 1;
//
//	while (fast <= end)
//	{
//		if (arr[fast] < pivot)
//		{
//			slow++;//slow��++�������ɽ���λ��
//			swap_int(&arr[fast], &arr[slow]);
//		}
//		fast++;
//	}
//	//����arr[slow]��arr[begin]
//	swap_int(&arr[slow], &arr[begin]);
//
//	//�ݹ�
//	Quick_Sort(arr, begin, slow - 1);
//	Quick_Sort(arr, slow + 1,end);
//}


#include<assert.h>

//�ǵݹ�汾(����ջ��ʵ��)
//��������
//����ʹ���������ַ���(hoare,�ڿӷ�������ָ�뷨)������һ�ָ��죬����pivotԪ�ص��±�
//������hoare

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
////����ջʵ�ַǵݹ�汾(�˴�ʹ��C����ʵ��ջ)
//void Quick_Sort(int* arr, int begin, int end)
//{
//	//����ջ
//	Stack s1;
//	//��ʼ��
//	StackInit(&s1);
//	//�������
//	CheckCapacity(&s1);
//	//����������ջ
//	StackPush(&s1,begin);
//	StackPush(&s1,end);
//
//	while (s1.size > 0)
//	{
//		int right = StackPop(&s1);//ȡ��������ֵ
//		int left = StackPop(&s1);//ȡ��������ֵ
//
//        int pivot = PartSort(arr, left, right);
//
//		//��������ջ
//		if (left < pivot-1)
//		{
//			StackPush(&s1, left);
//			StackPush(&s1, pivot - 1);
//		}
//		//��������ջ
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


//C��qsort������ʹ��
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


//C++�е�sort������ʹ��
//sort(Ҫ�����������ʼ��ַ��Ҫ��������Ľ�����ַ(���һ��Ҫ����ĵ�ַ)������ķ���)

//1.û�е�����������Ĭ�ϴ�С����
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

//2.ͨ���Լ�ʵ��compare�������ӵ���������ʵ�ִӴ�С����

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

//3.ͨ������C++�Ŀ⺯����ʵ��compare����
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

	sort(arr2, arr2 + 9,less<char>());//��С��������

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%c ", arr2[i]);
	}
	printf("\n");

	sort(arr1, arr1 + 10, greater<int>());//�Ӵ�С����

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	return 0;
}
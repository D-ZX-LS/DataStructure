#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(const SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}

int SeqListFind(const SL* ps, const SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}

}

void SeqListPushBack(SL* ps, const SLDataType x)
{
	//SeqListCheckCapacity(ps);
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);
}

void SeqListPopBack(SL* ps)
{
	//assert(ps->size > 0);
	//ps->size--;
	SeqListErase(ps, ps->size-1);
}

void SeqListPushFront(SL* ps, const SLDataType x)
{
	//SeqListCheckCapacity(ps);
	//int end = ps->size - 1;
	//while (end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
	//assert(ps->size > 0);
	//int begin = 0;
	//while (begin < ps->size - 1)
	//{
	//	ps->a[begin] = ps->a[begin + 1];
	//	begin++;
	//}
	//ps->size--;
	SeqListErase(ps, 0);
}

void SeqListInsert(SL* ps, const int pos, const SLDataType x)
{
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, const int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int begin = pos;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}

void DestorySeqList(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

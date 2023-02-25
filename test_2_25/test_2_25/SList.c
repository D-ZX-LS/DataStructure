#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* CreatSLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//�����½��
	SLTNode* newnode = CreatSLTNode(x);

	if (*pphead == NULL)
	{
		//1.����Ϊ�գ�ֱ�Ӳ���
		*pphead = newnode;
	}
	else
	{
		//2.����Ϊ�գ���β����
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//�����½��
	SLTNode* newnode = CreatSLTNode(x);

	//ͷ��
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	//����Ϊ��
	assert(*pphead);
	//����ֻ��һ�����
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//�������������������ϵĽ��
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	//����Ϊ��
	assert(*pphead);
	//����Ϊ��
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = CreatSLTNode(x);
	//posΪ��һ�����
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//pos���ǵ�һ�����
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = prev->next;
		prev->next = newnode;
	}
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = CreatSLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SListDestory(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* cur = *pphead;
	while (*pphead != NULL)
	{
		*pphead = cur->next;
		free(cur);
		cur = *pphead;
	}
}
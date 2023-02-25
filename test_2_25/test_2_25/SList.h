#pragma once

#include<stdio.h>
#include<stdlib.h>

#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//链表的打印
void SListPrint(SLTNode* phead);

//链表的尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);

//链表的头插
void SListPushFront(SLTNode** pphead, SLTDataType x);

//链表的尾删
void SListPopBack(SLTNode** pphead);

//链表的头删
void SListPopFront(SLTNode** pphead);

//链表的查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos位置的之前去插入一个结点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//在pos的后面去插入一个结点，更合适与单链表，也更加简单，C++的STL
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//删除pos位置的一个结点
void SListErase(SLTNode** pphead, SLTNode* pos);

//删除pos位置的后一个结点，更合适与单链表，也更加简单，C++的STL
void SListEraseAfter(SLTNode* pos);

//单链表的销毁
void SListDestory(SLTNode** pphead);

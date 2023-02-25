#pragma once

#include<stdio.h>
#include<stdlib.h>

#include<assert.h>

//线性表的定义

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;


//线性表的初始化
void SeqListInit(SL* ps);

//线性表的打印
void SeqListPrint(const SL* ps);

//线性表的查找
//找到返回对应位置的下标,找不到返回 -1
int SeqListFind(const SL* ps, const SLDataType x);

//线性表扩容的检测
void SeqListCheckCapacity(SL* ps);

//线性表的尾插
void SeqListPushBack(SL* ps, const SLDataType x);

//线性表的尾删
void SeqListPopBack(SL* ps);

//线性表的头插
void SeqListPushFront(SL* ps, const SLDataType x);

//线性表的头删
void SeqListPopFront(SL* ps);

//线性表指定位置的插入
void SeqListInsert(SL* ps, const int pos, const SLDataType x);

//线性表指定位置的删除
void SeqListErase(SL* ps, const int pos);

//线性表的销毁
void DestorySeqList(SL* ps);

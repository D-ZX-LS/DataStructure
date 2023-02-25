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

//����Ĵ�ӡ
void SListPrint(SLTNode* phead);

//�����β��
void SListPushBack(SLTNode** pphead, SLTDataType x);

//�����ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);

//�����βɾ
void SListPopBack(SLTNode** pphead);

//�����ͷɾ
void SListPopFront(SLTNode** pphead);

//����Ĳ���
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//��posλ�õ�֮ǰȥ����һ�����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//��pos�ĺ���ȥ����һ����㣬�������뵥����Ҳ���Ӽ򵥣�C++��STL
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//ɾ��posλ�õ�һ�����
void SListErase(SLTNode** pphead, SLTNode* pos);

//ɾ��posλ�õĺ�һ����㣬�������뵥����Ҳ���Ӽ򵥣�C++��STL
void SListEraseAfter(SLTNode* pos);

//�����������
void SListDestory(SLTNode** pphead);

#pragma once

#include<stdio.h>
#include<stdlib.h>

#include<assert.h>

//���Ա�Ķ���

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;


//���Ա�ĳ�ʼ��
void SeqListInit(SL* ps);

//���Ա�Ĵ�ӡ
void SeqListPrint(const SL* ps);

//���Ա�Ĳ���
//�ҵ����ض�Ӧλ�õ��±�,�Ҳ������� -1
int SeqListFind(const SL* ps, const SLDataType x);

//���Ա����ݵļ��
void SeqListCheckCapacity(SL* ps);

//���Ա��β��
void SeqListPushBack(SL* ps, const SLDataType x);

//���Ա��βɾ
void SeqListPopBack(SL* ps);

//���Ա��ͷ��
void SeqListPushFront(SL* ps, const SLDataType x);

//���Ա��ͷɾ
void SeqListPopFront(SL* ps);

//���Ա�ָ��λ�õĲ���
void SeqListInsert(SL* ps, const int pos, const SLDataType x);

//���Ա�ָ��λ�õ�ɾ��
void SeqListErase(SL* ps, const int pos);

//���Ա������
void DestorySeqList(SL* ps);

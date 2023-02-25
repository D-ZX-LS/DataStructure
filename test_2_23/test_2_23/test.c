#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//дһ����̬�����Ա�


void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1,1);
	SeqListPushBack(&s1,2);
	SeqListPushBack(&s1,3);
	SeqListPushBack(&s1,4);
	SeqListPushBack(&s1,5);
	SeqListPrint(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 7);
	SeqListPushFront(&s1, 8);
	SeqListPushFront(&s1, 9);
	SeqListPushFront(&s1, 6);
	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 2, 30);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 1, 32);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 5, 33);
	SeqListPrint(&s1);

	SeqListErase(&s1, 2);
	SeqListPrint(&s1);
	SeqListErase(&s1, 4);
	SeqListPrint(&s1);
	DestorySeqList(&s1);

}

void menu()
{
	printf("*******************************************\n");
	printf("***************** 0. exit *****************\n");
	printf("******      1. ͷ��      2. β��     ******\n");
	printf("******      3. ͷɾ      4. βɾ     ******\n");
	printf("******      5. Insert    6. Erase    ******\n");
	printf("***************** 7. ��ʾ *****************\n");
	printf("*******************************************\n");
}

int main()
{
	//TestSeqList1();
	int input = 0;
	SLDataType insert_data = 0;
	int pos = 0;
	SL s1;
	SeqListInit(&s1);

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫ��������ݣ�");
			scanf("%d", &insert_data);
			SeqListPushFront(&s1, insert_data);
			break;
		case 2:
			printf("������Ҫ��������ݣ�");
			scanf("%d", &insert_data);
			SeqListPushBack(&s1, insert_data);
			break;
		case 3:
			SeqListPopFront(&s1);
			break;
		case 4:
			SeqListPopBack(&s1);
			break;
		case 5:
			printf("������Ҫ������±��Լ����ݣ�");
			scanf("%d", &pos);
			scanf("%d", &insert_data);
			SeqListInsert(&s1, pos, insert_data);
			break;		
		case 6:
			printf("������Ҫɾ�����ݵ��±꣺");
			scanf("%d", &pos);
			SeqListErase(&s1, pos);
			break;		
		case 7:
			SeqListPrint(&s1);
			break;
		case 0:
			DestorySeqList(&s1);
			break;
		default:
			printf("ѡ����Ч��������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}

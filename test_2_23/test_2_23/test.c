#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//写一个动态的线性表


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
	printf("******      1. 头插      2. 尾插     ******\n");
	printf("******      3. 头删      4. 尾删     ******\n");
	printf("******      5. Insert    6. Erase    ******\n");
	printf("***************** 7. 显示 *****************\n");
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
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要插入的数据：");
			scanf("%d", &insert_data);
			SeqListPushFront(&s1, insert_data);
			break;
		case 2:
			printf("请输入要插入的数据：");
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
			printf("请输入要插入的下标以及数据：");
			scanf("%d", &pos);
			scanf("%d", &insert_data);
			SeqListInsert(&s1, pos, insert_data);
			break;		
		case 6:
			printf("请输入要删除数据的下标：");
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
			printf("选择无效，请重新选择\n");
			break;
		}
	} while (input);

	return 0;
}

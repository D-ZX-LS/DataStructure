#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//单链表

SListTest1()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
}

SListTest2()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

}

SListTest3()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
}

SListTest4()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 2);

	SListPushFront(&plist, 2);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 2);
	int i = 0;
	//总共2的个数
	while (pos)
	{
		printf("第%d个pos结点：%p -> %d\n", ++i, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}
	//查找的第二个含义：修改
	//5->50
	pos = SListFind(plist, 5);
	pos->data = 50;
	SListPrint(plist);
}

SListTest5()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 7);

	SListPushFront(&plist, 2);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 5);
	SListInsert(&plist, pos, 50);
	SListPrint(plist);


    pos = SListFind(plist, 4);
	SListInsert(&plist, pos, 40);
	SListPrint(plist);

	pos = SListFind(plist, 2);
	SListInsert(&plist, pos, 20);
	SListPrint(plist);

	pos = SListFind(plist, 20);
	SListErase(&plist, pos);
	SListPrint(plist);

	pos = SListFind(plist, 7);
	SListErase(&plist, pos);
	SListPrint(plist);
	
}

SListTest6()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 7);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 6);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 4);
	SListInsertAfter(pos, 40);
	SListPrint(plist);
    
	pos = SListFind(plist, 6);
	SListInsertAfter(pos, 60);
	SListPrint(plist);

	pos = SListFind(plist, 7);
	SListEraseAfter(pos);
	SListPrint(plist);

	pos = SListFind(plist, 6);
	SListEraseAfter(pos);
	SListPrint(plist);

	SListDestory(&plist);
}

int  main()
{
	//SListTest1();
	//SListTest2();
	//SListTest3();
	//SListTest4();
	//SListTest5();
	SListTest6();
	
	return 0;
}


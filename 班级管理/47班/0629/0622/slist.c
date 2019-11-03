#include "slist.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist)
{
	SListNode * tmp;
	while (plist->_head)
	{ 
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

void SListPopFront(SList* plist)
{
	assert(plist);

	SListNode * tmp;
	if (plist->_head)
	{ 
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListPrint(SList* plist)
{
	assert(plist);

	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode * cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
//ǰ�巶��������Ҫ��
void SListInsertFront(SList* plist, SLTDataType x, SLTDataType src)
{
	assert(plist);
	SListNode * cur;
	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));

	if (plist->_head->_data == x)
	{
		SListPushFront(plist, src);
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == x)
		{
			break;
		}
	}
	newdata->_data = src;
	newdata->_next = cur->_next;
	cur->_next = newdata;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode * tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);
}

void SListReverse(SList* plist)
{
	assert(plist->_head);
#if 0
	SListNode * tmp = plist->_head->_next;
	SListNode * cur = plist->_head;
	while (tmp)
	{
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;

		plist->_head = tmp;
		tmp = cur->_next;
	}
#elif 0
	SList * reve = (SList *)malloc(sizeof(SList));
	SListInit(reve);
	SListNode* cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		SListPushFront(reve, cur->_data);
	}
	SListDestory(plist);
	plist->_head = reve->_head;
#else
	SListNode * tmp = plist->_head->_next; //��¼next
	SListNode * cur = plist->_head;
	cur->_next = NULL; //��������ͷ��������next�Ͽ�����tmp��¼���������ҵ�
	while (tmp) //ÿ��ѭ����Ҫ��ɶ�����Ȼ��;�ͷ���³����Ĺ��̣�����������(tmpΪ��)����ѭ��
	{
		plist->_head = tmp; //����ͷ��tmpλ�û��Ϊ�µ�ͷ����ͷ�������ĵ�һ���ڵ�
		tmp = tmp->_next; //��¼�´�ѭ����tmp ��λ�ã���Ϊtmp�����ѭ�����Ѿ������ˣ����Һ������Ͼ�Ҫ���������Ա����������¼
		plist->_head->_next = cur; //���������ͷ�γ�����
		cur = plist->_head; //��¼��ͷ��λ�ã������´�ѭ������
	}
#endif
}

SListNode * getIntersectionNode(SList* listA, SList* listB)
{
	int lenA = 0;
	int lenB = 0;
	SListNode *cur;
	SListNode *headlong = listA->_head;
	SListNode *headshort = listB->_head;
	int gap;
	int i;

	for (cur = listA->_head; cur; cur = cur->_next)
	{
		lenA++;
	}

	for (cur = listB->_head; cur; cur = cur->_next)
	{
		lenB++;
	}
	gap = lenA - lenB;
	if (gap < 0)
	{
		gap *= -1;
		headshort = listA->_head;
		headlong = listB->_head;
	}

	for (i = 0; i < gap; i++)
	{
		headlong = headlong->_next;
	}

	for (; headlong; headlong = headlong->_next, headshort = headshort->_next)
	{
		if (headlong == headshort)
		{
			return headlong;
		}
	}
	return NULL;
}

int SListHasCycle(SList* plist)
{
	SListNode *fast = plist->_head;
	SListNode *slow = plist->_head;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;
}

SListNode* SListGetCycleNode(SList* plist)
{
	SListNode *fast = plist->_head;
	SListNode *slow = plist->_head;

	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			return fast;
		}
	}
	return NULL;
}

SListNode * SListDetectCycle(SList* plist)
{
	SListNode *tmp = SListGetCycleNode(plist);

	if (NULL == tmp)
	{
		return NULL;
	}

	SListNode * cur = plist->_head;
	for (; cur; cur = cur->_next, tmp = tmp->_next)
	{
		if (cur == tmp)
		{
			return cur;
		}
	}
	return NULL;
}
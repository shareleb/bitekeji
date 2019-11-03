#include "SList.h"
#include <stdio.h>
#include <math.h>

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}

void SListInit(SListNode** pphead)
{
	*pphead = NULL;
}

void SListDestory(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}

	while ((*pphead)->next)
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);
	*pphead = NULL;
}


void SListPushFront(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

SListNode* SListFind(SListNode* phead, SLTDataType x)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

void SListEraseAfter(SListNode* pos)
{
	SListNode* tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}


void SListRemoveAll(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp;
	while (*pphead && (*pphead)->data == x)
	{
		SListPopFront(pphead);
	}

	for (tmp = *pphead; tmp && tmp->next; )
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

void SListRemove(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp;
	if (*pphead == NULL)
	{
		return;
	}

	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
		return;
	}

	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}

void SListPrint(SListNode* phead)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
}


void SListReverse(SListNode **pphead)
{
	SListNode *head = *pphead;   //��ָ����ÿ��ѭ����ʼ��ָ��ǰ�����ͷ
	SListNode *tmp = head->next; //��ָ����ÿ��ѭ����ʼ��ָ��Ҫ����ɾͷ��Ľڵ�
	SListNode *oldh = *pphead;   //��ָ����ÿ��ѭ����ʼ��ָ��ԭ����ͷ��㣬����ı�ָ��

	while (tmp) //���tmpΪ�գ�����������������ͷ��next�Ѿ��ǿյ��ˣ���Ϊ�������ĩβ
	{
		oldh->next = tmp->next; //��tmp�ܿգ�ʵ���Ǻ�ɾ������һ����
		tmp->next = head; //��tmp����µ�ͷ��ʵ����ͷ�������һ���� 
		head = tmp; //��ͷ
		tmp = oldh->next; //��tmp����´�ѭ���д�ɾ���Ľڵ�
	}
	*pphead = head;
}

void SListReverse2(SListNode **pphead)
{
	SListNode *pre = *pphead;   //��ִ�в�����ǰһ���ڵ�
	SListNode *cur = pre->next; //��ִ�в����Ľڵ�
	SListNode *next = cur;      //��ִ�в����ĺ�һ���ڵ㣬��ʱָ��cur����ѭ����ʼ��ʱ����ת�����һ���ڵ�

	pre->next = NULL; //��ʱ��ͷ��������ת�����β������������������β�ڵ�
	while (next)
	{ 
		next = next->next; //����next�����һ���ڵ㣬֮���Բ������������Ϊ����nextΪ�յ�����
		cur->next = pre; //��ԭ��ָ�ź����ָ��ǰ�������Ⱥ�ת��
		pre = cur; //Ϊ���´�ѭ�����������ݣ������������´�ѭ������һ���ڵ㣨����ִ�в����Ľڵ㽫����´�ѭ������һ���ڵ㣩
		cur = next; //ͬ�ϣ����ε���һ���ڵ㽫���Ϊ�´εı�ִ�нڵ㣩
	}

	*pphead = pre; //ѭ��������cur��next���Ѿ�ָ����ˣ�pre�����µ�ͷ
}

SListNode *getIntersectionNode(SListNode *headA, SListNode *headB)
{
	int lenA = 0;
	int lenB = 0;
	int gap;
	int i;
	SListNode * cur;
	SListNode * longerlist = headA;
	SListNode * shorterlist = headB;

	for (cur = headA; cur; cur = cur->next)
	{
		lenA++;
	}

	for (cur = headB; cur; cur = cur->next)
	{
		lenB++;
	}

	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		longerlist = headB;
		shorterlist = headA;
	}

	for (i = 0; i < gap; i++)
	{
		longerlist = longerlist->next;
	}
	
	for (; longerlist && shorterlist; longerlist = longerlist->next, shorterlist = shorterlist->next)
	{
		if (longerlist == shorterlist)
		{
			return longerlist;
		}
	}
	return NULL;
}

SListNode *detectCycle(SListNode *head)
{
	SListNode * fast = head;
	SListNode * slow = head;

	while (fast && slow && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}

	for (; fast && fast->next; fast = fast->next, head = head->next)
	{
		if (fast == head)
		{
			return fast;
		}
	}
	return NULL;
}

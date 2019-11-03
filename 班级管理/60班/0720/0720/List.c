#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}

void ListDestory(List* plist)
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}

void ListPopBack(List* plist)
{
	ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDataType x)
{
	ListInsertAfter(plist->_head, x);
}

void ListPopFront(List* plist)
{
	ListErase(plist->_head->_next);
}

void ListInsertFront(ListNode* pos, LTDataType x)
{
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode * tmp = pos->_prev;

	cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
}

void ListInsertAfter(ListNode* pos, LTDataType x)
{
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode * tmp = pos->_next;

	cur->_data = x;

	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
}

void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
/*
void ListRemove(List* plist, LTDataType x)
{
	ListNode * cur = ListFind(plist, x);

	if (cur)
	{
		ListErase(cur);
	}
}*/

void ListDistinct(List* plist)
{
	ListNode * cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev; )
	{
		if (Contactcmp(cur->_data, cur->_next->_data) == 0)
		{
			ListErase(cur->_next);
		}
		else
		{
			cur = cur->_next;
		}
	}
}

void ListRankInsert(List *plist, LTDataType x)
{
	ListNode * cur;

	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (Contactcmp(cur->_data, x) >= 0)
		{
			break;
		}
	}
	ListInsertFront(cur, x);
}

void ListMerge(List* plist1, List* plist2)
{
	ListNode *cur1 = plist1->_head->_next, *cur2 = plist2->_head->_next;
	//cur1��cur2������1������2�ĵ�һ������
	ListNode *tmp1, *tmp2;
	while (cur1 != plist1->_head && cur2 != plist2->_head)//˫�����������������
	{
		if (Contactcmp(cur1->_data, cur2->_data) > 0) //�������1��ǰ�ڵ�����ݱ�����2�Ĵ�˵������2������ڵ�Ӧ�ò嵽����1�ĵ�ǰ�ڵ�ǰ��
		{
			tmp1 = cur1->_prev; //����cur1��prev�ᱻ�޸ģ�������һ������
			tmp2 = cur2->_next; //����cur2��next�ᱻ�޸ģ�������һ������

			cur1->_prev = cur2; //cur1��������cur2
			cur2->_next = cur1; //cur2��������cur1����������
			tmp1->_next = cur2; //tmp1(cur1��prev)����������cur2
			cur2->_prev = tmp1; //cur2����������tmp1����������

			cur2 = tmp2; //cur2�ҵ�������һ���ڵ�
		}
		else
		{
			cur1 = cur1->_next; //���cur1��ֵ������С����ôֱ����������һ���ڵ�
		}
	}

	if (cur1 == plist1->_head) //�������������list1��ĩβ�ˣ�֤��list2��û����������list2ʣ�µĽڵ��ֵ����list1������Ҫ��list2ʣ�µ����нڵ����list1����
	{
		tmp2 = plist2->_head->_prev; //��¼��Ҫ�ҵ����һ���ڵ㣬cur2������Ҫ�ҵĵ�һ���ڵ㣬Ҳ����Ҫ��cur2��tmp��һ�νڵ����cur1��ĩβ

		cur2->_prev = cur1->_prev; //��cur2����������list1�����һ���ڵ㣨��ʱcur1����list1��ͷ������cur1���������ľ���list1��β�ڵ㣩
		cur1->_prev->_next = cur2; //��list1��β�ڵ����������cur2��ǣ�ֳɹ�����ʱcur2��������list1��β��

		tmp2->_next = cur1; //�м�����нڵ㲻��Ҫ��������һ��Ҫ������ֻ��β�ڵ�tmp����tmp����������list1��ͷ��
		cur1->_prev = tmp2; //list1��ͷ����������tmp2��ǣ�ֳɹ���tmp2����list1��β�ڵ�
	}
	//���������������list2����ĩβ����ô˵��list2��Ԫ���Ѿ�ȫ������list1���ˣ���ֱ���ͷ�ͷ��

	free(plist2->_head); //����ͷŵ�list2�н�ʣ��ͷ��
}

void ListPrint(List* plist)
{
	ListNode * cur;

	printf("head->");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printData(cur->_data);
	}
	printf("head");
}

void ListFind(List *plist, char *find, SeqList *psl)
{
	ListNode * cur;
	int flag;
	char * ret;
	char age[4];
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		do{
			flag = 1;
			ret = strstr(cur->_data.name, find);
			if (ret)
			{
				break;
			}

			ret = strstr(cur->_data.phonenum, find);
			if (ret)
			{
				break;
			}

			sprintf(age, "%d", cur->_data.age);
			if (!strcmp(age, find))
			{
				break;
			}

			ret = strstr(cur->_data.address, find);
			if (ret)
			{
				break;
			}

			flag = 0;
		} while (0);

		if (flag)
		{
			SeqListPushBack(psl, cur);
		}
	}
}

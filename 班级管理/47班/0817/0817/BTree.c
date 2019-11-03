#include "BTree.h"
#include "queue.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

static int s_n;

BTNode *BinaryTreeCreateExe(BTDataType * src)
{
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}

	BTNode * cur = (BTNode *)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;

	cur->lchild = BinaryTreeCreateExe(src);
	cur->rchild = BinaryTreeCreateExe(src);

	return cur;
}

BTNode *BinaryTreeCreate(BTDataType * src)
{
	s_n = 0;
	return BinaryTreeCreateExe(src);
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{ 
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);
	}
}

void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode * cur;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->data);

		if (cur->lchild)
		{
			QueuePush(&qu, cur->lchild);
		}

		if (cur->rchild)
		{
			QueuePush(&qu, cur->rchild);
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root; //�Ӹ���ʼ

	StackInit(&st, 100);

	while (cur)
	{ 
		putchar(cur->data); //���ʵ�ǰ�ڵ�

		if (cur->rchild) //������Һ��ӣ��Һ�����ջ
		{
			StackPush(&st, cur->rchild);
		}

		if (cur->lchild) //��������ӣ���������
		{
			cur = cur->lchild;
		}
		else //û�����Ӿ�ȡջ��
		{
			cur = StackTop(&st); //ȡ����ʱ������������ѭ������
			StackPop(&st);
		}
	}
	StackDestory(&st);
}


void BinaryTreeInOrderNonR(BTNode * root)
{
	BTNode * cur = root;

	Stack st;
	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st))
	{
		for (; cur; cur = cur->lchild) //����ǰ�ڵ㼰��������ջ
		{
			StackPush(&st, cur);
		}

		cur = StackTop(&st); 
		//1������Һ���Ϊ�գ�forѭ��������ֱ��ȡջ��
		//2������к��Ӳ�Ϊ�գ���ô����һ��û�����ӵĽڵ�
		//��һ�������������������ϣ��ڶ��������������Ϊ�գ��������֣���ǰ�ڵ㶼Ҫ��ӡ
		putchar(cur->data);
		StackPop(&st);
		cur = cur->rchild; //��������Ϊ��ʱ�����ջ�Ƿ�Ϊ�գ����ջҲ���ˣ�ѭ������
	}

	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	char tag[64];

	BTNode * cur = root;

	Stack st;
	StackInit(&st, 100);

	do{
		for (; cur; cur = cur->lchild) //�������򣬽���ǰ�ڵ㼰����������ջ
		{
			StackPush(&st, cur);
			tag[st.size - 1] = 0; //�������������ʱ�ǣ�LT��
		}

		while (!StackIsEmpty(&st) && tag[st.size - 1]) 
		//ǰ�������ֻ�����һ��ѭ��������ʱ����Ч
		//��������������������
		//1����cur��Ϊ��ʱ�������for����������������
		//2����cur��Ϊ�գ������for�����������������
		//�����⵽��ǰ��LT����λ��Ҳ�������1������ô�ڴ�ӡ�굱ǰ�ڵ����ȥֱ�Ӽ����һ���ڵ㣨���ڵ㣩�ǲ���ҲҪ����ӡ�ˣ�LT��λ��֤��������������������ҲҪ����ӡ�ˣ�������Ҫ��whileѭ����ӡ
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);
		}

		if (!StackIsEmpty(&st)) //������ֻ�����һ��ѭ������ʱ��Ч
		{ 
			cur = StackTop(&st);
			//1����������while���ˣ���ô֤����������������ˣ���LT��λ
			//2����������whileû������ô֤�������������ڣ���LT��λ
			tag[st.size - 1] = 1;
			cur = cur->rchild;
			//������������Ϻ󣬷���������
		}
	} while (!StackIsEmpty(&st));
	//���ں�������и��ڵ�������ջ�ģ������ڸ��ڵ��ջǰ��ջ������Ϊ�գ�������ջ�Ƿ�Ϊ�����ж��Ƿ�Ҫ����

	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->data);

		if (cur->rchild && !cur->lchild)
		{
			return 0;
		}

		if (tag && (cur->rchild || cur->lchild))
		{
			return 0;
		}

		if (cur->lchild)
		{
			QueuePush(&qu, cur->lchild);
		}

		if (cur->rchild)
		{
			QueuePush(&qu, cur->rchild);
		}
		else
		{
			tag = 1;
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
	return 1;
}

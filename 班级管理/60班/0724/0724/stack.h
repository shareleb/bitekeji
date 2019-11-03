#ifndef _Stack_H_
#define _Stack_H_

// ˳���Ķ�̬�洢

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"
typedef BTNode * STDataType;

typedef struct Stack {
	STDataType* array;  // ָ��̬���ٵ�����
	size_t size;       // ��Ч���ݸ���
	size_t capacity;   // �����ռ�Ĵ�С
}Stack;

// ������ɾ��Ľӿ�
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, STDataType x);
void StackPop(Stack* psl);

STDataType StackFront(Stack* psl);
int StackIsEmpty(Stack* pq);

#endif /*_Stack_H_*/
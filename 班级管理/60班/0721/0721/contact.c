#include "contact.h"
#include <string.h>
#include <stdio.h>

void contactAdd(List * plist, Contact c)
{
	ListRankInsert(plist, c);
}

SeqList contactSearch(List * plist, char * find)
{
	SeqList sl;

	SeqListInit(&sl, 100);

	ListFind(plist, find, &sl);

	if (sl.size == 0)
	{
		printf("û���ҵ�����\n");
	}
	else
	{
		printf("���ҵ�%d������\n", sl.size);
		SeqListPrint(&sl);
	}

	return sl;
}

void contactFind(List * plist, char * find)
{
	SeqList sl = contactSearch(plist, find);
	SeqListDestory(&sl);
}

void contactDelete(List * plist, char * find)
{
	SeqList sl = contactSearch(plist, find);
	if (sl.size == 0)
	{
		printf("ɾ��ʧ��\n");
	}
	else if (sl.size == 1)
	{
		ListErase(sl.array[0]);
		printf("ɾ���ɹ�\n");
	}
	else if (sl.size > 1)
	{
		int del;
		printf("��ѡ��Ҫɾ������Ŀ:\n");
		scanf("%d", &del);
		ListErase(sl.array[del - 1]);
		printf("ɾ���ɹ�\n");
	}

	SeqListDestory(&sl);
}
/*
void contactChange()
{

}
*/

void fillData(Contact * src, char * name, char sex, char age, char * pn, char * addr)
{
	if (src == NULL)
	{ 
		return;
	}

	strcpy(src->name, name);
	src->sex = sex;
	src->age = age;
	strcpy(src->phonenum, pn);
	strcpy(src->address, addr);
}

int Contactcmp(Contact c1, Contact c2)
{
	return strcmp(c1.name, c2.name);
}

Contact createData()
{
	Contact ret;

	scanf("%[^\n]", ret.name);
	getchar();
	scanf("%c", &ret.sex);
	scanf("%d", &ret.age);
	scanf("%s", ret.phonenum);
	getchar();
	scanf("%[^\n]", ret.address);
	getchar();
}

void printData(Contact data)
{
	printf("%15s %c %2d %12s %s\n",
			data.name,
			data.sex,
			data.age,
			data.phonenum,
			data.address);
}

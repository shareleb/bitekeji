#include <stdio.h>
#include <string.h>
#include "MailList.h"

void inputData()
{
	struct MailList tmp;

	printf("������������\n");
	scanf("%49s", tmp.name);
	getchar();
	printf("�������Ա�f/m����\n");
	scanf("%c", &tmp.gender);
	printf("���������䣺\n");
	scanf("%d", &tmp.age);
	printf("������绰���룺\n");
	scanf("%29s", tmp.telnum);
	printf("�������ַ��\n");
	scanf("%199s", tmp.addr);

	int i;
	for (i = 0; i < g_count; i++)
	{
		if (strcmp(g_allMsg[i].name, tmp.name) > 0)
		{
			break;
		}
	}
	int j;
	for (j = g_count; j > i; j--)
	{
		g_allMsg[j] = g_allMsg[j - 1];
	}
	g_allMsg[i] = tmp;

	g_count++;
}

void searchData(char * find, int * searchres)
{
	int i, flag;
	char age[4] = { 0 };
	char * ret;
	for (i = 0; i < g_count; i++)
	{
		do{
			flag = 1;
			ret = strstr(g_allMsg[i].name, find);
			if (ret)
			{
				break;
			}

			ret = strstr(g_allMsg[i].telnum, find);
			if (ret)
			{
				break;
			}

			sprintf(age, "%d", g_allMsg[i].age);
			if (!strcmp(age, find))
			{
				break;
			}

			ret = strstr(g_allMsg[i].addr, find);
			if (ret)
			{
				break;
			}

			flag = 0;
		} while (0);

		if (flag)
		{
			searchres[0]++;
			searchres[searchres[0]] = i;
		}
	}
}


void outputData()
{
	int i;
	if (g_count == 0)
	{
		printf("û������\n");
		return;
	}

	printf("  ����     �Ա� ����     �绰        סַ\n");
	for (i = 0; i < g_count; i++)
	{
		printf("%-10s %3c  %3d  %11s %s\n", 
			g_allMsg[i].name,
			g_allMsg[i].gender,
			g_allMsg[i].age,
			g_allMsg[i].telnum,
			g_allMsg[i].addr);
	}
}

void outputSearchData(int * data)
{
	int i;
	if (data[0] == 0)
	{
		printf("û�з�������������\n");
		return;
	}

	printf("     ����     �Ա� ����     �绰      סַ\n");
	for (i = 1; i <= data[0]; i++)
	{
		printf("%2d %-10s %3c  %3d  %11s %s\n",
			i,
			g_allMsg[data[i]].name,
			g_allMsg[data[i]].gender,
			g_allMsg[data[i]].age,
			g_allMsg[data[i]].telnum,
			g_allMsg[data[i]].addr);
	}
}

void deleteOneData(int n)
{
	int i;
	for (i = n; i < g_count; i++)
	{
		g_allMsg[i] = g_allMsg[i + 1];
	}
	g_count--;
}

int catchOneData(char *find)
{
	int schres[1001] = { 0 };
	searchData(find, schres);
	if (schres[0] == 0)
	{
		return -1;
	}
	else if (schres[0] == 1)
	{
		return schres[1];
	}
	else
	{
		int i;
		outputSearchData(schres);
		printf("��������Ҫɾ���ڼ�������:\n");
		scanf("%d", &i);
		if (i < 1 || i > schres[0])
		{
			return -1;
		}
		return schres[i];
	}
}
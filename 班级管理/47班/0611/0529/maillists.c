#include "MailList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initMailList(MailLists * data)
{
	data->allMsg = (struct MailList *)calloc(PERSPACE, sizeof(struct MailList));
	data->count = 0;
	data->limit = PERSPACE;
}

void destoryMailList(MailLists * data)
{
	if (data->allMsg)
	{
		free(data->allMsg);
	}
	data->allMsg = NULL;
	data->count = 0;
	data->limit = 0;
}

void inputData(struct MailList * oneData)
{
	printf("������������\n");
	scanf("%49s", oneData->name);
	getchar();
	printf("�������Ա�f/m����\n");
	scanf("%c", &oneData->gender);
	printf("���������䣺\n");
	scanf("%d", &oneData->age);
	printf("������绰���룺\n");
	scanf("%29s", oneData->telnum);
	printf("�������ַ��\n");
	scanf("%199s", oneData->addr);
}

void addMailList(MailLists * data, struct MailList oneData)
{
	int i;

	if (data->count == data->limit)
	{
		data->limit += PERSPACE;
		data->allMsg = (struct MailList *)realloc(data->allMsg, data->limit * sizeof(struct MailList));
	}

	for (i = 0; i < data->count; i++)
	{
		if (strcmp(data->allMsg[i].name, oneData.name) > 0)
		{
			break;
		}
	}
	int j;
	for (j = data->count; j > i; j--)
	{
		data->allMsg[j] = data->allMsg[j - 1];
	}
	data->allMsg[i] = oneData;

	data->count++;
}

void searchData(MailLists data, char * find, int * searchres)
{
	int i, flag;
	char age[4] = { 0 };
	char * ret;
	for (i = 0; i < data.count; i++)
	{
		do{
			flag = 1;
			ret = strstr(data.allMsg[i].name, find);
			if (ret)
			{
				break;
			}

			ret = strstr(data.allMsg[i].telnum, find);
			if (ret)
			{
				break;
			}

			sprintf(age, "%d", data.allMsg[i].age);
			if (!strcmp(age, find))
			{
				break;
			}

			ret = strstr(data.allMsg[i].addr, find);
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

void deleteOneData(MailLists * data, int n)
{
	int i;
	for (i = n; i < data->count; i++)
	{
		data->allMsg[i] = data->allMsg[i + 1];
	}
	data->count--;
}

void outputData(MailLists data)
{
	int i;
	if (data.count == 0)
	{
		printf("û������\n");
		return;
	}

	printf("  ����     �Ա� ����     �绰        סַ\n");
	for (i = 0; i < data.count; i++)
	{
		printf("%-10s %3c  %3d  %11s %s\n",
			data.allMsg[i].name,
			data.allMsg[i].gender,
			data.allMsg[i].age,
			data.allMsg[i].telnum,
			data.allMsg[i].addr);
	}
}

void outputSearchData(MailLists data, int * outputdata)
{
	int i;
	if (outputdata[0] == 0)
	{
		printf("û�з�������������\n");
		return;
	}

	printf("     ����     �Ա� ����     �绰      סַ\n");
	for (i = 1; i <= outputdata[0]; i++)
	{
		printf("%2d %-10s %3c  %3d  %11s %s\n",
			i,
			data.allMsg[outputdata[i]].name,
			data.allMsg[outputdata[i]].gender,
			data.allMsg[outputdata[i]].age,
			data.allMsg[outputdata[i]].telnum,
			data.allMsg[outputdata[i]].addr);
	}
}

int catchOneData(MailLists data, char *find)
{
	int schres[1001] = { 0 };
	searchData(data, find, schres);
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
		outputSearchData(data, schres);
		printf("��������Ҫɾ���ڼ�������:\n");
		scanf("%d", &i);
		if (i < 1 || i > schres[0])
		{
			return -1;
		}
		return schres[i];
	}
}
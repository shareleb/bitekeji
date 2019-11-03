#include <stdio.h>
#include <string.h>
#include "MailList.h"

int menu()
{
	int tmp, ret;
	printf("0.	�˳�\n"
		"1.	�����ϵ����Ϣ\n"
		"2.	ɾ��ָ����ϵ����Ϣ\n"
		"3.	����ָ����ϵ����Ϣ\n"
		"4.	�޸�ָ����ϵ����Ϣ\n"
		"5.	��ʾ������ϵ����Ϣ\n"
		"6.	���������ϵ��\n"
		"7.	����\n"
		"������ѡ�");
	ret = scanf("%d", &tmp);
	return ret ? tmp : -1;
}

void MailList()
{
	int op;
	int ret;
	char str[256] = { 0 };
	int searchRes[1001] = { 0 };
	MailLists allData;
	struct MailList tmp;

	initMailList(&allData);
	if (loadData(&allData, FILENAME))
	{
		printf("��ȡʧ��\n");
	}
	while (1)
	{
		op = menu();
		if (op == 0)
		{
			break;
		}
		switch (op)
		{
		case ADD_MSG:
			inputData(&tmp);
			addMailList(&allData, tmp);
			break;
		case DELETE_MSG:
			printf("��������Ҫɾ������Ŀ��\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			ret = catchOneData(allData, str);
			if (ret >= 0)
			{ 
				deleteOneData(&allData, ret);
				printf("ɾ���ɹ�\n");
			}
			else
			{
				printf("ɾ��ʧ��\n");
			}
			break;
		case SEARCH_MSG:
			printf("��������Ҫ�������ַ�����\n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(allData, str, searchRes);
			outputSearchData(allData, searchRes);
			printf("���ҵ�%d������\n", searchRes[0]);
			break;
		case CHANGE_MSG:
			break;
		case DISPLAY_MSG:
			outputData(allData);
			break;
		case EMPTY_MSG:
			destoryMailList(&allData);
			initMailList(&allData);
			break;
		case SAVE_FILE:
			if (saveData(allData, FILENAME))
			{
				printf("����ʧ��\n");
			}
			else
			{
				printf("����ɹ�\n");
			}
		case -1:
			printf("������������������\n");
			break;
		default:
			printf("������������������\n");
		}
	}
	destoryMailList(&allData);
}
/*
void test()
{
	char str[256] = { 0 };
	int searchRes[1001] = { 0 };
	MailLists allData;
	struct MailList tmp;

	initMailList(&allData);
	inputData(&tmp);
	addMailList(&allData, tmp);
	inputData(&tmp);
	addMailList(&allData, tmp);
	inputData(&tmp);
	addMailList(&allData, tmp);
	inputData(&tmp);
	addMailList(&allData, tmp);
	inputData(&tmp);
	addMailList(&allData, tmp);
	if (saveData(allData, FILENAME))
	{
		printf("����ʧ��\n");
	}
	destoryMailList(&allData);
}

void test2()
{
	MailLists allData;
	initMailList(&allData);

	if (loadData(&allData, FILENAME))
	{
		printf("��ȡʧ��\n");
	}

	outputData(allData);
	destoryMailList(&allData);
}*/

int main()
{
	MailList();
	return 0;
}
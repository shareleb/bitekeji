#include <stdio.h>
#include <string.h>
#include "contact.h"

int menu()
{
	int tmp, ret;
	printf("1.	�����ϵ����Ϣ\n"
		"2.	ɾ��ָ����ϵ����Ϣ\n"
		"3.	����ָ����ϵ����Ϣ\n"
		"4.	�޸�ָ����ϵ����Ϣ\n"
		"5.	��ʾ������ϵ����Ϣ\n"
		"6.	���������ϵ��\n"
		"������ѡ�");
	ret = scanf("%d", &tmp);
	return ret ? tmp : -1;
}

void MailList()
{
	int op;
	int ret;
	char str[256] = { 0 };
	List list;
	ListInit(&list);

	while (1)
	{
		op = menu();

		switch (op)
		{
		case ADD_MSG:
			Contact data;
			data = createData();
			contactAdd(&list, data);
			break;
		case DELETE_MSG:
			printf("��������Ҫɾ������Ŀ����Ϣ��\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			contactDelete(&list, str);
			break;
		case SEARCH_MSG:
			printf("��������Ҫ�������ַ�����\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			contactFind(&list, str);
			break;
		case CHANGE_MSG:
			break;
		case DISPLAY_MSG:
			ListPrint(&list);
			break;
		case EMPTY_MSG:
			ListDestory(&list);
			ListInit(&list);
			break;
		case -1:
			printf("������������������\n");
			break;
		default:
			printf("������������������\n");
		}
	}
	ListDestory(&list);
}

int main()
{
	MailList();
	return 0;
}
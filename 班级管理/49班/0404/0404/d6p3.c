#include <stdio.h>

int judgeLeapYear(int y) //�շ�ʽ
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main63()
{
	if (judgeLeapYear(1999))
	{
		printf("����\n");
	}
	else
	{
		printf("ƽ��\n");
	}

	system("pause");
	return 0;
}
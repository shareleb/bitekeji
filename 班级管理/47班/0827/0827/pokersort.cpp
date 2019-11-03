#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Poker
{
	char type;
	int point;
};

enum{
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,
	JOKER
};

void inputpoker(Poker * pk)
{
	scanf("%c%d", &pk->type, &pk->point);
	pk->type -= 'a';
	if (pk->type == JOKER)
	{
		pk->point += 13;
	}
	while (getchar() != '\n');
}

void outputpoker(Poker k)
{
	char *type[5] = { "����", "����", "÷��", "��Ƭ", "" };
	char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };

	printf("%s%s\n", type[k.type], point[k.point]);
}

bool cmppoker(Poker a, Poker b)
{
	return (a.point < b.point) ||
		   (a.point == b.point && a.type > b.type);
}

void InsertSort(Poker * src, int n, bool(*cmp)(Poker, Poker) = cmppoker)
{
	int i, j;
	Poker tmp;

	for (i = 1; i < n; i++)
	{
		tmp = src[i];

		for (j = i; j > 0 && cmp(tmp, src[j - 1]); j--)
		{
			src[j] = src[j - 1];
		}

		src[j] = tmp;
	}
}

bool cmplulaoye(Poker a, Poker b)
{
	if (a.point <= 2)
	{
		a.point += 11;
	}
	else if (a.point <= 13)
	{
		a.point -= 2;
	}

	if (b.point <= 2)
	{
		b.point += 11;
	}
	else if (b.point <= 13)
	{
		b.point -= 2;
	}
	return (a.point > b.point) ||
		(a.point == b.point && a.type < b.type);
}

//a����һ���ַ���ת��Ϊ���֣�����ֵ����У��ת���Ƿ�ɹ�
bool strtoi(const char * src, int &res)
{
	if (!src)
	{
		return false;
	}

	while (*src <= ' ')
	{
		src++;
	}

	int flag = 1;
	if (*src == '-')
	{
		flag = -1;
		src++;
	}

	if (*src > '9' || *src < '0')
	{
		return false;
	}

	int sum = 0, tmp;
	int i;
	for (i = 0; src[i] <= '9' && src[i] >= '0'; i++)
	{
		tmp = src[i] - '0';
		sum = sum * 10 + tmp;
	}
	res = sum * flag;

	return true;
}

//b����һ������ͨ��ָ�����ư�λ����ֱ�Ӹ���ԭ����
void sysReverse(int &num, int hex)
{
	int i;
	int tmp, sum = 0;
	for (i = num; i; i /= hex)
	{
		tmp = i % hex;
		sum = sum * hex + tmp;
	}
	num = sum;
}

int main3()
{
	int res;
	int num = 1723;
	sysReverse(num, 16);
	cout << num << endl;

	if (strtoi("\n\n\a\a\r\r\t\t\b\b   -478a193", res))
	{
		cout << res << endl;
	}
	else
	{
		cout << "fail\n";
	}

	return 0;
}

int main1()
{
	Poker p[5];

	int i;
	for (i = 0; i < 5; i++)
	{
		inputpoker(p + i);
	}

	InsertSort(p, 5, cmplulaoye);

	for (i = 0; i < 5; i++)
	{
		outputpoker(p[i]);
	}

	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#define SIZE(a) sizeof(a) / sizeof(a[0])

int main112()
{
	char murder[4] = { 'a', 'b', 'c', 'd' };
	char killer;
	int i;
	/*
	A˵�������ҡ�
	B˵����C��
	C˵����D��
	D˵��C�ں�˵
	*/
	for (i = 0; i < SIZE(murder); i++){
		killer = murder[i];
		if ((murder[0] != killer) + (murder[2] == killer)
			+ (murder[3] == killer) + (murder[3] != killer)==3){
			printf("killer is %c\n", killer);
		}
	}
	system("pause");
	return 0;
}
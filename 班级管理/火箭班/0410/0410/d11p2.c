#include <stdio.h>
#include <stdlib.h>

int main112()
{
	int murder = 0;
	for (murder = 'A'; murder < 'E'; ++murder)
	{
		/*A˵�������ҡ�
			B˵����C��
			C˵����D��
			D˵��C�ں�˵*/
		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3)
		{
			printf("%c������\n", murder);
		}
	}

	return 0;
}
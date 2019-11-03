#include "date.h"
#include <stdlib.h>

int main()
{
	Date d1(2000, 12, 31);
	Date d2(2012, 3, 1);

	cout << d1++ << endl;
	cout << d1-- << endl;
	cout << d1 << endl;

	cout << --d2 << endl;
	cout << ++d2 << endl;
	cout << d2 << endl;

	/*
	Date d1(2019, 9, 9);
	Date d2(-2735888, 9, 6);

	cout << (d1 - 100 - d2 - 100) << endl;

	cout << (d1 + 100 + 100 + 100 + 65) << endl;
	*/
	//cout << (d2 + 1000000000) << endl;

#if 0 //���ַ��䷽ʽ������
	Date * pd1 = (Date *)malloc(sizeof(Date));
	//ֻ�Ƿ���ռ�
	Date * pd2 = (Date *)operator new(sizeof(Date));
	//����ռ䣬ʧ�ܻ���ô���ʽ�������쳣
	Date * pd3 = new Date(1999, 12, 20);
	//��operator new�Ļ����ϵ����˹��캯��

	Date * pd = new Date[3]{Date(1999, 12, 20), Date(2000, 12, 20), Date(2001, 12, 20)};


	cout << pd[0] << endl;
	cout << pd[2] << endl;

	delete[] pd;
#endif

#if 0 //��λnew���ʽ
	char * pa = new char [1024];
	size_t size = 0;

	Date * pd = new(pa + size)Date(2015, 2, 22);

	//size += sizeof(Date);
	//Date * pd2 = new(pa + size)Date(2015, 2, 22);
	//cout << (void *)pa << endl << pd << endl << pd2;

	pd->~Date();
	delete pa;
#endif
	return 0;
}


/*class HeapOnly{
	int m_a;

	HeapOnly() :
		m_a(0)
	{

	}
public:
	static HeapOnly * createObject();
};

HeapOnly * HeapOnly::createObject()
{
	HeapOnly * ho = new HeapOnly;
	return ho;
}

int main()
{
	Date a(1, 2, 3);

	return 0;
}*/
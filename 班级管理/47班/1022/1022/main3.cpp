#include <iostream>
using namespace std;

class TestBase
{
public:
	TestBase()
	{
		cout << "���๹��" << endl;
	}

	~TestBase()
	{
		cout << "��������" << endl;
	}
};

class Test : public TestBase
{
public:
	Test()
	{
		cout << "�����๹��" << endl;
	}

	void fun()
	{
		cout << "����������" << endl;
	}

	~Test()
	{
		cout << "����������" << endl;
	}
};



int main3()
{
	Test t;

	t.fun();

	return 0;
}
//4. intŸ���� ������ ��üȭ�� Integer Ŭ������ �ۼ��ϼ���.
//Integer Ŭ������ Ȱ���ϴ� �ڵ�� ������ �����ϴ�.
// ���ߴ�..
#include <iostream>
#include <string>

using namespace std;

class Integer
{
private:
	int n;
	string m;

public:
	Integer(int _n)
	{
		n = _n;
	}
	Integer(string _m)
	{
		m = _m;
	}
	~Integer()
	{

	}
	int set()
	{

	}
	void get()
	{

	}
	void isEven()
	{

	}
};

void main()
{
	Integer n(30);
	cout << n.get() << ' ';		// 30���
	n.set(50);
	cout << n.get() << ' ';		// 50���

	Integer m("300");
	cout << m.get() << ' ';		// 300���
	cout << m.isEven();			// true(������ 1) ���
}

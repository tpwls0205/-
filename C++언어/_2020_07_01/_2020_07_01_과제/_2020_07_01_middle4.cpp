//4. Add, Sub, Mul, Div Ŭ������ ����ϴ�.
//�� Ŭ�������� ���������� 4���� ����� ������ �ֽ��ϴ�
//int a, b;
//void setValue(int x, int y);		// x�� a��, y�� b�� ����
//int calculate()					// ������ �����ϰ� ��� ����
//���α׷��� ���ѷ����� ���ϴ�
//
//3 4 *
//= > 12
//5 2 /
//= > 2

#include <iostream>

using namespace std;

class Add	// ��
{
private:
	int a, b;

public:
	void setValue(int x, int y)
	{
		a = x;
		b = y;
	}
	int calculate()
	{
		return a + b;
	}
};
class Sub	// ����
{
private:
	int a, b;

public:
	void setValue(int x, int y)
	{
		a = x;
		b = y;
	}
	int calculate()
	{
		return a - b;
	}
};
class Mul	// ��
{
private:
	int a, b;

public:
	void setValue(int x, int y)
	{
		a = x;
		b = y;
	}
	int calculate()
	{
		return a * b;
	}
};
class Div	// ������
{
private:
	int a, b;

public:
	void setValue(int x, int y)
	{
		a = x;
		b = y;
	}
	int calculate()
	{
		return a / b;
	}
};

void main()
{
	int x, y;
	Add ad;
	Sub su;
	Mul mu;
	Div di;
	while (1)
	{
		cout << "���� �Է� : ";
		cin >> x >> y;
		ad.setValue(x, y);
		su.setValue(x, y);
		mu.setValue(x, y);
		di.setValue(x, y);
		cout << "�� ���� �� : " << ad.calculate() << endl;
		cout << "�� ���� ���� : " << su.calculate() << endl;
		cout << "�� ���� �� : " << mu.calculate() << endl;
		cout << "�� ���� ������ : " << di.calculate() << endl;
	}
}
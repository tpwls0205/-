//4. Add, Sub, Mul, Div 클래스를 만듭니다.
//이 클래스들은 공통적으로 4개의 멤버를 가지고 있습니다
//int a, b;
//void setValue(int x, int y);		// x를 a에, y를 b에 저장
//int calculate()					// 연산을 실행하고 결과 리턴
//프로그램은 무한루프를 돕니다
//
//3 4 *
//= > 12
//5 2 /
//= > 2

#include <iostream>

using namespace std;

class Add	// 합
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
class Sub	// 빼기
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
class Mul	// 곱
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
class Div	// 나누기
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
		cout << "정수 입력 : ";
		cin >> x >> y;
		ad.setValue(x, y);
		su.setValue(x, y);
		mu.setValue(x, y);
		di.setValue(x, y);
		cout << "두 수의 합 : " << ad.calculate() << endl;
		cout << "두 수의 빼기 : " << su.calculate() << endl;
		cout << "두 수의 곱 : " << mu.calculate() << endl;
		cout << "두 수의 나누기 : " << di.calculate() << endl;
	}
}
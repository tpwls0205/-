//1. Calc클래스는 4개의 멤버를 가지고 있습니다
//Calc의 자식인 Add, Sub, Mul, Div 클래스를 만듭니다.
//int a, b;
//void setValue(int x, int y);	// x를 a에, y를 b에 저장
//virtual int calculate() = 0;					// 연산을 실행하고 결과 리턴
//
//calculate()함수는 클래스 마다 고유의 계산으로 재정의하세요
//
//main()함수에서 아래처럼 객체를 생성하세요
//Calc* calc[4] = { new Add(), new Sub(), new Mul(), new Div() };
//
//그리고 아래처럼 화면을 구현하세요
//
//[실행화면]
//계산을 선택하세요(0:Add, 1 : Sub, 2 : Mul, 3 : Div) >> 0
//= > Add 계산입니다
//= > 숫자 2개를 입력하세요 >> 10 20
//= > 결과는 30입니다
//
//계산을 선택하세요(0:Add, 1 : Sub, 2 : Mul, 3 : Div) >>

#include <iostream>
#include "Calc.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"

using namespace std;

void main()
{	
	Calc* calc[4] = { new Add(), new Sub(), new Mul(), new Div() };
	while (1)
	{	
		int sel;
		int one, two;
		cout << "계산을 선택하세요(0:Add, 1:Sub, 2:Mul, 3:Div) >> ";
		cin >> sel;
		if (sel == 0)
		{	
			cout << "Add 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 >> ";
			Add* ad = new Add();
			cin >> one >> two;
			ad->setvalue(one, two);
			cout << "결과는 " << ad->calculate() << "입니다" << endl;
		}
		if (sel == 1)
		{
			cout << "Sub 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 >> ";
			Sub* su = new Sub();
			cin >> one >> two;
			su->setvalue(one, two);
			cout << "결과는 " << su->calculate() << "입니다" << endl;
		}
		if (sel == 2)
		{
			cout << "Mul 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 >> ";
			Mul* mu = new Mul();
			cin >> one >> two;
			mu->setvalue(one, two);
			cout << "결과는 " << mu->calculate() << "입니다" << endl;
		}
		if (sel == 3)
		{
			cout << "Div 계산입니다" << endl;
			cout << "숫자 2개를 입력하세요 >> ";
			Div* di = new Div();
			cin >> one >> two;
			di->setvalue(one, two);
			cout << "결과는 " << di->calculate() << "입니다" << endl;
		}
	}
	delete[] calc;
}
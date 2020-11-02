//1. CalcŬ������ 4���� ����� ������ �ֽ��ϴ�
//Calc�� �ڽ��� Add, Sub, Mul, Div Ŭ������ ����ϴ�.
//int a, b;
//void setValue(int x, int y);	// x�� a��, y�� b�� ����
//virtual int calculate() = 0;					// ������ �����ϰ� ��� ����
//
//calculate()�Լ��� Ŭ���� ���� ������ ������� �������ϼ���
//
//main()�Լ����� �Ʒ�ó�� ��ü�� �����ϼ���
//Calc* calc[4] = { new Add(), new Sub(), new Mul(), new Div() };
//
//�׸��� �Ʒ�ó�� ȭ���� �����ϼ���
//
//[����ȭ��]
//����� �����ϼ���(0:Add, 1 : Sub, 2 : Mul, 3 : Div) >> 0
//= > Add ����Դϴ�
//= > ���� 2���� �Է��ϼ��� >> 10 20
//= > ����� 30�Դϴ�
//
//����� �����ϼ���(0:Add, 1 : Sub, 2 : Mul, 3 : Div) >>

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
		cout << "����� �����ϼ���(0:Add, 1:Sub, 2:Mul, 3:Div) >> ";
		cin >> sel;
		if (sel == 0)
		{	
			cout << "Add ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� >> ";
			Add* ad = new Add();
			cin >> one >> two;
			ad->setvalue(one, two);
			cout << "����� " << ad->calculate() << "�Դϴ�" << endl;
		}
		if (sel == 1)
		{
			cout << "Sub ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� >> ";
			Sub* su = new Sub();
			cin >> one >> two;
			su->setvalue(one, two);
			cout << "����� " << su->calculate() << "�Դϴ�" << endl;
		}
		if (sel == 2)
		{
			cout << "Mul ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� >> ";
			Mul* mu = new Mul();
			cin >> one >> two;
			mu->setvalue(one, two);
			cout << "����� " << mu->calculate() << "�Դϴ�" << endl;
		}
		if (sel == 3)
		{
			cout << "Div ����Դϴ�" << endl;
			cout << "���� 2���� �Է��ϼ��� >> ";
			Div* di = new Div();
			cin >> one >> two;
			di->setvalue(one, two);
			cout << "����� " << di->calculate() << "�Դϴ�" << endl;
		}
	}
	delete[] calc;
}
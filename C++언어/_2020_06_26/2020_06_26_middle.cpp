//1.swap(&a, &b) �� a�� b�� ���� ��ȯ�ǵ��� �ϴ� swap�Լ��� �����͸� ����ؼ� �ۼ��ϼ���
//
//2.swap(a, b) �� a�� b�� ���� ��ȯ�ǵ��� �ϴ� swap�Լ��� ���۷����� ����ؼ� �ۼ��ϼ���
//
//3.swap(&a, &b, &c) �� a = > b, b = > c, c = > a�� ���޵ǵ��� �����͸� ����ؼ� �ۼ��ϼ���
//
//4.swap(a, b, c) �� a = > b, b = > c, c = > a�� ���޵ǵ��� ���۷����� ����ؼ� �ۼ��ϼ���

//1.swap(&a, &b) �� a�� b�� ���� ��ȯ�ǵ��� �ϴ� swap�Լ��� �����͸� ����ؼ� �ۼ��ϼ���
#include <iostream>

using namespace std;

//void swap(int* a, int* b)
//{
//	int temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void main()
//{
//	int a = 10;
//	int b = 20;
//	swap(&a, &b);
//	cout << "a :" << a << endl << "b :" << b;
//}

//2.swap(a, b) �� a�� b�� ���� ��ȯ�ǵ��� �ϴ� swap�Լ��� ���۷����� ����ؼ� �ۼ��ϼ���

//void swap(int& a, int& b)
//{
//	int temp = 0;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//void main()
//{
//	int a = 10;
//	int b = 20;
//	swap(a, b);
//	cout << "a :" << a << endl << "b :" << b;
//}

//3.swap(&a, &b, &c) �� a = > b, b = > c, c = > a�� ���޵ǵ��� �����͸� ����ؼ� �ۼ��ϼ���

//void swap(int* a, int* b, int* c)
//{
//	int temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = *c;
//	*c = temp;
//}
//
//void main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	swap(&a, &b, &c);
//	cout << "a :" << a << endl << "b :" << b << endl << "c :" << c << endl;
//}

//4.swap(a, b, c) �� a = > b, b = > c, c = > a�� ���޵ǵ��� ���۷����� ����ؼ� �ۼ��ϼ���

void swap(int& a, int& b, int& c)
{
	int temp = 0;
	temp = a;
	a = b;
	b = c;
	c = temp;
}

void main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	swap(a, b, c);
	cout << "a :" << a << endl << "b :" << b << endl << "c :" << c << endl;
}
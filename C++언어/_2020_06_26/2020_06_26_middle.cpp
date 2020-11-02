//1.swap(&a, &b) 시 a와 b의 값이 교환되도록 하는 swap함수를 포인터를 사용해서 작성하세요
//
//2.swap(a, b) 시 a와 b의 값이 교환되도록 하는 swap함수를 레퍼런스를 사용해서 작성하세요
//
//3.swap(&a, &b, &c) 시 a = > b, b = > c, c = > a에 전달되도록 포인터를 사용해서 작성하세요
//
//4.swap(a, b, c) 시 a = > b, b = > c, c = > a에 전달되도록 레퍼런스를 사용해서 작성하세요

//1.swap(&a, &b) 시 a와 b의 값이 교환되도록 하는 swap함수를 포인터를 사용해서 작성하세요
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

//2.swap(a, b) 시 a와 b의 값이 교환되도록 하는 swap함수를 레퍼런스를 사용해서 작성하세요

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

//3.swap(&a, &b, &c) 시 a = > b, b = > c, c = > a에 전달되도록 포인터를 사용해서 작성하세요

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

//4.swap(a, b, c) 시 a = > b, b = > c, c = > a에 전달되도록 레퍼런스를 사용해서 작성하세요

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
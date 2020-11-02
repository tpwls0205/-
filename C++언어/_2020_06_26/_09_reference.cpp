#include <iostream>

using namespace std;

void swapPtr(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

// ���۷��� : ����, ����� == ��Ǳ�
// �����ͷ� �����ϴ� �� ������ �۾�, c���
// c++������ ��Ը� ������Ʈ�� ���� ���۷��� ��� ���� ���
// &�� ����� ������ �ּҸ� ��Ī�ϴ� �� �ƴ�
// int �� ra(����)���� ����Ű�� ���۷���
// 1. �������� Low���������� ����
// 2. ������ (������ ������ ���� �ý����� �ٸ� �κ��� ������ ��
//			�ִµ� �̷� ���� ���α׷����� ������ ������ ������ �� �ִ�.
//			=> �׷��� �������� �ش� �������� ������ ����ϴ� ������� �ٲ� ��
void swapRef(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

void main()
{
	int num0 = 10, num1 = 20;
	cout << "num0: " << num0 << endl;
	cout << "num1: " << num1 << endl;
	//swapPtr(&num0, &num1);
	swapRef(num0, num1);
	cout << "num0: " << num0 << endl;
	cout << "num1: " << num1 << endl;
}
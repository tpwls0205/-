/*
	c���� ���α׷��� �����ϴٰ� ������ �߻��� ��
	�Ϲ������� return ������ ó���Ѵ�.
	���ϴ� return ���� �ƴ� ���� ��������� �޼�����
	�����ְų� ���α׷��� �����Ѵ�.
*/
/*
	c��� ��Ÿ���� ����ó��
	1. �Ϲ������� �Լ��� ����� �� return�� ����� �������� �������� �Ǵ��Ѵ�.
	2. �׷��Ƿ� �����ϴ� �ڵ� �������� ������ ó���ϴ� �ڵ尡 ���� ������ �ȴ�.
	3. ����� ����ó���� ������ �ݺ������� �ڵ尡 ������� ������ �����ϱ� ���������.
*/
#include <iostream>

using namespace std;

// �����⸦ �ϴ� �Լ� (���� / �и� / �����)
// true�� ����, false�� ����
bool divide(double dividend, double divider, double& result)
{
	if (divider == 0)
	{
		return false;
	}
	result = dividend / divider;
	return true;
}

void main()
{
	double num1, num2, result;

	cout << "A/B�� ������ 2���� �� �Է�: ";
	cin >> num1 >> num2;
	if (divide(num1, num2, result)==true)
	{
		cout << num1 << "/" << num2 << "=" << result << endl;
	}
	else
	{
		cout << "Invalid Value!!!" << endl;
	}
}
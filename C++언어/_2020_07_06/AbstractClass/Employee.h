#pragma once
#include <iostream>

using namespace std;

/*  ���� ���� �Լ��� 1���̻��� ������
	�߻� Ŭ����(Abstract Class)�� �θ���
	�� Ŭ������ ��ü�� ���� �� ����

	������ ����� ������ �Ѵ�.
	
	main���� Employee ��ü ���� ��ü�� �� �� ����.
*/

class Employee
{
private:
	string name;
	string companyNum;
public:
	virtual void inputEmployee();
	virtual void showEmployee();
	virtual int calcPay() = 0;		// ���� ���� �Լ�, = 0 : �����ΰ� ���� ��
// �ڽ� 3Ŭ���� : ������, �ӽ���, �Ͽ��� => �޿��� ü�谡 �ٸ���. �θ� �ϰ������� �����ִ°� ���ǹ�(��¥�� �ڽ��� �������ؾ���)
};

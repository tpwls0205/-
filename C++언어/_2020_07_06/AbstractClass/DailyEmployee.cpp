#include "DailyEmployee.h"

void DailyEmployee::inputEmployee()
{
	Employee::inputEmployee();
	cout << "�ñ� �Է� : ";
	cin >> this->perTimePay;
	cout << "�ٹ��ð� �Է� : ";
	cin >> this->workHour;
}
void DailyEmployee::showEmployee()
{
	Employee::showEmployee();
	cout << "�ñ� : " << this->perTimePay << endl;
	cout << "�ٹ��ð� : " << this->workHour << endl;
	cout << "���� : " << this->calcPay() << endl;
}
int DailyEmployee::calcPay()
{
	return this->perTimePay * this->workHour;
}
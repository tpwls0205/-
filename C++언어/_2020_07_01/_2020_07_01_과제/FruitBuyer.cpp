#include "FruitBuyer.h"
#include <iostream>

using namespace std;

int FruitBuyer::buyApple(int money)
{
	int num = money / APPLE_PRICE;
	this->numOfApple += num;
	this->money -= money;
	return num;
}
void FruitBuyer::showBuyResult()
{
	cout << "[�������� ��Ȳ]" << endl;
	cout << "��� ���� : " << this->numOfApple << endl;
	cout << "���� �ܾ� : " << this->money << endl;
}
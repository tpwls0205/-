#include "FruitSeller.h"
#include <iostream>

using namespace std;

void FruitSeller::saleApple(FruitBuyer& buyer, int money)
{
	this->numOfApple = buyer.buyApple(money);
	this->money += money;
}
void FruitSeller::showSaleResult()
{
	cout << "[�Ǹ����� ��Ȳ]" << endl;
	cout << "���� ��� : " << this->numOfApple << endl;
	cout << "��ü �Ѿ� : " << this->money << endl;
	cout << endl;
}

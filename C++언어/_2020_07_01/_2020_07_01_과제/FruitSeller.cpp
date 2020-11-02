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
	cout << "[판매자의 현황]" << endl;
	cout << "남은 사과 : " << this->numOfApple << endl;
	cout << "전체 총액 : " << this->money << endl;
	cout << endl;
}

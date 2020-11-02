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
	cout << "[구매자의 현황]" << endl;
	cout << "사과 개수 : " << this->numOfApple << endl;
	cout << "현재 잔액 : " << this->money << endl;
}
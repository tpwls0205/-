#pragma once
#include "FruitBuyer.h"

class FruitSeller
{
private:
	int numOfApple = 20;
	int money = 100000;

public:
	void saleApple(FruitBuyer& buyer, int money);
	void showSaleResult();
};
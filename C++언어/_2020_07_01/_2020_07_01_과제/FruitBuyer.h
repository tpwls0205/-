#pragma once

class FruitBuyer
{
private:
	int money = 10000;
	int numOfApple = 0;
	const int APPLE_PRICE = 1000;

public:
	int buyApple(int money);
	void showBuyResult();
};
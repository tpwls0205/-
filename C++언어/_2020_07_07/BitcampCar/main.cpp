#include "ICar.h"
#include "HyundaiCar.h"
#include "KiaCar.h"
#include "ToyotaCar.h"
#include "CarTester.h"
#include "BenzCar.h"

void heapDeleteAll(ICar** dpICar, int len)
{
	for (int i = 0; i < len; i++)
	{
		delete dpICar[i];
	}
}

void main()
{
	ICar* arrICar[] = {new HyundaiCar(), new KiaCar(), new ToyotaCar(), new BenzCar()};
	CarTester carTester;
	for (int i = 0; i < sizeof(arrICar) / sizeof(arrICar[0]); i++)
	{
		carTester.setICar(arrICar[i]);
		carTester.testIntegration();
	}
	for (int i = 0; i < sizeof(arrICar) / sizeof(arrICar[0]); i++)
	{
		cout << "평가점수 : " << arrICar[i]->getScore() << endl;
	}
	heapDeleteAll(arrICar, sizeof(arrICar) / sizeof(arrICar[0]));
}
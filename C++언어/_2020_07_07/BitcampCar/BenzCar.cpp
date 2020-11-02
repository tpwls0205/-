#include "BenzCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

BenzCar::BenzCar()
{
	srand((unsigned int)time(NULL));	// ³­¼ö ÃÊ±âÈ­
	this->score = 0;
}
void BenzCar::driver()
{
	int num = rand() % B_DRIVER_SKILL + B_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::»Ñ¾Æ¾Ó ¿îÇàµÈ´Ù~" << endl;
}
void BenzCar::accel()
{
	int num = rand() % B_ACCEL_SKILL + B_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::ºÎ½ºÅÍ °¡¼ÓµÈ´Ù~" << endl;
}
void BenzCar::brake()
{
	int num = rand() % B_BRAKE_SKILL + B_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::Äç ¸ØÃá´Ù~" << endl;
}
int BenzCar::getScore()
{
	return this->score;
}
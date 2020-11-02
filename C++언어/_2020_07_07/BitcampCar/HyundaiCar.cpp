#include "HyundaiCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

HyundaiCar::HyundaiCar()
{
	srand((unsigned int)time(NULL));	// 난수 초기화
	this->score = 0;
}
void HyundaiCar::driver()
{
	int num = rand() % H_DRIVER_SKILL + H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::잘 운행된다~" << endl;
}
void HyundaiCar::accel()
{
	int num = rand() % H_ACCEL_SKILL + H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::잘 가속된다~" << endl;
}
void HyundaiCar::brake()
{
	int num = rand() % H_BRAKE_SKILL + H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -(num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::잘 멈춘다~" << endl;
}
int HyundaiCar::getScore()
{
	return this->score;
}
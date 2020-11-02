#include "ToyotaCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

ToyotaCar::ToyotaCar()
{
	srand((unsigned int)time(NULL));	// 난수 초기화
	this->score = 0;
}
void ToyotaCar::driver()
{
	int num = rand() % T_DRIVER_SKILL + T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::부드럽게 운행된다~" << endl;
}
void ToyotaCar::accel()
{
	int num = rand() % T_ACCEL_SKILL + T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::부드럽게 가속된다~" << endl;
}
void ToyotaCar::brake()
{
	int num = rand() % T_BRAKE_SKILL + T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::부드럽게 멈춘다~" << endl;
}
int ToyotaCar::getScore()
{
	return this->score;
}
#include "KiaCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

KiaCar::KiaCar()
{
	srand((unsigned int)time(NULL));	// 난수 초기화
	this->score = 0;
}
void KiaCar::driver()
{
	int num = rand() % K_DRIVER_SKILL + K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::매끄럽게 운행된다~" << endl;
}
void KiaCar::accel()
{
	int num = rand() % K_ACCEL_SKILL + K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::매끄럽게 가속된다~" << endl;
}
void KiaCar::brake()
{
	int num = rand() % K_BRAKE_SKILL + K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::매끄럽게 멈춘다~" << endl;
}
int KiaCar::getScore()
{
	return this->score;
}
#include "BenzCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

BenzCar::BenzCar()
{
	srand((unsigned int)time(NULL));	// ���� �ʱ�ȭ
	this->score = 0;
}
void BenzCar::driver()
{
	int num = rand() % B_DRIVER_SKILL + B_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�Ѿƾ� ����ȴ�~" << endl;
}
void BenzCar::accel()
{
	int num = rand() % B_ACCEL_SKILL + B_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�ν��� ���ӵȴ�~" << endl;
}
void BenzCar::brake()
{
	int num = rand() % B_BRAKE_SKILL + B_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�� �����~" << endl;
}
int BenzCar::getScore()
{
	return this->score;
}
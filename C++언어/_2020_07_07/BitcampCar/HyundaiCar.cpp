#include "HyundaiCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

HyundaiCar::HyundaiCar()
{
	srand((unsigned int)time(NULL));	// ���� �ʱ�ȭ
	this->score = 0;
}
void HyundaiCar::driver()
{
	int num = rand() % H_DRIVER_SKILL + H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�� ����ȴ�~" << endl;
}
void HyundaiCar::accel()
{
	int num = rand() % H_ACCEL_SKILL + H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�� ���ӵȴ�~" << endl;
}
void HyundaiCar::brake()
{
	int num = rand() % H_BRAKE_SKILL + H_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME -(num * BASIC_MULTIPLE_NUM));
	cout << "HyundaiCar::�� �����~" << endl;
}
int HyundaiCar::getScore()
{
	return this->score;
}
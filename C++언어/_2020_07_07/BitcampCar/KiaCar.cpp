#include "KiaCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

KiaCar::KiaCar()
{
	srand((unsigned int)time(NULL));	// ���� �ʱ�ȭ
	this->score = 0;
}
void KiaCar::driver()
{
	int num = rand() % K_DRIVER_SKILL + K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::�Ų����� ����ȴ�~" << endl;
}
void KiaCar::accel()
{
	int num = rand() % K_ACCEL_SKILL + K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::�Ų����� ���ӵȴ�~" << endl;
}
void KiaCar::brake()
{
	int num = rand() % K_BRAKE_SKILL + K_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "KiaCar::�Ų����� �����~" << endl;
}
int KiaCar::getScore()
{
	return this->score;
}
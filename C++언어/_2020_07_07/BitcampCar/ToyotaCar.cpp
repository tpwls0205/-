#include "ToyotaCar.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

ToyotaCar::ToyotaCar()
{
	srand((unsigned int)time(NULL));	// ���� �ʱ�ȭ
	this->score = 0;
}
void ToyotaCar::driver()
{
	int num = rand() % T_DRIVER_SKILL + T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::�ε巴�� ����ȴ�~" << endl;
}
void ToyotaCar::accel()
{
	int num = rand() % T_ACCEL_SKILL + T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::�ε巴�� ���ӵȴ�~" << endl;
}
void ToyotaCar::brake()
{
	int num = rand() % T_BRAKE_SKILL + T_BASIC_SCORE;
	this->score += num;
	Sleep(BASIC_SLEEP_TIME - (num * BASIC_MULTIPLE_NUM));
	cout << "ToyotaCar::�ε巴�� �����~" << endl;
}
int ToyotaCar::getScore()
{
	return this->score;
}
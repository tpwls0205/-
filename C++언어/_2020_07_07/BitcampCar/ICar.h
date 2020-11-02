#pragma once
#include <combaseapi.h>
#define BASIC_SLEEP_TIME 100
#define BASIC_MULTIPLE_NUM 5

interface ICar
{
	int score = 0;
	virtual void driver() = 0;
	virtual void accel() = 0;
	virtual void brake() = 0;
	virtual int getScore() = 0;
};
#pragma once
#include "ICar.h"
#define B_DRIVER_SKILL 10
#define B_ACCEL_SKILL 10
#define B_BRAKE_SKILL 10
#define B_BASIC_SCORE 5

class BenzCar : public ICar
{
public:
	BenzCar();
public:
	virtual void driver();
	virtual void accel();
	virtual void brake();
	virtual int getScore();
};
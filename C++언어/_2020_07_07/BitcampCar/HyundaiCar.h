#pragma once
#include "ICar.h"
#define H_DRIVER_SKILL 10
#define H_ACCEL_SKILL 8
#define H_BRAKE_SKILL 9
#define H_BASIC_SCORE 5

class HyundaiCar : public ICar
{
public:
	HyundaiCar();
public:
	virtual void driver();
	virtual void accel();
	virtual void brake();
	virtual int getScore();
};
#pragma once
#include "Calc.h"
class Sub : public Calc
{
public:
	void setvalue(int x, int y);	// x를 a에, y를 b에 저장
	virtual int calculate();
};


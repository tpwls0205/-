#pragma once
#include "Calc.h"

class Add : public Calc
{
public:
	void setvalue(int x, int y);	// x�� a��, y�� b�� ����
	virtual int calculate();
};


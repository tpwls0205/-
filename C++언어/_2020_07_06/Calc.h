#pragma once

class Calc
{
protected:
	int a, b;
public:
	void setvalue(int x, int y);
	virtual int calculate() = 0;
};
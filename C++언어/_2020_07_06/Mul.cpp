#include "Mul.h"

void Mul::setvalue(int x, int y)
{
	Calc::setvalue(x, y);
}
int Mul::calculate()
{
	return  a * b;
}
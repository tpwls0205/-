#include "Sub.h"

void Sub::setvalue(int x, int y)
{
	Calc::setvalue(x, y);
}
int Sub::calculate()
{
	return a - b;
}
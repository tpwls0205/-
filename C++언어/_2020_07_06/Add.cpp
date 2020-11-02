#include "Add.h"

void Add::setvalue(int x, int y)
{
	Calc::setvalue(x, y);
}
int Add::calculate()
{
	return a + b;
}
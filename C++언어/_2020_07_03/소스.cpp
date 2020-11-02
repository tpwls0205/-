#include "Human.h"
#include "ComputerEngineer.h"
#include "Programmer.h"
#include <iostream>
using namespace std;
void main()
{
	Human hu(23, "Àå±æ»ê");
	ComputerEngineer comEng(32,"ÀÓ²©Á¤", 3);
	Programmer prog(24, "È«±æµ¿", 2, 10);
	comEng.Overtime();
	prog.NeverEndingStudy();
}
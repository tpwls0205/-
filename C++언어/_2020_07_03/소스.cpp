#include "Human.h"
#include "ComputerEngineer.h"
#include "Programmer.h"
#include <iostream>
using namespace std;
void main()
{
	Human hu(23, "����");
	ComputerEngineer comEng(32,"�Ӳ���", 3);
	Programmer prog(24, "ȫ�浿", 2, 10);
	comEng.Overtime();
	prog.NeverEndingStudy();
}
#include <iostream>
#include "ComputerEngineer.h"
using namespace std;
ComputerEngineer::ComputerEngineer(int age, char* Name, int nComputer) :Human(age, Name)
{
	m_nComputer = nComputer;
	cout << "ComputerEngineer 생성자 호출" << endl;
}
ComputerEngineer::~ComputerEngineer()
{
	cout << "ComputerEngineer 소멸자호출" << endl;
}
void ComputerEngineer::Overtime()
{
	cout << m_strName << "는 야근을 한다" << endl;
}
void ComputerEngineer::Info()
{
	Human::Info();
	cout << m_strName << "는 컴퓨터를" << m_nComputer << "대 가지고 있다" << endl;
}
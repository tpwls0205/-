#include <iostream>
#include "ComputerEngineer.h"
using namespace std;
ComputerEngineer::ComputerEngineer(int age, char* Name, int nComputer) :Human(age, Name)
{
	m_nComputer = nComputer;
	cout << "ComputerEngineer ������ ȣ��" << endl;
}
ComputerEngineer::~ComputerEngineer()
{
	cout << "ComputerEngineer �Ҹ���ȣ��" << endl;
}
void ComputerEngineer::Overtime()
{
	cout << m_strName << "�� �߱��� �Ѵ�" << endl;
}
void ComputerEngineer::Info()
{
	Human::Info();
	cout << m_strName << "�� ��ǻ�͸�" << m_nComputer << "�� ������ �ִ�" << endl;
}
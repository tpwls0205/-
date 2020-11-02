#include "Programmer.h"
#include "Human.h"
#include <iostream>

using namespace std;
Programmer::Programmer(int age, char* Name, int nComputer, int nLanguage) : ComputerEngineer(age, Name, nComputer)
{
	m_nLanguage = nLanguage;
	cout << "Programmer ������ȣ��" << endl;
}

Programmer::~Programmer()
{
	cout << "Programmer �Ҹ���ȣ��" << endl;
}

void Programmer::NeverEndingStudy()
{
	cout << m_strName << "�� ��Ӱ����ϱ�" << endl;
}

void Programmer::Sleep()
{
	cout << m_strName << "�� �ʰ��߶�����������" << endl;
}

void Programmer::Overtime()
{
	ComputerEngineer::Overtime();
	cout << "����~" << endl;
}

void Programmer::Info()
{
	ComputerEngineer::Info();
	cout << m_strName << "�� �˰��ִ� ���α׷��� ��" << m_nLanguage << "�� �̴�" << endl;
}
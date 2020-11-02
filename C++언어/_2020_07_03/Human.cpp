#pragma warning(disable:4996)
#include<iostream>
#include"human.h"


using namespace std;
Human::Human(int age, char* Name)
{
	m_nAge = age;
	m_strName = new char[strlen(Name) + 1];
	strcpy(m_strName, Name);
	cout << "Human생성자호출" << endl;

}

Human::~Human()
{
	delete[] m_strName;
	cout << "Human소멸자호출" << endl;
}

void Human::Eat()
{
	cout << m_strName << "밥을 먹는다" << endl;

}
void Human::Sleep()
{
	cout << m_strName << "는 잠을 잔다" << endl;

}
void Human::Work()
{
	cout << m_strName << "는 일을 한다" << endl;
}

void Human::Info()
{
	cout << "이름:" << m_strName << endl;
	cout << "나이:" << m_nAge << endl;
}
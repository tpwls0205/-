#include "Human.h"

Human::Human(string name, int age)		// default 매개변수, 아무것도 값을 안받아오면 (사람,0) // 받아오면 (그 값)
{
	this->name = name;
	this->age = age;
	cout << "Human 생성자 호출" << endl;
}

Human::~Human()
{
	cout << "Human 소멸자 호출" << endl;
}

void Human::eat()
{
	cout << this->name << "은 밥을 먹는다" << endl;
}
void Human::sleep()
{
	cout << this->name << "은 잠을 잔다" << endl;
}
void Human::work()
{
	cout << this->name<< "은 일을 한다" << endl;
}
void Human::info()
{
	cout << "이름 : " << this->name << endl;
	cout << "나이 : " << this->age << endl;
}
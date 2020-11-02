#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	int age;
public:
	//Student(Student* this, string _name, int _age)
	Student(string name, int age)
	{
		this->name = name;		// this-> 하면 지역변수명이랑 클래스변수명이 같아도 구분이 가능.
		this->age = age;
	}
	//void showInfo(Student* this)
	void showInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
};

void main()
{
	Student st0("홍길동", 24);
	Student st1("임꺽정", 33);
	st0.showInfo();	// showInfo(&st0);
	st1.showInfo(); // showInfo(&st1);
}
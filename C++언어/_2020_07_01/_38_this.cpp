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
		this->name = name;		// this-> �ϸ� �����������̶� Ŭ������������ ���Ƶ� ������ ����.
		this->age = age;
	}
	//void showInfo(Student* this)
	void showInfo()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
};

void main()
{
	Student st0("ȫ�浿", 24);
	Student st1("�Ӳ���", 33);
	st0.showInfo();	// showInfo(&st0);
	st1.showInfo(); // showInfo(&st1);
}
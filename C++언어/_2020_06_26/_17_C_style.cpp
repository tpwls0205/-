#include <iostream>

using namespace std;

struct Student
{
	char name[20];
	int age;
};

void inputStudent(Student& st)
{
	cout << "�̸� �Է�: ";
	cin >> st.name;
	cout << "���� �Է�: ";
	cin >> st.age;
}
void showStudent(Student& st)
{
	cout << "�̸� : " << st.name << endl;
	cout << "���� : " << st.age << endl;
}

void main()
{
	Student st;
	inputStudent(st);
	showStudent(st);
}
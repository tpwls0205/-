#include <iostream>

using namespace std;

struct Student
{
	char name[20];
	int age;

	void inputStudent()
	{
		cout << "�̸� �Է�: ";
		cin >> name;
		cout << "���� �Է�: ";
		cin >> age;
	}
	void showStudent()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
};

void main()
{
	Student st;	// ������ �Լ��� ���� ������ ���� => ��ü
	st.inputStudent();
	st.showStudent();
}
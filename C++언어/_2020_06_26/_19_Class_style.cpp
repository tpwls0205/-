#include <iostream>

using namespace std;

// ����ü�� ������ �����ϴ°� ����.
// Ŭ������ ������ ����
// �ʿ��Ѱ� �� �����ϰ� �����.
class Student
{
private:	// ������, �������, �ܺ����� x
	char name[20];
	int age;

public:		// ������, �ܺ����� o
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
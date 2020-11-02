#include <iostream>

using namespace std;

// 구조체는 접근을 방해하는게 없다.
// 클래스는 접근을 방해
// 필요한것 만 노출하게 만든다.
class Student
{
private:	// 개인적, 멤버끼리, 외부접근 x
	char name[20];
	int age;

public:		// 공공의, 외부접근 o
	void inputStudent()
	{
		cout << "이름 입력: ";
		cin >> name;
		cout << "나이 입력: ";
		cin >> age;
	}
	void showStudent()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
};

void main()
{
	Student st;	// 변수와 함수를 같이 가지는 변수 => 객체
	st.inputStudent();
	st.showStudent();
}
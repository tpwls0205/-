#include <iostream>

#define NAME_LEN 20

using namespace std;

class Student
{
private:
	char* name;
	// 포인터변수 동적할당을 할때는 복사생성자를 사용해야한다.
public:
	Student()
	{
		name = new char[NAME_LEN];
	}
	Student(Student& st)		// 복사생성자의 매개변수는 반드시 래퍼런스를 써야한다
	{
		name = new char[NAME_LEN]();
		memcpy(name, st.name, NAME_LEN);
	}
	~Student()
	{
		delete[] name;
	}
public:
	void setName(const char* _name)
	{
		strncpy_s(name, NAME_LEN, _name, strlen(_name) + 1);
	}
	void showName()
	{
		cout << "이름 : " << name << endl;
	}
};

void main()
{
	Student st;
	st.setName("홍길동");
	st.showName();

	Student st1 = st;
	st1.showName();

	st1.setName("임꺽정");
	st.showName();
	st1.showName();
}
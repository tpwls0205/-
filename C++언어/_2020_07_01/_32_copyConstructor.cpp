#include <iostream>

#define NAME_LEN 20

using namespace std;

class Student
{
private:
	char* name;

public:
	Student()
	{
		name = new char[NAME_LEN];
	}
	Student(Student& st)
	{	
		/* 컴파일러가 생성해준 default 복사생성자의 역할
		   멤버간의 복사
		   (얕은 복사 : shallow copy)
		   name = st.name;
		*/

		// 공간을 할당 후 내용을 복사
		// 깊은 복사 : deep copy
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
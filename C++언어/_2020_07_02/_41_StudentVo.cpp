/*	MVC 패턴
	Model : 데이터, 데이터베이스, 파일
	1. VO(Value Object) : 값을 보관하는 역할의 객체
	2. DAO(Data Access Object) : 저장소와 입출력을 담당하는 객체
*/

#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	string address;
	int age;

public:
	Student(string name = "", string address = "", int age = 0)	// default 매개변수
	{
		this->name = name;
		this->address = address;
		this->age = age;
	}

public:
	// 변수에 대한 getter/setter 함수
	string getName()
	{
		return this->name;
	}
	Student& setName(string name)
	{
		this->name = name;
		return *this;				// this를 리턴할때 : 자기자신을 연속적으로 리턴할때는 this가 가르치는 주소의 값을 리턴
	}								// 연속적 리턴이기때문에 각 함수는 래퍼런스로 만들어야함.
	string getAddress()
	{
		return this->address;
	}
	Student& setAddress(string address)
	{
		this->address = address;
		return *this;
	}
	int getAge()
	{
		return this->age;
	}
	Student& setAge(int age)
	{
		this->age = age;
		return *this;
	}
};

void main()
{
	Student st;	// 현재 초기값을 안줬기때문에 default값을 가지고있음
	//setName(&st, "홍길동");
	st.setName("홍길동")
		.setAddress("지리산")
		.setAge(24);

	cout << st.getName() << ":" << st.getAddress() << ":" << st.getAge() << endl;
}
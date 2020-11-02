#include "_07_struct_01.h"
#include "_07_struct_02.h"
#include "_07_namespace.h"
#include <iostream>

using namespace A::Score;
using namespace std;

void main()
{
	//A:: Score::Student st = { "홍길동", 90, 88, 100 };
	Student st = { "홍길동", 90, 88, 100 };
	std::cout << "이름: " << st.name << std::endl;
	std::cout << "국어: " << st.kor << std::endl;
	std::cout << "수학: " << st.math << std::endl;
	std::cout << "영어: " << st.eng << std::endl;

	std::cout << std::endl << std::endl;

	B:: Personal::Student st1 = { "홍길동", "지리산", 24, 174.5f, 76.5f };
	std::cout << "이름: " << st1.name << std::endl;
	std::cout << "주소: " << st1.address << std::endl;
	std::cout << "나이: " << st1.age << std::endl;
	std::cout << "키: " << st1.height << std::endl;
	std::cout << "몸무게: " << st1.weight << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << A::name << std::endl;
	std::cout << B::name << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << A::job << std::endl;
	std::cout << B::job << std::endl;
}
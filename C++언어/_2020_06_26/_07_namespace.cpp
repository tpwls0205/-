#include "_07_struct_01.h"
#include "_07_struct_02.h"
#include "_07_namespace.h"
#include <iostream>

using namespace A::Score;
using namespace std;

void main()
{
	//A:: Score::Student st = { "ȫ�浿", 90, 88, 100 };
	Student st = { "ȫ�浿", 90, 88, 100 };
	std::cout << "�̸�: " << st.name << std::endl;
	std::cout << "����: " << st.kor << std::endl;
	std::cout << "����: " << st.math << std::endl;
	std::cout << "����: " << st.eng << std::endl;

	std::cout << std::endl << std::endl;

	B:: Personal::Student st1 = { "ȫ�浿", "������", 24, 174.5f, 76.5f };
	std::cout << "�̸�: " << st1.name << std::endl;
	std::cout << "�ּ�: " << st1.address << std::endl;
	std::cout << "����: " << st1.age << std::endl;
	std::cout << "Ű: " << st1.height << std::endl;
	std::cout << "������: " << st1.weight << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << A::name << std::endl;
	std::cout << B::name << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << A::job << std::endl;
	std::cout << B::job << std::endl;
}
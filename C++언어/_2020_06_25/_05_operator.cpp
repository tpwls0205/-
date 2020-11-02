#include <iostream>

void main()
{
	int num1, num2;									
	std::cout << "정수 2개 입력: " << std::endl;		// std라는 곳 안에 소속된 ::
	// std안에 소속된 콘솔아웃함수를 사용하고 std안에 소속된 개행문자를 사용
	// 연산자 오버로딩(직관적으로 표현한다)
	std::cin >> num1 >> num2;						// cin 콘솔로 부터 입력받아라.
	std::cout << num1 << "+" << num2 << "=" << num1 + num2 << std::endl;
}
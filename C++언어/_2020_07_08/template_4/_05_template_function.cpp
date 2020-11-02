#include <iostream>

/*
	C++ 클래스를 통해 확장과 설계를 꿈꾸는 개발자 그룹과 별개로
	다른 그룹에서는 논리가 동일한 문법을 쉽게 확장할 수 있는
	template문법을 연구적용하기 시작한다.
*/
/*
	Template은 Generic이라는 명칭으로 더 널리 사용되고 있다.
	주로 논리는 동일하고 자료형만 다른 함수나 클래스 구현에 사용된다.
	대표적인 예가 자료구조, 알고리즘이다.
	그래서 Template으로 만들어진 라이브러리가 STL이다.

	C# / JAVA에서는 Generic이라고 표현하고
	이를 통해 만들어진 라이브러리를 Collection이라고 표현한다.
*/

using namespace std;

template<typename T>
T add(T a, T b)
{
	cout << "General Template" << endl;
	return a + b;
}

/*
	<템플릿의 특화>
	T가 char*면 위의 것을 안쓰고
	이것으로 처리하겠다
*/
template<>
char* add(char* a, char* b)
{
	cout << "Special Template" << endl;
	int len = strlen(a) + strlen(b) + 1;
	char* p = new char[len]();
	strncpy_s(p, len, a, strlen(a));
	strncpy_s(p + strlen(a), len - strlen(a), b, strlen(b));
	p[strlen(a) + strlen(b)] = 0;
	return p;
}

void main()
{	
	cout << add<int>(100, 200) << endl;
	cout << add<double>(2.5, 3.4) << endl;
	cout << add<char*>((char*)"대한민국",(char*)"부산") << endl;
	cout << add<string>("대한민국", "부산");
}
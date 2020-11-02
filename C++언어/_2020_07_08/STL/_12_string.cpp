#include <iostream>

using namespace std;

void main()
{
	string str("Hi! How are you?");

	cout << "str length: " << str.length() << endl;
	printf("%s\n", str.c_str());	// 스트링클래스 내부에 char*로 배열의 시작주소를 리턴

	str.clear();					// 내부의 버퍼값을 지우고
	if (str.empty())				// 스트링이 비어있다면 출력해봐
	{
		cout << "Now string is empty." << endl;
		cout << "str length: " << str.length() << endl;
	}
}
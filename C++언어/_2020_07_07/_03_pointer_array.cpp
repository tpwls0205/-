#include <iostream>

using namespace std;

/*	
	포인터 배열의 시작주소를 함수에 전달할 때는
	2차원 포인터로 매개변수를 만들어야 한다.
*/
void printNames(const char** names, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << names[i] << endl;
	}
}
void main()
{
	const char* names[] = { "홍길동", "임꺽정", "장길산" };
	// 포인터 배열 : 포인터의 시작주소를 넘겨줘야하기 때문에 2차원 포인터 필요
	printNames(names, sizeof(names) / sizeof(names[0]));
}
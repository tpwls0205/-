#include <iostream>

#define ADD(x, y) ((x)+(y))

using namespace std;

inline int add(int a, int b)	// inline : 내용의 코드가 메인 안으로 들어와버림, 함수로 왔다갔다 x, 속도향상
{
	return a + b;
}

void main()
{
	int result = 0;
	for (int i = 0; i < 1000000; i++)
		result = add(result, i);
	cout << result << endl;
}
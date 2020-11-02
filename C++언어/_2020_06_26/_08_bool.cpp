#include <iostream>

using namespace std;

void main()
{
	int num;
	cout << "숫자 입력(1이면 3개반복): ";
	cin >> num;

	int cnt = 0;
	bool isRun = num == 1;	// bool 자료형은 true와 false만 존재, bool은 1byte 크기
	cout << "bool의 크기 : " << sizeof(bool) << endl;
	// while (num == 1)	// num = 1 버그의 원인이 될 수 있다.
	while (isRun == true)
	{
		cout << cnt << endl;
		cnt++;
		if (cnt == 3)
			break;
	}
}
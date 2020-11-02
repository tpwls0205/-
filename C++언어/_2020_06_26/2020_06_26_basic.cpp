//1. 1 ~100까지 더한 결과를 출력하세요.
//cout을 사용하세요.
//
//
//2. 1 ~100까지 한줄에 10개씩 출력하세요.
//정수는 탭으로 간격을 줄 것
//
//3. C를 C++의 cout, cin을 사용하여 바꾸세요
//
//#include <stdio.h>
//int main() { // 문제에 주어진 코드
//	int k, n = 0;
//	int sum = 0;
//	printf("끝 수를 입력하세요>>");
//	scanf("%d", &n);
//	for (k = 1; k <= n; k++) {
//		sum += k;
//	}
//	printf("1에서 %d까지의 합은 %d 입니다.\n", n, sum);
//	return 0;
//}

//1. 1 ~100까지 더한 결과를 출력하세요.
//cout을 사용하세요.
#include <iostream>

using namespace std;

void main1()
{	
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}
	cout << sum;
}

//2. 1 ~100까지 한줄에 10개씩 출력하세요.
//정수는 탭으로 간격을 줄 것

void main2()
{
	for (int i = 1; i <= 100; i++)
	{
		cout << i;
		cout << '\t';
		if (i % 10 == 0)
		{
			cout << endl;
		}
	}
}

//3. C를 C++의 cout, cin을 사용하여 바꾸세요
//
//#include <stdio.h>
//int main() { // 문제에 주어진 코드
//	int k, n = 0;
//	int sum = 0;
//	printf("끝 수를 입력하세요>>");
//	scanf("%d", &n);
//	for (k = 1; k <= n; k++) {
//		sum += k;
//	}
//	printf("1에서 %d까지의 합은 %d 입니다.\n", n, sum);
//	return 0;
//}

#include <stdio.h>
int main()
{
	int k, n = 0;
	int sum = 0;
	cout << "끝 수를 입력하세요>>";
	cin >> n;
	for (k = 1; k <= n; k++)
	{
		sum += k;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum << " 입니다" << endl;
}
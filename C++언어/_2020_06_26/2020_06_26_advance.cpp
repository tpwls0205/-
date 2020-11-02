//1. strcmp, strncmp, 직접 문자 하나하나 비교해서 검사하는 함수제작
//문자열 2개 입력받고 문자열이 같은지 다른지 검사하는 프로그램 작성하세요.
//
//cin, cout 사용할 것
//
//2. 사용자로부터 계속 정수를 입력받는다.
//- 1이 되면 출력한다.
//default로 5개를 동적할당하고
//5개를 넘어가면 + 5씩 동적할당을 증가시킨다.
//5 -> 10 -> 15
//반드시 new 연산자를 사용할 것
//
//3. TelInfo를 new delete를 사용하여 수정할 것
//
//4. 3번문제를 구조체에서 클래스로 전환할 것

//1. strcmp, strncmp, 직접 문자 하나하나 비교해서 검사하는 함수제작
//문자열 2개 입력받고 문자열이 같은지 다른지 검사하는 프로그램 작성하세요.

#include <iostream>
#pragma warning(disable:4996)

using namespace std;

//void main()
//{
//	char i[100] = { 0 };
//	char j[100] = { 0 };
//	cout << "문자열 2개를 입력 : ";
//	cin >> i >> j;
//	for (int num = 0; num < 100; num++)
//	{
//		if (i[num] == j[num])
//		{
//			cout << "문자열이 같습니다." << i << "과" << " " << j;
//			break;
//		}
//		else
//		{
//			cout << "문자열이 다릅니다." << i << "과" << " " << j;
//			break;
//		}
//	}
//}

//2. 사용자로부터 계속 정수를 입력받는다.
//- 1이 되면 출력한다.
//default로 5개를 동적할당하고
//5개를 넘어가면 + 5씩 동적할당을 증가시킨다.
//5 -> 10 -> 15
//반드시 new 연산자를 사용할 것
#define num_len 5
void main()
{	// 5개가되면 지우고 다시 재할당
	// 인덱스가 지금 사이즈보다 if문 들어가서 num포인터에 재할당
	cout << "정수를 입력해주세요(출력은 -1을 적어주세요) : ";
	int* num = new int[num_len];
	for (int i = 1; i <= num_len; i++)
	{	
		cin >> num[i];
		if (num[i] == -1)
		{
			cout << num[i] << " ";
		}
	}
	delete[] num;
}

//4. 구조체에서 클래스로 전환할 것
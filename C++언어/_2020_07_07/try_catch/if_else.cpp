/*
	c언어에서 프로그램이 동작하다가 오류가 발생할 때
	일반적으로 return 값으로 처리한다.
	원하는 return 값이 아닐 때는 사용자한테 메세지를
	보여주거나 프로그램을 종료한다.
*/
/*
	c언어 스타일의 오류처리
	1. 일반적으로 함수를 사용할 때 return의 결과로 오류인지 성공인지 판단한다.
	2. 그러므로 실행하는 코드 다음에는 오류를 처리하는 코드가 종종 나오게 된다.
	3. 실행과 오류처리의 영역이 반복됨으로 코드가 길어지면 논리에만 집중하기 어려워진다.
*/
#include <iostream>

using namespace std;

// 나누기를 하는 함수 (분자 / 분모 / 결과값)
// true면 성공, false면 실패
bool divide(double dividend, double divider, double& result)
{
	if (divider == 0)
	{
		return false;
	}
	result = dividend / divider;
	return true;
}

void main()
{
	double num1, num2, result;

	cout << "A/B를 연산할 2개의 수 입력: ";
	cin >> num1 >> num2;
	if (divide(num1, num2, result)==true)
	{
		cout << num1 << "/" << num2 << "=" << result << endl;
	}
	else
	{
		cout << "Invalid Value!!!" << endl;
	}
}
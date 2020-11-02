/*

*/

#include <iostream>

using namespace std;

void divide(double dividend, double divider, double& result)
{
	if (divider == 0)
	{
		throw false;		// throw를 만나면 바로 catch{}로 보낸다
	}
	result = dividend / divider;
}

void loop(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		cout << i << ",";
		cout << endl;
	}
}

string getStrNum()
{
	string strNum;
	cout << "숫자를 입력하세요: ";
	cin >> strNum;
	return strNum;
}

void main()
{
	double num1, num2, result;

	cout << "A/B 를 연산할 2개의 수 입력: ";
	cin >> num1 >> num2;

	try		// 코드 실행 영역
	{	
		// bool 예외 영역
		divide(num1, num2, result);
		cout << num1 << "/" << num2 << "=" << result << endl;

		// string 예외 영역
		string strNum = getStrNum();
		if (strNum[0] >= '0' && strNum[0] <= '9')
		{
			int num = atoi(strNum.c_str());		// 문자열을 정수로 변환 , c_str() : 문자열의 시작주소
			loop(num);
		}
		else 
		{
			throw "숫자가 아님!";
		}
	}
	catch (bool exception)		// 예외 처리 영역
	{
		cout << "Invalid Value!!!" << endl;
	}
	catch (const char* exception)
	{
		cout << exception << endl;
	}
}
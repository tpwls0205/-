/*

*/

#include <iostream>

using namespace std;

void divide(double dividend, double divider, double& result)
{
	if (divider == 0)
	{
		throw false;		// throw�� ������ �ٷ� catch{}�� ������
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
	cout << "���ڸ� �Է��ϼ���: ";
	cin >> strNum;
	return strNum;
}

void main()
{
	double num1, num2, result;

	cout << "A/B �� ������ 2���� �� �Է�: ";
	cin >> num1 >> num2;

	try		// �ڵ� ���� ����
	{	
		// bool ���� ����
		divide(num1, num2, result);
		cout << num1 << "/" << num2 << "=" << result << endl;

		// string ���� ����
		string strNum = getStrNum();
		if (strNum[0] >= '0' && strNum[0] <= '9')
		{
			int num = atoi(strNum.c_str());		// ���ڿ��� ������ ��ȯ , c_str() : ���ڿ��� �����ּ�
			loop(num);
		}
		else 
		{
			throw "���ڰ� �ƴ�!";
		}
	}
	catch (bool exception)		// ���� ó�� ����
	{
		cout << "Invalid Value!!!" << endl;
	}
	catch (const char* exception)
	{
		cout << exception << endl;
	}
}
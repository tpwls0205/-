#include <iostream>
#include <string>

using namespace std;

void main()
{
	string s0("C++ string");
	string s1(s0);
	string s2(s0, 1, 2);	// �ε��� 1���� �ε��� 2����
	string s3(10, 'x');		// 'x'�� 10��

		cout << s0 << endl;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
}
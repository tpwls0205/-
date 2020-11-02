#include <iostream>
#include <string>

using namespace std;

void main()
{
	string s0("C++ string");
	string s1(s0);
	string s2(s0, 1, 2);	// 인덱스 1부터 인덱스 2까지
	string s3(10, 'x');		// 'x'가 10개

		cout << s0 << endl;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
}
#include <iostream>

using namespace std;

void main()
{
	string s0("I have money");
	string s1("You need a dream");
	string s2;

	s2 = s0.substr(0, 7); // 문자열에 포함된 일부 문자열을 뽑아내라 : 인덱스 0부터 7글자 추출
	s2.append(s1, 9, 7);  // s1의 인덱스 9부터 7글자를 추가
	s2.append(3, '!');	  // '!'를 3개 추가해라
	s2 += "\n";

	cout << s2;
}
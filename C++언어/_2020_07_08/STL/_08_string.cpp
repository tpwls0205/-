#include <iostream>

using namespace std;

void main()
{
	string s0("I have money");
	string s1("You need a dream");
	string s2;

	s2 = s0.substr(0, 7); // ���ڿ��� ���Ե� �Ϻ� ���ڿ��� �̾Ƴ��� : �ε��� 0���� 7���� ����
	s2.append(s1, 9, 7);  // s1�� �ε��� 9���� 7���ڸ� �߰�
	s2.append(3, '!');	  // '!'�� 3�� �߰��ض�
	s2 += "\n";

	cout << s2;
}
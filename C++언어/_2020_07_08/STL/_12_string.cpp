#include <iostream>

using namespace std;

void main()
{
	string str("Hi! How are you?");

	cout << "str length: " << str.length() << endl;
	printf("%s\n", str.c_str());	// ��Ʈ��Ŭ���� ���ο� char*�� �迭�� �����ּҸ� ����

	str.clear();					// ������ ���۰��� �����
	if (str.empty())				// ��Ʈ���� ����ִٸ� ����غ�
	{
		cout << "Now string is empty." << endl;
		cout << "str length: " << str.length() << endl;
	}
}
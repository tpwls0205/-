#include <iostream>

using namespace std;

void main()
{
	int num;
	cout << "���� �Է�(1�̸� 3���ݺ�): ";
	cin >> num;

	int cnt = 0;
	bool isRun = num == 1;	// bool �ڷ����� true�� false�� ����, bool�� 1byte ũ��
	cout << "bool�� ũ�� : " << sizeof(bool) << endl;
	// while (num == 1)	// num = 1 ������ ������ �� �� �ִ�.
	while (isRun == true)
	{
		cout << cnt << endl;
		cnt++;
		if (cnt == 3)
			break;
	}
}
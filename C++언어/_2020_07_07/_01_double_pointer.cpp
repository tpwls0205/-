#include <iostream>

using namespace std;

/*	
	int* ptr����
	int*�� �ڷ����̰� ptr�� �����̸��̴�.
	�ٸ� ptr�� int������ int�迭�� �����ּҸ�
	���� �� �ִ� ���ҷ� ������ ���̴�.
	�׷��� ptr�� &ptr�� ����ϸ�
	ptr�� �ּҰ� ����� �ȴ�
*/

void main()
{
	int num = 10;
	int* ptr = &num;

	cout << &num << endl;			// num�� �ּ�
	cout << *ptr << endl;			// ptr�� ����Ű�� ��
	cout << sizeof(ptr) << endl;	// ptr������ ũ��
	cout << &ptr << endl;			// ptr������ �ּ�
}
#include <iostream>

using namespace std;

void main()
{
	int num = 10;
	int* ptr = &num;
	int** dptr = &ptr;
	int*** tptr = &dptr;
	
	cout << num << endl;			// num�� ��
	cout << *ptr << endl << endl;	// num�� ��
	cout << dptr << endl;			// ptr�� �ּ�
	cout << *dptr << endl;			// num�� �ּ�
	cout << **dptr << endl;			// num�� ��
	cout << ***tptr << endl;		// num�� ��
}
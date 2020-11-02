#include <iostream>

using namespace std;

void main()
{
	int num = 10;
	int* ptr = &num;
	int** dptr = &ptr;
	int*** tptr = &dptr;
	
	cout << num << endl;			// num의 값
	cout << *ptr << endl << endl;	// num의 값
	cout << dptr << endl;			// ptr의 주소
	cout << *dptr << endl;			// num의 주소
	cout << **dptr << endl;			// num의 값
	cout << ***tptr << endl;		// num의 값
}
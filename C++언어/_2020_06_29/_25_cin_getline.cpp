#include <iostream>

using namespace std;

void main()
{
	cout << "�ּ� �Է� : ";
	char address[100];
	cin.getline(address, sizeof(address), 0x20);	// �����̽� �������� ©��� // char�� getline
	cout << address << endl;
}
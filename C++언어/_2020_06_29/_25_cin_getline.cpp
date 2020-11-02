#include <iostream>

using namespace std;

void main()
{
	cout << "주소 입력 : ";
	char address[100];
	cin.getline(address, sizeof(address), 0x20);	// 스페이스 기준으로 짤라라 // char형 getline
	cout << address << endl;
}
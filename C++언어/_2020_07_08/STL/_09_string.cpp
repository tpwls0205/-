#include <iostream>

using namespace std;

void main()
{
	string str("M red ballon matches my red hat.");
	string red("red");
	string blue("blue");

	size_t found = str.find(red);	// str���� red��� ���ڸ� ã�ƶ�
	while (found != string::npos)	// npos ��ã���� �� ������ ��
	{
		str.replace(found, red.length(), blue);
		found = str.find(red, found + 1);
	}
	cout << str << endl;
}
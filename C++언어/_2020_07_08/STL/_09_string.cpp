#include <iostream>

using namespace std;

void main()
{
	string str("M red ballon matches my red hat.");
	string red("red");
	string blue("blue");

	size_t found = str.find(red);	// str에서 red라는 글자를 찾아라
	while (found != string::npos)	// npos 못찾았을 때 나오는 값
	{
		str.replace(found, red.length(), blue);
		found = str.find(red, found + 1);
	}
	cout << str << endl;
}
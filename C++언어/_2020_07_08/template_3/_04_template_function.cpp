#include <iostream>

/*
	C++ Ŭ������ ���� Ȯ��� ���踦 �޲ٴ� ������ �׷�� ������
	�ٸ� �׷쿡���� ���� ������ ������ ���� Ȯ���� �� �ִ�
	template������ ���������ϱ� �����Ѵ�.
*/
/*
	Template�� Generic�̶�� ��Ī���� �� �θ� ���ǰ� �ִ�.
	�ַ� ���� �����ϰ� �ڷ����� �ٸ� �Լ��� Ŭ���� ������ ���ȴ�.
	��ǥ���� ���� �ڷᱸ��, �˰����̴�.
	�׷��� Template���� ������� ���̺귯���� STL�̴�.

	C# / JAVA������ Generic�̶�� ǥ���ϰ�
	�̸� ���� ������� ���̺귯���� Collection�̶�� ǥ���Ѵ�.
*/

using namespace std;

// ���� == �ؾƲ
// add �Լ��� ���� Ʋ
// ��� : int, double
template<typename T>
T add(T a, T b)
{
	return a + b;
}
void main()
{	
	cout << add<int>(100, 200) << endl;
	cout << add<double>(2.5, 3.4) << endl;

	//cout << add(100, 200) << endl;
	//cout << add(2.5, 3.4) << endl;
}
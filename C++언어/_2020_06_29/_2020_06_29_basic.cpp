//1. Random Ŭ������ �����
//
//#include <iostream>
//#include <cstdlib>
//#include <ctime> 
//
//using namespace std;
//
//// Random �̶� Ŭ���� ����
//// next()��� �Լ� ����
//// nextInRange(int x, int y)����
//
//class Random
//{
//private:
//
//public:
//	int next()
//	{	
//		int n = rand();
//		return n;
//	}
//	int nextInRange(int x, int y)
//	{
//		int n;
//		n = rand() % (y - 1) + x;
//		return n;
//	}
//};
//
//int main() {
//	srand(time(NULL));			// �ѹ��ϸ� ��� ������ ���� �� ����
//	Random r;
//	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
//		cout << n << ' ';
//	}
//	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
//		cout << n << ' ';
//	}
//	cout << endl;
//}


//2. Oval Ŭ���� �����
//
#include <iostream>
using namespace std;

// class Oval ����
// Oval ������ ����
// set(int x, int y) �Լ� ����
// show() �Լ� ����
// getwidth() �Լ� ����
// getHeight() �Լ� ����

class Oval
{
private:
	int w;
	int h;
	int i;
	int j;
	
public:
	Oval()
	{
	}
	Oval(int _w, int _h)
	{
		w = _w;
		h = _h;
	}
	~Oval()
	{
		cout << "�Ҹ��� �Լ�";
	}
	void set(int _i, int _j)
	{
		i = _i;
		j = _j;
	}
	void show()
	{
		cout << i << "," << j << endl;
	}
	int getWidth()
	{
		return w;
	}
	int getHeight()
	{
		return h;
	}


};

// main() �Լ�
int main() {
	Oval a; 
	Oval b(3, 4);
	a.set(10, 20);			// �� : ����, �� : ��������
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}


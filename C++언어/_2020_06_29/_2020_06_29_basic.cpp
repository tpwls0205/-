//1. Random 클래스를 만들것
//
//#include <iostream>
//#include <cstdlib>
//#include <ctime> 
//
//using namespace std;
//
//// Random 이란 클래스 생성
//// next()라는 함수 생성
//// nextInRange(int x, int y)생성
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
//	srand(time(NULL));			// 한번하면 계속 랜덤한 난수 값 생성
//	Random r;
//	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
//		cout << n << ' ';
//	}
//	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
//	for (int i = 0; i < 10; i++) {
//		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
//		cout << n << ' ';
//	}
//	cout << endl;
//}


//2. Oval 클래스 만들기
//
#include <iostream>
using namespace std;

// class Oval 생성
// Oval 생성자 생성
// set(int x, int y) 함수 생성
// show() 함수 생성
// getwidth() 함수 생성
// getHeight() 함수 생성

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
		cout << "소멸자 함수";
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

// main() 함수
int main() {
	Oval a; 
	Oval b(3, 4);
	a.set(10, 20);			// 셋 : 저장, 겟 : 가져오다
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}


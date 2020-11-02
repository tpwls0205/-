//1. Random 클래스를 상속해서 짝수 정수만 랜덤하게 발생시키는 EvenRandom 클래스를 작성하고
//next()를 재정의하여
//10개의 짝수를 랜덤하게 출력하는 프로그램을 완성하세요.
//0도 짝수로 처리합니다.

//2. EvenRandom 클래스를 상속해 짝수, 홀수를 선택할 수 있는 생성자를 가진
//생성자를 가진 SelectableRandom 클래스를 작성하고
//next()를 재정의하여
//각각 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하세요.

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// 임의의 정수를 랜덤하게 제공하는 클래스
class Random {
public:
	Random(); // 생성자. 랜덤 seed를 설정한다.
	int next(); // 랜덤 정수를 리턴한다.
};

Random::Random() {
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
}

int Random::next() {
	return rand(); // 0에서 RAND_MAX 사이의 랜덤한 정수 리턴
}

class EvenRandom : public Random	// EvenRandom은 Random의 자식
{
public:
	int next();
};

int EvenRandom::next()
{
	int a = rand();
	{
		while (a % 2 != 0)
			a = rand();
	}
	return a;
}

class SelectableRandom : public EvenRandom
{
private:
	int sel;
public:
	SelectableRandom()
	{
	}
	SelectableRandom(int sel)
	{	
		this->sel = sel;
	}
	~SelectableRandom()
	{
	}
public:
	int next();
};

int SelectableRandom::next()
{
	int a = 0;
	if (sel == 0) {//짝수
		a = EvenRandom::next();
	}
	else if (sel == 1) {//홀수
		a = EvenRandom::next();
		while (a % 2 == 0) {
			a = rand();
		}
	}
	return a;
}

int main() {
	Random r;
	
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for(int i=0; i<10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}

	cout << endl << endl;

	EvenRandom r1;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r1.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << " ";
	}

	cout << endl << endl;

	SelectableRandom even(0), odd(1);
	int j = 0;
	cout << "-- 0에서 " << RAND_MAX << "까지의 선택 정수 10 개 (0==짝수, 1==홀수) --" << endl;
	cin >> j;
	if (j == 0)
	{
		for (int i = 0; i < 10; i++) {
			int n = even.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
			cout << n << " ";
		}
	}
	if (j == 1)
	{
		for (int i = 0; i < 10; i++) {
			int n = odd.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
			cout << n << " ";
		}
	}
}
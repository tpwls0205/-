//2. 1번을 참고해서 짝수 정수만 랜덤하게 발생시키는 EvenRandom 클래스를 작성하고
//10개의 짝수를 랜덤하게 출력하는 프로그램을 완성하세요.
//0도 짝수로 처리합니다.

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// 임의의 정수를 랜덤하게 제공하는 클래스
class EvenRandom {
public:
	EvenRandom(); // 생성자. 랜덤 seed를 설정한다.
	int next(); // 랜던 정수를 리턴한다.
	int nextInRange(int low, int high); // low와 high 사이의 랜덤 정수를 리턴한다.
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
}

int EvenRandom::next() {

	int random = 0;
	while(1)
	{	
		random = rand();
		
		if (random % 2 == 0)
		{
			return random; // 0에서 RAND_MAX 사이의 랜덤한 정수 리턴
		}
	}
}

int EvenRandom::nextInRange(int low, int high) {
	int range = (high - low) + 1;
	return low + (rand() % range); // low와 high 사이의 랜덤 정수를 리턴한다. 
}

int main() {
	EvenRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}
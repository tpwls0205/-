//2. 1���� �����ؼ� ¦�� ������ �����ϰ� �߻���Ű�� EvenRandom Ŭ������ �ۼ��ϰ�
//10���� ¦���� �����ϰ� ����ϴ� ���α׷��� �ϼ��ϼ���.
//0�� ¦���� ó���մϴ�.

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// ������ ������ �����ϰ� �����ϴ� Ŭ����
class EvenRandom {
public:
	EvenRandom(); // ������. ���� seed�� �����Ѵ�.
	int next(); // ���� ������ �����Ѵ�.
	int nextInRange(int low, int high); // low�� high ������ ���� ������ �����Ѵ�.
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int EvenRandom::next() {

	int random = 0;
	while(1)
	{	
		random = rand();
		
		if (random % 2 == 0)
		{
			return random; // 0���� RAND_MAX ������ ������ ���� ����
		}
	}
}

int EvenRandom::nextInRange(int low, int high) {
	int range = (high - low) + 1;
	return low + (rand() % range); // low�� high ������ ���� ������ �����Ѵ�. 
}

int main() {
	EvenRandom r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}
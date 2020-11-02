//1. Random Ŭ������ ����ؼ� ¦�� ������ �����ϰ� �߻���Ű�� EvenRandom Ŭ������ �ۼ��ϰ�
//next()�� �������Ͽ�
//10���� ¦���� �����ϰ� ����ϴ� ���α׷��� �ϼ��ϼ���.
//0�� ¦���� ó���մϴ�.

//2. EvenRandom Ŭ������ ����� ¦��, Ȧ���� ������ �� �ִ� �����ڸ� ����
//�����ڸ� ���� SelectableRandom Ŭ������ �ۼ��ϰ�
//next()�� �������Ͽ�
//���� ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷��� �ۼ��ϼ���.

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// ������ ������ �����ϰ� �����ϴ� Ŭ����
class Random {
public:
	Random(); // ������. ���� seed�� �����Ѵ�.
	int next(); // ���� ������ �����Ѵ�.
};

Random::Random() {
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int Random::next() {
	return rand(); // 0���� RAND_MAX ������ ������ ���� ����
}

class EvenRandom : public Random	// EvenRandom�� Random�� �ڽ�
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
	if (sel == 0) {//¦��
		a = EvenRandom::next();
	}
	else if (sel == 1) {//Ȧ��
		a = EvenRandom::next();
		while (a % 2 == 0) {
			a = rand();
		}
	}
	return a;
}

int main() {
	Random r;
	
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for(int i=0; i<10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}

	cout << endl << endl;

	EvenRandom r1;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ¦�� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r1.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << " ";
	}

	cout << endl << endl;

	SelectableRandom even(0), odd(1);
	int j = 0;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 �� (0==¦��, 1==Ȧ��) --" << endl;
	cin >> j;
	if (j == 0)
	{
		for (int i = 0; i < 10; i++) {
			int n = even.next(); // 0���� RAND_MAX(32767) ������ ������ ����
			cout << n << " ";
		}
	}
	if (j == 1)
	{
		for (int i = 0; i < 10; i++) {
			int n = odd.next(); // 0���� RAND_MAX(32767) ������ ������ ����
			cout << n << " ";
		}
	}
}
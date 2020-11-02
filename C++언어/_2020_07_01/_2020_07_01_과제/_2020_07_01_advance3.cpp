//3. 짝수, 홀수를 선택할 수 있는 생성자를 가진 SelectableRandom 클래스를 작성하고
//각각 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하세요.

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

class SelectableRandom
{
private:
	int _x;

public:
	SelectableRandom()
	{
		srand((unsigned)time(0));
	}
	~SelectableRandom()
	{

	}
	int selectablerandom(int _x);
};

int SelectableRandom::selectablerandom(int _x)
{
	if (_x == 0)
	{
		int random = 0;
		while (1)
		{
			random = rand();

			if (random % 2 == 0)
			{
				return random; // 0에서 RAND_MAX 사이의 랜덤한 정수 리턴
			}
		}
	}
	if (_x == 1)
	{
		int random = 0;
		while (1)
		{
			random = rand();

			if (random % 2 == 1)
			{
				return random; // 0에서 RAND_MAX 사이의 랜덤한 정수 리턴
			}
		}
	}
}

void main()
{
	SelectableRandom r;
	int x;
	cout << "0을 누르면 짝수, 1을 누르면 홀수" << endl;
	cin >> x;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.selectablerandom(x); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
}
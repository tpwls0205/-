//3. ¦��, Ȧ���� ������ �� �ִ� �����ڸ� ���� SelectableRandom Ŭ������ �ۼ��ϰ�
//���� ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷��� �ۼ��ϼ���.

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
				return random; // 0���� RAND_MAX ������ ������ ���� ����
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
				return random; // 0���� RAND_MAX ������ ������ ���� ����
			}
		}
	}
}

void main()
{
	SelectableRandom r;
	int x;
	cout << "0�� ������ ¦��, 1�� ������ Ȧ��" << endl;
	cin >> x;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.selectablerandom(x); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
}
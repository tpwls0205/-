#include "StarUnit.h"
#include "Scv.h"
#include "Marine.h"
#include "Hydra.h"
#include "FireSoldier.h"
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*	�������� �������� ǥ��
	1. ���ȿ����� �θ������ �����ϴ� �ڽ�
	2. ���۽ô� �ڽŸ��� ������ �� ����
*/

/*	�������� ����
	1. ������ �迭�� ��� �Ļ� Ŭ������ �ϰ� ���� �� �ִ�.
	2. �θ� ������ ������ ���� �ڽ� ��ü�� �����ص�
		virtual �Լ��� �ڽ� ��ü ������ ������ �ϰ� �ȴ�.
	3. ���ο� Unit�� �ʿ��� �� �θ� ��Ӹ� �޾Ƶ�
		���� �ڵ忡 ������ �� �ִ�.
		3-1. �θ� ������ �迭 : ��� ����
		3-2. �θ� ������ �Ű����� : �ڽİ�ü : ������ ���
			�θ�Ŭ���� ��� �� virtual�Լ� �߰����ָ�
			������ �ڵ带 ��ġ�� �ʰ� �״�� ��밡��
*/

int randomSleep()
{
	int delay = rand() % 2000 + 500;	// 500~2499
	Sleep(delay);
	return delay;
}

void hitAndRun(StarUnit* pUnit)
{
	pUnit->attack();
	int delay = randomSleep();
	if (delay < 1500) 
	{ 
		pUnit->die();
	}
	else 
	{ 
		pUnit->move();
	}
}

//void deleteStarUnit(StarUnit* unit[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		delete unit[i];
//	}
//}

void main()
{
	srand((unsigned int)time(NULL));	// ���� �ʱ�ȭ
	/*	1. ������ �ڽİ���
		�ڽİ�ü���� �θ� ������ ����
		�迭�� �ϰ� ������ �� �ִ�
	*/
	StarUnit* unit[] = { new Scv(), new Marine(), new Hydra(), new FireSoldier() };
	hitAndRun(unit[0]);
	cout << endl;
	hitAndRun(unit[1]);
	cout << endl;
	hitAndRun(unit[2]);
	cout << endl;
	hitAndRun(unit[3]);
	cout << endl;

	/*deleteStarUnit(unit, 3);*/
	delete unit[0];
	delete unit[1];
	delete unit[2];
	delete unit[3];
}
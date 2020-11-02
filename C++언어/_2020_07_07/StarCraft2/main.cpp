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

/*	다형성의 비유적인 표현
	1. 집안에서는 부모님한테 순응하는 자식
	2. 동작시는 자신만의 개성을 잘 발휘
*/

/*	다형성의 장점
	1. 포인터 배열로 모든 파생 클래스를 일괄 묶을 수 있다.
	2. 부모 포인터 변수를 통해 자식 객체를 전달해도
		virtual 함수는 자식 객체 고유의 동작을 하게 된다.
	3. 새로운 Unit이 필요할 때 부모를 상속만 받아도
		기존 코드에 참여할 수 있다.
		3-1. 부모 포인터 배열 : 묶어서 관리
		3-2. 부모 포인터 매개변수 : 자식객체 : 고유의 기능
			부모클래스 상속 후 virtual함수 추가해주면
			기존의 코드를 고치지 않고도 그대로 사용가능
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

/*	int배열을 매개변수 int*
	char* 배열을 매개변수 char**
*/
void heapDeleteAll(StarUnit** unit, int len)
{
	for (int i = 0; i < len; i++)
	{
		delete unit[i];
	}
}

void main()
{
	srand((unsigned int)time(NULL));	// 난수 초기화
	/*	1. 다형성 자식관리
		자식객체들을 부모 포인터 변수
		배열로 일괄 저장할 수 있다
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

	heapDeleteAll(unit, sizeof(unit)/sizeof(unit[0]));
	//delete unit[0];
	//delete unit[1];
	//delete unit[2];
	//delete unit[3];
}
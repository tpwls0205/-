/*
	list 자료구조 == Sequence Container
	- 순서가 있다
	- 나열된다.
	1. 배열 : 물리적으로 순차적
			  시작 ~ 끝까지 검색 빠르다, but 삽입 삭제하면 한칸씩 전체이동, 하나의 자료를 찾기위해 처음부터 탐색해야한다.
	2. 링크드리스트 : 논리적으로 순차적
					 포인터, 래퍼런스로 가리키기 때문에 중간에 삽입 삭제가 용이하다.
	3. 덱 : 배열 / 링크드리스트로 만든다.
			양방향 증가
*/
#include <iostream>
#include <list>

using namespace std;

void main()
{
	/*  링크드 리스트
		1. 순서보장
		2. 중간 삽입/삭제에 유연한 구조
	*/
	const int DATE_NUM = 6;
	list<int> llist;
	for (int i = 0; i < DATE_NUM; i++)
	{
		llist.push_back(i * 2);
	}

	// 반복자
	list<int>::iterator it = llist.begin();
	++it; // 2번째 위치로 이동
	// 99가 2번째 위치에 삽입
	// it는 3번째를 가리킨다.
	llist.insert(it, 99);
	llist.erase(it);

	it = llist.begin();
	while (it != llist.end())
	{
		cout << *it++ << ", ";
	}
	cout << endl;
}
/*	associate container(연관 컨테이너)
	순차검색은 배열이 가장 빠름, 특정 값을 찾을 때(검색) 가장 빠른 자료구조
	데이터 저장속도는 배열, 리스트 구조보다 느리다.
	hash변환 -> 정렬
	반면에 특정 값 검색이 가장 빠른 구조
	
	a. hash Algorithm으로 변환
	b. hash 공식 적용에 의해 일정한 크기의 정수로 변환된다.
	   a -> hash -> 89ac7803
	   홍길동 -> hash -> 1c90dfd3
	   동해물과 백두산이 마르고 닳도록 -> hash -> 22fc09da
	   소설 토지 전문 -> hash -> 90acf102
	c. hash 정수를 정렬
	d. 해당 위치를 바로 찾아간다
	1. set : 데이터 자체가 key이면서 동시에 값이다. Data로 검색
		Data -> hash -> key
		Data ---------> value
	2. map(dictionary, hashTable) : key를 사용해서 값을 검색한다
		key -> hash
		Data
*/
#include <iostream>
#include <set>

using namespace std;

void main()
{
	string fruitArr[] = { "kiwi", "apple", "pineapple", "orange", "lemon", "banana" };
	set<string> fruitSet;
	int arrLen = sizeof(fruitArr) / sizeof(fruitArr[0]);
	for (int i = 0; i < arrLen; i++)
		fruitSet.insert(fruitArr[i]);

	// set 순차 출력
	set<string>::iterator it = fruitSet.begin();
	while (it != fruitSet.end())
	{
		cout << *it++ << endl;
	}

	cout << endl << endl;

	// 검색
	string testArr[] = { "strawberry", "banana", "watermelon", "apple", "melon", "kiwi" };
	arrLen = sizeof(testArr) / sizeof(testArr[0]);
	for (int i = 0; i < arrLen; i++)
	{
		set<string> ::iterator found = fruitSet.find(testArr[i]);
		if (found != fruitSet.end())
		{
			cout << *found << " found in the set" << endl;
		}
	}
}
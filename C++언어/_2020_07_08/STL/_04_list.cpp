/*
	list �ڷᱸ�� == Sequence Container
	- ������ �ִ�
	- �����ȴ�.
	1. �迭 : ���������� ������
			  ���� ~ ������ �˻� ������, but ���� �����ϸ� ��ĭ�� ��ü�̵�, �ϳ��� �ڷḦ ã������ ó������ Ž���ؾ��Ѵ�.
	2. ��ũ�帮��Ʈ : �������� ������
					 ������, ���۷����� ����Ű�� ������ �߰��� ���� ������ �����ϴ�.
	3. �� : �迭 / ��ũ�帮��Ʈ�� �����.
			����� ����
*/
#include <iostream>
#include <list>

using namespace std;

void main()
{
	/*  ��ũ�� ����Ʈ
		1. ��������
		2. �߰� ����/������ ������ ����
	*/
	const int DATE_NUM = 6;
	list<int> llist;
	for (int i = 0; i < DATE_NUM; i++)
	{
		llist.push_back(i * 2);
	}

	// �ݺ���
	list<int>::iterator it = llist.begin();
	++it; // 2��° ��ġ�� �̵�
	// 99�� 2��° ��ġ�� ����
	// it�� 3��°�� ����Ų��.
	llist.insert(it, 99);
	llist.erase(it);

	it = llist.begin();
	while (it != llist.end())
	{
		cout << *it++ << ", ";
	}
	cout << endl;
}
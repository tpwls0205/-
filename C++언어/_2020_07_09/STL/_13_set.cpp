/*	associate container(���� �����̳�)
	�����˻��� �迭�� ���� ����, Ư�� ���� ã�� ��(�˻�) ���� ���� �ڷᱸ��
	������ ����ӵ��� �迭, ����Ʈ �������� ������.
	hash��ȯ -> ����
	�ݸ鿡 Ư�� �� �˻��� ���� ���� ����
	
	a. hash Algorithm���� ��ȯ
	b. hash ���� ���뿡 ���� ������ ũ���� ������ ��ȯ�ȴ�.
	   a -> hash -> 89ac7803
	   ȫ�浿 -> hash -> 1c90dfd3
	   ���ع��� ��λ��� ������ �⵵�� -> hash -> 22fc09da
	   �Ҽ� ���� ���� -> hash -> 90acf102
	c. hash ������ ����
	d. �ش� ��ġ�� �ٷ� ã�ư���
	1. set : ������ ��ü�� key�̸鼭 ���ÿ� ���̴�. Data�� �˻�
		Data -> hash -> key
		Data ---------> value
	2. map(dictionary, hashTable) : key�� ����ؼ� ���� �˻��Ѵ�
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

	// set ���� ���
	set<string>::iterator it = fruitSet.begin();
	while (it != fruitSet.end())
	{
		cout << *it++ << endl;
	}

	cout << endl << endl;

	// �˻�
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
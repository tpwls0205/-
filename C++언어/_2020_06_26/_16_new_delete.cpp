#include <iostream>

#define NUM_LEN 10

using namespace std;

void main()
{	
	// int�迭 10���� �����ҵ� �� 2�� ��� ����
	int* pnum = (int*)malloc(sizeof(int) * NUM_LEN);
	for (int i = 0; i < NUM_LEN; i++)
	{
		pnum[i] = i * 2;
		cout << pnum[i] << " ";
	}
	cout << endl;
	free(pnum);

	pnum = new int[NUM_LEN];	//malloc
	//pnum = new int[NUM_LEN]();	//calloc
	for (int i = 0; i < NUM_LEN; i++)
	{
		pnum[i] = i * 2;
		cout << pnum[i] << " ";
	}
	cout << endl;
	delete[] pnum;
}
//1. 1 ~100���� ���� ����� ����ϼ���.
//cout�� ����ϼ���.
//
//
//2. 1 ~100���� ���ٿ� 10���� ����ϼ���.
//������ ������ ������ �� ��
//
//3. C�� C++�� cout, cin�� ����Ͽ� �ٲټ���
//
//#include <stdio.h>
//int main() { // ������ �־��� �ڵ�
//	int k, n = 0;
//	int sum = 0;
//	printf("�� ���� �Է��ϼ���>>");
//	scanf("%d", &n);
//	for (k = 1; k <= n; k++) {
//		sum += k;
//	}
//	printf("1���� %d������ ���� %d �Դϴ�.\n", n, sum);
//	return 0;
//}

//1. 1 ~100���� ���� ����� ����ϼ���.
//cout�� ����ϼ���.
#include <iostream>

using namespace std;

void main1()
{	
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}
	cout << sum;
}

//2. 1 ~100���� ���ٿ� 10���� ����ϼ���.
//������ ������ ������ �� ��

void main2()
{
	for (int i = 1; i <= 100; i++)
	{
		cout << i;
		cout << '\t';
		if (i % 10 == 0)
		{
			cout << endl;
		}
	}
}

//3. C�� C++�� cout, cin�� ����Ͽ� �ٲټ���
//
//#include <stdio.h>
//int main() { // ������ �־��� �ڵ�
//	int k, n = 0;
//	int sum = 0;
//	printf("�� ���� �Է��ϼ���>>");
//	scanf("%d", &n);
//	for (k = 1; k <= n; k++) {
//		sum += k;
//	}
//	printf("1���� %d������ ���� %d �Դϴ�.\n", n, sum);
//	return 0;
//}

#include <stdio.h>
int main()
{
	int k, n = 0;
	int sum = 0;
	cout << "�� ���� �Է��ϼ���>>";
	cin >> n;
	for (k = 1; k <= n; k++)
	{
		sum += k;
	}
	cout << "1���� " << n << "������ ���� " << sum << " �Դϴ�" << endl;
}
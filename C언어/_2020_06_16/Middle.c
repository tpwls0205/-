#include <stdio.h>
#include <string.h>

//1. �� ���� �Է¹ް� �ּҰ������ ���ϴ� �Լ��� ����� ����ϼ���
//int getLcm(int num0, int num1);
/*
int getLcm(int num0, int num1);
{
	if()
}

void main()
{	
	int num0 = 0;
	int num1 = 0;
	printf("�� ���� �Է����ּ���");
	scanf_s("%d%d", &num0, &num1);
	printf("%d", getLcm);
}
*/

//2. 2���� ������ �Է¹޽��ϴ�.
//ù��° ������ �ش� ���� ���
//�ι�° ������ �ݺ� ȸ���Դϴ�
//���� ��� ù��° ���ڴ� 5
//�ι�° ���ڴ� 7
//��� : 5 10 15 20 25 30 35
//void viewMultiple(int num0, int num1);
/*
void viewMultiple(int num0, int num1)
{	
	int i = 0;
	for (i = 1; i <= num1; i++)
	{
		printf("%d\n",(i * num0));
	}
}

void main()
{
	int num0 = 0;
	int num1 = 0;
	printf("�� ���� �Է����ּ��� : ");
	scanf_s("%d%d", &num0, &num1);
	viewMultiple(num0, num1);
}
*/

//3. �Է¹��� ������ �������� ����ϴµ� �������� ����ϴ� �Լ��� ����� ����ϼ���
//��) 3 * 9 = 27
//3 * 8 = 24...
//void viewMultiplication(int num);
/*
void viewMultiplication(int num)
{
	int i = 0;
	int j = 0;
	for (i = 9; i >= 1; i--)
	{	
		j = num * i;
		printf("%d x %d = %d\n", num, i, j);
	}
}

void main()
{
	int num = 0;
	printf("���ڸ� �ϳ� �Է����ּ��� >> ");
	scanf_s("%d", &num);
	viewMultiplication(num);
}
*/

//4. ���� n�� �Է¹ް� n!�� ���ϼ���.(factorial)
//5�� �Է��Ѱ�� 1 * 2 * 3 * 4 * 5�� ���ϼ���.
//int factorial(int num);
//
//factory(5) = > 120
/*
int factorial(int num)
{	
	int i = 0;
	int j = 1;
	for (i = num; i >= 1; i--)
	{
		j *= i;
	}
	printf("%d", j);
	return j;
}

void main()
{	
	int num = 0;
	printf("���� �ϳ��� �Է����ּ��� >> ");
	scanf_s("%d", &num);
	factorial(num);
}
*/
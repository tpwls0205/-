#include <stdio.h>
#include <string.h>

//1. do~while���� �̿��ؼ� 1���� 100���� ����ϼ���
//for���� �̿��ؼ� 1���� 100���� ����ϼ���
/*
void main()
{
	int i = 0;
	do {
		i++;
			printf("%d\n", i);
	} while (i < 100);
}

void main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		printf("%d\n", i);
	}
}
*/

//2. do~while���� �̿��ؼ� 10���� 20���� ����ϼ���
//for���� �̿��ؼ� 10���� 20���� ����ϼ���
/*
void main()
{
	int i = 10;
	do {
		printf("%d\n", i);
		i++;
	} while (i <= 20);
}

void main()
{
	int i = 0;
	for (i = 10; i <= 20; i++)
	{
		printf("%d\n", i);
	}
}
*/

//3. do~while���� �̿��ؼ� 1���� 10���� ���� ����ϼ���
//for���� �̿��ؼ� 1���� 10���� ���� ����ϼ���
/*
void main()
{	
	int i = 0;
	int sum = 0;
	do {
			i++;
			sum += i;
	} while (i<10);
	printf("%d", sum);
}

void main()
{
	int i = 0;
	int sum = 0;
	for (i = 0; i <= 10; i++)
	{
		sum += i;
	}
	printf("%d", sum);
}
*/

//4. do~while���� �̿��ؼ� 1���� 10���� �߿� ¦���� ����ϼ���
//do~while������ ���ǹ��� �־��ָ� ��
//¦�� ���� if (num % 2 == 0)
/*
void main()
{
	int i = 0;
	do {
		i++;
		if (i % 2 == 0)
		{
			printf("%d\n", i);
		}
	} while (i < 10);
}

void main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d\n", i);
		}
	}
}
*/

//5. do~while���� �̿��ؼ� ���� ������ �Է¹ް� �� ����ŭ "�����մϴ�"�� ����ϼ���
//for���� �̿��ؼ� ���� ������ �Է¹ް� �� ����ŭ "�����մϴ�"�� ����ϼ���
/*
void main()
{
	int i = 0;
	int count = 0;
	do {
		printf("���� ������ �Է����ּ��� : ");
		scanf_s("%d", &i);
		if (i >= 0)
		{
			for (count = 0; count < i; count++)
			{
				printf("�����մϴ�\n");
			}
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int count = 0;
	printf("���� ������ �Է����ּ��� : ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		for (count = 0; count < i; count++)
		{
			printf("�����մϴ�\n");
		}
	}
}
*/
//6. do~while���� �̿��ؼ� ���� ���� �Է¹ް� �� ����ŭ 3�� ��� ����ϼ���
//���� ��� 5�� �Է¹����� 3 6 9 12 15�� ����ϸ� �˴ϴ�
//for���� �̿��ؼ� ~
/*
void main()
{
	int i = 0;
	int j = 0;
	do {
		printf("���� ������ �Է����ּ��� : ");
		scanf_s("%d", &i);
		if (i>=0)
		{	
			for (j = 1; j <= i; j++)
			{
				printf("%d\n", j*3);
			}
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int j = 0;
	printf("���� ������ �Է����ּ��� : ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d\n", j * 3);
		}
	}
}
*/

//7. do~while���� �̿��ؼ�, for���� �̿��ؼ� ���� 2������ Ǯ�����
//�Է¹��� ������ �������� ����ϼ���
//���� ��� 3�� �Է��ϸ�
//3 x 1 = 3
//3 x 2 = 6
//...
//3 x 9 = 27
/*
void main()
{
	int i = 0;
	int j = 0;
	do {
		printf("���� ������ �Է����ּ��� : ");
		scanf_s("%d", &i);
		if (i >= 0)
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d x %d = %d\n", i, j, i * j); 
			}
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int j = 0;
	printf("���� ������ �Է����ּ��� : ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
	}
}
*/

//8. do~while���� �̿��ؼ�, for���� �̿��ؼ� 2������ Ǯ�����
//����ڷκ��� ������ �Է¹޽��ϴ�.
//�Է� ���� ���� ��� ���մϴ�
//����ڰ� 0�� �Է��ϸ� ���� ����մϴ�
//�׸��� ���α׷��� �����մϴ�.
/*
void main()
{
	int i = 0;
	int sum = 0;
	printf("������ �Է����ּ���\n");
	printf("0�� �Է��ϸ� ���� ����մϴ�\n");
	do {
		scanf_s("%d",&i);
		getchar();
		sum += i;
		if (i == 0)
		{
			printf("\n%d", sum);
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int j = 0;
	int sum = 0;
	printf("������ �Է����ּ���\n");
	printf("0�� �Է��ϸ� ���� ����մϴ�\n");
	for (i = 0; ; i++)
	{
		scanf_s("%d", &j);
		getchar();
		sum += j;
		if (j == 0)
		{
			printf("\n%d", sum);
			break;
		}
	}
}
*/

//9. 0���� 1�� ������ ���� �����Ͽ� ���մϴ�.
//��� ���Ѱ��� 1000�� ���� �� �� ���հ�
//���� ���� ���ϼ���.
/*
void main()
{
	int i = 0;
	int sum = 0;
	for (i = 0; ; i++)
	{	
		sum += i;
		printf("%d��° : %d\n", i, sum);
			if (sum >= 1000)
			{	
				printf("\n������ : %d\n", sum);
				break;
			}
	}
}
*/

//10. int multiplication[8][9] �迭�� �����ϼ���
//�׸��� �������� 2 ~9�ܱ����� �������
//�迭�� �����ϼ���
//
//�׸��� ����ϼ���
/*
void main()
{	
	int i = 0;
	int j = 0;
	int multiplication[8][9] = { 0 };
	for (i = 0; i < 8; i++)
	{	
		for (j = 0; j < 9; j++)
		{
			multiplication[i][j] = (i + 2)*(j + 1);
			printf("%d\t", multiplication[i][j]);
		}
		printf("\n");
	}
}
*/


/*
1. ���� ���� �Է¹ް� �� ����ŭ 3�� ��� ����ϼ���
   ���� ��� 5�� �Է¹����� 3 6 9 12 15�� ����ϸ� �˴ϴ�


2. ����ڷκ��� ������ �Է¹޽��ϴ�.
   �Է� ���� ���� ��� ���մϴ�
   ����ڰ� 0�� �Է��ϸ� ���� ����մϴ�
   �׸��� ���α׷��� �����մϴ�.

3. 5�� �Է��ϸ�
*
**
***
****
*****
�̷��� ����ϼ���.


4. 5�� �Է��ϸ�
*****
****
***
**
*
�̷��� �������� ����ϼ���.

5. 3���� ������� �Է¹ް� ���հ� ����� ����ϼ���
  �Լ��� ���� ����ϼ���
  �Լ� �̸� : inputKor,   calcTotal,  calcAvg
 */

#include "turboc.h"

/*
1. ���� ���� �Է¹ް� �� ����ŭ 3�� ��� ����ϼ���
���� ��� 5�� �Է¹����� 3 6 9 12 15�� ����ϸ� �˴ϴ�
void main()
{
	int i = 0;
	printf("���� ������ �Է����ּ��� >> ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		i = i * 3;
		printf("\n%d", i);
	}
}
*/

/*
2. ����ڷκ��� ������ �Է¹޽��ϴ�.
�Է� ���� ���� ��� ���մϴ�
����ڰ� 0�� �Է��ϸ� ���� ����մϴ�
�׸��� ���α׷��� �����մϴ�.
void main()
{
	int i = 0;
	int sum = 0;
	printf("���� �Է��Ͻø� �� �ص���� >> \n");
	printf("������ �˰� ������ 0�� �Է��ϼ���! \n");
	while (1)
	{
		scanf_s("%d", &i);
		sum += i;	// sum = sum + i;
		if (i == 0)
		{	
			printf("%d", sum);
			break;
		}
	}
}
*/


/*
3. 5�� �Է��ϸ�
*
**
***
****
*****
�̷��� ����ϼ���.
void main()
{
	int i, j, num = 0;
	printf("���ڸ� �Է����ּ��� >> ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++)
	{				
		for (j = 0; j < i; j++)
		{			
			printf("*");
		}
		printf("\n");
	}
}
*/

/*
4. 5�� �Է��ϸ�
* ****
****
***
**
*
�̷��� �������� ����ϼ���.
void main()
{
	int i, j, num = 0;
	printf("���ڸ� �Է����ּ��� >> ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num-i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
*/

/*
5. 3���� ������� �Է¹ް� ���հ� ����� ����ϼ���
�Լ��� ���� ����ϼ���
�Լ� �̸� : inputKor, calcTotal, calcAvg
void main()
{
	int inputKor1, inputKor2, inputKor3 = 0;
	int calcTotal = 0;
	double calcAvg = 0;
	printf(" �л� 3���� ������� �Է����ּ��� \n");
	printf(" 1�� �л� >> ");
	scanf_s("%d", &inputKor1);
	printf("\n");
	printf(" 2�� �л� >> ");
	scanf_s("%d", &inputKor2);
	printf("\n");
	printf(" 3�� �л� >> ");
	scanf_s("%d", &inputKor3);
	printf("\n");
	calcTotal = inputKor1 + inputKor2 + inputKor3;
	printf(" �л� 3���� ����� ���� >> %d \n", calcTotal);
	calcAvg = (inputKor1 + inputKor2 + inputKor3) / 3;
	printf(" �л� 3���� ����� ��� >> %.2lf \n", calcAvg);
}
*/
/*	3���� �л��� �̸��� ���������� �Է¹ް�
	��ü ������ ���
	�� �л� �̸��� ������ ����ϼ���
	�̸��� �������� ��� �迭�� ����ϼ���
*/

#include <stdio.h>
#include <string.h>

#define ST_NUM 3
#define ST_NUMBER 20
#define ST_KOR 3

void main()
{
	int i = 0;
	int sum = 0;
	int avg = 0;
	char names[ST_NUM][ST_NUMBER] = { 0 };
	int kor[ST_KOR] = { 0 };
	for (i = 0; i < ST_NUM; i++)
	{
		printf("�̸� �Է� >> ");
		fgets(names[i], sizeof(names[i]) - 1, stdin);
		names[i][strlen(names[i]) - 1] = 0;
		printf("�л� ���� ���� �Է� : ");
		scanf_s("%d", &kor[i]);	getchar();	 
	}
	for (int i = 0; i < ST_NUM; i++)
	{
		printf("\n%d��° �л� �̸��� %s �Դϴ� \n", i + 1, names[i]);
		printf("%d��° �л� %s�� ���������� %d �Դϴ� \n", i + 1, names[i], kor[i]);
	}
	for (int i = 0; i < ST_NUM; i++)
	{
		sum += kor[i];
		avg = sum / ST_NUM;
	}
	printf("\n�л����� ���� ������ %d �Դϴ� \n", sum);
	printf("�л����� ���� ����� %d �Դϴ� \n", avg);
}
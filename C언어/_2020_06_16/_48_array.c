// ���������� ���� 50�̻� ~ 100 ����
#include "turboc.h"
#define ST_NUM 100			

// �迭�� ź���� ���� �ڵ�
void main()
{
	int kor[ST_NUM] = { 0 };
	int sum = 0;
	double avg = 0.0;

	randomize();		// ���� �ʱ�ȭ
	for (int i = 0; i < sizeof(kor) / sizeof(kor[0]); i++)
	{	
		kor[i] = 50+random(51);
			sum += kor[i];
			printf("%02d ", kor[i]);
			if (i % 10 == 9)
			{
				printf("\n");
			}
	}
	avg = (double)sum / ST_NUM;

	printf(" 3���� �л� ���� : %d��\n", sum);
	printf(" 3���� �л� ��� : %.2lf��\n", avg);
}
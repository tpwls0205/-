#include <stdio.h>

// �迭�� ź���� ���� �ڵ�
void main()
{
	int kor[3] = { 0 };	// ��� 0���� �ʱ�ȭ
	int sum = 0;
	double avg = 0.0;
	printf("1��° �л� ���� ���� �Է� : ");
	scanf_s("%d", &kor[0]);
	printf("2��° �л� ���� ���� �Է� : ");
	scanf_s("%d", &kor[1]);
	printf("3��° �л� ���� ���� �Է� : ");
	scanf_s("%d", &kor[2]);

	sum = kor[0] + kor[1] + kor[2];
	avg = (double)sum / 3;

	printf(" 3���� �л� ������ ��� : %d��\t%.2lf��\n", sum, avg);
}
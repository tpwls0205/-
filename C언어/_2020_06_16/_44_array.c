#include <stdio.h>

// �迭�� ź���� ���� �ڵ�
void main()
{
	int kor[3] = { 0 };	// ��� 0���� �ʱ�ȭ
	int sum = 0;
	double avg = 0.0;
	for (int i = 0; i < 3; i++)
	{
		printf("%d��° �л� ���� ���� �Է� : ", i + 1);
		scanf_s("%d", &kor[i]);
		sum += kor[i];
	}
	avg = (double)sum / 3;

	printf(" 3���� �л� ������ ��� : %d��\t%.2lf��\n", sum, avg);
}
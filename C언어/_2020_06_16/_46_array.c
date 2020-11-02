#include <stdio.h>

/* ����� ����ϴ� 2���� ����
	1. ����� ���ڸ� �ٲٸ� ����� ����
	��ü �ڵ忡 ����ȴ�(������ Ȯ���� ����)
	2. �ǹ̾��� ���ں��� �ǹ��ִ� �ܾ
	�ؼ��ϱ� ����(�������� ��������)
*/
#define ST_NUM 3				// ��� ����

// �迭�� ź���� ���� �ڵ�
void main()
{
	int kor[ST_NUM] = { 0 };	// ��� 0���� �ʱ�ȭ
	int sum = 0;
	double avg = 0.0;

	/* �迭�� ���̸�ŭ �ݺ����� ����� ��
		�迭�� ���̸� ���ؾ� �Ѵ�
		1. ����� ����
		2. sizeof(�迭�̸�)/sizeof(�迭[0])
		   sizeof(kor) : 12byte
		   sizeof(kor[0]) : 4byte
		   12/4 = 3
		   �迭��üũ��/�迭1��°ũ�� = ����
	*/
	for (int i = 0; i < sizeof(kor)/sizeof(kor[0]); i++)
	{
		printf("%d��° �л� ���� ���� �Է� : ", i + 1);
		scanf_s("%d", &kor[i]);
		sum += kor[i];
	}
	avg = (double)sum / ST_NUM;

	printf(" 3���� �л� ������ ��� : %d��\t%.2lf��\n", sum, avg);
}
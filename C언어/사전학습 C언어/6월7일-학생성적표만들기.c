#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������
#include<time.h> // �ð����� ���

// �л� 10���� ��,��,�� ������ 10�� 3���� �Է¹޾Ƽ� ������ּ���.

int kor;
int eng;
int math;
int i;

int step01() {
	printf("�л� ������ �Է����ּ���. > ");
	scanf_s("%d %d %d\n", &kor, &eng, &math);
	printf("%d %d %d\n", kor, eng, math);
	return 0;
}

int step02() {
	printf("�л� ������ �Է����ּ���. > ");
	for (i = 0; i < 10; ++i) {
		scanf_s("%d %d %d\n", &kor, &eng, &math);
		printf("%d %d %d\n", kor, eng, math);
	}
	return 0;
}

int main(void) {
	step02();

	return 0;
}
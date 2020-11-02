#include <stdio.h>

// 배열이 탄생한 후의 코드
void main()
{
	int kor[3] = { 0 };	// 모두 0으로 초기화
	int sum = 0;
	double avg = 0.0;
	printf("1번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor[0]);
	printf("2번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor[1]);
	printf("3번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor[2]);

	sum = kor[0] + kor[1] + kor[2];
	avg = (double)sum / 3;

	printf(" 3명의 학생 총점과 평균 : %d점\t%.2lf점\n", sum, avg);
}
#include <stdio.h>

// 배열이 탄생한 후의 코드
void main()
{
	int kor[3] = { 0 };	// 모두 0으로 초기화
	int sum = 0;
	double avg = 0.0;
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 학생 국어 점수 입력 : ", i + 1);
		scanf_s("%d", &kor[i]);
		sum += kor[i];
	}
	avg = (double)sum / 3;

	printf(" 3명의 학생 총점과 평균 : %d점\t%.2lf점\n", sum, avg);
}
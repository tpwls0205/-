/*	배열(짝, 줄서있다)
	1. 용도
	- 국어점수 1000명의 학생 입력
	int kor[1000];
	int변수가 1000개 줄서있다
	kor[0], kor[1], kor[2], ... kor[999]
*/
#include <stdio.h>

// 배열이 탄생하기 이전의 코드
void main()
{
	int kor0 = 0, kor1 = 0, kor2 = 0;
	int sum = 0;
	double avg = 0.0;
	printf("1번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor0);
	printf("2번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor1);
	printf("3번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor2);

	sum = kor0 + kor1 + kor2;
	// 정수와 정수의 연산의 결과는 정수
	// 275 / 3 => 275.0 / 3 => 소수점 가능
	// sum을 int -> double로 형변환
	avg = (double)sum / 3;

	printf(" 3명의 학생 총점과 평균 : %d점\t%.2lf점\n", sum, avg);
}
#include <stdio.h>

/* 상수를 사용하는 2가지 목적
	1. 상수의 숫자만 바꾸면 상수를 쓰는
	전체 코드에 적용된다(오류의 확률을 줄임)
	2. 의미없는 숫자보다 의미있는 단어가
	해석하기 좋다(가독성이 좋아진다)
*/
#define ST_NUM 3				// 상수 선언

// 배열이 탄생한 후의 코드
void main()
{	
	int kor[ST_NUM] = { 0 };	// 모두 0으로 초기화
	int sum = 0;
	double avg = 0.0;
	for (int i = 0; i < ST_NUM; i++)
	{
		printf("%d번째 학생 국어 점수 입력 : ", i + 1);
		scanf_s("%d", &kor[i]);
		sum += kor[i];
	}
	avg = (double)sum / ST_NUM;

	printf(" 3명의 학생 총점과 평균 : %d점\t%.2lf점\n", sum, avg);
}
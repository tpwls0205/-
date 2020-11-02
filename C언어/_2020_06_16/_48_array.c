// 국어점수가 최하 50이상 ~ 100 이하
#include "turboc.h"
#define ST_NUM 100			

// 배열이 탄생한 후의 코드
void main()
{
	int kor[ST_NUM] = { 0 };
	int sum = 0;
	double avg = 0.0;

	randomize();		// 난수 초기화
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

	printf(" 3명의 학생 총점 : %d점\n", sum);
	printf(" 3명의 학생 평균 : %.2lf점\n", avg);
}
/*	3명의 학생의 이름과 국어점수를 입력받고
	전체 총점과 평균
	각 학생 이름과 점수를 출력하세요
	이름과 국어점수 모두 배열을 사용하세요
*/

#include <stdio.h>
#include <string.h>

#define ST_NUM 3
#define ST_NUMBER 20
#define ST_KOR 3

void main()
{
	int i = 0;
	int sum = 0;
	int avg = 0;
	char names[ST_NUM][ST_NUMBER] = { 0 };
	int kor[ST_KOR] = { 0 };
	for (i = 0; i < ST_NUM; i++)
	{
		printf("이름 입력 >> ");
		fgets(names[i], sizeof(names[i]) - 1, stdin);
		names[i][strlen(names[i]) - 1] = 0;
		printf("학생 국어 점수 입력 : ");
		scanf_s("%d", &kor[i]);	getchar();	 
	}
	for (int i = 0; i < ST_NUM; i++)
	{
		printf("\n%d번째 학생 이름은 %s 입니다 \n", i + 1, names[i]);
		printf("%d번째 학생 %s의 국어점수는 %d 입니다 \n", i + 1, names[i], kor[i]);
	}
	for (int i = 0; i < ST_NUM; i++)
	{
		sum += kor[i];
		avg = sum / ST_NUM;
	}
	printf("\n학생들의 점수 총합은 %d 입니다 \n", sum);
	printf("학생들의 점수 평균은 %d 입니다 \n", avg);
}
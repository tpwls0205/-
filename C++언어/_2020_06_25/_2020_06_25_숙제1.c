//* 배열을 사용하세요
//
//1. 10명의 영어점수를 입력하고, 총합과 평균을 구하세요
//
//2. 국어, 영어, 수학 점수를 각 3개씩 입력받고, 각과목의 총합과 평균을 구하고
//전체 과목의 총합과 평균을 구하세요
//
//3. 과목명을 입력받고, 3명의 점수를 입력받으세요
//그리고 과목명과 3명의 점수를 출력하세요
//
//4. 10명의 수학점수를 입력받고, index가 홀수인 것만 출력하세요
//
//5. 7명의 국어점수를 배열 초기화를 사용해서 미리 입력하세요
//그리고 70점 이상인 학생점수만 출력하세요
//
//6. 5명의 학생의 이름과 국어점수를 입력받으세요
//이름과 점수를 출력하세요
//
//7. 8명의 학생의 이름과 수학점수를 입력받으세요
//가장 점수가 높은 학생의 이름과 점수를 출력하세요
//
//8. 8명의 학생의 이름과 수학점수를 입력받으세요
//가장 점수가 낮은 학생의 이름과 점수를 출력하세요

#include <stdio.h>
#include <math.h>
#include <string.h>
//1. 10명의 영어점수를 입력하고, 총합과 평균을 구하세요
//#define engnum 10
//
//void main()
//{
//	int sum = 0;
//	double avg = 0;
//	int num[engnum] = { 0 };
//	printf("10개의 영어점수를 입력해주세요\n");
//	for (int i = 0; i < engnum; i++)
//	{
//		scanf_s("%d", &num[i]);
//		sum += num[i];
//	}
//	avg = (double)sum / engnum;
//	printf("\n%d\n", sum);
//	printf("%.2lf", avg);
//}

//2. 국어, 영어, 수학 점수를 각 3개씩 입력받고, 각과목의 총합과 평균을 구하고
//전체 과목의 총합과 평균을 구하세요
//#define math 3
//#define eng 3
//#define kor 3
//
//void main()
//{	
//	int mathscore[math] = { 0 };
//	int engscore[eng] = { 0 };
//	int korscore[kor] = { 0 };
//	int summath = 0;
//	int sumeng = 0;
//	int sumkor = 0;
//	double avgmath = 0;
//	double avgeng = 0;
//	double avgkor = 0;
//	int sumtotal = 0;
//	double avgtotal = 0;
//	printf("수학 점수 3개 입력 : ");
//	for (int i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &mathscore[i]);
//		summath += mathscore[i];
//	}
//	printf("영어 점수 3개 입력 : ");
//	for (int i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &engscore[i]);
//		sumeng += engscore[i];
//	}
//	printf("국어 점수 3개 입력 : ");
//	for (int i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &korscore[i]);
//		sumkor += korscore[i];
//	}
//	avgmath = (double)summath / math;
//	avgeng = (double)sumeng / eng;
//	avgkor = (double)sumkor / kor;
//	sumtotal = summath + sumeng + sumkor;
//	avgtotal = (avgmath + avgeng + avgkor) / 3;
//	printf("%d %d %d\n", summath, sumeng, sumkor);
//	printf("%.2lf %.2lf %.2lf\n", avgmath, avgeng, avgkor);
//	printf("%d %.2lf", sumtotal, avgtotal);
//}

//3. 과목명을 입력받고, 3명의 점수를 입력받으세요
//그리고 과목명과 3명의 점수를 출력하세요
//void main()
//{	
//	char input[100] = { 0 };
//	int std[3] = { 0 };
//	int i = 0;
//	printf("\n과목명을 알려주세요 : ");
//	//gets(input);
//	scanf_s("%s", &input, sizeof(input));
//	printf("\n3명의 점수를 알려주세요 : ");
//	for (i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &std[i]);
//		printf("%d번째 학생 %s 과목 점수 : %d\n",i+1, input, std[i]);
//	}
//}

//4. 10명의 수학점수를 입력받고, index가 홀수인 것만 출력하세요
//void main()
//{
//	int maths[10] = { 0 };
//	int i = 0;
//	printf("10명의 수학점수 : ");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &maths[i]);
//		if (i % 2 == 0)
//		{
//			printf("%d", maths[i]);
//		}
//	}
//}

//5. 7명의 국어점수를 배열 초기화를 사용해서 미리 입력하세요
//그리고 70점 이상인 학생점수만 출력하세요
//void main()
//{
//	int kor[7] = { 10, 20, 30, 40, 50, 60, 70 };
//	for (int i = 0; i < 7; i++)
//	{
//		if (kor[i] >= 70)
//		{
//			printf("%d", kor[i]);
//		}
//	}
//}

//6. 5명의 학생의 이름과 국어점수를 입력받으세요
//이름과 점수를 출력하세요
//#define size 50
//#define num 5
//typedef struct std
//{
//	char name[num][size];
//	int kor[num];
//};
//
//void main()
//{	
//	struct std st;
//	printf("5명의 학생 이름과 국어점수를 입력 : ");
//	for (int i = 0; i < num; i++)
//	{
//		scanf_s("%s", st.name[i],sizeof(st.name[i]));
//		scanf_s("%d", &st.kor[i]);
//		printf("%s, %d\n", st.name[i], st.kor[i]);
//	}
//}

//7. 8명의 학생의 이름과 수학점수를 입력받으세요
//가장 점수가 높은 학생의 이름과 점수를 출력하세요
//#define size 50
//#define num 8
//typedef struct std
//{
//	char name[size];
//	int math;
//}Std;
//
//Std _std[num] = { 0 };
//int stdcnt = 0;
//
//void main()
//{
//	int max = 0;
//	for (int i = 0; i < num; i++)
//	{
//		printf("학생 이름 입력 : \n");
//		scanf_s("%s", _std[i].name, sizeof(_std[i].name));
//		printf("학생 수학점수를 입력 : \n");
//		scanf_s("%d", &_std[i].math);
//		if (i == 0)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			max = _std[i].math;
//			stdcnt++;
//		}
//		else if (max < _std[i].math)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			max = _std[i].math;
//			stdcnt++;
//		}
//	}
//		stdcnt--;
//		printf("%s, %d\n", _std[stdcnt].name, max);
//}

//8. 8명의 학생의 이름과 수학점수를 입력받으세요
//가장 점수가 낮은 학생의 이름과 점수를 출력하세요
//#define size 50
//#define num 8
//typedef struct std
//{
//	char name[size];
//	int math;
//}std;
//
//std _std[num] = { 0 };
//int stdcnt = 0;
//
//void main()
//{
//	int min = 0;
//	for (int i = 0; i < num; i++)
//	{
//		printf("학생 이름 입력 : \n");
//		scanf_s("%s", _std[i].name, sizeof(_std[i].name));
//		printf("학생 수학점수를 입력 : \n");
//		scanf_s("%d", &_std[i].math);
//		if (i == 0)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			min = _std[i].math;
//			stdcnt++;
//		}
//		else if (min > _std[i].math)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			min = _std[i].math;
//			stdcnt++;
//		}
//	}
//	stdcnt--;
//	printf("%s, %d\n", _std[stdcnt].name, min);
//}
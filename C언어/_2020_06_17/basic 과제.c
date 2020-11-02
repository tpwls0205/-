
#include "turboc.h"
#include <stdio.h>
#include <ctype.h>

//1. 10개 정수 입력 후 최대 최소 총합 평균을 구하세요.
//void main()
//{
//    int i = 0;
//    int num[10] = { 0 };
//    int sum = 0;
//    double avg = 0;
//    int max = 0;
//    int min = 9999;
//
//    printf("10개의 정수를 입력해주세요 : ");
//    for (i = 0; i <= 9; i++)
//    {
//        scanf_s("%d", &num[i]);
//        sum += num[i];
//    }
//    for (i = 0; i <= 9; i++)
//    {
//        if (num[i] > max)
//            max = num[i];
//        if (num[i] < min)
//            min = num[i];
//    } 
//    avg = sum / 10;
//    printf(" 총합 값 은 : %d\n", sum);
//    printf(" 평균 값 은 : %.1lf\n", avg);
//    printf(" 최대 값 은 : %d\n", max);
//    printf(" 최소 값 은 : %d\n", min);
//}

//2.소문자를 대문자로, 대문자를 소문자로,
//그외 문자는 그대로 출력하세요.(변환하는 함수를 만들것)
//void main()
//{
//	int i = 0;
//	char str[100] = "";
//
//	printf("변환할 문자 입력 : ");
//	gets_s(str,sizeof(str));				// 문자열 입력 함수(개행문자 기준)
//
//	for (i = 0; str[i]; i++)
//	{
//		if (islower(str[i]))				// 입력된 값 중에 소문자가 있는지 확인하는 함수
//		{
//			str[i] = toupper(str[i]);		// 입력된 값 중에 소문자를 대문자로 변환시키는 함수
//		}
//		else if (isupper(str[i]))			// 입력된 값 중에 대문자가 있는지 확인하는 함수
//		{
//			str[i] = tolower(str[i]);		// 입력된 값 중에 대문자를 소문자로 변환시키는 함수
//		}
//	}
//	puts(str);								// 문자열 출력 함수
//}

//3. 사용자로부터 초를 입력받은 후 이를[시, 분, 초]의
//형태로 출력하는 프로그램을 작성하세요.
//1) 입력 함수
//2) 시간 계산 / 출력 함수
//void main() 
//{
//	int sec, min, hour;
//	printf("초(second)를 입력하세요 : ");
//	scanf_s("%d", &sec); 
//	min = sec / 60;		// 입력받은 sec를 60으로 나누면 분(min) 
//	hour = min / 60;	// min의 값을 60으로 나누면 시(hour)
//	sec = sec % 60;		// 시분초로 바꿔주는 것이므로, sec를 60으로 나눠 그 나머지가 남은 초 
//	min = min % 60;		// min을 60으로 나눠 그 나머지가 남은 분
//	printf("%d시간 %d분 %d초\n",hour,min,sec); 
//}
 
//4. 사용자로부터 시, 분, 초를 입력받은 후 초로 변환하는 함수와
//이 계산된 초를 출력하는 함수를 만들고 사용하세요
//1) 시, 분, 초 입력 / 계산 함수
//2) 초 출력 함수
//void main()
//{
//	int sec, min, hour;
//	int sec1, sec2, sec3;
//	printf("시(hour), 분(min), 초(sec)를 입력하세요 : ");
//	scanf_s("%d %d %d", &hour, &min, &sec);
//	sec1 = hour * 3600;
//	sec2 = min * 60;
//	sec3 = sec;
//	sec = sec1 + sec2 + sec3;
//	printf("%d초", sec);
//}

//5. 키와 몸무게를 입력하는 함수를 만들고 사용해보세요	-> 매개변수 다 없애고 전역변수 i, j 선언하니까 출력이 됌..
//int i = 0;
//int j = 0;
//void print(void)
//{
//	printf("키와 몸무게를 입력해주세요 : ");
//}
//
//void input()
//{
//	scanf_s("%d %d", &i, &j);
//}
//
//void output()
//{
//	printf("당신의 키는 %dcm 몸무게는 %dkg 입니다 ", i, j);
//}
//
//void main()
//{
//	print();
//	input(i, j);
//	output(i, j);
//}

//6. 반드시 A를 이용해서 B의 값을 채우도록 하세요
//// 배열 A, B를 선언
//int A[2][4] = { 1,2,3,4,5,6,7,8 };
//int B[4][2] = { 0 };
//
//A                B
//1 2 3 4          1 5
//5 6 7 8          2 6
//			       3 7
//                 4 8
//void main()
//{
//	int A[2][4] = { 1,2,3,4,5,6,7,8 }; 
//	int B[4][2] = { 0 };			   
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 2; ++j)
//		{
//			B[i][j] = A[j][i];
//			printf("%d", B[i][j]);
//		}
//		printf("\n");
//	}
//}
//1. 2개의 값을 서로 교환하는 swap함수를 만드세요
//int num0 = 10, num1 = 20;
//swap(&num0, &num1);
//을 호출하면 num0은 20을 num1은 10을 담고 있으면 됩니다.
//
//2. 3개의 값을 서로 교환하는 swap함수를 만드세요
//int num0 = 10, num1 = 20, num2 = 30;
//swap(&num0, &num1, &num2);
//을 호출하면 num0은 30을 num1은 10, num2는 20을 담고 있으면 됩니다.
//
//3. 10개의 실수를 배열로 전달해서 평균을 구하는 함수를 만드세요
//
//4. char* name = "korea";
//int len = strlen(name);
//을 하면 len에는 5가 담겨 있습니다.
//strlen함수는 문자열의 끝에 '\0'을 찾아서 그 전까지 개수를 세는 방식으로
//구현되어 있습니다
//직접 int str_len(char* ptr); 함수를 구현하세요

#include <stdio.h>
//1. 2개의 값을 서로 교환하는 swap함수를 만드세요
//int num0 = 10, num1 = 20;
//swap(&num0, &num1);
//을 호출하면 num0은 20을 num1은 10을 담고 있으면 됩니다.
//void swap(int* num0, int* num1)
//{	
//	int change = 0;
//	change = *num0;
//	*num0 = *num1;
//	*num1 = change;
//}
//void main()
//{	
//	int num0 = 10, num1 = 20;
//	swap(&num0, &num1);
//	printf("num0:%d ,num1:%d", num0, num1);
//}

//2. 3개의 값을 서로 교환하는 swap함수를 만드세요
//int num0 = 10, num1 = 20, num2 = 30;
//swap(&num0, &num1, &num2);
//을 호출하면 num0은 30을 num1은 10, num2는 20을 담고 있으면 됩니다.
//void swap(int* num0, int* num1, int* num2)
//{
//	int change = 0;
//	change = *num2;
//	*num2 = *num1;
//	*num1 = *num0;
//	*num0 = change;
//}
//
//void main()
//{
//	int num0 = 10, num1 = 20, num2 = 30;
//	swap(&num0, &num1, &num2);
//	printf("num0:%d , num1:%d, num2:%d", num0, num1, num2);
//}

//3. 10개의 실수를 배열로 전달해서 평균을 구하는 함수를 만드세요
//void avg(double num, int len)
//{	
//	static int cnt = 0;
//	static double sum = 0;
//	double avg = 0;
//	sum += num;
//	cnt++;
//	if (cnt == len)
//	{
//		avg = (double)sum / len;
//		num = avg;
//		printf("%lf", num);
//	}
//}
//void main()
//{
//	double num[10] = { 0 };
//	printf("10개의 실수를 입력 : ");
//	for (int i = 0; i < 10; i++)
//	{
//		scanf_s("%lf",&num[i]);
//		avg(num[i], sizeof(num[i]));
//	}
//}

//4. char* name = "korea";
//int len = strlen(name);
//을 하면 len에는 5가 담겨 있습니다.
//strlen함수는 문자열의 끝에 '\0'을 찾아서 그 전까지 개수를 세는 방식으로
//구현되어 있습니다
//직접 int str_len(char* ptr); 함수를 구현하세요

void main()
{

}
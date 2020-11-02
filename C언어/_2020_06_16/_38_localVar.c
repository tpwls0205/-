// 지역변수(local variable)
#include <stdio.h>

void main()
{
	int result = 0;		// main 소속
	//	int result = 0; // 동일영역 중복명칭 x
	for (int i = 1; i <= 10; i++)
	{
		int result = 0;	// for문 소속 // 동일 중복명칭 해당 지역변수가 우선
		result += i;
		printf("결과는 %d 입니다\n", result);
	}
	printf("결과는 %d 입니다\n", result);
}

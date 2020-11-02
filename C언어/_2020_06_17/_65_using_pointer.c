/*	<포인터의 1번째 용법>
	포인터 변수를 사용하면 함수간의 경계를 넘어서
	직접 변수를 접근하는 것이 가능하다
	그러므로 함수의 결과값이 여러 개 일때
	직접 여러 개의 변수에 결과값을 전달받는 것이
	가능하다
*/

#include <stdio.h>

#define IN
#define OUT

void div(IN int num0, IN int num1,
		OUT int* qprt, OUT int* rptr)
{
	*qprt = num0 / num1;	// quotient
	*rptr = num0 % num1;	// remainder
}

void main()
{
	int quotient = 0, remainder = 0;
	div(10, 3, &quotient, &remainder);
	printf("10/3의 몫은 %d입니다\n", quotient);
	printf("10/3의 나머지는 %d입니다\n", remainder);
}
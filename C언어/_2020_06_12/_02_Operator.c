//<연산자 우선순위>
//1. 먼저 연산하고 싶은 것을 ()로 묶는다.
//2. =(대입연산자)는 우측 연산이 모두 종료되고 마지막에 대입된다.

#include <stdio.h>

void main() {
	
	int num0 = 100;
	int num1 = 200;
	int num2 = 2;
	int result = 0;
	result = num0 + num1 / num2;
	printf("%d\n", result);

	int isTrue = num0 == 100 && num1 == 50;			// c언어는 맞으면 1을 리턴, 틀리면 0을 리턴
	if (isTrue == 1) 
		puts("참입니다");							// puts : 서식문자가 필요없을 때 화면 출력
	else 
		puts("거짓입니다");
}
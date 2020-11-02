/*
	int* ptr: *는 int결합한 기호
			ptr은 int변수의 주소를 담는다
	*ptr : *는 연산자

*/
#include <stdio.h>

void main()
{
	int num = 99;
	int result = 0;
	/*	int* 자료형 : int(변수/배열)의 주소
		ptr 변수명
	*/
	/* ptr : 주소값
		*ptr : 주소가 가르키는 공간(값)
	*/
	int* ptr = NULL;
	ptr = &num;
	result = *ptr;// num의 값
	*ptr = 1000;  // num변수공간

	printf("result : %d\n", result);
	printf("num : %d\n", num);
}
/* 함수 모양
리턴타입 함수명(매개변수)
{	// 영역의 시작

	return 리턴타입 변수;
}	// 영역의 끝

<함수를 설계할 때 정해줘야 하는 것>
1. 함수명		- 무조건 존재
2. 프로세스		- 무조건 존재
3. 매개변수		- o x
4. 리턴값		- o x
*/

#include <stdio.h>

// 매개변수 x, 리턴값 o
int getNum()
{
	int num = 0;
	printf("숫자 입력 : ");
	scanf_s("%d", &num);
	return num;
}

// 매개변수 o, 리턴값 o
int add(int num0, int num1)	// num0, num1도 지역변수에 해당
{
	return num0 + num1;
}

// 매개변수 o, 리턴값 x
void viewResult(int result)
{
	printf("계산 결과는 %d 입니다\n", result);
}

// 매개변수 x, 리턴값 x
void viewTitle()
{
	printf("*** 더하기 연산입니다 ***");
}

void main()
{
	// 함수의 시작 부분에 변수 선언
	int num0 = 0, num1 = 0, result = 0;
	// 해당부분에 선언해도 됌
	// int i = 0;

	// 변수 선언이후로 프로세스 전개
	viewTitle();
	num0 = getNum();
	num1 = getNum();
	result = add(num0, num1);
	viewResult(result);

	// i는 다른 변수와 다르게 보조적 역할 변수
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n", i);
	//}
}
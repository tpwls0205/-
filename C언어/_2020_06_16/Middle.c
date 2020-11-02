#include <stdio.h>
#include <string.h>

//1. 두 수를 입력받고 최소공배수를 구하는 함수를 만들고 사용하세요
//int getLcm(int num0, int num1);
/*
int getLcm(int num0, int num1);
{
	if()
}

void main()
{	
	int num0 = 0;
	int num1 = 0;
	printf("두 수를 입력해주세요");
	scanf_s("%d%d", &num0, &num1);
	printf("%d", getLcm);
}
*/

//2. 2개의 정수를 입력받습니다.
//첫번째 정수는 해당 수의 배수
//두번째 정수는 반복 회수입니다
//예를 들어 첫번째 숫자는 5
//두번째 숫자는 7
//결과 : 5 10 15 20 25 30 35
//void viewMultiple(int num0, int num1);
/*
void viewMultiple(int num0, int num1)
{	
	int i = 0;
	for (i = 1; i <= num1; i++)
	{
		printf("%d\n",(i * num0));
	}
}

void main()
{
	int num0 = 0;
	int num1 = 0;
	printf("두 수를 입력해주세요 : ");
	scanf_s("%d%d", &num0, &num1);
	viewMultiple(num0, num1);
}
*/

//3. 입력받은 숫자의 구구단을 출력하는데 역순으로 출력하는 함수를 만들고 출력하세요
//예) 3 * 9 = 27
//3 * 8 = 24...
//void viewMultiplication(int num);
/*
void viewMultiplication(int num)
{
	int i = 0;
	int j = 0;
	for (i = 9; i >= 1; i--)
	{	
		j = num * i;
		printf("%d x %d = %d\n", num, i, j);
	}
}

void main()
{
	int num = 0;
	printf("숫자를 하나 입력해주세요 >> ");
	scanf_s("%d", &num);
	viewMultiplication(num);
}
*/

//4. 정수 n을 입력받고 n!을 구하세요.(factorial)
//5를 입력한경우 1 * 2 * 3 * 4 * 5를 구하세요.
//int factorial(int num);
//
//factory(5) = > 120
/*
int factorial(int num)
{	
	int i = 0;
	int j = 1;
	for (i = num; i >= 1; i--)
	{
		j *= i;
	}
	printf("%d", j);
	return j;
}

void main()
{	
	int num = 0;
	printf("정수 하나를 입력해주세요 >> ");
	scanf_s("%d", &num);
	factorial(num);
}
*/
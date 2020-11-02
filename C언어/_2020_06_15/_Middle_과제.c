/*
1. 양의 정수 입력받고 그 수만큼 3의 배수 출력하세요
   예를 들어 5를 입력받으면 3 6 9 12 15를 출력하면 됩니다


2. 사용자로부터 정수를 입력받습니다.
   입력 받은 값을 계속 더합니다
   사용자가 0을 입력하면 합을 출력합니다
   그리고 프로그램을 종료합니다.

3. 5를 입력하면
*
**
***
****
*****
이렇게 출력하세요.


4. 5를 입력하면
*****
****
***
**
*
이렇게 역순으로 출력하세요.

5. 3명의 국어성적을 입력받고 총합과 평균을 출력하세요
  함수를 만들어서 사용하세요
  함수 이름 : inputKor,   calcTotal,  calcAvg
 */

#include "turboc.h"

/*
1. 양의 정수 입력받고 그 수만큼 3의 배수 출력하세요
예를 들어 5를 입력받으면 3 6 9 12 15를 출력하면 됩니다
void main()
{
	int i = 0;
	printf("양의 정수를 입력해주세요 >> ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		i = i * 3;
		printf("\n%d", i);
	}
}
*/

/*
2. 사용자로부터 정수를 입력받습니다.
입력 받은 값을 계속 더합니다
사용자가 0을 입력하면 합을 출력합니다
그리고 프로그램을 종료합니다.
void main()
{
	int i = 0;
	int sum = 0;
	printf("값을 입력하시면 더 해드려요 >> \n");
	printf("총합을 알고 싶으면 0을 입력하세요! \n");
	while (1)
	{
		scanf_s("%d", &i);
		sum += i;	// sum = sum + i;
		if (i == 0)
		{	
			printf("%d", sum);
			break;
		}
	}
}
*/


/*
3. 5를 입력하면
*
**
***
****
*****
이렇게 출력하세요.
void main()
{
	int i, j, num = 0;
	printf("숫자를 입력해주세요 >> ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++)
	{				
		for (j = 0; j < i; j++)
		{			
			printf("*");
		}
		printf("\n");
	}
}
*/

/*
4. 5를 입력하면
* ****
****
***
**
*
이렇게 역순으로 출력하세요.
void main()
{
	int i, j, num = 0;
	printf("숫자를 입력해주세요 >> ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num-i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
*/

/*
5. 3명의 국어성적을 입력받고 총합과 평균을 출력하세요
함수를 만들어서 사용하세요
함수 이름 : inputKor, calcTotal, calcAvg
void main()
{
	int inputKor1, inputKor2, inputKor3 = 0;
	int calcTotal = 0;
	double calcAvg = 0;
	printf(" 학생 3명의 국어성적을 입력해주세요 \n");
	printf(" 1번 학생 >> ");
	scanf_s("%d", &inputKor1);
	printf("\n");
	printf(" 2번 학생 >> ");
	scanf_s("%d", &inputKor2);
	printf("\n");
	printf(" 3번 학생 >> ");
	scanf_s("%d", &inputKor3);
	printf("\n");
	calcTotal = inputKor1 + inputKor2 + inputKor3;
	printf(" 학생 3명의 국어성적 총합 >> %d \n", calcTotal);
	calcAvg = (inputKor1 + inputKor2 + inputKor3) / 3;
	printf(" 학생 3명의 국어성적 평균 >> %.2lf \n", calcAvg);
}
*/
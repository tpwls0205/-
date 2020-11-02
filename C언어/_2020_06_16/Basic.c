#include <stdio.h>
#include <string.h>

//1. do~while문을 이용해서 1부터 100까지 출력하세요
//for문을 이용해서 1부터 100까지 출력하세요
/*
void main()
{
	int i = 0;
	do {
		i++;
			printf("%d\n", i);
	} while (i < 100);
}

void main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		printf("%d\n", i);
	}
}
*/

//2. do~while문을 이용해서 10부터 20까지 출력하세요
//for문을 이용해서 10부터 20까지 출력하세요
/*
void main()
{
	int i = 10;
	do {
		printf("%d\n", i);
		i++;
	} while (i <= 20);
}

void main()
{
	int i = 0;
	for (i = 10; i <= 20; i++)
	{
		printf("%d\n", i);
	}
}
*/

//3. do~while문을 이용해서 1부터 10까지 합을 출력하세요
//for문을 이용해서 1부터 10까지 합을 출력하세요
/*
void main()
{	
	int i = 0;
	int sum = 0;
	do {
			i++;
			sum += i;
	} while (i<10);
	printf("%d", sum);
}

void main()
{
	int i = 0;
	int sum = 0;
	for (i = 0; i <= 10; i++)
	{
		sum += i;
	}
	printf("%d", sum);
}
*/

//4. do~while문을 이용해서 1부터 10까지 중에 짝수만 출력하세요
//do~while문내에 조건문을 넣어주면 됨
//짝수 조건 if (num % 2 == 0)
/*
void main()
{
	int i = 0;
	do {
		i++;
		if (i % 2 == 0)
		{
			printf("%d\n", i);
		}
	} while (i < 10);
}

void main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d\n", i);
		}
	}
}
*/

//5. do~while문을 이용해서 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하세요
//for문을 이용해서 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하세요
/*
void main()
{
	int i = 0;
	int count = 0;
	do {
		printf("양의 정수를 입력해주세요 : ");
		scanf_s("%d", &i);
		if (i >= 0)
		{
			for (count = 0; count < i; count++)
			{
				printf("감사합니다\n");
			}
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int count = 0;
	printf("양의 정수를 입력해주세요 : ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		for (count = 0; count < i; count++)
		{
			printf("감사합니다\n");
		}
	}
}
*/
//6. do~while문을 이용해서 양의 정수 입력받고 그 수만큼 3의 배수 출력하세요
//예를 들어 5를 입력받으면 3 6 9 12 15를 출력하면 됩니다
//for문을 이용해서 ~
/*
void main()
{
	int i = 0;
	int j = 0;
	do {
		printf("양의 정수를 입력해주세요 : ");
		scanf_s("%d", &i);
		if (i>=0)
		{	
			for (j = 1; j <= i; j++)
			{
				printf("%d\n", j*3);
			}
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int j = 0;
	printf("양의 정수를 입력해주세요 : ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d\n", j * 3);
		}
	}
}
*/

//7. do~while문을 이용해서, for문을 이용해서 각각 2가지로 풀어보세요
//입력받은 숫자의 구구단을 출력하세요
//예를 들어 3을 입력하면
//3 x 1 = 3
//3 x 2 = 6
//...
//3 x 9 = 27
/*
void main()
{
	int i = 0;
	int j = 0;
	do {
		printf("양의 정수를 입력해주세요 : ");
		scanf_s("%d", &i);
		if (i >= 0)
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d x %d = %d\n", i, j, i * j); 
			}
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int j = 0;
	printf("양의 정수를 입력해주세요 : ");
	scanf_s("%d", &i);
	if (i >= 0)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
	}
}
*/

//8. do~while문을 이용해서, for문을 이용해서 2가지로 풀어보세요
//사용자로부터 정수를 입력받습니다.
//입력 받은 값을 계속 더합니다
//사용자가 0을 입력하면 합을 출력합니다
//그리고 프로그램을 종료합니다.
/*
void main()
{
	int i = 0;
	int sum = 0;
	printf("정수를 입력해주세요\n");
	printf("0을 입력하면 합을 출력합니다\n");
	do {
		scanf_s("%d",&i);
		getchar();
		sum += i;
		if (i == 0)
		{
			printf("\n%d", sum);
			break;
		}
	} while (1);
}

void main()
{
	int i = 0;
	int j = 0;
	int sum = 0;
	printf("정수를 입력해주세요\n");
	printf("0을 입력하면 합을 출력합니다\n");
	for (i = 0; ; i++)
	{
		scanf_s("%d", &j);
		getchar();
		sum += j;
		if (j == 0)
		{
			printf("\n%d", sum);
			break;
		}
	}
}
*/

//9. 0부터 1씩 증가한 값을 누적하여 더합니다.
//모두 더한값이 1000이 넘을 때 의 총합과
//더한 값을 구하세요.
/*
void main()
{
	int i = 0;
	int sum = 0;
	for (i = 0; ; i++)
	{	
		sum += i;
		printf("%d번째 : %d\n", i, sum);
			if (sum >= 1000)
			{	
				printf("\n총합은 : %d\n", sum);
				break;
			}
	}
}
*/

//10. int multiplication[8][9] 배열을 생성하세요
//그리고 구구단의 2 ~9단까지의 결과값을
//배열에 저장하세요
//
//그리고 출력하세요
/*
void main()
{	
	int i = 0;
	int j = 0;
	int multiplication[8][9] = { 0 };
	for (i = 0; i < 8; i++)
	{	
		for (j = 0; j < 9; j++)
		{
			multiplication[i][j] = (i + 2)*(j + 1);
			printf("%d\t", multiplication[i][j]);
		}
		printf("\n");
	}
}
*/


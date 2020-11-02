/*
1. while문을 이용해서 1부터 100까지 출력하세요


2. while문을 이용해서 10부터 20까지 출력하세요


3. while문을 이용해서 1부터 10까지 합을 출력하세요


4. while문을 이용해서 1부터 10까지 중에 짝수만 출력하세요
   while문내에 조건문을 넣어주면 됨
   짝수 조건 if(num % 2 == 0)


5. 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하세요

6. 세개의 숫자를 입력받아서 가장 큰 수를 출력하는 프로그램을 구현하라
*/

#include "turboc.h"

/* 
1. while문을 이용해서 1부터 100까지 출력하세요
void main()
{	
	int i = 0;
	while (1)
	{
		for (i = 1; i <= 100; ++i)
		{
			printf("%d\n", i);
		}
		break;
	}
}
*/

/*
2. while문을 이용해서 10부터 20까지 출력하세요
void main()
{
	int i = 0;
	while (1)
	{
		for (i = 10; i <= 20; ++i)
		{
			printf("%d\n", i);
		}
		break;
	}
}
*/

/*
3. while문을 이용해서 1부터 10까지 합을 출력하세요
void main()
{
	int i = 1;
	int sum = 0;

	while (i <= 10)
	{
		sum += i;	// sum = sum + i;
		i += 1;		// i = i + 1
	}
	printf("1~10까지의 합 = %d\n", sum);

}
*/

/*
4. while문을 이용해서 1부터 10까지 중에 짝수만 출력하세요
void main()
{
	int i = 1;
	while (i <= 10)
	{
		if (i % 2 == 0)
		{
			printf("%d", i);
		}
		i++;
	}
}
*/

/*
5. 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하세요
void main()
{	
	int i = 0;
	int count = 0;
	printf("양의 정수 값을 입력해주세요 >> \t");
	scanf_s("%d", &i);
	if (i >= 0)
	{	
		for (count = 0; count <= i; count++)
		{
			printf("감사합니다\n");
		}
	}
}
*/


/*
6. 세개의 숫자를 입력받아서 가장 큰 수를 출력하는 프로그램을 구현하라
void main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	printf("세개의 숫자를 입력해주세요 >> ");
	scanf_s("%d\n", &i);
	scanf_s("%d\n", &j);
	scanf_s("%d", &k);
	if (i >= j)
	{	
		if (i >= k)
		{
			printf("\n%d", i);
		}
	}
	if(j >= i)
	{
		if(j >= k)
		{
			printf("\n%d", j);
		}
	}
	if(k >= i)
	{
		if (k >= j)
		{
			printf("\n%d", k);
		}
	}
}
*/
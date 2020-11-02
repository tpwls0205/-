/*
1. 숫자를 입력받고 숫자만큼 "나무를 찍으세요"
다 찍으면 "나무를 캐었다" 출력

2. 1번을 함수로 만들고 함수에 숫자를 전달하면
"나무를 찍는다"를 반복하세요.
다 찍으면 "나무를 캐었다" 출력

3. 함수를 만들어서 1번째 인자는 반복회수,
2번째 인자는 해당번째 마다 "쿵"을 출력
chopTree(10, 3);
"나무를 찍었다"
"나무를 찍었다"
"나무를 찍었다"
"쿵"

4. chopTree(10, 3, 2);
 3번에 1번 "쿵"  2번에 1번 "쩍"
*/

#include "turboc.h"

/*
1,2 숫자를 입력받고 숫자만큼 "나무를 찍으세요"
다 찍으면 "나무를 캐었다" 출력
void main()
{	
	int i = 0;
	int j = 0;
	printf("나무를 몇번 찍으실건가요? >> ");
	scanf_s("%d", &i);
	for (j = 0; j < i; j++)
	{
		printf("나무를 찍는다\n");
	}
printf("나무를 캤다\n");
}
*/

/*
3. 함수를 만들어서 1번째 인자는 반복회수,
2번째 인자는 해당번째 마다 "쿵"을 출력
chopTree(10, 3);
"나무를 찍었다"
"나무를 찍었다"
"나무를 찍었다"
"쿵"

void main()
{
	int i = 0;
	int j = 0;
	int k = j % 3;
	printf("나무를 몇번 찍으실건가요? >> ");
	scanf_s("%d", &i);
	for (j = 1; j <= i; j++)
	{
		k = j % 3;
		printf("나무를 찍는다\n");
		if (k == 0)
		{
			printf("쿵\n");
		}
	}
	printf("나무를 캤다\n");
}
*/

/*
4. chopTree(10, 3, 2);
3번에 1번 "쿵"  2번에 1번 "쩍"
void main()
{
	int i, j;
	int k = 0;
	printf("나무를 몇번 찍으실건가요? >> ");
	scanf_s("%d", &i);
	for (j = 1; j <= i; j++)
	{
		printf("나무를 찍는다\n");
		if (k == j % 3)
		{
			printf("쿵\n");
		}

		if (k == j % 2)
		{
			printf("쩍\n");
		}
	}
	printf("나무를 캤다\n");
}
*/

void main()
{
	int i = 0;
	int j = 0;
	int k = j % 3;
	int n = j % 2;
	printf("나무를 몇번 찍으실건가요? >> ");
	scanf_s("%d", &i);
	for (j = 1; j <= i; j++)
	{
		printf("나무를 찍는다\n");
		if (k == 0)
		{
			printf("쿵\n");
		}
		if (n == 0)
		{
			printf("짝\n");
		}
	}
	printf("나무를 캤다\n");
}
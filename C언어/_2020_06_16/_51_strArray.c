#include <stdio.h>
#include <string.h>

#define ST_NUM 3

void main()
{
	char name0[10] = { 0 };
	char name1[10] = { 0 };
	char name2[10] = { 0 };
	int kor0 = 0, kor1 = 0, kor2 = 0;

	// scanf_s는 "홍길동" ok
	//			 "홍 길동" => "홍"
	// scanf_s는 space, enter를 기준으로 읽어들임
	// fgets는 enter를 기준으로 읽어들임
	// fgets는 최대크기까지만 읽어들임
	// fgets를 사용하는 이유는 성과 이름을 띄어쓰기해도 모두 입력받고 싶어서
	printf("1번째 학생 이름 입력 : ");
	fgets(name0, sizeof(name0) - 1, stdin); // 키보드로부터 name0에다가 name0의 크기만큼 입력받겠다
	name0[strlen(name0) - 1] = 0;	// strlen : 문자열의 길이, 마지막부분에 enter값 대신 NULL로 치환하겠다
	printf("1번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor0);	getchar();

	printf("2번째 학생 이름 입력 : ");
	fgets(name1, sizeof(name1) - 1, stdin);
	name1[strlen(name1) - 1] = 0;
	printf("2번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor1);	getchar();

	printf("3번째 학생 이름 입력 : ");
	fgets(name2, sizeof(name2) - 1, stdin);
	name2[strlen(name2) - 1] = 0;
	printf("3번째 학생 국어 점수 입력 : ");
	scanf_s("%d", &kor2);	getchar();

	printf("%s학생의 국어점수는 %d입니다\n",name0, kor0);
	printf("%s학생의 국어점수는 %d입니다\n",name1, kor1);
	printf("%s학생의 국어점수는 %d입니다\n",name2, kor2);
}
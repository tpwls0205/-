#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더
#define SIZE 100
#pragma warning (disable:4996)

typedef struct person {
	char name[SIZE];
	char sex[SIZE];
	char age[SIZE];
}PERSON;

void menu();
PERSON record();
void add(PERSON data);
void search(PERSON data);
void print(PERSON data);

//  struct person data;

int main() {
	int score;
	score = 0;
	while (1) {
		
		menu();
		printf(" 메뉴를 선택하세요 : ");
		int m;
	//	scanf("%d",&m);
		if (scanf("%d", 1)) {
			
		}
		else if(scanf("%d", 2)) {
			printf(" 전체목록 ");
		}
		else if (scanf("%d", 3)) {
			return 0;
		}
	}
}

void menu() {
	printf(" 추가 : 1 \n");
	printf(" 전체보기 : 2 \n");
	printf(" 나가기 : 3 \n");
}

PERSON record()
{
	PERSON data;

	printf(" 이름 : \t\n"); gets_s(data.name, sizeof(data.name));
	printf(" 성별 : \t\n"); gets_s(data.sex, sizeof(data.sex));
	printf(" 나이 : \t\n"); gets_s(data.age, sizeof(data.age));

	return data;
}

void add(data) {
	PERSON data;
	data = record();
	

}

/*
char add[SIZE];
char view[SIZE];
char end[SIZE]; */



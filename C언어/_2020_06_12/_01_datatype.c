// 드래그 ctrl + k + c : 드래그 범위 주석처리
// 드래그 ctrl + k + u : 드래그 범위 주석처리 해제

#include <stdio.h>

int main(void) {

	int num = 100;		// 정수형
	char ch = 'A';		// 문자
	double fnum = 3.14; // 실수
	char str[] = "korean"; // 배열

	printf("정수 %d\n", num);
	printf("문자 %c, %d\n", ch, ch);
	printf("실수 %lf\n", fnum);
	printf("문자열 %s\n", str);


	return 0;
}
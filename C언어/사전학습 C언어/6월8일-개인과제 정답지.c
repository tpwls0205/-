#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {


	char ch;
	int digit = 0;// 숫자
	int alpha = 0;// 영문자 
	int words = 0;// 띄어쓰기
	int numbers = 0;// 정수들의 총합


	while ((ch = getchar()) != EOF) {
		if (ch >= '0' && ch <= '9') digit++;
		if (ch >= 'A' && ch <= 'z') alpha++;
		if (ch >= ' ' && ch <= ' ') words++;
		if (ch != digit ) numbers++;
	}
	printf("digit : %d\n", digit);
	printf("alpha : %d\n", alpha);
	printf("words : %d\n", words);
	printf("numbers : %d\n", numbers);

	return 0;
}

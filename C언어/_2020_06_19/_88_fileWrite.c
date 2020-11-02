/* 파일 입출력 3단계
1. 스트림 생성(open)
2. 동작(write / read)
3. 스트림 종료(close)
*/
#include <stdio.h>

void main()
{
	// 1) 스트림 생성
	FILE* fp = NULL;
	fopen_s(&fp, "test.txt", "wt");

	// 2-1) 문자 저장
	fputc('A', fp); fputc('\n', fp);
	fputc('B', fp); fputc('\n', fp);

	// 2-2) 문자열 저장
	fputs("I Love You!\n", fp);
	fputs("홍길동\n", fp);
	fputs("임꺽정\n", fp);
	fputs("장길산\n", fp);

	// 3) 스트림 종료
	fclose(fp);
}
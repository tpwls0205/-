/* 
<파일 모드>
w : write  새로쓰기
r : read   읽기
a : append 추가하기

t : 한글, 영어(사람이 사용하는 문자(열))
b : 변수, 구조체, 배열(메모리의 비트/바이트) 
*/
#include <stdio.h>

void main()
{
	// 1) 스트림 생성
	FILE* fp = NULL;
	fopen_s(&fp, "test.txt", "at");

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
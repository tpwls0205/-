// 로컬 헤더 파일은 아래처럼 포함시킬 수 있음
#include "turboc.h"	// f12 문서로 이동 단축키

void main()
{
	setcursortype(NOCURSOR);	// NO 커서
	clrscr();					// 화면 청소
	gotoxy(20, 12);
	printf("감사합니다\n");
}
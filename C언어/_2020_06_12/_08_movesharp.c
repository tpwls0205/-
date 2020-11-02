// 로컬 헤더 파일은 아래처럼 포함시킬 수 있음
#include "turboc.h"	// f12 문서로 이동 단축키

void main()
{
	setcursortype(NOCURSOR);	// NO 커서
	int x = 0;
	for (x = 0; x <= 80; x++)
	{
		gotoxy(x, 12);
		puts("#");
		delay(100);					// 0.1초 동안 잠시 멈춤
		gotoxy(x, 12);
		puts(" ");
	}
}
// 끝에 닿으면 되돌아가기 축약형 3번
#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO 커서
	int x = 0;
	int dir = 1;			// 우측 : 1 , 좌측 : -1
	while (1)
	{
		gotoxy(x, 12);
		puts("#");
		delay(10);					// 0.1초 동안 잠시 멈춤
		gotoxy(x, 12);
		puts(" ");
		x += dir;
		// 양 끝에 닿으면 부호를 바꾸어라
		// 부호를 변경 = 증가 <-> 감소
		if (x == 80 || x == 0)
			dir = dir * -1; // dir *= -1;
	}
}
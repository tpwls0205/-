// 끝에 닿으면 되돌아가기 2번
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
			x = x + dir;			// x+= dir;
			if (x == 80)
				dir = -1;
			else if (x == 0)
				dir = 1;
	}
}
// 끝에 닿으면 되돌아가기
#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO 커서
	int x = 0;
//	for(;;) == while(1) / 무한루프
	while (1)
	{
		for (x = 0; x <= 80; x++)
		{
			gotoxy(x, 12);
			puts("#");
			delay(10);					// 0.1초 동안 잠시 멈춤
			gotoxy(x, 12);
			puts(" ");
		}
		for (x = 80; x >= 0; x--)
		{
			gotoxy(x, 12);
			puts("#");
			delay(10);					// 0.1초 동안 잠시 멈춤
			gotoxy(x, 12);
			puts(" ");
		}
	}
}
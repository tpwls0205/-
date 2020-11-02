// 끝에 닿으면 반사
#include "turboc.h"

void main()
{
		void clrscr();
		setcursortype(NOCURSOR);
		int i = 0;
		for (i = 0; i <= 40; i++)
		{
			gotoxy(i, 24);
			puts("■");
		}
		int j = 0;
		for (j = 0; j <= 25; j++)
		{
			gotoxy(79, j);
			puts("■");
		}
}

/*
	void clrscr();
	setcursortype(NOCURSOR);
	int x = 0, y = 0;
		for (x = 0; x <= 80; x++)
		{
			gotoxy(x, 25);
			puts("■");
		}
		for ( y = 0 ; y <= 25; y++)
		{
			gotoxy(x, y);
			puts("■");
		}
*/
/*	2���� ���ڸ� �̵���Ű��
	1. ������ ���̸� ����
	2. �ð��� ���̸� ����
*/
#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);
	int x = 0;
	int n = 0;
	for (x = 0; x <= 80; x++)
	{
		clrscr();
		gotoxy(x, 12);
		puts("######");
		//delay(100);
		n = x - 20;
		if (n < x)
		{
			gotoxy(n, 18);
			puts("#");
			delay(100);
		}
	}
	x = 80;
	for (n = x-20; n <= x ; n++)
	{
		clrscr();
		gotoxy(x, 12);
		puts("######");
		gotoxy(n, 18);
		puts("#");
		delay(100);
	}
} 
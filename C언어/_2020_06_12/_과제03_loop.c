#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO Ŀ��
	int x = 0;
	int y = 0;
//	int map[80] = { 0 };
	while (1)
	{
		for (x,y = 0; x,y <= 80; x++,y++)
		{
			gotoxy(x, y);
			puts("#");
			delay(100);						// 0.1�� ���� ��� ����
			gotoxy(x, y);
			puts(" ");
			if (x, y == 80)
			{
				for (x, y = 80; x, y >= 0; x--, y--)
				{
					gotoxy(x, y);
					puts("#");
					delay(100);						// 0.1�� ���� ��� ����
					gotoxy(x, y);
					puts(" ");
				}
			}
		}
	}
}
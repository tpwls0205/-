#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO Ŀ��
	int x = 0;
	int y = 0;
	while (1)
	{
		for (x = 0; x <= 80; x++)
		{
			gotoxy(x, y);
			puts("#");
			delay(100);					// 0.1�� ���� ��� ����
			gotoxy(x, y);
			puts(" ");

		}
	}
}
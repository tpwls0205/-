#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO Ä¿¼­
	int x = 0;
	int y = 0;
	while (1)
	{
		for (x = 0; x <= 80; x++)
		{
			gotoxy(x, y);
			puts("#");
			delay(100);					// 0.1ÃÊ µ¿¾È Àá½Ã ¸ØÃã
			gotoxy(x, y);
			puts(" ");

		}
	}
}
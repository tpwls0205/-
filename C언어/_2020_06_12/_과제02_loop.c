#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO ƒøº≠
	int x = 0;
	while (1)
	{
		for (x = 0; x <= 80; x++)
		{
			gotoxy(x, 12);
			puts("#");
			delay(100);					// 0.1√  µøæ» ¿·Ω√ ∏ÿ√„
			gotoxy(x, 12);
			puts(" ");
			if (x == 80) {
				for (x = 80; x >= 0; x--)
				{
					gotoxy(x, 12);
					puts("#");
					delay(100);					// 0.1√  µøæ» ¿·Ω√ ∏ÿ√„
					gotoxy(x, 12);
					puts(" ");
				}
			}
		}
	}
}
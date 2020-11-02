// 끝에 닿으면 반사
#include "turboc.h"

/// <summary>
/// icon을 직선으로 그리는 함수
/// </summary>
/// <param name="goalVal"> 0부터 goalVal 까지 변화 </param>
/// <param name="any"> 0이면 x축 변화, 1이면 y축 변화</param>
/// <param name="pt"> x축이 변하면 y축 기준, y축이 변하면 x축 기준 </param>
/// <param name="icon"> 그리는 icon 모양 </param>
void drawWall(int goalVal, int any, int pt, char* icon)
{
	int i = 0;
	for (i = 0; i <= goalVal; i++)
	{
		if (any == 0)
			gotoxy(i, pt);
		else if (any == 1)
			gotoxy(pt, i);

		puts(icon);
	}
}

void main()
{
	void clrscr();
	setcursortype(NOCURSOR);
	
	drawWall(80 / 2, 0, 24, "■");
	drawWall(25 , 1, 79, "■");
}
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
	int width = 80;
	int height = 25;
	void clrscr();
	setcursortype(NOCURSOR);

	drawWall(width / 2, 0, height+1 , "■");	// x축
	drawWall(height, 1, width+2 , "■");		// y축

	int x = 0, y = 0;				// 좌표값
	int dirX = 1, dirY = 1;			// 변화값(증감)
	while (1)
	{
		gotoxy(x, y);
		puts("#");
		delay(30);					// 0.1초 동안 잠시 멈춤
		gotoxy(x, y);
		puts(" ");
		x += dirX;
		y += dirY;
		// x의 경계선에 닿으면 x의 변화
		if (x == width || x == 0)
			dirX *= -1;
		// y의 경계선에 닿으면 y의 변화
		if (y == height || y == 0)
			dirY *= -1;
	}
}
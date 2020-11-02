// 끝에 닿으면 반사
#include "turboc.h"

// 2. 상수를 만드는 방법
//#define WIDHT 80
//#define HEIGHT 25

// 3. 상수를 만드는 방법
enum {
	WIDTH = 80, HEIGHT = 25
};

/// <summary>
/// icon을 직선으로 그리는 함수
/// </summary>
/// <param name="start"> 그림이 시작되는 위치 </param>
/// <param name="end"> 그림이 끝나는 위치 </param>
/// <param name="any"> 0이면 x축 변화, 1이면 y축 변화</param>
/// <param name="pt"> x축이 변하면 y축 기준, y축이 변하면 x축 기준 </param>
/// <param name="icon"> 그리는 icon 모양 </param>
void drawWall(int start, int end, int any, int pt, char* icon)
{
	int i = 0;
	for (i = start; i <= end; i++)
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
	// 1. 상수를 만드는 방법
	//const int WIDTH = 80;		// 상수 : const , 변수였던 width가 상수로 바뀜
	//const int HEIGHT = 25;		// 상수 : 값을 변경하지 못함, 상수는 일반적으로 대문자표기
	void clrscr();
	setcursortype(NOCURSOR);

	drawWall(0, WIDTH / 2, 0, HEIGHT + 1, "■");	// x축
	drawWall(0, HEIGHT, 1, WIDTH + 2, "■");		// y축

	int x = 0, y = 0;				// 좌표값
	int dirX = 1, dirY = 1;			// 변화값(증감)
	while (1)
	{
		// 상자그리기
			int sX = 0 + WIDTH / 2 / 2;
			int eX = sX + WIDTH / 2;
			int sY = 0 + HEIGHT / 2 / 2;
			int eY = sY + HEIGHT / 2;
			drawWall(sX, eX, 0, sY, "+"); // 상단 x축
			drawWall(sX, eX, 0, eY, "+"); // 하단 x축
			drawWall(sY, eY, 1, sX, "+"); // 좌단 y축
			drawWall(sY, eY, 1, eX, "+"); // 우단 y축
		gotoxy(x, y);
		puts("#");
		delay(30);					// 0.1초 동안 잠시 멈춤
		gotoxy(x, y);
		puts(" ");
		x += dirX;
		y += dirY;
		// x의 경계선에 닿으면 x의 변화
		if (x == WIDTH || x == 0)
			dirX *= -1;
		// y의 경계선에 닿으면 y의 변화
		if (y == HEIGHT || y == 0)
			dirY *= -1;
	}
}
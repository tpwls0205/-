#include "turboc.h"

#define WIDTH 80
#define HEIGHT 25

#define TRUE 1
#define FALSE 0

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77

void drawXLine(int sX, int eX, int yPos, const char* icon)
{
	int x = 0;
	for (x = sX; x <= eX; x++)
	{
		gotoxy(x, yPos);
		puts(icon);
	}
}

void drawYLine(int sY, int eY, int xPos, const char* icon)
{
	int y = 0;
	for (y = sY; y <= eY; y++)
	{
		gotoxy(xPos, y);
		puts(icon);
	}
}

void drawBar(int x, int y, char* bar)
{
	gotoxy(x, y);
	puts(bar);
}

void main()
{
	char* bar = "�âââ�";
	int preX, preY;
	int newX, newY;
	preX = newX = (WIDTH / 2 - strlen(bar) / 2);
	preY = newY = HEIGHT / 5 * 4;
	drawXLine(0, WIDTH + 2, HEIGHT + 2, "��");
	drawYLine(0, HEIGHT + 2, WIDTH + 2, "��");
	drawBar(newX, newY, bar);

	while (TRUE)
	{
		if (_kbhit())	// Ű���尡 ���ȴ�?
		{
			preX = newX;
			preY = newY;
			char key = _getch();
			switch (key)
			{
			case UP_KEY:
				if (preY>0)				// if������ ������ �Ǹ� ���̻� �������ϰ� ��.
				{
					newY--;
				}
				break;
			case DOWN_KEY:
				if (preY< HEIGHT+1)		// if������ ������ �Ǹ� ���̻� �������ϰ� ��.
				{
					newY++;
				}
				break;
			case LEFT_KEY:
				if (preX>0)				// if������ ������ �Ǹ� ���̻� �������ϰ� ��.
				{
					newX--;
				}
				break;
			case RIGHT_KEY:
				if (preX < WIDTH-6)		// if������ ������ �Ǹ� ���̻� �������ϰ� ��.
				{
					newX++;
				}
				break;
			}
			drawBar(preX, preY, "        ");
			drawBar(newX, newY, bar);
		}
	}
}
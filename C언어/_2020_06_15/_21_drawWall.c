// ���� ������ �ݻ�
#include "turboc.h"

/// <summary>
/// icon�� �������� �׸��� �Լ�
/// </summary>
/// <param name="goalVal"> 0���� goalVal ���� ��ȭ </param>
/// <param name="any"> 0�̸� x�� ��ȭ, 1�̸� y�� ��ȭ</param>
/// <param name="pt"> x���� ���ϸ� y�� ����, y���� ���ϸ� x�� ���� </param>
/// <param name="icon"> �׸��� icon ��� </param>
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

	drawWall(width / 2, 0, height+1 , "��");	// x��
	drawWall(height, 1, width+2 , "��");		// y��

	int x = 0, y = 0;				// ��ǥ��
	int dirX = 1, dirY = 1;			// ��ȭ��(����)
	while (1)
	{
		gotoxy(x, y);
		puts("#");
		delay(30);					// 0.1�� ���� ��� ����
		gotoxy(x, y);
		puts(" ");
		x += dirX;
		y += dirY;
		// x�� ��輱�� ������ x�� ��ȭ
		if (x == width || x == 0)
			dirX *= -1;
		// y�� ��輱�� ������ y�� ��ȭ
		if (y == height || y == 0)
			dirY *= -1;
	}
}
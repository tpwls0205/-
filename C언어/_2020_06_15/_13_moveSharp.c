// ���� ������ �ݻ�
#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO Ŀ��
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
		if (x == 80 || x == 0)
			dirX *= -1;
		// y�� ��輱�� ������ y�� ��ȭ
		if (y == 25 || y == 0)
			dirY *= -1;
	}
}
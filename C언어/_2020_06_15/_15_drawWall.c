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
	void clrscr();
	setcursortype(NOCURSOR);
	
	drawWall(80 / 2, 0, 24, "��");
	drawWall(25 , 1, 79, "��");
}
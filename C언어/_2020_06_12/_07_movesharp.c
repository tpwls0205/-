// ���� ��� ������ �Ʒ�ó�� ���Խ�ų �� ����
#include "turboc.h"	// f12 ������ �̵� ����Ű

void main()
{
	setcursortype(NOCURSOR);	// NO Ŀ��
	int x = 0;
	for (x = 0; x <= 80; x++)
	{
		clrscr();					// ȭ�� ��ü �����
		gotoxy(x, 12);
		puts("#");
		delay(100);					// 0.1�� ���� ��� ����
	}
}
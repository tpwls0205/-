// ���� ������ �ǵ��ư��� ����� 3��
#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// NO Ŀ��
	int x = 0;
	int dir = 1;			// ���� : 1 , ���� : -1
	while (1)
	{
		gotoxy(x, 12);
		puts("#");
		delay(10);					// 0.1�� ���� ��� ����
		gotoxy(x, 12);
		puts(" ");
		x += dir;
		// �� ���� ������ ��ȣ�� �ٲپ��
		// ��ȣ�� ���� = ���� <-> ����
		if (x == 80 || x == 0)
			dir = dir * -1; // dir *= -1;
	}
}
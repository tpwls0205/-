/*	C++������ ����ü�� ������ ��
	Struct�� �Ⱥ��ĵ� �ȴ�.
*/

#include <stdio.h>

struct _Point
{
	int x;
	int y;
};
typedef struct _Point point;

void main()
{
	_Point pt;
	pt.x = 10;
	pt.y = 20;
	printf("[%d %d]\n", pt.x, pt.y);

	_Point _pt;
	pt.x = 10;
	pt.y = 20;
	printf("[%d %d]\n", pt.x, pt.y);
}
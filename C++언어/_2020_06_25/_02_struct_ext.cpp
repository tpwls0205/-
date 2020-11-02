/*	C++에서는 구조체를 선언할 때
	Struct를 안붙쳐도 된다.
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
/* 전역 변수(global Variable)
	1. 영역 내에 있지 않다
	2. 0으로 초기화 하지 않아도 자동 0으로 초기화
	3. 어디서나 사용가능하다
	4. 프로그램 전체에서 값을 유지할 목적으로 사용
	5. 동일한 이름의 지역변수가 있으면 지역변수가 우선순위를 갖는다
*/

#include "turboc.h"

int g_EnterNum = 0;

void checkEnter()
{
	printf("VIPS에 입장하셨습니다\n");
	g_EnterNum++;
}

void showMenu()
{
	printf("1. 애슐리\n");
	printf("2. 아웃백\n");
	printf("3. VIPS\n");
	printf("4. Exit\n");
}

int getSelMenu()
{
	int num = 0;
	printf("\n선택하세요 >> ");
    num = getchar() - '0';	// 문자로 들어온 것에 0을 빼주면 숫자로 바뀐다(아스키 코드)
	getchar();				// \n값을 제거할 목적
	return num;
}

void main()
{
	while (1)
	{	
		clrscr();
		showMenu();
		int sel = getSelMenu();
		if (sel == 3)
		{
			checkEnter();
		}
		else if (sel == 4)
		{
			break;
		}
	}
	printf("VIPS에 입장한 고객은 %d 명입니다.\n", g_EnterNum);
}
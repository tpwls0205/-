#include<stdio.h>

void viewMenu()
{
	printf("\t<주소록 관리 프로그램>\n");
	printf("1. 입력\n");
	printf("2. 검색\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 전체출력\n");
	printf("6. 종료\n");
}

int getSelNum()
{
	int selNum = 0;
	printf("\n 번호를 선택하세요 >> ");
	scanf_s("%d", &selNum);

	return selNum;
}

void processWork(int selNum)
{
	if (selNum == 1)
	{
		printf("\n\t입력처리 하였습니다~\n");
	}
	else if (selNum == 2)
	{
		printf("\n\t검색처리 하였습니다~\n");
	}
	else if (selNum == 3)
	{
		printf("\n\t수정처리 하였습니다~\n");
	}
	else if (selNum == 4)
	{
		printf("\n\t삭제처리 하였습니다~\n");
	}
	else if (selNum == 5)
	{
		printf("\n\t전체출력처리 하였습니다~\n");
	}
	else if (selNum == 6)
	{
		printf("\n\t프로그램 종료하겠습니다~\n");
	}
}

void main()
{
	int selNum = 0;

	// 업무처리가 끝난 후 다시 메뉴가 나타날 수 있도록
	// 무한 루프 처리를 한다.
	while (1)
	{
		viewMenu();

		selNum = getSelNum();

		processWork(selNum);
	}
}
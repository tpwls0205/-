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

void inputAddress()
{
	printf("\n\t입력처리 하였습니다~\n\n");
}

void searchAddress()
{
	printf("\n\t검색처리 하였습니다~\n\n");
}

void updateAddress()
{
	printf("\n\t수정처리 하였습니다~\n\n");
}

void deleteAddress()
{
	printf("\n\t삭제처리 하였습니다~\n\n");
}

void printAllAddress()
{
	printf("\n\t전체출력처리 하였습니다~\n\n");
}

void exitApp()
{
	printf("\n\t프로그램 종료하겠습니다~\n\n");
}

void processWork(int selNum)
{
	switch (selNum)
	{
	case 1:
		inputAddress();
		break;
	case 2:
		searchAddress();
		break;
	case 3:
		updateAddress();
		break;
	case 4:
		deleteAddress();
		break;
	case 5:
		printAllAddress();
		break;
	case 6:
		exitApp();
		break;
	default:
		printf("잘못입력하셨습니다");
		break;
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
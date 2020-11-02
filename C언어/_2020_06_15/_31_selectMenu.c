#include "turboc.h"

// 숫자 대신 의미있는 문자를 사용한다
// 처음 숫자 다음부터는 자동으로 1씩 증가한다
enum {
	INPUT_ADDR=1,
	SEARCH_ADDR,
	UPDATE_ADDR,
	DELETE_ADDR,
	PRINTALL_ADDR,
	EXIT_ADDR
};

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
	case INPUT_ADDR:
		inputAddress();
		break;
	case SEARCH_ADDR:
		searchAddress();
		break;
	case UPDATE_ADDR:
		updateAddress();
		break;
	case DELETE_ADDR:
		deleteAddress();
		break;
	case PRINTALL_ADDR:
		printAllAddress();
		break;
	case EXIT_ADDR:
		exitApp();
		break;
	default:
		printf("\n\t잘못입력하셨습니다\n\n");
		break;
	}
}

void laterProcess()
{
	getchar();				// scanf_s에서 입력된 \n을 처리
	getchar();				// 아무 입력 받기(화면 잠시 멈춤)
	clrscr();				// 화면청소
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

		laterProcess();			// 후처리
	}
}
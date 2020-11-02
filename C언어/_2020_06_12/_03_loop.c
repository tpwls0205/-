// 함수를 모르면 함수클릭 하고 f1키 누르면 설명창으로 넘어감

#include <stdio.h>
#include <conio.h>

void main() {
	
	printf("1. 주소 입력\n");
	printf("2. 주소 검색\n");
	printf("3. 주소 수정\n");
	printf("4. 주소 삭제\n");
	printf("5. 프로그램 종료\n");

	printf("번호를 선택하세요 >> \n");
	//char sel = getchar();	// 문자 넣고 enter를 쳐줘야함
	char sel = _getch();	// 문자만 넣으면 입력
	printf("%c 번 선택하셨습니다\n", sel);

}
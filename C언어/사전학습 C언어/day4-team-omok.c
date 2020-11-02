#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

char* img[] = { "●","○","┌ ","┬ ","┐ ","├ ","┼ ","┤ ","└ ","┴ ","┘ " };		// img라는 배열속에 11개(길이가 11번)의 문자요소가 있다.
#define PAN_SIZE 19																		// 오목판의 사이즈는 19 -> 전처리명령을 통해 19라는 정수를 PAN_SIZE라는 문자에 저장

void panInit(int stone[][PAN_SIZE])														// 매개변수 스톤, [][] 판사이즈, 반환값 없음.
{
	int i, j;																			// 변수선언 i, j
	for (i = 0; i < PAN_SIZE; i++)														// i는 0부터 시작해서 18까지 1씩 증가한다.
	{
		for (j = 0; j < PAN_SIZE; j++)													// j는 0부터 시작해서 18까지 1씩 증가한다.
		{
			if (i == 0)																	// i가 0이라면
			{
				if (j == 0) stone[i][j] = 2;											// i가 0이면서 j가 0이라면 스톤ij는 문자요소 2번이다.
				else if (j == PAN_SIZE - 1) stone[i][j] = 4;							// i가 0인데 j가 0이 아니라면 j는 18-1 = 17, 스톤ij는 문자요소 4번이다.
				else	stone[i][j] = 3;												// 그마저도 아니라면 스톤ij의 문자요소는 3번이다.
			}
			else if (i == PAN_SIZE - 1)													// i가 0이 아니라면 i는 18-1 = 17이다.
			{
				if (j == 0) stone[i][j] = 8;											// i가 0이 아니면서 j가 0이라면 스톤ij는 문자요소 8번이다.
				else if (j == PAN_SIZE - 1) stone[i][j] = 10;							// i가 0이 아니면서 j가 0이 아니라면 j는 18-1 = 17, 스톤ij는 문자요소 10번이다.
				else	stone[i][j] = 9;												// 그마저도 아니라면 스톤ij의 문자요소는 9번이다.
			}
			else																		// i가 0도 아니고 17도 아니라면
			{
				if (j == 0) stone[i][j] = 5;											// i가 0도 아니고 17도 아닐때 j가 0이라면 스톤ij는 문자요소 5번이다.
				else if (j == PAN_SIZE - 1) stone[i][j] = 7;							// i가 0도 아니고 17도 아닐때 j가 17이ㅏ면 스톤ij는 문자요소 7번이다.
				else	stone[i][j] = 6;												// 그마저도 아니라면 스톤ij의 문자요소는 6번이다.
			}
		}

	}
}

void panDisplay(int stone[][PAN_SIZE])													// 매개변수 스톤, [][] 판사이즈, 반환값 없음.
{
	int i, j;																			// 변수선언 i, j
	printf("  ");																		// 공백을 출력한다.
	for (j = 0; j < PAN_SIZE; j++)														// j는 0부터 시작해서 18까지 1씩 증가한다.
	{
		printf("%2d", j);																// 2자리 정수로 j의 값을 출력한다.
	}
	printf("\n");																		// 행내림.

	for (i = 0; i < PAN_SIZE; i++)														// i는 0부터 시작해서 18까지 1씩 증가한다.
	{
		printf("%2d", i);																// 2자리 정수로 i의 값을 출력한다.
		for (j = 0; j < PAN_SIZE; j++)													// j는 0부터 시작해서 18까지 1씩 증가한다.
		{
			printf("%s", img[stone[i][j]]);												// 스톤ij의 문자요소를 출력한다.
		}
		printf("\n");																	// 행내림.
	}
}
int setPosition(int field[][PAN_SIZE], int stone, int x, int y)							// 매개변수 필드, [][] 판사이즈, 스톤, x위치, y위치
{
	if (y > (PAN_SIZE - 1) || y < 0 ||													// y가 판사이즈보다 크거나 작으면(or)
		x > (PAN_SIZE - 1) || x < 0 ||													// x가 판사이즈보다 크거나 작으면(or)
		field[y][x] == 0 || field[y][x] == 1)											// 필드 yx의 주소가 0이거나 1이면
	{
		printf("%s 잘못된 위치입니다.\n", (stone == 0) ? "Black" : "White");			// 잘못된 위치라고 출력한다. 스톤이 0이면 black을 아니면 white를 출력
		return 1;																		// 1로 되돌아간다??
	}
	else {																				// x,y가 판사이즈 안에 위치하고 필드yx주소가 0과 1이 아니라면
		field[y][x] = stone;															// 필드 yx의 주소는 스톤에 위치한다.
	}
	return 0;
}

int judge(int stone[][PAN_SIZE], int player, int px, int py)							// 심판. 매개변수 스톤 [][]판사이즈, 플레이어, px, py
{
	int i;																				// 변수 i 선언
	int count;																			// 변수 count 선언

	count = 0;																			// 카운트를 0으로 초기화
	for (i = 0; i < PAN_SIZE; i++)														// i는 0부터 18까지 1씩 증가한다.
	{	// 수평
		if (stone[py][i] == player)														// 만약 스톤 pyi의 주소값이 플레이어와 같다면
		{
			count++;																	// 카운트를 1 더한다.
			if (count > 4)	return 1;													// 스톤 pyi의 주소값이 플레이어와 같아서 1씩 더한값이 3이되면 반환한다.
		}
		else if (count)	count = 0;														// 스톤 pyi의 주소값이 플에이어와 다르다면 카운트는 0이다.
	}
	count = 0;																			// 카운트를 0으로 초기화
	for (i = 0; i < PAN_SIZE; i++)														// i는 0부터 18까지 1씩 증가한다.
	{	// 수직
		if (stone[i][px] == player)														// 스톤 ipx의 값이 
		{
			count++;
			if (count > 4)	return 1;
		}
		else if (count)	count = 0;
	}
	count = 0;
	int b;
	int y;
	b = py - px;
	for (i = 0; i < PAN_SIZE ; i++)
	{	
		y = i + b;
		if (( y >= 0 && y < PAN_SIZE) && stone[y][i] == player)
		{
			count++;
			if (count > 4)	return 1;
		}
		else if (count)	count = 0;
	}
	count = 0;
	b = py + px;
	for (i = 0; i < PAN_SIZE; i++)
	{
		y = i + b;
		if ((y >= 0 && y < PAN_SIZE) && stone[y][i] == player)
		{
			count++;
			if (count > 4)	return 1;
		}
		else if (count)	count = 0;
	}
	count = 0;
	return 0;
}
int judgedred(int array[][PAN_SIZE], int size, int player)
{
	int i, j;
	int count = 0;
	int k;

	k = player;

	for (i = 0; i < PAN_SIZE - 5; i++)
	{
		for (j = 0; j < PAN_SIZE; j++)
		{
			if (array[i][j] == k && array[i + 1][j + 1] == k && array[i + 2][j + 2] == k && array[i + 3][j + 3] == k && array[i + 4][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i - 1][j + 1] == k && array[i - 2][j + 2] == k && array[i - 3][j + 3] == k && array[i - 4][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i - 1][j + 1] == k && array[i - 2][j + 2] == k && array[i - 3][j + 3] == k && array[i - 4][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i][j + 1] == k && array[i][j + 2] == k && array[i][j + 3] == k && array[i][j + 4] == k)
				return 1;
			else if (array[i][j] == k && array[i + 1][j] == k && array[i + 2][j] == k && array[i + 3][j] == k && array[i + 4][j] == k)
				return 1;
		}
	}
	return 0;
}
int copyArray(int dummy[][PAN_SIZE], int pan[][PAN_SIZE]) {
	for (int i = 0; i < PAN_SIZE; ++i) {
		for (int k = 0; k < PAN_SIZE; ++k) {
			dummy[i][k] = pan[i][k];
		}
	}
	return 0;
}


int team01(int pan[][PAN_SIZE], int* px, int* py);
int team02(int pan[][PAN_SIZE], int* px, int* py);
int team03(int pan[][PAN_SIZE], int* px, int* py);
int team04(int pan[][PAN_SIZE], int* px, int* py);

int gameOn(
	int (*black)(int[][PAN_SIZE], int*, int*),
	int (*white)(int[][PAN_SIZE], int*, int*)
)
{
	int player = 0, x = 0, y = 0;
	int pan[PAN_SIZE][PAN_SIZE] = { 0 };
	int dummy[PAN_SIZE][PAN_SIZE] = { 0 };
	int stoneCount = 0;
	int replay;
	
	// x = -1 게임이 시작된다.
	// y = -1 흑돌(0), 0 백돌(1)
	x = -1, y = -1;
	black(dummy, &x, &y);
	x = -1, y = 0;
	white(dummy, &x, &y);
	x = 0, y = 0;

	panInit(pan);
	// 게임 시작
	while (1)
	{
		system("cls");
		// 오목판 출력
		panDisplay(pan);
		copyArray(dummy, pan);
		do {
			replay = 0;
			// 플레이어 함수 호출
			if (player == 0){ black(dummy, &x, &y);		}
			if (player == 1){ white(dummy, &x, &y);		}
			if (x < 0 || y < 0 || x >= PAN_SIZE || y >= PAN_SIZE) {
				replay = 1;
				printf("%s wrong position\n", (player)?"WHITE":"BLACK");
			}
		} while (replay);

		// 오목돌 저장
		if (setPosition(pan, player, x, y))
		{
			printf("놓을 수 없는 자리입니다.\n");
		}
		else
		{
			// 승패판정
			if (judge(pan, player, x, y))
			{
				system("cls");
				panDisplay(pan);
				printf("%s@{y:%d,x:%d} Win!!!!!!!\n", 
					(player)?"WHITE":"BLACK",y,x);
				break;
			}
			// 플레이어 변경
			player ^= 1;
			stoneCount++;
			if (stoneCount >= (PAN_SIZE * PAN_SIZE))
			{
				system("cls");
				panDisplay(pan);
				printf("더이상 돌을 놓을 자리가 없습니다.\n무승부입니다.");
				player = EOF;
				break;
			}
		}
	}
	return player;
}

int main(int argc, char** argv) {
	int (*play[])(int[][PAN_SIZE], int*, int*) =								// 플레이어 
	{ team01,team02,team03,team04 };
	int score[4][4] = { 0 };
	for (int bl = 0; bl < 4; ++bl) {
		for (int wh = 0; wh < 4; ++wh) {
			if (bl != wh) {
				int winner = gameOn(play[bl], play[wh]);
				printf("\n\t%d team and %d team\n", bl + 1, wh + 1);
				if (winner == EOF) {
					printf("Draw : %d vs %d \n", bl + 1, wh + 1);
				}
				else if (winner == 0) {
					printf("Winner : %d team \n", bl + 1);
					score[bl][wh] += 1;
				}
				else if (winner == 1) {
					printf("Winner : %d team \n", wh + 1);
					score[wh][bl] += 1;
				}
//				getchar();
			}
		}
	}// game

	system("cls");
	printf(" Score Board \n    ");
	for (int i = 1; i <= 4; ++i) {
		printf("%2d\t", i);
	}
	printf("\n");
	for (int i = 0; i < 4; ++i) {
		printf("%2d: ", i + 1);
		for (int k = 0; k < 4; ++k) {
			printf("%2d\t", score[i][k]);
		}
		printf("\n");
	}

}

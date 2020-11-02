#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

char* img[] = { "��","��","�� ","�� ","�� ","�� ","�� ","�� ","�� ","�� ","�� " };		// img��� �迭�ӿ� 11��(���̰� 11��)�� ���ڿ�Ұ� �ִ�.
#define PAN_SIZE 19																		// �������� ������� 19 -> ��ó������� ���� 19��� ������ PAN_SIZE��� ���ڿ� ����

void panInit(int stone[][PAN_SIZE])														// �Ű����� ����, [][] �ǻ�����, ��ȯ�� ����.
{
	int i, j;																			// �������� i, j
	for (i = 0; i < PAN_SIZE; i++)														// i�� 0���� �����ؼ� 18���� 1�� �����Ѵ�.
	{
		for (j = 0; j < PAN_SIZE; j++)													// j�� 0���� �����ؼ� 18���� 1�� �����Ѵ�.
		{
			if (i == 0)																	// i�� 0�̶��
			{
				if (j == 0) stone[i][j] = 2;											// i�� 0�̸鼭 j�� 0�̶�� ����ij�� ���ڿ�� 2���̴�.
				else if (j == PAN_SIZE - 1) stone[i][j] = 4;							// i�� 0�ε� j�� 0�� �ƴ϶�� j�� 18-1 = 17, ����ij�� ���ڿ�� 4���̴�.
				else	stone[i][j] = 3;												// �׸����� �ƴ϶�� ����ij�� ���ڿ�Ҵ� 3���̴�.
			}
			else if (i == PAN_SIZE - 1)													// i�� 0�� �ƴ϶�� i�� 18-1 = 17�̴�.
			{
				if (j == 0) stone[i][j] = 8;											// i�� 0�� �ƴϸ鼭 j�� 0�̶�� ����ij�� ���ڿ�� 8���̴�.
				else if (j == PAN_SIZE - 1) stone[i][j] = 10;							// i�� 0�� �ƴϸ鼭 j�� 0�� �ƴ϶�� j�� 18-1 = 17, ����ij�� ���ڿ�� 10���̴�.
				else	stone[i][j] = 9;												// �׸����� �ƴ϶�� ����ij�� ���ڿ�Ҵ� 9���̴�.
			}
			else																		// i�� 0�� �ƴϰ� 17�� �ƴ϶��
			{
				if (j == 0) stone[i][j] = 5;											// i�� 0�� �ƴϰ� 17�� �ƴҶ� j�� 0�̶�� ����ij�� ���ڿ�� 5���̴�.
				else if (j == PAN_SIZE - 1) stone[i][j] = 7;							// i�� 0�� �ƴϰ� 17�� �ƴҶ� j�� 17�̤��� ����ij�� ���ڿ�� 7���̴�.
				else	stone[i][j] = 6;												// �׸����� �ƴ϶�� ����ij�� ���ڿ�Ҵ� 6���̴�.
			}
		}

	}
}

void panDisplay(int stone[][PAN_SIZE])													// �Ű����� ����, [][] �ǻ�����, ��ȯ�� ����.
{
	int i, j;																			// �������� i, j
	printf("  ");																		// ������ ����Ѵ�.
	for (j = 0; j < PAN_SIZE; j++)														// j�� 0���� �����ؼ� 18���� 1�� �����Ѵ�.
	{
		printf("%2d", j);																// 2�ڸ� ������ j�� ���� ����Ѵ�.
	}
	printf("\n");																		// �೻��.

	for (i = 0; i < PAN_SIZE; i++)														// i�� 0���� �����ؼ� 18���� 1�� �����Ѵ�.
	{
		printf("%2d", i);																// 2�ڸ� ������ i�� ���� ����Ѵ�.
		for (j = 0; j < PAN_SIZE; j++)													// j�� 0���� �����ؼ� 18���� 1�� �����Ѵ�.
		{
			printf("%s", img[stone[i][j]]);												// ����ij�� ���ڿ�Ҹ� ����Ѵ�.
		}
		printf("\n");																	// �೻��.
	}
}
int setPosition(int field[][PAN_SIZE], int stone, int x, int y)							// �Ű����� �ʵ�, [][] �ǻ�����, ����, x��ġ, y��ġ
{
	if (y > (PAN_SIZE - 1) || y < 0 ||													// y�� �ǻ������ ũ�ų� ������(or)
		x > (PAN_SIZE - 1) || x < 0 ||													// x�� �ǻ������ ũ�ų� ������(or)
		field[y][x] == 0 || field[y][x] == 1)											// �ʵ� yx�� �ּҰ� 0�̰ų� 1�̸�
	{
		printf("%s �߸��� ��ġ�Դϴ�.\n", (stone == 0) ? "Black" : "White");			// �߸��� ��ġ��� ����Ѵ�. ������ 0�̸� black�� �ƴϸ� white�� ���
		return 1;																		// 1�� �ǵ��ư���??
	}
	else {																				// x,y�� �ǻ����� �ȿ� ��ġ�ϰ� �ʵ�yx�ּҰ� 0�� 1�� �ƴ϶��
		field[y][x] = stone;															// �ʵ� yx�� �ּҴ� ���濡 ��ġ�Ѵ�.
	}
	return 0;
}

int judge(int stone[][PAN_SIZE], int player, int px, int py)							// ����. �Ű����� ���� [][]�ǻ�����, �÷��̾�, px, py
{
	int i;																				// ���� i ����
	int count;																			// ���� count ����

	count = 0;																			// ī��Ʈ�� 0���� �ʱ�ȭ
	for (i = 0; i < PAN_SIZE; i++)														// i�� 0���� 18���� 1�� �����Ѵ�.
	{	// ����
		if (stone[py][i] == player)														// ���� ���� pyi�� �ּҰ��� �÷��̾�� ���ٸ�
		{
			count++;																	// ī��Ʈ�� 1 ���Ѵ�.
			if (count > 4)	return 1;													// ���� pyi�� �ּҰ��� �÷��̾�� ���Ƽ� 1�� ���Ѱ��� 3�̵Ǹ� ��ȯ�Ѵ�.
		}
		else if (count)	count = 0;														// ���� pyi�� �ּҰ��� �ÿ��̾�� �ٸ��ٸ� ī��Ʈ�� 0�̴�.
	}
	count = 0;																			// ī��Ʈ�� 0���� �ʱ�ȭ
	for (i = 0; i < PAN_SIZE; i++)														// i�� 0���� 18���� 1�� �����Ѵ�.
	{	// ����
		if (stone[i][px] == player)														// ���� ipx�� ���� 
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
	
	// x = -1 ������ ���۵ȴ�.
	// y = -1 �浹(0), 0 �鵹(1)
	x = -1, y = -1;
	black(dummy, &x, &y);
	x = -1, y = 0;
	white(dummy, &x, &y);
	x = 0, y = 0;

	panInit(pan);
	// ���� ����
	while (1)
	{
		system("cls");
		// ������ ���
		panDisplay(pan);
		copyArray(dummy, pan);
		do {
			replay = 0;
			// �÷��̾� �Լ� ȣ��
			if (player == 0){ black(dummy, &x, &y);		}
			if (player == 1){ white(dummy, &x, &y);		}
			if (x < 0 || y < 0 || x >= PAN_SIZE || y >= PAN_SIZE) {
				replay = 1;
				printf("%s wrong position\n", (player)?"WHITE":"BLACK");
			}
		} while (replay);

		// ���� ����
		if (setPosition(pan, player, x, y))
		{
			printf("���� �� ���� �ڸ��Դϴ�.\n");
		}
		else
		{
			// ��������
			if (judge(pan, player, x, y))
			{
				system("cls");
				panDisplay(pan);
				printf("%s@{y:%d,x:%d} Win!!!!!!!\n", 
					(player)?"WHITE":"BLACK",y,x);
				break;
			}
			// �÷��̾� ����
			player ^= 1;
			stoneCount++;
			if (stoneCount >= (PAN_SIZE * PAN_SIZE))
			{
				system("cls");
				panDisplay(pan);
				printf("���̻� ���� ���� �ڸ��� �����ϴ�.\n���º��Դϴ�.");
				player = EOF;
				break;
			}
		}
	}
	return player;
}

int main(int argc, char** argv) {
	int (*play[])(int[][PAN_SIZE], int*, int*) =								// �÷��̾� 
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

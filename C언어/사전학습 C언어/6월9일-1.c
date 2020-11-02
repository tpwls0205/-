#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������, ���Ű ó�����
#include<time.h> // �ð����� ���
#include<ctype.h> // ���ڳ� ���ڰ��� ��ȯó���� �� �� ���

#pragma pack(1)

struct position {
	int x;
	int y;
	int u;
	int d;
	int l;
	int r;
};
struct _Coord {
	int length;						// arr �迭�� ����(���� ����)
//	struct position arr[30*15];		// �����迭
	struct position *arr			// �����迭
};
typedef struct _coord Coord;
typedef struct _position Position;

/* 2������ ǥ���Ϸ��� ����ü�� ��ҷ� �ϴ� [] 1���迭�� ����ϴ��� - ����ü�� ��, ������� ���̵ȴ�.
	[][] 2���迭�� ����ϴ��� - �ڷ����� ��� �Ȱ��ƾ��Ѵ�.
	*/

#define	W	30		// ��ó�����, ��ũ�λ���� �����. ����ϱ� ���Կ��� �� �� ����.
#define H	15		// ���� 30, ���� 15
int map[H][W];	// �����迭, ��� �Լ����� ������ �����ϴ�. ��������, �����迭�� �ڵ����� 0�� ���·� ���������.

int showMap(void) {
	// Ű����� �̵��� ��Ű�� �̵���θ� ������ �����.
	// �� ���� �Է� �Ҷ����� ȭ�� �׸��� ����ϰ� ����� ����
	// <enter> ����
	for (int r = 0; r < H; ++r) {					// ��
		for (int c = 0; c < W; ++c) {				// ��
			map[r][c] = 1;
		}
	}
	return 0;
}

int drawMap(void) {
	// Ű����� �̵��� ��Ű�� �̵���θ� ������ �����.
	// �� ���� �Է� �Ҷ����� ȭ�� �׸��� ����ϰ� ����� ����
	// <enter> ����
	int iy, ix;
		iy = 0;
		ix = 0;
	while (1) { 								// ���ѹݺ�, ctrl + ] ������ ��ȣ�� ¦�� ã�� �� �ִ�.
		system("cls");							// ������ �ܼ� �󿡼� ������ �� �ִ� ���α׷�
		for (int r = 0; r < H; ++r) {					// ��
			for (int c = 0; c < W; ++c) {				// ��
				if (r==iy && c==ix) {
					printf("��");							// �����ڸ� ������ Ÿ����� ���� ���ڿ�
				}
				else {
					printf("%s", (map[r][c]) ?"��":"��"); // ���ǿ����� ; ���� 0�϶� ; �ڴ� 0�� �ƴҶ�
				}
			}
			putchar('\n');
		}// end for
		// Ű���尡 ������ ��
		if (_kbhit()) {				// _kbhit() : Ű���带 �������� / ���ͷ�Ʈ ��� �Ѵ�. / �̺�Ʈ ��� �Ѵ�. / ����ڰ� �߰��� ���� ��
			// Ű���尡 �������� �Էµ� ���ڰ� �������� Ȯ��.
			char ch = _getch();		// echo ����� ����(ȭ�鿡 ������ �ʴ´�) : ����ڰ� ������ �������� ȭ�鿡 ������ �ʴ´�.
			// ����Ű�� ���Ű�̴�.. ���� ��ƴ�..
			// ǥ�� Ű����� ���Ű �Է� �� 2byte�� ���� ����
//			if (ch == 0) {}						    // ù 1byte�� 0 or 0xE0, Ű���� �����
			if (ch == -32) {						// char �ִ� 127���� ǥ���� �ȵȴ�. �׷��� 16������ ������ ǥ���ؾ���. Ű�е���
				ch = _getch();
			}
			// �� ��° byte ���� Ű ��
			if (ch == '\r') {		// <enter> : conio.h ������ enter�� \r�̴�.
				break;				// stop while
			}
//			ch = tolower(ch);		// �Էµ� ���ڸ� �ҹ��ڷ� ����ڴ�. / toupper(ch); // <ctype.h> : ���ڳ� ���ڰ��� ��ȯó���� �� �� ���
			// ����Ű �̵� = 1;
			if (ch == 'W' || ch == 'w' || ch == 72) { // up
				--iy;					  // �ܼ�â���� ���ΰ��� = y - 1
			}
			if (ch == 'S' || ch == 's' || ch == 80) { // down
				++iy;
			}
			if (ch == 'A' || ch == 'a' || ch == 75) { // left
				--ix;
			}
			if (ch == 'D' || ch == 'd' || ch == 77) { // right
				++ix;
			}
			// ���� ��ġ ǥ��
			map[iy][ix] = 1;
		//	map[iy][ix] = 1 - map[iy][ix]; // ��� : �Դٸ� ���ٸ�
		}
	}// end while
	printf("end drawMap()\n\n");
	return 0;
}

Coord* searchMap(void) {
//	map[][];
	Coord *var;
	var = (Coord*)malloc(sizeof(Coord));
	var->length = 0;
	var->arr = (Position*)malloc(var->length * sizeof(Position));
	return &var;
}

int main(int argc, char** argv) {
	drawMap();								// ȣ���ϴ� ��ġ���� ���� �ݵ�� �����̳� ���ǰ� �־���Ѵ�.
	showMap();
											// map[][]
	for (int i = 0; i < cp->length; ++i) {
		printf("(%d %d){ %d %d %d %d }\n",
			cp->arr[i].x,					// cp��°� ����ü���� �� �ȿ� arr��°� �ֱ���
			cp->arr[i].y,					// arr��°� ����ü���� �� �ȿ� x y u d l r�� �ֱ���
			cp->arr[i].u,
			cp->arr[i].d,
			cp->arr[i].l,
			cp->arr[i].r);
	}
	free(cp);

	return 0;
}
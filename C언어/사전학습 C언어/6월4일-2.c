#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������
#include<time.h> // �ð����� ���

int drawLine(int x);

int main(void) {
	int y, x;
	int a, b;

	a = 1;
	b = 0;
	for (x = 0; x < 20; ++x) {
		y = (a * x) + b;
		system("cls"); // ������� ȭ�� �����
		for (int r = 0; r < 20; ++r) {
			for (int c = 0; c < 20; ++c) {
				(r == y && c == x) ? printf("��") : printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}

int main_02(int argc, char* argv[]) {
	int a = 1;  // xy�� ����
	int b = 0;	// y�� ���� �����̵�
	int x = 0;
	int y = (a * x) + b; // �������� ����

	for (x = 0; x < 10; ++x) { // x���� 0~9���� �־������� y���� �󸶰� �������� ����ؼ� ����ϰڴ�.
		y = (a * x) + b;
		printf("{%d,%d}\n",x,y);
	}

	return 0;
}

int main_01(int argc, char* argv[]) {
	drawLine(1);
	return 0;
}

int drawLine(int x) {
	// ȭ�� ���� �׸��� ���α׷� ����
	int y;
//	int x = 4;
	y = (1 * x) + 5;
	// ��, �� ǥ�� �� �ݺ��� 2�� ���ļ� ����� �ڵ�
	for (int r = 0; r < 10; ++r) {		// ���� ����
		printf("[%2d]", r);
		for (int c = 0; c < 10; ++c) {
			// �� ��ġ(r,c)
			if (r ==y && c ==x ) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");				// ���� ����, ǥ��
	}
	return 0;
}
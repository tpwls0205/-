#include<stdio.h>
#include<windows.h>
#include<time.h>
//1. ���� �߱� ������ �ۼ��ϼ���. (�Ʒ��� �Լ��� ������ ��,
//	�ʿ��ϸ� �Լ� �� �ۼ��ص� ��)
//	1) ����� �Է�
//	2) ���
//	3) ��� �����ֱ�
//	4) �ٽ� ���� ����
//
//	0 ~9 �ߺ����� �ʰ�
//	��ǻ�Ͱ� ������ 3�� ����
void makeNum(int num[3]) {
	int check[10] = { 0 };
	for (int i = 0; i < 3; i++) {
		while (1) {
			int n = rand() % 10;
			if (i == 0 && n == 0) continue;
			if (check[n] == 1) continue;
			num[i] = n; check[n] = 1; break;
		}
	}
}
int comparison(int com[3], int user[3]) {
	int strike = 0, ball = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (com[i] == user[j]) {
				i == j ? strike++ : ball++;
			}
		}
	}
	printf("%d strike %d ball ~~~\n\n", strike, ball);
	return strike;
}
int retryGame() {
	printf("�ٽ� �Ͻðڽ��ϱ�?(yes:1 no:0)\n");
	int r; scanf_s("%d", &r);
	return r == 1 ? 1 : 0;
}
int problem1() {
	printf("��ǻ�Ͱ� ������ ���� ���� �����մϴ�.\n");
	Sleep(3000);
	int com[3];
	makeNum(com);
	printf("��ǻ�Ͱ� ���� �����߽��ϴ�.\n");
	Sleep(1000);
	printf("������ �����մϴ�.\n");
	Sleep(1000);
	while (1) {
		printf("'User'�� ������ ���� �Է����ּ���\n");
		int user[3] = {0};
		printf("-----------------\n");
		for (int i = 0; i < 3; i++) {
			printf("%d��° �� : ",i + 1); scanf_s("%d", &user[i]);
		}
		printf("-----------------\n");
		int strike = comparison(com,user);
		if (strike == 3) { 
			printf("�����ϼ̽��ϴ�~~~!!\n\n"); break;
		}
	}
	int r = retryGame();
	return r == 1 ? 1 : 0;
}
int main()
{
	srand((unsigned)time(NULL));
	while (1) {
		printf("������ ������ �Է��ϼ��� : ");
		int select; scanf_s("%d", &select);
		if (select == 0) break;
		else if (select == 1) {
			while (1) {
				int game = problem1();
				if (game == 0) break;
			}
			printf("������ �����Ͽ����ϴ�.\n");
		}
		printf("\n");

	}
}
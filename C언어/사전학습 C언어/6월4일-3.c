#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������
#include<time.h> // �ð����� ���

/*/
// 2�� �迭 ����ϱ�
int display() {
	int numbers[5][10] = { 0 };		// [���Ǳ���][���Ǳ���], 5�� 10��¥�� 2���迭�� �������.
	// ���̸� ��� ����
	// 1�� �迭 ���� ���� �ִ�.. ���� 10�� 1�� �迭 5���� �ִ�..
	printf("\t0 \t1 \t2 \t3 \t4 \n");
	for (int row = 0; row < 5; ++row) {
		// row�� ��, 10�� ¥�� 1�� �迭�� 5�� �����´�.
		printf("%d\t", row);
		for (int col = 0; col < 5; ++col) {
			// col�� ��, 1�� �迭 �ӿ� �ִ� ���� 10�� �����´�.
			printf("%d\t", numbers[row][col]);
		}
		printf("\n");
	}

	return 0;
}
int main(int argc, char** argv) {
	display();

	return 0;
}



// ���� ������ ��ũ�� ����� ��ȯ : �̸��� �ִ� ���, ������ �ƴ�.
#define ASIZE 5				// #�� ������ ; ����Ŭ���� �����ʴ´�. ��ũ�� ��� ����� ���, ��ó���Ⱑ ASIZE��� ���ڸ� ã�Ƽ� 5�� ��ȯ����.


int display() {
	int numbers[ASIZE][ASIZE] = { 0 };		// [���Ǳ���][���Ǳ���], 5�� 10��¥�� 2���迭�� �������.
	// 1�� �迭 ���� ���� �ִ�.. ���� 10�� 1�� �迭 5���� �ִ�..
		printf("\t0 \t1 \t2 \t3 \t4 \n");
	for (int row = 0; row < ASIZE; ++row) {
		// row�� ��, 10�� ¥�� 1�� �迭�� 5�� �����´�.
		printf("%d\t", row);
		for (int col = 0; col < ASIZE; ++col) {
			// col�� ��, 1�� �迭 �ӿ� �ִ� ���� 10�� �����´�.
			printf("%d\t", numbers[row][col]);
		}
		printf("\n");
	}

	return 0;
}
int main(int argc, char** argv) {
	display();

	return 0;
}

*/

// ���� ������ ��ũ�� ����� ��ȯ : �̸��� �ִ� ���, ������ �ƴ�.
#define ASIZE 5				// #�� ������ ; ����Ŭ���� �����ʴ´�. ��ũ�� ��� ����� ���, ��ó���Ⱑ ASIZE��� ���ڸ� ã�Ƽ� 5�� ��ȯ����.

// 2���迭�� �����Ѵ�. -> �Ű������� ����ڴ�.
int display(int numbers[][ASIZE], int rows) {
	                                                           		// [���Ǳ���][���Ǳ���], 5�� 10��¥�� 2���迭�� �������.
	// 1�� �迭 ���� ���� �ִ�.. ���� 10�� 1�� �迭 5���� �ִ�..
	printf("\t0 \t1 \t2 \t3 \t4 \n");
	for (int row = 0; row < rows; ++row) {
		// row�� ��, 10�� ¥�� 1�� �迭�� 5�� �����´�.
		printf("%d\t", row);
		for (int col = 0; col < ASIZE; ++col) {
			// col�� ��, 1�� �迭 �ӿ� �ִ� ���� 10�� �����´�.
			printf("%d\t", numbers[row][col]);
		}
		printf("\n");
	}

	return 0;
}
int main(int argc, char** argv) {
	int pan[ASIZE][ASIZE] = { 0 };

	pan[0][1] = 1;		// [0]���� [1]������ �̱�
	pan[1][0] = -1;		// ���� [1]���� [0]������ ��

	display(pan,ASIZE);		// �迭��, ����

	return 0;
}
#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������

// �� ������ 9���� ��, ������ ���� ������ �־����?
// 10���� ������� ����. ǥ���� 3x3

/* a�� �� b�� �� c�� ������
leftdan�� ����ù���� ����
*/
int a;
int b;
int c;
int leftdan = 2;
int dan;
int v;
int unit = 3;

int main(void) {
    for (int c = 0; c < 3; c++, leftdan += unit) {

        for (int b = 0; b < 9; b++) {
            v = b + 1;
            for (int a = 0; a < unit; a++) {
                dan = leftdan + a;
                if (dan <= 9) {
                    printf("%d\t",(dan*v));
                }
            }
                printf("\n");
            }
            printf("----------------\n");
        }
        return 0;
    }


int main_01(void) {
    int leftdan = 2;
    int dan;
    int v;
    int unit = 3; // �� �ٿ� �� �� ���� ����Ұų�
    for (int bl = 0; bl < 3; ++bl, leftdan += unit) { // 3�������� �����. 0~2������, ù���� ����(2) += unit
                                                      //++bl�� �������� ����, leftdan+=unit�� 2,5,8�� ������ ������?  
        for (int row = 0; row < 9; ++row) {           // 9���� �����. 0��~8�����
            v = row+1;                                // v = 1~9 / row�� ���� ���⿣ 0~8������ +1�� ��
            for (int col = 0; col < unit; col++) {    // 3���� �����. 0��~2������
                dan = leftdan + col;                  // ����ù���� ������ + ���� ������ ���Ѵ�
                if (dan<=9) {                         // ���� �װ��� 9�����̸�
                    printf("%dx%d = %d\t", dan, v, (dan * v)); // ex) 2+0 , 1, 2
                }
            }
            printf("\n");                             // �ึ�� ������ �������
        }
            printf("----\n");                         // ���������� ---- ���м�
        }
    return 0;
}





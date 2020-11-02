#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력

// 한 블럭에는 9개의 행, 옆으로 단의 구분이 있어야함?
// 10단은 출력하지 않음. 표형식 3x3

/* a는 열 b는 행 c는 페이지
leftdan은 왼쪽첫열의 정수
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
    int unit = 3; // 한 줄에 몇 개 열을 출력할거냐
    for (int bl = 0; bl < 3; ++bl, leftdan += unit) { // 3페이지를 만든다. 0~2페이지, 첫열의 숫자(2) += unit
                                                      //++bl은 페이지의 순서, leftdan+=unit은 2,5,8의 정수를 만들어낸다?  
        for (int row = 0; row < 9; ++row) {           // 9행을 만든다. 0행~8행까지
            v = row+1;                                // v = 1~9 / row에 따라서 쓰기엔 0~8까지라 +1을 함
            for (int col = 0; col < unit; col++) {    // 3열을 만든다. 0열~2열까지
                dan = leftdan + col;                  // 왼쪽첫열의 정수와 + 열의 순서를 더한다
                if (dan<=9) {                         // 만약 그값이 9이하이면
                    printf("%dx%d = %d\t", dan, v, (dan * v)); // ex) 2+0 , 1, 2
                }
            }
            printf("\n");                             // 행마다 밑으로 띄워쓰기
        }
            printf("----\n");                         // 페이지마다 ---- 구분선
        }
    return 0;
}





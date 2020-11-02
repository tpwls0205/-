#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

int drawLine(int x);

int main(void) {
	int y, x;
	int a, b;

	a = 1;
	b = 0;
	for (x = 0; x < 20; ++x) {
		y = (a * x) + b;
		system("cls"); // 출력전에 화면 지우기
		for (int r = 0; r < 20; ++r) {
			for (int c = 0; c < 20; ++c) {
				(r == y && c == x) ? printf("○") : printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}

int main_02(int argc, char* argv[]) {
	int a = 1;  // xy의 기울기
	int b = 0;	// y축 방향 평행이동
	int x = 0;
	int y = (a * x) + b; // 변수들의 관계

	for (x = 0; x < 10; ++x) { // x값을 0~9까지 넣어줬을때 y값이 얼마가 나오는지 계산해서 출력하겠다.
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
	// 화면 선을 그리는 프로그램 구현
	int y;
//	int x = 4;
	y = (1 * x) + 5;
	// 행, 열 표현 시 반복문 2개 겹쳐서 만드는 코드
	for (int r = 0; r < 10; ++r) {		// 행의 개수
		printf("[%2d]", r);
		for (int c = 0; c < 10; ++c) {
			// 각 위치(r,c)
			if (r ==y && c ==x ) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");				// 행의 구조, 표현
	}
	return 0;
}
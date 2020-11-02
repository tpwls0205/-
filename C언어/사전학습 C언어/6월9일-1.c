#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력, 기능키 처리기능
#include<time.h> // 시간관련 헤더
#include<ctype.h> // 문자나 문자값의 변환처리를 할 때 헤더

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
	int length;						// arr 배열의 길이(점차 증가)
//	struct position arr[30*15];		// 정적배열
	struct position *arr			// 동적배열
};
typedef struct _coord Coord;
typedef struct _position Position;

/* 2차원을 표현하려면 구조체를 요소로 하는 [] 1차배열을 사용하던지 - 구조체는 열, 멤버들은 행이된다.
	[][] 2차배열을 사용하던지 - 자료형이 모두 똑같아야한다.
	*/

#define	W	30		// 전처리명령, 매크로상수를 만든다. 상수니까 대입연산 할 수 없다.
#define H	15		// 가로 30, 세로 15
int map[H][W];	// 전역배열, 모든 함수에서 접근이 가능하다. 전역변수, 전역배열은 자동으로 0인 상태로 만들어진다.

int showMap(void) {
	// 키보드로 이동을 시키고 이동경로를 벽으로 만든다.
	// 한 번씩 입력 할때마다 화면 그리고 출력하고 지우는 동작
	// <enter> 종료
	for (int r = 0; r < H; ++r) {					// 행
		for (int c = 0; c < W; ++c) {				// 열
			map[r][c] = 1;
		}
	}
	return 0;
}

int drawMap(void) {
	// 키보드로 이동을 시키고 이동경로를 벽으로 만든다.
	// 한 번씩 입력 할때마다 화면 그리고 출력하고 지우는 동작
	// <enter> 종료
	int iy, ix;
		iy = 0;
		ix = 0;
	while (1) { 								// 무한반복, ctrl + ] 누르면 괄호의 짝을 찾을 수 있다.
		system("cls");							// 윈도우 콘솔 상에서 실행할 수 있는 프로그램
		for (int r = 0; r < H; ++r) {					// 행
			for (int c = 0; c < W; ++c) {				// 열
				if (r==iy && c==ix) {
					printf("♬");							// 영문자를 제외한 타국어는 전부 문자열
				}
				else {
					printf("%s", (map[r][c]) ?"☆":"★"); // 조건연산자 ; 앞은 0일때 ; 뒤는 0이 아닐때
				}
			}
			putchar('\n');
		}// end for
		// 키보드가 눌렸을 때
		if (_kbhit()) {				// _kbhit() : 키보드를 눌렀을때 / 인터럽트 라고 한다. / 이벤트 라고 한다. / 사용자가 중간에 들어올 때
			// 키보드가 눌렸으니 입력된 문자가 무엇인지 확인.
			char ch = _getch();		// echo 기능이 없음(화면에 보이지 않는다) : 사용자가 무엇을 눌렀는지 화면에 보이지 않는다.
			// 방향키는 기능키이다.. 아주 어렵다..
			// 표준 키보드는 기능키 입력 시 2byte의 값이 전달
//			if (ch == 0) {}						    // 첫 1byte는 0 or 0xE0, 키보드 상단쪽
			if (ch == -32) {						// char 최대 127까지 표현이 안된다. 그래서 16진수나 음수로 표현해야함. 키패드쪽
				ch = _getch();
			}
			// 두 번째 byte 실제 키 값
			if (ch == '\r') {		// <enter> : conio.h 에서는 enter가 \r이다.
				break;				// stop while
			}
//			ch = tolower(ch);		// 입력된 문자를 소문자로 만들겠다. / toupper(ch); // <ctype.h> : 문자나 문자값의 변환처리를 할 때 헤더
			// 방향키 이동 = 1;
			if (ch == 'W' || ch == 'w' || ch == 72) { // up
				--iy;					  // 콘솔창에서 위로간다 = y - 1
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
			// 현재 위치 표시
			map[iy][ix] = 1;
		//	map[iy][ix] = 1 - map[iy][ix]; // 토글 : 왔다리 갔다리
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
	drawMap();								// 호출하는 위치보다 위에 반드시 선언이나 정의가 있어야한다.
	showMap();
											// map[][]
	for (int i = 0; i < cp->length; ++i) {
		printf("(%d %d){ %d %d %d %d }\n",
			cp->arr[i].x,					// cp라는게 구조체구나 그 안에 arr라는게 있구나
			cp->arr[i].y,					// arr라는게 구조체구나 그 안에 x y u d l r이 있구나
			cp->arr[i].u,
			cp->arr[i].d,
			cp->arr[i].l,
			cp->arr[i].r);
	}
	free(cp);

	return 0;
}
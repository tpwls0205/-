#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

/*/
// 2차 배열 사용하기
int display() {
	int numbers[5][10] = { 0 };		// [행의길이][열의길이], 5행 10열짜리 2차배열을 만들었다.
	// 길이를 계산 가능
	// 1차 배열 여러 개가 있다.. 길이 10인 1차 배열 5개가 있다..
	printf("\t0 \t1 \t2 \t3 \t4 \n");
	for (int row = 0; row < 5; ++row) {
		// row번 행, 10개 짜리 1차 배열을 5번 가져온다.
		printf("%d\t", row);
		for (int col = 0; col < 5; ++col) {
			// col번 열, 1차 배열 속에 있는 변수 10번 가져온다.
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



// 위의 내용을 매크로 상수로 변환 : 이름이 있는 상수, 변수가 아님.
#define ASIZE 5				// #이 붙은건 ; 세미클론을 쓰지않는다. 매크로 상수 만드는 방법, 전처리기가 ASIZE라는 문자를 찾아서 5로 변환해줌.


int display() {
	int numbers[ASIZE][ASIZE] = { 0 };		// [행의길이][열의길이], 5행 10열짜리 2차배열을 만들었다.
	// 1차 배열 여러 개가 있다.. 길이 10인 1차 배열 5개가 있다..
		printf("\t0 \t1 \t2 \t3 \t4 \n");
	for (int row = 0; row < ASIZE; ++row) {
		// row번 행, 10개 짜리 1차 배열을 5번 가져온다.
		printf("%d\t", row);
		for (int col = 0; col < ASIZE; ++col) {
			// col번 열, 1차 배열 속에 있는 변수 10번 가져온다.
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

// 위의 내용을 매크로 상수로 변환 : 이름이 있는 상수, 변수가 아님.
#define ASIZE 5				// #이 붙은건 ; 세미클론을 쓰지않는다. 매크로 상수 만드는 방법, 전처리기가 ASIZE라는 문자를 찾아서 5로 변환해줌.

// 2차배열을 전달한다. -> 매개변수를 만들겠다.
int display(int numbers[][ASIZE], int rows) {
	                                                           		// [행의길이][열의길이], 5행 10열짜리 2차배열을 만들었다.
	// 1차 배열 여러 개가 있다.. 길이 10인 1차 배열 5개가 있다..
	printf("\t0 \t1 \t2 \t3 \t4 \n");
	for (int row = 0; row < rows; ++row) {
		// row번 행, 10개 짜리 1차 배열을 5번 가져온다.
		printf("%d\t", row);
		for (int col = 0; col < ASIZE; ++col) {
			// col번 열, 1차 배열 속에 있는 변수 10번 가져온다.
			printf("%d\t", numbers[row][col]);
		}
		printf("\n");
	}

	return 0;
}
int main(int argc, char** argv) {
	int pan[ASIZE][ASIZE] = { 0 };

	pan[0][1] = 1;		// [0]번이 [1]번에게 이김
	pan[1][0] = -1;		// 따라서 [1]번은 [0]번에게 짐

	display(pan,ASIZE);		// 배열명, 길이

	return 0;
}
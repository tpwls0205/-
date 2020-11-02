#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

/*
	1. 소스 파일 만들기 .c
	2. 헤더 파일 붙이기 .h
	3. main 함수 만들기 int main(){return 0;}
	4. main 함수 안에 실행 내용 작성하기
*/
/*
	@arg : argc - 인자의 개수
		   argv - 문자열(들) 인자
*/
// 함수선언부 /////////////////////////////////////////////////////////
// {} 중괄호를 뺀 앞부분만 적은 것 -> 함수의 선언,	LNK오류(링커) -> 호출한 함수의 실제 실행할 내용{}이 없다.
void fn(void);
int sum(int a, int b);	// 전달되는 값을 받을 변수 - 매개 변수라고 말한다.()소괄호 안에 만든 변수를 말한다.
int printIntArray(int ar[],int length );   // 전달과 반환이 있는 함수, 배열을 전달할 때는 배열 길이를 같이 전달하여야 한다.

// ////////////////////////////////////////////////////////////////////


int main(int argc, char** argv) { // char* argv[] == char** argv, 실행할 내용은 메인함수 안에 있어야함. 메인함수가 fn함수를 호출한다.
/*
	fn(); // 함수 호출(실행); , 메인함수안에 실행시키려는 함수는 메인함수 위에 선언을 적어둔다.

	int rt = getValue(); // 실행 후 int 형 값을 반환한다.
	// 함수의 반환은 1개만 가능, 전달은 여러 개 가능하다.

	int hap = sum(2, 10);
*/
	int score[10] = { 0 };	// 객체 지향의 핵심 1. 소유권 // 메인함수가 배열을 생성했다. 그 배열의 처리를 위해 다른함수에게 전달하겠다.
	// 1차 배열을 전달한다. (배열명, 길이)
	int nums = printIntArray(score,10);

	return 0;
}

// 함수 정의부 ////////////////////////////////////////////////////////
void fn(void) {
	// 반환형 void 일 때 return 생략 가능 void fn(void) -> 앞에 void가 반환할 것, 뒤에 ()안에는 전달할 것
	return; // 함수를 종료한다는 의미
}
int sum(int a, int b) {
	// 매개변수가 있는 함수를 호출할 때는 반드시 전달해야 한다.
	int s = a + b;
	return s;
}

// 배열을 전달받는 함수 만들기
int printIntArray(int ar[], int length) {
	// Q. 소괄호()에 선언하는 것을 매개변수 -> int ar[]은 배열이 간게아니라 포인터임. 그래서 길이 값을 줘야함
	int nums = 0;	    // 출력한 개수를 반환
	for (int i = 0; i < length; ++i) {
		printf("%d ", ar[i]);
		nums++;
	}
	printf("\n");		// 화면 행 단위
	return nums;
}

int getValue(void) {

	int result = 0;
	return result;
}

// END ////////////////////////////////////////////////////////////////
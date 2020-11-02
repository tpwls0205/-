#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력

/* 자료구조 : 배열 -> c언어에서는 같은 자료형끼리. 배열명, 요소명(타입에 따라 요소명이 다르다) */
/* 선언 후 사용 */

int main_09(void) {
	// 배열 선언, 생성 - 자료형, 최대 개수(길이)를 정해놔야 한다.
	int arr[10]; // int 변수(요소) 최대 10개를 저장할 수 있다. 배열 arr을 선언, 생성 했다. [] 하나 인 것을 1차배열(선형)이라 부른다. [][]2차 [][][]3차
	char string[80]; // 문자배열(문자열) : char형을 요소로 하는 배열

	int length = 10; // 배열의 길이를 저장 arr배열의 10이라는 최대 값을 length로 넣음
	int curlength = 0; // 현재 배열이 0개 저장되어있다. 현재 길이, 최대 길이를 항상 비교

	int index = 0; // 요소번호 : 각 요소의 일련 번호, 아래 i를 선언 해둔것임.

	// 배열명 : arr - [0]번 요소의 주소를 의미함. 값x
	// 요소명 : 배열명[번호]
	// 요소가 배열인 경우 - 2차(다차) 배열
	//		요소명 == 배열명

	// 처리 방법 - 반복문과 함께 사용
	for (int i = 0; i < length; ++i) {
		arr[i] = (i + 1);				// 모든 요소의 임의 값을 저장
	}
	for (int i = 0; i < length; ++i) {
		printf("%d", arr[1]);			// 요소의 값을 출력, 배열의 1번요소의 값을 출력한다.
	}

	return 0;
}

// 배열을 만들기 -> 길이 현재, 최대 선언 -> 반복문으로 임의 값 저장 -> 요소의 값 출력

int main_02(void) {
	int score[] = { 1,2,3,4,5,6,7,8,9 }; // 묵시적 선언, 중괄호 안에 몇개 썻냐에 따라 배열의 길이가 됌. = 9개
	int length = sizeof(score) / sizeof(score[0]);      // 배열의 길이를 변수에 따로 저장할 것, 배열의 크기/요소의 크기
														// sizeof() 연산 : 길이와 크기를 판단하기 위해 쓴다.(메모리 byte)
	printf("size of array : %d\n", sizeof(score));		// 배열의 크기(byte)를 알고 싶다. 배열명을 소괄호에 넣어야함.
	printf("size of element : %d\n", sizeof(score[0])); // 요소의 크기(byte)를 알고 싶다. []번호, 자료형이 같기때문에 다른 요소도 크기가 같다.

	printf("long %d\n", sizeof(long));
	printf("long long %d\n", sizeof(long long));
	printf("%d\n", score); // 배열의 시작주소를 알려줌(메모리속), [0]번 요소의 주소, 배열명은 주소인데 0번 요소의 주소이다 -> 0번 요소가 score배열의 시작주소를 가지고 있기 때문에
	
	return 0;
}

/*  
	길이와 크기를 구분해야한다.
	요소번호 범위를 절대 초과하게 해서는 안된다.
	배열명 : 이름인데 주소로 이해하라.
	요소 : 각 데이터
	요소명 : 이름을 붙치는 건데 요소의 type에 따라 다르게 봐야한다. 
	요소번호 : 언어에 따라 음수, 양수를 쓰지만 c언어는 양수의 정수만 표현 0에서부터 1씩증가하는 번호 : 0 ~ (배열길이 -1)까지
*/


// 배열선언할때 c에선 변수선언할 수 없다 = []안에 변수명을 쓸 수 없다. 정수만 가능하다.

int main_03(void) {
	// 정수배열
	int maxlength = 10;
	int score[2 * 5] = { 0 }; // 배열요소 10가지를 0으로 초기화 시켰다. {0}
	int index = 1 * 5 + 2;	  // 7번요소의 값 = 2차배열의 1번배열의 2번요소 값, 행번호*행길이+열번호
	score[7] = 1;
	printf("%d\n", score[index]);
	printf("%d\n", score[7]);

		return 0;
}
// row(행번호) x length of row(행의 전체 길이) + col(열번호) = [row][col]의 2차배열과 같음
//	int d2[2][5];			  // int형 변수가 10개인데 5개씩 2셋트로 묶었다.


int main_04(void) {
	// 정수 배열 - 추가
	int score[10] = { 0 };		// 꼭 초기화 할 필요는없지만 배열 데이터 중 값의입력이 안된 것을 찾기위해(출력했을때) 구분할 때 이용되기도 한다.
	int last = -1;				// 마지막에 추가된 요소번호가 몇번이냐 -> -1번이다.
	++last;						// 요소번호는 음수가 될 수 없으니까 1증가시킨다. -> 0번이 된다.
	score[last] = 1;			// 처음이자 마지막 데이터이다. last의 요소에 1이라는 값을 저장한다.
	++last;						// 요소번호는 음수가 될 수 없으니까 증가시킨다. -> 1번이 된다.
	score[last] = 2;			// 마지막 데이터이다. last의 요소에 2라는 값을 저장한다.
	++last;						// 요소번호는 음수가 될 수 없으니까 증가시킨다. -> 2번이 된다.
	score[last] = 3;			// 마지막 데이터이다. last의 요소에 3라는 값을 저장한다.
								
	for (int i = 0; i <= last; ++i) {	 // 출력 시 추가된 값들(저장한) 출력해라
		printf("[%d]%d\n", i, score[i]); // 내가 저장한 번호와 값을 출력해라.
	}

	if (last<10-1) {
		++last;
		score[last] = 3; // 범위 내에서
	}
	else {
		printf("full \n");
	}

	return 0;
}


// 변수의 초기값과 ++,--가 달라지면 전체로직이 바뀐다.
// 0번부터 시작하면 = 개수 : last(개), 번호[last-1]번이 마지막이다.
int main_05(void) {
	// 정수 배열 - 추가
	// 추가 시 초기값에 따라 증감 순서가 다르다.
	// 번호(요소) 범위를 판단하는 조건이 다르다.
	int score[10] = { 0 };
	int last = 0;
	score[last] = 1;
	++last;						
	score[last] = 2;			
	++last;						
	score[last] = 3;
	++last;								 // 여기서 ++이 붙기때문에 <10이된다. <10-1을 써버리면 하나의 요소를 건너뛰게 된다.

	for (int i = 0; i < last; ++i) {	 // 출력 시 추가된 값들(저장한) 출력해라
		printf("[%d]%d\n", i, score[i]); // 내가 저장한 번호와 값을 출력해라.
	}

	if (last < 10) {
		score[last] = 3; // 범위 내에서
		++last;
	}
	else {
		printf("full \n");
	}

	return 0;
}


// head -> 데이터를 꺼낼때(out), tail -> 데이터를 넣을때(in) : 꺼내면 버려진다.
// head와 tail의 번호가 같으면 데이터가 비었거나 꽉차있거나
	// 일정한 크기 배열을 무한한 공간처럼 사용하는 방법(알고리즘)
	// 2개 이상의 변수들로 공간을 제어하는 방법
	// 요소 번호로 제어하는 아이디어 - 원형 큐
    // stack - 역순 , Queue - 정순

int main_07(void) {
	// stack(스택) : 선입후출, 후입선출 = 역순
	int score[10] = { 0 };
	int sp = -1;	// sp(스택포인터, 마지막 요소번호)
	// 추가하기
	++sp;
	score[sp] = 1;
	// 마지막 요소를 꺼내기
	int value = score[sp];
	--sp;

	return 0;
}

/*
프로그래밍을 할때는
1. 문제가 무엇이냐?
1-1. 프로그래밍을 위해서 필요한 단어, 개념들로 정리하는 시간이 필요하다.
1-2. 자료형과 함수를 찾는 것 : 자료형이 어떤 것들이 있을건지, 함수들이 어떤 게 있는지
2. 제어문에 실행할 순서에 따라 작성한다.
=> 반복, 숙달만이 살아남는 방법이다.
*/

// 선생님이 학생 점수를 입력하고 출력하는 프로그램을 만들어 본다.
// 누가? 사용할 것인지 생각하고 만들어야 한다.
#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

// 무엇을? 무엇을 하려는건지 생각하고 만들어야 한다.
// 점수를 입력, 출력하는 프로그램을 만든다. 문장 속 목적어와 동사를 찾아라. => ~를 : 값, 데이터 / 한다,해라,하기 : 명령, 함수
// 점수라는 데이터를 c언어에서 어떤 자료형으로 표현할 수 있는가?
// 점수라는 것(0~100)을 정수, 실수로 표현하더라. => int라는 자료형으로 표현할 수 있다.
// 함수 : scanf() => 정수입력 받을 수 있고 / printf() => 정수출력 할 수 있고
// 함수 사용시 반환, 전달을 생각해야한다.

// 코딩 : 프로그램을 실행 시킬 때 첫 번째에 실행되는게 무엇이냐..
//   빌드 : 1. 전처리 : 문자를 바꾼다.
		  //2. compile : 번역(단어, 문법) -> 오류 : c(번호)
		  //3. link : 연결, 조합, 여러 개의 파일을 연결 -> 오류 : LNK(@@)

int step01() {
	// 점수 : 정수(int)
	int score;
	printf("Score > "); // 입력하세요를 출력
	scanf_s("%d", &score);		// scanf_s 함수로 정수를 입력받고 싶을 때, 입력받아라 -> 저장한다. / & - 이 변수에 값을 저장한다.
	// 변수에 값을 다른 함수가 저장하게 하려면 변수 주소를 준다.
	printf("입력받은 점수 : %d \n", score);
		// 변수의 값을 전달
	return 0;
}

int step02() {	// 학생 1명이 점수 3개를 가진다.
	// 점수 1개, 3과목 : 국어, 영어, 수학
	// 변수에는 1개의 값을 저장할 수 있다.
	int kor, eng, math; // 변수 여러 개 사용 시, 각각 변수 의미(용도)를 알아야한다.

	// scanf, printf 한 번 실행 시 여러 개 입출력 함수이다.
	printf("국어 영어 수학 점수 순서로 입력 > ");
	scanf_s("%d %d %d", &kor, &eng, &math); // 순서가 중요, 국, 영, 수

	printf("%d %d %d \n", kor, eng, math);
	return 0;
}

int step03() {
	// 학생이 5명이 있음, 각 학생마다 국,영,수 점수를 가진다.
	// 총 15개의 점수들
	// 여러 개의 데이터를 처리하는 프로그램 만드는 연습
	// 자료구조 :여러 개 변수 다루는 방법
	int score[15] = { 0 };			//int kor2, eng2, math2;	// 각각의 변수를 선언하는 개수가 많아지면 한계가 있다.
	// 배열 요소(변수) 각 0~ 번호 == 요소번호
	// 첫번째 학생의 3과목 점수로 보겠다.
	printf("첫번째 학생의 점수 > ");
	scanf_s("%d %d %d", &score[0], &score[1], &score[2]);			// scanf_s (&변수:주소)
	printf("두번째 학생의 점수 > ");
	scanf_s("%d %d %d", &score[3], &score[4], &score[5]);
	printf("세번째 학생의 점수 > ");
	scanf_s("%d %d %d", &score[6], &score[7], &score[8]);
	printf("네번째 학생의 점수 > ");
	scanf_s("%d %d %d", &score[9], &score[10], &score[11]);
	printf("다섯번째 학생의 점수 > ");
	scanf_s("%d %d %d", &score[12], &score[13], &score[14]);

	printf("%d %d %d\n", score[0], score[1], score[2]);
	printf("%d %d %d\n", score[3], score[4], score[5]);
	printf("%d %d %d\n", score[6], score[5], score[6]);
	printf("%d %d %d\n", score[9], score[8], score[9]);
	printf("%d %d %d\n", score[12], score[13], score[14]);

	return 0;
}

int step04() {
	// 변수들의 개수가 많아지면 제어문 활용
	// 배열과 for은 거의 한 쌍으로 다닌다.
	int score[15] = { 0 };
	for (int i = 0; i < 15; ++i) {
		int v;
		scanf_s("%d", &v);
		score[i] = v ;
	}
	for (int i = 0; i < 15; ++i) {
		printf("%d\t", score[i]);
	}

	return 0;
}

int step05() {
	// 5 x 3 == 15개의 정수를 입력, 저장, 출력기능을 만들자. 사람의 눈에 알기 쉽게
	// 출력, 추가적 계산(합, 평균)
	// 구분 : 학생과 점수의 구분 방법이 필요하다.
	int score[5 * 3] = { 0 }; // [5][3]
	int no = 1;
	for (int i = 0; i < 13; i+=3) {
		printf("[%d]번 학생의 점수들을 입력하세요 > ", no);
		no++;
		scanf_s("%d %d %d", &score[i+0], &score[i+1], &score[i+2]);
	
	}
	// 입력한 방법에 따라서 출력하세요
	no = 1;
	for (int i = 0; i < 13; i += 3) {
		printf("[%d]번 학생의 점수 > ", no++);
		printf("%d %d %d\n", score[i + 0], score[i + 1], score[i + 2]);

	}
	return 0;
}

int main(void) {
	
	step05();
	return 0;
}

/* int main(void) {
	// 식 : 연산자를 사용한 문장 : 산술, 관계, 논리
	// 100을 출력하고 싶어, 고민하지말고 일단 변수를 만들어라.
	int n = 100;
	step02();
	printf("%d", n);			// LNK 이름을 찾을 수 없다는 에러 => header file
								// 만약 헤더가 없다면 함수 자체를 바꿔라
	return 0;
}
*/
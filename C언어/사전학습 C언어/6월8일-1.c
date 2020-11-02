#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

/*
	문자열 : '\0' 을 끝으로 하는 문자 배열
	문자열 처리를 위한 포인터
	동적할당 : 포인터를 이용하여 실행 중 메모리의 생성과 삭제 관리 배열, 구조체, 구조체 배열
*/

int string_def0() {
	// 문자열 - 문자 배열 - char[] => char형 배열
	// 배열명 - 주소(&[0])
	// 문자열의 처리는 첫 글자로부터 '\0' 까지 - 가변 길이
	// NULL - pointer , NUL - 문자 => 어찌됐던 둘 다 0 => 0은 논리적으로 거짓
	char str[80] = { 0 };
	// 문자열 출력 : "%s", char *, for
	printf("%s \n", str); // 배열명 [0]번에서부터 NUL문자 전까지 출력한다.
}


int string_def1() {

	char str[80] = { "korea 2\0 20 fi" };
	printf("%s \n", str);
}


int string_def2() {

	char str[80] = { "korea 2020 fi" };
	printf("%s \n", str);

	int v = puts(str);	// &[0] 0번 요소의 주소, char형의 주소
	printf("v:%d\n", v);

	for (int i = 0; str[i] != '\0';  ++i) // 문자열은 NUL문자를 끝으로 보기 때문에.
	{
		putchar(str[i]);							// 화면에 1글자 출력
	}
	putchar('\n');									// 문자는 '' , 문자열은 ""

	// fputs();										// c언어에서 f가 앞에있으면 파일이 있다. f가 뒤에있으면 형식이 있다.
}


int string_input() {
	char str[80] = { 0 };
	while(1){										// == int i = 80; while (--i) {
	int v = scanf_s("%s",&str,sizeof(str));			// 키보드로 문자를 입력받는 함수, &변수명 : 단어로 나누어 받는다. 공백, tab, \n, \r은 받지못한다.
													// _s 함수들은 주소와 크기를 전달해야 한다.
	// 사용자가 중간에 나가고 싶을때는 어떻게 할 것이냐..?
	// 배열의 공간을 다 쓰거나, 중간에 나가고싶을 때
	// ?
	
	if (v == 0) { break; }
													// printf("v:%d\n", v);
//	fputs(str, stdout);								// fputs 파일출력 함수, 어디에서 ~ 어디로 , stdin - 키보드, stdout - 모니터에 출력해라
//	fputs("\n", stdout);							// fputs 는 행내림을 직접해줘야함
	puts(str);										// puts 는 자동으로 행내림을 해줌

	}			// 반복을 종료시키려면 어찌해야하는가?
	return 0;
}


int string_input1() {
	char str[80] = { 0 };
	fgets(str, 80, stdin);
	gets_s(str, sizeof(str) - 2);					// gets_s : 키보드입력 / -1, -2를 준 것은 배열의 여유공간을 주는 것 / get_s 함수는 한 줄을 통으로 들고온다.
	printf("%s, \n", str);

	return 0;
}


int string_input2() {
	char str[80] = { 0 };
	char ch;
	int i = 0;								// 글자 단위로 변경, 확인처리를 할 때는 한글자씩 하곤한다.
	while ((ch = getchar()) != '\n')		// 안쪽 소괄호의 결과값이 같으면 반복하고 다르면 종료한다. getchar : 문자를 하나씩 가져온다. enter를 치면 끝난다는 것
	{
		if (i == 0) {						// 입력된 첫글자가 알파벳 소문자이면
			if ('a'<=ch&&ch<='z') {			// 소문자 이면
				ch -= 32;					// 대문자로 바꾼다.
			}
	}
		str[i] = ch;
		++i;
	}
	str[i] = 0; // '\0'
	printf("%s, \n", str);
	return 0;
}


int ptr4string0() {
	char* p;					// 포인터변수 - char 형 변수의 주소
	// const : 변경하지 않는다. 상수로 표현한다.
	const char* cp;				// 문자값을 바꾸지 않는다. 주소는 변경 가능 / cp는 바꿔도 되나 char형을 바꾸지말라
//	cp = 1004;
//	cp = 2004;
//	cp = 3004;
//	*cp = 'A';					// 포인터가 가르키고 있는 변수는 바꾸지 못한다. const 때문에
	char* const ccp;			// 문자는 바꿀 수 있지만 주소는 변경 못한다.
//	const char* const ccp;		// 문자, 주소 변경 못함
	return 0;
}


int ptr4string1() {
	char* p;
	const char* cp;
	cp = "korea 2020";			// 문자열의 시작주소를 저장하는 p, 문자열을 저장한게 아님. 문자열을 저장하려면 배열이 있어야함!, 문자열 상수라고 부름(읽기전용)
//	*cp = 'K';					// p가 가르키는 곳에 값을 저장
	// " " 문자열 상수는 변경할 수 없다.

	return 0;
}


int string2pointer(){
	// 문자열과 포인터 같이 사용하기
	char aStr[80] = "korea 2020";
	char* pStr;
	// = 연산의 왼쪽 오른쪽 자료형 일치시키기
	pStr = aStr; // [0]요소의 주소 char*
//	pStr = aSter[0]; // 포인터 = 변수 : 일치가 안되서 사용불가능, 요소명 : 배열명[번호], 1차배열 : 변수이다.
					 // 다차 배열의 요소는 배열명[번호] - 배열이다
	pStr = &aStr[0];  // 포인터 = 주소 : 일치되어 사용 가능
	// 포인터변수를 사용할 때는 배열명이 하나 더 있다고 생각하고 사용하자.
	pStr[0]= 'A'; // aSter[0]
	pStr[1]= 'B'; // aSter[1]

	printf("%s\n", aStr);

	char(*pp)[80];	// 배열포인터 변수 : *pp는 char형 80짜리 배열을 가르킨다.
	pp = &aStr;						// 배열의 주소
	printf("%s\n", (*pp));			// (*pp) = aStr
	printf("%s\n", pp[0]);			// (*pp) = aStr
//	printf("%d \n", pp + 1);		// 주소(포인터변수) + (1 * sizeof( *주소) )
	return 0;
}


int op4pointer() {
	// 배열 요소번호와 포인터 연산의 관계
	char str[80] = { "korea\n" };
	char* p = &str[0]; // = str 이라는 배열명을 쓴거와 의미가 같다.
	printf(" %p - %c \n", p + 0, *(p + 0)); // p : 포인터 변수명(주소), *p : 포인터 변수가 가르치는 주소의 값 / 주소+정수 == 주소
	printf(" %p - %c \n", p + 1, *(p + 1));		// int변수 했을때는 주소값을 0, +4, +8, +12 를 해야한다. 크기의 값이 char과 차이나기 때문에
	printf(" %p - %c \n", p + 2, *(p + 2));
	printf(" %p - %c \n", p + 3, *(p + 3));
	printf(" %p - %c \n", p + 4, *(p + 4));

	printf(" %p - %c \n", &str[0], str[0]);
	printf(" %p - %c \n", &str[1], str[1]);
	printf(" %p - %c \n", &str[2], str[2]);
	printf(" %p - %c \n", &str[3], str[3]);
	printf(" %p - %c \n", &str[4], str[4]);
	return 0;
}


// 키보드 입력받을때 : scanf_s(단어) , gets_s(행단위), fgets(행단위), getchar(문자 하나)
// 모니터 출력받을때 : 
// 문자열의 끝 : 메모리(NUL = 0) 문서,키보드(\n,\r)
// 배열과 포인터를 같게 생각하면서 사용할려면 시작위치[0]와 이동거리(size)를 같게 만들어야한다.
// 타입을 보고 이동거리를 생각해야한다. char 1byte씩 int 4byte씩 등
int main(int argc, char** argv) {

//	string_def(); // 출력. 문자열의 끝이 있다.
 string_input(); // 입력. 문자열의 끝이 무엇인지
//	ptr4string(); // 문자열은 주소로 다룬다.
//	string2pointer(); // 문자열과 포인터변수
//	op4pointer();
	return 0;
}
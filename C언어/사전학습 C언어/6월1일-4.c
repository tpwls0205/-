#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
/*
	자료형, 변수 사용
	연산자
	- 산술연산
	- 관계연산자(비교연산자)
	- 논리연산자
	- 비트연산(2진수)
	
*/
int main(void) {
	// 산술연산 : 값(정수, 실수) - c언어는 문자도 산술연산에 들어간다.
	int n = 10;
	double lf = 12.34;
	char ch = 'a'; // a는 아스키코드 97번

	printf("%d\n", n + 20); // 정수
	printf("%lf\n", lf + 20); // 실수 + 정수 = 실수
	printf("%d\n", ch + 20); // 정수
	printf("%c\n", 97 + 20); // 정수 + 정수지만 %c(문자로 표현), char도 실제로는 정수이다.
	// 아스키는 127번까지만 그 이상은 ?로 표시됌

	// printf("%d\n", 97/0); // 나누기에서 0은 안됌
	printf("%lf\n", (double)97/20); // lf에서 정수/정수는 안됌으로 97을 실수형식으로 바꾸기 위해 (double)
	// printf("%lf\n", (double)(97/20)); 먼저 실수로 바꾼 후에 나누기 할 것

	printf("%d\n", n % 5); // 나머지는 n이 5의 배수인지, n을 5미만의 값으로 바꾸기 위해

	// 형변환 시 주의
	int a = 256;
	double b = a; // 정수 -> 실수로 바꾼다는 개념
	int c = b; // double은 8바이트 int는 4바이트 int로 바꾸다가 데이터 손실이 일어날 수 있다.
	printf("%d%lf%d\n", a, b, c);


	return 0;
}
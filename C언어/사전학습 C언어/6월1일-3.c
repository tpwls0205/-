#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력

int main(void) {
	// 자료형 변수의 선언과 사용
	int num;
	num = 10;
	printf("%d \n", num); // 10진수로 num변수를 출력해라
	printf("%c %d %lf %s \n", 'A', 12, 32.45, "string");
	// 형식문자열, printf는 문자열을 줘야한다. %_ : 형식지정자
	// %d(10진수 정수), %x(16진수 정수), 'c'(문자 하나), "s"(문자열), f(실수), lf(실수, 더블과 같음)
	// p(주소형, 16진 표현법)
		return 0;
}
#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더


// 전역변수 : 함수 밖에서 선언된 변수
// 이 소스 파일에 정의된 모든 함수들이 사용 가능하다.


int main_01(int argc, char** argv) {
	// 선언 위치에 따른 변수의 구분 : 변수의 지역성
	// 지역변수 : 함수 내에서 선언된 변수, 이 함수에서만 사용할 수 있다.
	// {} 중괄호도 지역성을 가진다.
	int v1 = 10;		// v1에 10이라는 값을 저장
	int* p;
	{
		int v2 = 1000;		
		v1 = 20;			// 중괄호안에서도 사용가능
		v2 = 2000;
		p = &v2;
		printf("v2:%p\n", &v2);
	}
		printf("v2:%d\n", *p);
	*p = 3000;				// 중괄호 밖에서 선언된 포인터 변수 -> 중괄호 내에 변수의 주소를 따옴 -> 중괄호 밖에서 중괄호 안에 선언된 변수 주소 가져올 수 있음.
		printf("%p -> %d\n", p, *p); // 포인터를 이용한 간접 참조 방식 가능, 변수가 살아 있는 경우에만 가능.

//	v2 = 3000; 지역 내 선언된 변수는 지역 밖에서 사용 불가

	return 0;
}


// 전역변수 : 함수 밖에서 선언된 변수
// 이 소스 파일에 정의된 모든 함수들이 사용 가능하다.
int gValue = 10;
extern int ext_value;	// 외부변수, 이 소스 파일이 아니라 다른 소스 파일에 있는 변수를 끌어온다. 다른 소스파일에 정의된 전역변수의 사용
static int internal_value;	// 전역변수에서 스태틱은 외부에서 변수를 끌어가는걸 막는 것. extern 불가

int f2() {
	// 지역변수에 static
	static int static_value=0; // 유지해라, 없애지마라

	int v3 = 100;			// 지역변수는 이 함수가 살아 있는 동안에만 사용 가능
	gValue = 100;
	return 0;
}

int f1() {
	f2();
	return 0;
}

int static_fn() {
	
	static int cnt = 0;  // 앞에 static를 붙침으로써 지역이 사라지지 않음.
	cnt++;
	return cnt;
}

int main_02(int argc, char** argv) {	// main이 시작이자 끝. main 함수 속에서 호출되면 f1으로 f1에서 호출되면 f2. f2가 리턴(지역이 사라짐) -> f1가 리턴(지역이 사라짐) -> main에서 남은 작업마무리

	// 함수가 호출된 횟수를 알고 싶다.
	int cnt;
	cnt = static_fn();
	printf("%d\n", cnt);

	cnt = static_fn();
	printf("%d\n", cnt);

	cnt = static_fn();
	printf("%d\n", cnt);


	return 0;
}


// 포인터 변수 주소를 알면 변경이 가능하다..
int updateNumber(int *param) {	// 2. 매개변수가 포인터로 해야한다. // param = &cnt
	int v = *param;	// v = cnt	// v에 포인터변수를 저장
	*param = v * 10;			// v에 10을 곱해서 포인터변수에 저장해서 main 함수에 반환
	return 0;
}

int main(int argc, char** argv) {
	int cnt = 2;
	// 1. 자신의 변수를 다른 함수가 변경하도록 값이 아닌 주소를 전달해야한다.
	updateNumber(&cnt); // & 주소를 저장
	printf("%d\n", cnt);


	return 0;
}

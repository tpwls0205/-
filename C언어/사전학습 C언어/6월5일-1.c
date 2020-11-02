#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더


int main_01(int argc, char** argv) {
	// 사용자 정의 형 (복합형) : 구조체 : 변수들의 모음 / 클래스가 아니다. c++과 큰 차이점
	// 1. 구조체형 정의
	// 2. 구조체형 변수 선언
	// 3. 구조체형 변수 안에 멤버들을 처리 -> 구조체안에 들어있는 변수들을 멤버라고 부름. / 함수를 제외한 나머지는 전부 멤버로서 안에 넣을 수 있다.
	// 멤버 접근하는 방법
	// 1. 변수명.멤버명 / 이름일때는 .(점)
	// 2. 포인터변수명(주소)->멤버명 / 주소일때는 -> 화살표												

	return 0;
}

// 구조체는 보통 전역변수처럼 가장 꼭대기에 정의한다.
// 배열과 구조체의 공통점 데이터를 여러가지를 가지고 있다. / 배열은 자료형이 모두 같은애들, 구조체는 여러가지 자료형을 모을 수 있다.
struct car {
	// member
	int code;
	char name[80];
	double price;
};

int main_02(int argc, char** argv) {
	struct car myCar = { 1, "Grandure", 1000.10};						// 변수선언, struct car : car까지 다 쓴게 자료형의 이름이다 헷갈리지 말자 c++과 차이점 
																		// 멤버에 들어있는 순서에 맞게 타입에 맞게 작성
	printf("{%d, %s, %lf}\n",
		myCar.code, myCar.name, myCar.price								// 구조체는 안에 멤버들을 반복으로 할 수 없다. 하나하나 다 적어야한다.
		);

	return 0;
}

int main_03(int argc, char** argv) {
	struct car myCar = { 1, "Grandure", 1000.10 };				

	// 구조체 변수를 복사한다.
	// 진짜 복사한다. ( 깊은 복사 ) / 참조만 복사하는 것은 얕은복사	
	struct car uCar = myCar;
	
	printf("%p vs %p \n", myCar.name, uCar.name);							// %p -> 주소를 알려줌 
	printf("{%d, %s, %lf}\n",												// 깊은 복사는 주소는 다르지만 똑같은거 하나를 통으로 다른 주소에 만든거고
		uCar.code, uCar.name, uCar.price									// 얕은 복사는 하나의 주소가 여기 있다고 링크를 걸어주는 개념.
	);

	return 0;
}

// #define Car struct car								// Car를 struct car로 바꿔서 생각해라. 문자의 치환, 자료형이 아님, 추천방법은 아님
typedef	struct car Car;								// 자료형명을 새로 등록 / c언어의 명령 / 현재 자료형명이 struct car인데 Car도 같은 자료형명으로 취급하겠다.
typedef unsinged int _uint;							// 구조체뿐만이 아니라 긴이름의 자료형명을 바꾸기 위해 사용할 수 있다.
typedef struct car {								// 구조체 앞에 typedf 붙치고 }와 ; 사이에 여러가지 이름을 지정할 수 있음.
	// member
	int code;
	char name[80];
	double price;
}CAR, UCAR, ICAR;


int main(int argc, char** argv) {
	typedef struct car ic;
	// 구조체형 이름을 짧게, 다르게 사용하고 싶을 때.
	Car mycar;
	printf("%d\n", sizeof(Car));
	printf("%d\n", sizeof(mycar));
		// 구조체 기본 크기 계산법 : 멤버들의 총합 보다 크게 나온다.

	return 0;
}


#pragma pack(1)				// 구조체 멤버정렬. 1byte 간격으로 맞춰서 구조체를 만들어라. 서로 다른 자료형이 있는 구조체의 크기를 실제 총합과 똑같이 만드는 방법
typedef struct _rgb_color {
	unsigned char blue : 2;                  //  unsigned char blue;
	unsigned char green : 4;                 // unsigned char green;
	unsigned char red : 2;                   //  unsigned char red;
}RGB;
	// :(콜론) 뒤에 숫자가 붙은 것 -> 비트 필드 구조체 - 자료형이 모두 같아야하며, 비트의 총합이 자료형의 크기와 같아야함 : 2+4+2=8비트 = 1바이트(char)

int main_05(void) {
	printf("%d\n", sizeof(RGB));		// 크기 byte : 자료형이 똑같을때는 총합과 똑같이 나오는데, 자료형이 서로 다르면 총합이 조금 더 크게 나온다.


	return 0;
}


#pragma pack(1)				
typedef struct _bits {						// 비트 필드 구조체, 0번 비트~7번 비트 = 1바이트, 각각의 비트에 데이터가 있는지 없는지 구분할 수 있음.
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
}BITS;

// 자료구조 -> 자기 참조 구조체
struct _node {
	int data;
	struct _node* prev;					// 구조체 멤버중에 포인터가 있는데, 포인터의 왼쪽 타입이 구조체의 명칭과 같을 때 -> 자기 참조 구조체
	struct _node* next;
};

int main_06(void) {
	printf("%d\n", sizeof(RGB));


	return 0;
}

#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

// 구조체는 데이터들 변수들만 있는거 // 클래스는 구조체에 함수들까지 합쳐놓은거  ------- 이 둘의 차이점을 기억해둬야함!!

// data 여러 개의 데이터처리 시 반드시 하나를 지정하는 방법 / 여러개의 데이터를 다루려면 반드시 하나하나를 지정해야한다.
struct _car{
	int number;									// 차
	double price;								// 주차요금
	time_t in;									// 들어오는 시간, 주차요금은 부호가 없다.
	time_t out;									// 나가는 시간, 주차요금은 부호가 없다.
};
typedef struct _car Car;

// Car를 여러 개 저장(주차)해야하니까 - 타입이 똑같다.- 배열을 사용하겠구나
Car list[20];									// Car형 배열을 만든다.
int seq = 0;
int hasEmpty(void) {
	// 비어있다 ? 상태를 어떻게 표현할 것이냐??
	for (int i = 0; i < 20; ++i) {
		if (list[i].number == 0); {						// 비어있다는 것을 넘버가 0인걸로 표현하겠다.
			return i;									// 비어있으면 i라는 요소번호를 반환하겠다.
		}
	}
	return -1;	// 빈자리가 없다. 50번 행으로 돌아감.
}
int goHome() {
	time_t now = time(NULL);					// 사람입장에서의 시간, unsigned int 는 4바이트인데 time_t는 longlong타입이라 8바이트를 먹는다. 즉 짤려서 표기된다.
	struct tm tm;
	localtime_s(&tm, &now);					    // 시간 계산 방법	printf("\n now : %lld\n", now/(60*60));
	int h = tm.tm_hour;
	int m = tm.tm_min;
	if (h > 18); {                              // printf("%d시 %d분 \n", h, m);
		return 0;								// 퇴근시간이다.
	}
	return 1;
}

//	clock_t ct = clock();						// cpu의 실행시간, clock는 long타입 4바이트 = int 4바이트. 크기가 맞다. / 우리 프로그램이 실행된지 얼마나 됐는지
//	printf("\n clock : %d\n", ct);


int main(int argc, char** argv) {
	printf("// 주차장입니다. 저는 주차장 관리자입니다.\n");
	do {
		printf("[1]IN [2]OUT >");	// 키보드입력 받는 함수 : getchar();	/ getchar(); 를 두개 붙쳐쓰면 입력한 문자 갯수 2개까지는 1개는 버리고 뒤에 getchar를 다시 실행해준다.
		char key = getchar(); getchar();   // getchar : 여러문자를 입력할 수 있지만 enter를 쳐야 끝이난다. / enter까지 포함해서 입력한 문자 갯수만큼 반복실행한다.
			if (key == '1') {
				printf("// 차가 들어오고 있다.\n");
				printf("// 주차장 내 빈 공간이 있으면?");
				if (hasEmpty() != -1) {
					printf("// 주차할 수 있다.\n");
					Car car;
					printf("차량번호 >");
					scanf_s("%d", &car.number);		// 키보드에서 입력받은 자료를 원하는 자료형으로 변환해줌, 차번호 4자리 정수받기
					car.price = 1000.0;				// 기본요금
					car.in = time(NULL);			// 들어온 시간
					// 주차시키기
					list[seq] = car;				// seq라는 변수선언, 하나씩 증가시키려고
					++seq;
				}
				else {
					printf("// 빈 자리가 없으면 나가야한다.\n");
				}
			}
			if (key == '2') {
				printf("// 차가 나가고 있다.\n");
				printf("차량번호 >");
					int num;
				scanf_s("%d", &num);
				Car car;
				for (int i = 0; i < 20; ++i) {
					if (num == list[i].number) {			// 나간차량이 맞는지 비교해봐야함.
						car = list[i];
						printf("// 차가 나갔으니 빈 자리가 생겼다.\n");
						list[i].number = 0; // 빈 자리라는 의미의 값
						break;
					}
				}
				if (car.number != 0) {
					printf("// 요금을 주세요\n");
					car.out = time(NULL);
					// 시간 차이(주차한 시간)
					car.price += 5000.0;
					printf("요금 : %lf\n", car.price);
				}
				
			
			}
	} while (goHome());															// 퇴근 시간이 아직 안됐으면..!, 거짓이 나와야 퇴근할 수 있음 c언어의 거짓은 0
			printf("// 퇴근 시간이 되어서 주차장 출입문을 잠그고 집에 간다.\n");	// 퇴근 시간이 됐으면..!

	return 0;
}

/*

typedef struct _car* PCar;				// P가 붙어있으면 포인터라고 생각한다.
typedef struct _car ACar[12];			// 배열이구나

int main_02(int argc, char** argv) {
	ACar list;				// struct _car listp[12]; 와 의미가 같음
	PCar now = &list[0];	// struct _car *now; 와 의미가 같음
	Car temp;

	printf("%d\n", sizeof(list));

	temp = list[0];		// 구조체 변수의 복사
	temp.number = 11;
	temp.price = 1000.0;

	return 0;
}


struct _car {
	int number;
	double price;
};

int main_01(int argc, char** argv) {

	struct _car t;
	t.number = 1003;				// 멤버에다 값을 저장 t.
	t.price = 1000.0;

	// 주소->멤버명
	(&t)->number = 2003;			// 멤버주소->멤버명 = 값 저장

	// 포인터 변수는 주소다.
	struct _car* cp;
	cp = &t;
	cp->price = 2000.0;

	(*cp).number = 3003;			// 포인터에 *(별) 붙힌거는 이름붙친거와 같다. t라는 이름을 쓴거임.

	// 만약 헷갈린다면 -> 화살표를 많이 써라.

	return 0;
}

*/
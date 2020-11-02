#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

int main_01(void) {
	// 길이 15인 정수형 1차 배열 선언하기
	int numbers[15] = { 0 };
	int length = 15; // sizeof(배열명)/sizeof(int); --- 꼭 요소명이 아니더라도 인트형이니까 byte는 같기때문에 계산가능
	
	// 난수 발생 기준값 변경하고 싶으면 - rand함수를 진짜 랜덤하게 하고싶으면
	srand( (unsigned int)time(NULL) ); // 시간은 항상 변하기 때문에 시간정보를 써라, unsigned int 부호없는 정수(양수)

	// 모든 요소에 임의 정수를 저장하세요.
	for (int i = 0; i < length; ++i) {
		numbers[i] = rand(); // 0~32656범위의 정수값을 랜덤으로 입력
	}
	for (int i = length - 1; i >= 0; --i) {
		printf("%6d", numbers[i]);									// %@d : @에 숫자에 따라 자릿수를 지정할 수 있다. ex) 6하면 6자릿수
	}
	printf("\n");

	// 배열 처리 시 기본 기능
	int min;
	int max;
	min = max = numbers[0];	                                       // 0번요소의 값을 min max에 저장하라
	// 찾기 : 값, 요소번호를 찾으려는건지 분간해서 찾기
	// 최소최대 값을 찾기
	for (int i = 1; i < length; ++i) {
		if (min > numbers[i]) {  // 현재 최소값은 min변수인데 이거보다 작은 요소가 있으면 그 요소를 min변수에 넣는다.
			min = numbers[i];
		}
		if (max < numbers[i]) {
			max = numbers[i];
		}
	}
	printf("max:%d,min:%d\n", max, min);


	// 최소최대값이 몇번요소이냐?
	min = max = 0;												// 값 0을 min max에 저장하라
	for (int i = 1; i < length; ++i) {
		if (numbers[min] > numbers[i]) {  // 현재 최소값은 min변수인데 이거보다 작은 요소가 있으면 그 요소를 min변수에 넣는다.
			min = i;
		}
		if (numbers[max] < numbers[i]) {
			max = i;
		}
	}
	printf("max:%d,min:%d\n", numbers[max], numbers[min]);

	// 배열 요소들으 크기 순서대로 재배치 - 정렬 sort
	// 정렬 방법 - 알고리즘(다양하다)
	// 비교 - 교환
	int first = 0; // 첫 번째 요소번호
	int last = length-1 ;  // 마지막 요소번호					

	for (int k = 0; k < (length/2); ++k) {	        // for문이 끝날때 요소번호 양끝이 사라지기 때문에 나누기 2해야함.
		int min = first;         // 요소번호
		int max = first;
		for (int i = first+1; i <= last; ++i) {
			if (numbers[min] > numbers[i]) {
				min = i;
			}
			if (numbers[max] < numbers[i]) {
				max = i;
			}

		}
		// 교환
		int t = numbers[min];						 // min 요소번호는 t변수에 저장한다.
		numbers[min] = numbers[first];				 // first 요소번호는 min 요소번호에 저장한다.
		numbers[first] = t;							 // t변수를 first 요소번호에 저장한다.
		t = numbers[max];
		numbers[max] = numbers[last];
		numbers[last] = t;
		
		printf("\n");
		++first;
		--last;
	}
	// 정렬 후 출력
	for (int i = 0; i < length; ++i) {
		printf("%6d", numbers[i]);				// %@d : @에 숫자에 따라 자릿수를 지정할 수 있다. ex) 6하면 6자릿수
	}
	printf("\n");

	return 0;
}


int main_02(void) {
	int shape[40] = { 1 };						// 0번 요소에만 1의 값을 준다.										// 왜 전체에 주는게 아니지? 40개 요소인 shape배열인데
	int cur = 1;
	while(1){									// 1은 논리적으로 참이니까 무한반복
		system("cls");							// 윈도우 명령 : 화면 지우기
		for (int i = 0; i < 40; ++i) {
			printf("%s", (shape[i]) ?"@ " : "  ");			// 조건연산자(삼항) -> (조건식) ? 참일때 : 거짓일때 ;
															// 요소의 값에 따라 출력할 문자열이 다르다.
		}
		printf("\n");
		// 1을 한 칸씩 오른쪽으로 옮긴다.
		shape[cur-1] = 0;
		shape[cur] = 1;							// cur이라는 요소에 1이라는 값을 저장해라.
		cur++;
		cur %= 40;								// 0~39사이에서만의 범위만 표현되도록

	}
	return 0;
}


int main_03(void) {
	int W = 19;									// 가로길이
	int H = 19;									// 세로길이
	int omokpan[19*19] = { 1,0,1,1,0 };												// 오목판 배열의 19x19 요소들을 1,0,1,1,0 이라는 순서로 값을 저장하겠다.
	// 요소의 값이 0이면 ┼ 1이면 ○를 출력하고 싶다.								// 요소의 값이 0으로 저장되있으면 +를 1으로 저장되있으면 O을 출력하겠다.

	for (int r = 0; r < H; ++r) {				// r번 행							// 변수r은 0부터 1씩 더하여 세로길이인 H미만까지(세로길이 19 미만)
		for (int c = 0; c < W; ++c) {			// c번 열							// 변수c는 0부터 1씩 더하여 가로길이인 W미만까지(가로길이 19 미만)
			// 값에 따른 분기 처리를 할 수 있다.
			int v = omokpan[r * W + c];			//	r*W는 페이지개념 c는 페이지속 번호개념  // 오목판 배열의 행*가로길이+열로 뽑아낸 요소번호 속의 값을 = 변수 v에 저장하겠다.(??)
			if(v == 0) {															// 만약 v에 0의 값이 저장되있으면 +모양을 출력
				printf("┼");
			}
			else if (v == 1) {														// 그게 아니고 v에 1의 값이 저장되있으면 O모양을 출력
				printf("○");
			}
		}
		printf("\n");
	}
	return 0;
}



int display(int n) {
	char d0[] = {
	0, 1, 0,
	1, 1, 0,
	0, 1, 0,
	0, 1, 0,
	1, 1, 1
	};

	char d1[] = {
	0, 1, 0,
	1, 1, 0,
	0, 1, 0,
	0, 1, 0,
	1, 1, 1
	};
	char d2[] = {
	1, 1, 1,
	0, 0, 1,
	1, 1, 1,
	1, 0, 0,
	1, 1, 1
	};
	char d3[] = {
	1, 1, 1,
	0, 0, 1,
	1, 1, 1,
	0, 0, 1,
	1, 1, 1
	};
	char d4[] = {
	1, 0, 1,
	1, 0, 1,
	1, 1, 1,
	0, 0, 1,
	0, 0, 1
	};
	char d5[] = {
	1, 1, 1,
	1, 0, 0,
	1, 1, 1,
	0, 0, 1,
	1, 1, 1
	};
	char d6[] = {
	1, 1, 1,
	1, 0, 0,
	1, 1, 1,
	1, 0, 1,
	1, 1, 1
	};
	char d7[] = {
	1, 1, 1,
	1, 0, 1,
	0, 0, 1,
	0, 0, 1,
	0, 0, 1
	};
	char d8[] = {
	1, 1, 1,
	1, 0, 1,
	1, 1, 1,
	1, 0, 1,
	1, 1, 1
	};
	char d9[] = {
	1, 1, 1,
	1, 0, 1,
	1, 1, 1,
	0, 0, 1,
	1, 1, 1
	};

	int digit;
	for (int i = 0; i < 5; ++i) {
		for (int k = 0; k < 3; ++k) {
			digit =                           // darr[n][idx]; // 배열 요소번호 선택한다. if분기문을 대체할 수 있다.
															   // [][] 다차배열 : 배열의 배열, []배열섹션[]하나의 배열안에 요소 개수(길이)
				(n == 0) ? d0[idx] :
				(n == 1) ? d1[idx] :
				(n == 2) ? d2[idx] :
				(n == 3) ? d3[idx] :
				(n == 4) ? d4[idx] :
				(n == 5) ? d5[idx] :
				(n == 6) ? d6[idx] :
				(n == 7) ? d7[idx] :
				(n == 8) ? d8[idx] :
				d9[idx];

			++idx;
			printf("%s", (digit) ? "ㅁ" : " ");
		}
		printf("\n");
	}
	return 0;
}

	int main_01(void){
		display


			// 포인터 함수포인터 -> 함수를 교체할 수 있다.(EVT : 이벤트 발생 처리할 함수들의 표)

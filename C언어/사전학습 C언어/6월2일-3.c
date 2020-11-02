#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력


/* int main(void) {
	// 컴퓨터는 음의개념을 보수로 취한다.
	unsigned int sn = 0x800A1234; // 4byte를 16진수로 표시, x는 16진수라는 표시, unsigned는 부호를 사용하지 않겠다.
	printf("%u\n", sn); // %d는 부호를 사용하겠다는 뜻임, %u를 사용해야함. %X,%x는 16진수 표기

	return 0;
}
	*/

// 정수를 2진수로 출력하는 함수를 만들었다.
void printBits(int n) {
	for (int b = 31; b >= 0; b--) {
		if (n & (1 << b)) {// b번 비트의 값이 1이면, 0이면 거짓 0이 아니면 참
			printf("1"); // if else : 둘 중에 하나만 해야한다.
		}
		else {
			printf("0");
		}
	}
	printf("\n");
}

int main(void) {
	// int가 4바이트니까 32번을 뽑아내야한다
	unsigned int n = 0xA5; // 2진수값을 쓸 수 없다. A: 1010, 5: 0101
	printBits(n);
			// n변수의 [2]번 비트를 0으로 만드세요
	unsigned int a = (1 << 2); // 2번 비트만 1 나머지는 0
	unsigned int c = ~(1 << 2); // ~(1의보수) 반전된다. 2번을 제외한 나머지는 1
	n = n & c; // c변수의 1인 비트 자리는 모두 n의 값이 그대로, &연산을 통해서 하나라도 0이 있으면 0이 되기때문
	printBits(n);
	return 0;
}
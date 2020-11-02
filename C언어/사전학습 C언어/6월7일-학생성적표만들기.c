#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

// 학생 10명의 국,영,수 성적을 10행 3열로 입력받아서 출력해주세요.

int kor;
int eng;
int math;
int i;

int step01() {
	printf("학생 성적을 입력해주세요. > ");
	scanf_s("%d %d %d\n", &kor, &eng, &math);
	printf("%d %d %d\n", kor, eng, math);
	return 0;
}

int step02() {
	printf("학생 성적을 입력해주세요. > ");
	for (i = 0; i < 10; ++i) {
		scanf_s("%d %d %d\n", &kor, &eng, &math);
		printf("%d %d %d\n", kor, eng, math);
	}
	return 0;
}

int main(void) {
	step02();

	return 0;
}
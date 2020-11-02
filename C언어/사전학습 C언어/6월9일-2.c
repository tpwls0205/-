#include<stdio.h> // <> 비주얼스튜디오 안에 인클루드 폴더안에 헤더파일이 있다. - 표준함수(라이브러리)
#include<string.h> // 문자열에 관련된 헤더
#include<stdlib.h> // 그 외에 기타 필요한 헤더 --- 위 3개의 헤더는 필수적으로 붙는다.
#include<math.h> // 함수문제에 관한 헤더
#include<conio.h> // 위에 4개는 표준입출력, conio.h는 콘솔입출력
#include<time.h> // 시간관련 헤더

struct _data {
	int code;
	char name[80];
	int type;
};

int main(void) {
	FILE* fp;
	// 파일에 쓰기한대로 읽어들인다...
	// 파일에 쓰기한 형식이 뭐냐 : format
	struct _data d = { 0 };
	d.code = 100;
	strncpy_s(d.name, 80, " 임의문자열 ", strlen(" 임의문자열 "));
	d.type = 1;

	fopen_s(&fp, "demo-user.dat", "wb");
	fwrite(&d, sizeof(d), 1, fp);
	fclose(fp);

	struct _data t;
	fopen_s(&fp, "demo-user.dat", "rb");
	fread(&t, sizeof(t), 1, fp);
	fclose(fp);
	printf("%d %s %d \n", t.code, t.name, t.type);

	return 0;
}


int main_binary(int argc, char** argv) {
	// 블럭입출력
	// 크기 단위로 입출력
	FILE* fp;
	const char* fname = "demo-block.dat";
	int nums[5][20] = { 0 };							// 20바이트 만큼 공간을 다쓴다.
	fopen_s(&fp, fname, "rb");							// wb 새로만들어 쓰기, rb 읽기
//	fwrite(nums, sizeof(nums), 1, fp);
	fread(nums, sizeof(nums), 1, fp);
	fclose(fp);
	printf("%s \n", nums[0]);
	printf("%s \n", nums[1]);
	printf("%s \n", nums[2]);
	printf("%s \n", nums[3]);
	return 0;
}


int main_append(int argc, char** argv) {
	// 파일 입출력
	// FILE 형 구조체, 포인터변수
	// 함수의 사용법만 알아두면 된다.
	// 권한, 용도가 있다.	소유자, 그룹, 외부 - w(쓰기), r(읽기), x(실행)
	FILE* fp = NULL;
	fopen_s(&fp, "demo.txt", "a");
	// 파일이 있으면 기존 파일 끝에 추가
	// 파일이 없으면 새로 생성
	if (fp == NULL) {
		printf("not found error : %s \n", "demo.txt");
		return 0;
	}
	fprintf(fp, "[LOG]%s: %d-%d-%d : %s \n", "192.168.0.1", 2020,10,20, "bitcamp");

	// 파일 닫기
	fclose(fp);
	return 0;
}


int main_write(int argc, char** argv) {
	// 파일 입출력
	// FILE 형 구조체, 포인터변수
	// 함수의 사용법만 알아두면 된다.
	// 권한, 용도가 있다.	소유자, 그룹, 외부 - w(쓰기), r(읽기), x(실행)
	FILE* fp = NULL;
		// 파일 열기					// w:newfile / r:읽기만 / a:eof 파일끝에 추가 / w+ : 읽기, 쓰기(둘중하나 가능) / r+ : 읽기, 쓰기(둘중 하나) 수정가능 / a+
		fopen_s(&fp,"demo.txt","w");		// char *:""
		if (fp == NULL) {
			printf("not found error : %s \n", "demo.txt");
			return 0;
		}
		// 읽기 또는 쓰기(출력)
		// 텍스트 파일
		fputc('A', fp);
		fputc('\n', fp);					// 개행문자 2byte
		fputs("new new new new", fp);
		// 여러가지, 여러 개의 데이터
		fprintf(fp, "%d %s \n", 100, "korea");						// 다른 출력함수들은 뒤에 파일을 쓰는데, fprintf는 앞에쓴다.

		// 파일 닫기
		fclose(fp);
	return 0;
}

// BMP는 상단헤더 파일이 54BYTE
// RGB는 픽셀 하나하나가 3BYTE : 24BIT
// 이미지 파일은 구조체가 필요

// 윈도우 그림편집기->다른이름으로 저장하기JPG파일을 BMP파일로
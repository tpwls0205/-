#include <stdio.h>

void main()
{
	// 1) 스트림 생성
	FILE* fp = NULL;
	fopen_s(&fp, "test.txt", "rt");

	// 2) 파일 읽기
	// 2-1) 1글자씩 읽기
	int ch = fgetc(fp);  printf("%c", ch);
	ch = fgetc(fp);  printf("%c", ch);
	ch = fgetc(fp);  printf("%c", ch);
	ch = fgetc(fp);  printf("%c", ch);

	// 2-2) 1라인씩 읽기
	while (1)
	{
		char str[100] = { 0 };
		fgets(str, sizeof(str) - 1, fp);
		printf("%s", str);

		// 파일의 끝(더 이상 읽을 내용이 없다)
		if (feof(fp) != 0)
			break;
	}

	// 3) 스트림 종료
	fclose(fp);
}
#include <stdio.h>

void korPresentation()
{
	printf("정수를 입력하세요 >> ");

}
void engPresentation()
{
	printf("input Interger >> ");

}
int inputValue(void(*present)())	// 리턴형은 void, 매개변수는 없는 함수포인터로 해석
{
	present();
	int num = 0;
	scanf_s("%d", &num);
	return num;
}

void main()
{
	int value = 0;
	value = inputValue(engPresentation);
	printf("%d\n", value);
}
#include <stdio.h>

void korPresentation()
{
	printf("������ �Է��ϼ��� >> ");

}
void engPresentation()
{
	printf("input Interger >> ");

}
int inputValue(void(*present)())	// �������� void, �Ű������� ���� �Լ������ͷ� �ؼ�
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
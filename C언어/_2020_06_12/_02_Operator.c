//<������ �켱����>
//1. ���� �����ϰ� ���� ���� ()�� ���´�.
//2. =(���Կ�����)�� ���� ������ ��� ����ǰ� �������� ���Եȴ�.

#include <stdio.h>

void main() {
	
	int num0 = 100;
	int num1 = 200;
	int num2 = 2;
	int result = 0;
	result = num0 + num1 / num2;
	printf("%d\n", result);

	int isTrue = num0 == 100 && num1 == 50;			// c���� ������ 1�� ����, Ʋ���� 0�� ����
	if (isTrue == 1) 
		puts("���Դϴ�");							// puts : ���Ĺ��ڰ� �ʿ���� �� ȭ�� ���
	else 
		puts("�����Դϴ�");
}
// ��������(local variable)
#include <stdio.h>

void main()
{
	int result = 0;		// main �Ҽ�
	//	int result = 0; // ���Ͽ��� �ߺ���Ī x
	for (int i = 1; i <= 10; i++)
	{
		int result = 0;	// for�� �Ҽ� // ���� �ߺ���Ī �ش� ���������� �켱
		result += i;
		printf("����� %d �Դϴ�\n", result);
	}
	printf("����� %d �Դϴ�\n", result);
}

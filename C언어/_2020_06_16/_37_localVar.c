/* ��������(local variable)
	1. �������� �����ϴ� ���� {}
	2. ������ ���۵� �� ź��
	3. ������ ���� �� �Ҹ�
*/
#include <stdio.h>

void main()
{

	for (int i = 1; i <= 10; i++)
	{
		int result = 0;
		result += i;
	}
	printf("����� %d �Դϴ�\n", result);
}
// result�� for�� ���������� ��ȿ�ϴ�
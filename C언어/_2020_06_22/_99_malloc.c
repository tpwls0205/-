/*	�޸� �����Ҵ�
	�������� 3��° ���
	- �������� �Ҵ�
	- �ʿ��� �� �Ҵ�/���� ������� �� �� ����
	- ū �޸𸮰� �ʿ��� ��
*/

/*	char name[20]�� ��������������
	getName()�Լ��� ����� ���� ���� ������ ���� ����.
*/
#include <stdio.h>

char* getName()
{
	char name[20];						// ���������� �Ѱ�, �ּҰ��� �Ѱ��� �� ������ ���� �Լ��� �����ϸ鼭 �����.
	printf("�̸� �Է�: ");
	fgets(name, sizeof(name) - 1, stdin);
	printf("�̸� : %s\n", name);
	printf("name : %p\n", name);
	return name;
}

void main()
{
	char* pName = getName();
	printf("name : %p\n", pName);
	printf("�̸�: %s\n", pName);
}
/*	<�������� 1��° ���>
	������ ������ ����ϸ� �Լ����� ��踦 �Ѿ
	���� ������ �����ϴ� ���� �����ϴ�
	�׷��Ƿ� �Լ��� ������� ���� �� �϶�
	���� ���� ���� ������ ������� ���޹޴� ����
	�����ϴ�
*/

#include <stdio.h>

#define IN
#define OUT

void div(IN int num0, IN int num1,
		OUT int* qprt, OUT int* rptr)
{
	*qprt = num0 / num1;	// quotient
	*rptr = num0 % num1;	// remainder
}

void main()
{
	int quotient = 0, remainder = 0;
	div(10, 3, &quotient, &remainder);
	printf("10/3�� ���� %d�Դϴ�\n", quotient);
	printf("10/3�� �������� %d�Դϴ�\n", remainder);
}
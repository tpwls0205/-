/*
	<������ �����ε�>
	������ == ��ȣ
	��ȣ => �������� ����
	Ŭ��������
	�����ڰ� �����ȣ�� �������� ������ ���
	������(����)�ϰ� ���ִ� ������ν�
	�����ڸ� �Լ��� �����ϰ� ���ش�.
*/

#include "Position.h"

void main()
{
	Position pos(10, 10);
	Position pos1(20, 20);
	// pos.operator+(pos1);
	Position pos2 = pos + pos1;
	pos2.showPosition();
}
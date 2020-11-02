/*
	�迭 : ������ ������ ������ ���� �� �ʿ��� ��
		ex) 3�� �л��� ��������
	����ü : �ϳ��� �繰/������ �ʿ��� ������ ���� ��
		ex) �л��� ���� : �̸�, ����, �ּ�, Ű, ������
		- �̸� �л� �ڷ����� ������ �� �����ϱ�
			�ʿ��� �� �л����������� ���
			�л� �ڷ����� ����� ����ض�.
		= �л� �ڷ������� ���� ������
			�л��� ���õ� ������ ������ �� �ִ�.
*/
/*	���α׷����� �׷�
	1. ������ �׷����ϰ� ������ => �Լ�
	2. �������� �׷����ϰ� ������ => ����ü
*/
#include <stdio.h>

struct Student
{
	char name[20];
	int age;
	char address[30];
	float height;
	float weight;
};

void showStudent(struct Student st)
{
	printf("�̸� : %s\n", st.name);
	printf("���� : %d\n", st.age);
	printf("�ּ� : %s\n", st.address);
	printf("Ű : %.2f\n", st.height);
	printf("������ : %.2f\n", st.weight);
}

void main()
{
	struct Student st;
	strcpy_s(st.name,sizeof(st.name), "ȫ�浿");		// name������ ȫ�浿�̶� ���� ī���ض�
	st.age = 24;
	strcpy_s(st.address, sizeof(st.address), "������");
	st.height = 160.9f;
	st.weight = 45.2f;
	showStudent(st);
}
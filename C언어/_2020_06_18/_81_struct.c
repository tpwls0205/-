
#include <stdio.h>
#include <string.h>

// ����ü�� ���� �� ���� ������ ���´�.
typedef struct Student
{
	char name[20];
	int age;
	char address[30];
	float height;
	float weight;
}stud;


void showStudent(stud* pst)
{
	printf("�̸� : %s\n", pst->name);
	printf("���� : %d\n", pst->age);
	printf("�ּ� : %s\n", pst->address);
	printf("Ű : %.2f\n", pst->height);
	printf("������ : %.2f\n", pst->weight);
}

void main()
{
	stud st;
	strcpy_s(st.name, sizeof(st.name), "ȫ�浿");
	st.age = 24;
	strcpy_s(st.address, sizeof(st.address), "������");
	st.height = 160.9f;
	st.weight = 45.2f;
	showStudent(&st);
}

#include <stdio.h>
#include <string.h>

// 구조체를 만들 때 부터 별명을 짓는다.
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
	printf("이름 : %s\n", pst->name);
	printf("나이 : %d\n", pst->age);
	printf("주소 : %s\n", pst->address);
	printf("키 : %.2f\n", pst->height);
	printf("몸무게 : %.2f\n", pst->weight);
}

void main()
{
	stud st;
	strcpy_s(st.name, sizeof(st.name), "홍길동");
	st.age = 24;
	strcpy_s(st.address, sizeof(st.address), "지리산");
	st.height = 160.9f;
	st.weight = 45.2f;
	showStudent(&st);
}
#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������
#include<time.h> // �ð����� ���
#define SIZE 100
#pragma warning (disable:4996)

typedef struct person {
	char name[SIZE];
	char sex[SIZE];
	char age[SIZE];
}PERSON;

void menu();
PERSON record();
void add(PERSON data);
void search(PERSON data);
void print(PERSON data);

//  struct person data;

int main() {
	int score;
	score = 0;
	while (1) {
		
		menu();
		printf(" �޴��� �����ϼ��� : ");
		int m;
	//	scanf("%d",&m);
		if (scanf("%d", 1)) {
			
		}
		else if(scanf("%d", 2)) {
			printf(" ��ü��� ");
		}
		else if (scanf("%d", 3)) {
			return 0;
		}
	}
}

void menu() {
	printf(" �߰� : 1 \n");
	printf(" ��ü���� : 2 \n");
	printf(" ������ : 3 \n");
}

PERSON record()
{
	PERSON data;

	printf(" �̸� : \t\n"); gets_s(data.name, sizeof(data.name));
	printf(" ���� : \t\n"); gets_s(data.sex, sizeof(data.sex));
	printf(" ���� : \t\n"); gets_s(data.age, sizeof(data.age));

	return data;
}

void add(data) {
	PERSON data;
	data = record();
	

}

/*
char add[SIZE];
char view[SIZE];
char end[SIZE]; */



//1. random하게 80 * 25안의 임의의 위치에 100개의 별이 생성되고 역순으로 지워지는 프로그램

//2. 학생 구조체를 작성합니다
//구조체는 이름, 나이, 키, 몸무게, 번호 로 이루어져있습니다
//학생 5명의 정보를 입력받고
//모두 출력하세요
//반드시 함수로 작성하고, 함수의 매개변수는 포인터를 통해 전달해야 합니다
//#include <iostream>
//#define member 5
//
//typedef struct Student
//{
//	char name[10];
//	int age;
//	double height;
//	double weight;
//	int num;
//}stu;
//
//stu _stu[member];
//int stucnt = 0;
//
//void input(char* name, int* age, double* height, double* weight, int* num)
//{
//	stu _stu[member];
//	for (int i = 0; i < member; i++)
//	{
//		printf("학생 이름, 나이, 키, 몸무게, 번호를 입력해주세요 : ");
//		scanf_s("%s", _stu[i].name, sizeof(_stu[i].name));
//		scanf_s("%d", &_stu[i].age);
//		scanf_s("%lf", &_stu[i].height);
//		scanf_s("%lf", &_stu[i].weight);
//		scanf_s("%d", &_stu[i].num);
//		stucnt++;
//	}
//	stucnt--;
//	for (int j = 0; j < member; j++)
//	{
//		printf("%s\n%d\n%.2lf\n%.2lf\n%d\n\n", _stu[j].name, _stu[j].age,
//			_stu[j].height, _stu[j].weight, _stu[j].num);
//	}
//}
//
//void main()
//{
//	char name[10];
//	int age;
//	double height;
//	double weight;
//	int num;
//	input(name, &age, &height, &weight, &num);
//}
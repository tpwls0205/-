//1. random�ϰ� 80 * 25���� ������ ��ġ�� 100���� ���� �����ǰ� �������� �������� ���α׷�

//2. �л� ����ü�� �ۼ��մϴ�
//����ü�� �̸�, ����, Ű, ������, ��ȣ �� �̷�����ֽ��ϴ�
//�л� 5���� ������ �Է¹ް�
//��� ����ϼ���
//�ݵ�� �Լ��� �ۼ��ϰ�, �Լ��� �Ű������� �����͸� ���� �����ؾ� �մϴ�
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
//		printf("�л� �̸�, ����, Ű, ������, ��ȣ�� �Է����ּ��� : ");
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
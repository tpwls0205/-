//* �迭�� ����ϼ���
//
//1. 10���� ���������� �Է��ϰ�, ���հ� ����� ���ϼ���
//
//2. ����, ����, ���� ������ �� 3���� �Է¹ް�, �������� ���հ� ����� ���ϰ�
//��ü ������ ���հ� ����� ���ϼ���
//
//3. ������� �Է¹ް�, 3���� ������ �Է¹�������
//�׸��� ������ 3���� ������ ����ϼ���
//
//4. 10���� ���������� �Է¹ް�, index�� Ȧ���� �͸� ����ϼ���
//
//5. 7���� ���������� �迭 �ʱ�ȭ�� ����ؼ� �̸� �Է��ϼ���
//�׸��� 70�� �̻��� �л������� ����ϼ���
//
//6. 5���� �л��� �̸��� ���������� �Է¹�������
//�̸��� ������ ����ϼ���
//
//7. 8���� �л��� �̸��� ���������� �Է¹�������
//���� ������ ���� �л��� �̸��� ������ ����ϼ���
//
//8. 8���� �л��� �̸��� ���������� �Է¹�������
//���� ������ ���� �л��� �̸��� ������ ����ϼ���

#include <stdio.h>
#include <math.h>
#include <string.h>
//1. 10���� ���������� �Է��ϰ�, ���հ� ����� ���ϼ���
//#define engnum 10
//
//void main()
//{
//	int sum = 0;
//	double avg = 0;
//	int num[engnum] = { 0 };
//	printf("10���� ���������� �Է����ּ���\n");
//	for (int i = 0; i < engnum; i++)
//	{
//		scanf_s("%d", &num[i]);
//		sum += num[i];
//	}
//	avg = (double)sum / engnum;
//	printf("\n%d\n", sum);
//	printf("%.2lf", avg);
//}

//2. ����, ����, ���� ������ �� 3���� �Է¹ް�, �������� ���հ� ����� ���ϰ�
//��ü ������ ���հ� ����� ���ϼ���
//#define math 3
//#define eng 3
//#define kor 3
//
//void main()
//{	
//	int mathscore[math] = { 0 };
//	int engscore[eng] = { 0 };
//	int korscore[kor] = { 0 };
//	int summath = 0;
//	int sumeng = 0;
//	int sumkor = 0;
//	double avgmath = 0;
//	double avgeng = 0;
//	double avgkor = 0;
//	int sumtotal = 0;
//	double avgtotal = 0;
//	printf("���� ���� 3�� �Է� : ");
//	for (int i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &mathscore[i]);
//		summath += mathscore[i];
//	}
//	printf("���� ���� 3�� �Է� : ");
//	for (int i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &engscore[i]);
//		sumeng += engscore[i];
//	}
//	printf("���� ���� 3�� �Է� : ");
//	for (int i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &korscore[i]);
//		sumkor += korscore[i];
//	}
//	avgmath = (double)summath / math;
//	avgeng = (double)sumeng / eng;
//	avgkor = (double)sumkor / kor;
//	sumtotal = summath + sumeng + sumkor;
//	avgtotal = (avgmath + avgeng + avgkor) / 3;
//	printf("%d %d %d\n", summath, sumeng, sumkor);
//	printf("%.2lf %.2lf %.2lf\n", avgmath, avgeng, avgkor);
//	printf("%d %.2lf", sumtotal, avgtotal);
//}

//3. ������� �Է¹ް�, 3���� ������ �Է¹�������
//�׸��� ������ 3���� ������ ����ϼ���
//void main()
//{	
//	char input[100] = { 0 };
//	int std[3] = { 0 };
//	int i = 0;
//	printf("\n������� �˷��ּ��� : ");
//	//gets(input);
//	scanf_s("%s", &input, sizeof(input));
//	printf("\n3���� ������ �˷��ּ��� : ");
//	for (i = 0; i < 3; i++)
//	{
//		scanf_s("%d", &std[i]);
//		printf("%d��° �л� %s ���� ���� : %d\n",i+1, input, std[i]);
//	}
//}

//4. 10���� ���������� �Է¹ް�, index�� Ȧ���� �͸� ����ϼ���
//void main()
//{
//	int maths[10] = { 0 };
//	int i = 0;
//	printf("10���� �������� : ");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &maths[i]);
//		if (i % 2 == 0)
//		{
//			printf("%d", maths[i]);
//		}
//	}
//}

//5. 7���� ���������� �迭 �ʱ�ȭ�� ����ؼ� �̸� �Է��ϼ���
//�׸��� 70�� �̻��� �л������� ����ϼ���
//void main()
//{
//	int kor[7] = { 10, 20, 30, 40, 50, 60, 70 };
//	for (int i = 0; i < 7; i++)
//	{
//		if (kor[i] >= 70)
//		{
//			printf("%d", kor[i]);
//		}
//	}
//}

//6. 5���� �л��� �̸��� ���������� �Է¹�������
//�̸��� ������ ����ϼ���
//#define size 50
//#define num 5
//typedef struct std
//{
//	char name[num][size];
//	int kor[num];
//};
//
//void main()
//{	
//	struct std st;
//	printf("5���� �л� �̸��� ���������� �Է� : ");
//	for (int i = 0; i < num; i++)
//	{
//		scanf_s("%s", st.name[i],sizeof(st.name[i]));
//		scanf_s("%d", &st.kor[i]);
//		printf("%s, %d\n", st.name[i], st.kor[i]);
//	}
//}

//7. 8���� �л��� �̸��� ���������� �Է¹�������
//���� ������ ���� �л��� �̸��� ������ ����ϼ���
//#define size 50
//#define num 8
//typedef struct std
//{
//	char name[size];
//	int math;
//}Std;
//
//Std _std[num] = { 0 };
//int stdcnt = 0;
//
//void main()
//{
//	int max = 0;
//	for (int i = 0; i < num; i++)
//	{
//		printf("�л� �̸� �Է� : \n");
//		scanf_s("%s", _std[i].name, sizeof(_std[i].name));
//		printf("�л� ���������� �Է� : \n");
//		scanf_s("%d", &_std[i].math);
//		if (i == 0)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			max = _std[i].math;
//			stdcnt++;
//		}
//		else if (max < _std[i].math)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			max = _std[i].math;
//			stdcnt++;
//		}
//	}
//		stdcnt--;
//		printf("%s, %d\n", _std[stdcnt].name, max);
//}

//8. 8���� �л��� �̸��� ���������� �Է¹�������
//���� ������ ���� �л��� �̸��� ������ ����ϼ���
//#define size 50
//#define num 8
//typedef struct std
//{
//	char name[size];
//	int math;
//}std;
//
//std _std[num] = { 0 };
//int stdcnt = 0;
//
//void main()
//{
//	int min = 0;
//	for (int i = 0; i < num; i++)
//	{
//		printf("�л� �̸� �Է� : \n");
//		scanf_s("%s", _std[i].name, sizeof(_std[i].name));
//		printf("�л� ���������� �Է� : \n");
//		scanf_s("%d", &_std[i].math);
//		if (i == 0)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			min = _std[i].math;
//			stdcnt++;
//		}
//		else if (min > _std[i].math)
//		{
//			strcpy(_std[stdcnt].name, _std[i].name);
//			min = _std[i].math;
//			stdcnt++;
//		}
//	}
//	stdcnt--;
//	printf("%s, %d\n", _std[stdcnt].name, min);
//}
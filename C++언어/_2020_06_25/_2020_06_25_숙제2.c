//1. 2���� ���� ���� ��ȯ�ϴ� swap�Լ��� ���弼��
//int num0 = 10, num1 = 20;
//swap(&num0, &num1);
//�� ȣ���ϸ� num0�� 20�� num1�� 10�� ��� ������ �˴ϴ�.
//
//2. 3���� ���� ���� ��ȯ�ϴ� swap�Լ��� ���弼��
//int num0 = 10, num1 = 20, num2 = 30;
//swap(&num0, &num1, &num2);
//�� ȣ���ϸ� num0�� 30�� num1�� 10, num2�� 20�� ��� ������ �˴ϴ�.
//
//3. 10���� �Ǽ��� �迭�� �����ؼ� ����� ���ϴ� �Լ��� ���弼��
//
//4. char* name = "korea";
//int len = strlen(name);
//�� �ϸ� len���� 5�� ��� �ֽ��ϴ�.
//strlen�Լ��� ���ڿ��� ���� '\0'�� ã�Ƽ� �� ������ ������ ���� �������
//�����Ǿ� �ֽ��ϴ�
//���� int str_len(char* ptr); �Լ��� �����ϼ���

#include <stdio.h>
//1. 2���� ���� ���� ��ȯ�ϴ� swap�Լ��� ���弼��
//int num0 = 10, num1 = 20;
//swap(&num0, &num1);
//�� ȣ���ϸ� num0�� 20�� num1�� 10�� ��� ������ �˴ϴ�.
//void swap(int* num0, int* num1)
//{	
//	int change = 0;
//	change = *num0;
//	*num0 = *num1;
//	*num1 = change;
//}
//void main()
//{	
//	int num0 = 10, num1 = 20;
//	swap(&num0, &num1);
//	printf("num0:%d ,num1:%d", num0, num1);
//}

//2. 3���� ���� ���� ��ȯ�ϴ� swap�Լ��� ���弼��
//int num0 = 10, num1 = 20, num2 = 30;
//swap(&num0, &num1, &num2);
//�� ȣ���ϸ� num0�� 30�� num1�� 10, num2�� 20�� ��� ������ �˴ϴ�.
//void swap(int* num0, int* num1, int* num2)
//{
//	int change = 0;
//	change = *num2;
//	*num2 = *num1;
//	*num1 = *num0;
//	*num0 = change;
//}
//
//void main()
//{
//	int num0 = 10, num1 = 20, num2 = 30;
//	swap(&num0, &num1, &num2);
//	printf("num0:%d , num1:%d, num2:%d", num0, num1, num2);
//}

//3. 10���� �Ǽ��� �迭�� �����ؼ� ����� ���ϴ� �Լ��� ���弼��
//void avg(double num, int len)
//{	
//	static int cnt = 0;
//	static double sum = 0;
//	double avg = 0;
//	sum += num;
//	cnt++;
//	if (cnt == len)
//	{
//		avg = (double)sum / len;
//		num = avg;
//		printf("%lf", num);
//	}
//}
//void main()
//{
//	double num[10] = { 0 };
//	printf("10���� �Ǽ��� �Է� : ");
//	for (int i = 0; i < 10; i++)
//	{
//		scanf_s("%lf",&num[i]);
//		avg(num[i], sizeof(num[i]));
//	}
//}

//4. char* name = "korea";
//int len = strlen(name);
//�� �ϸ� len���� 5�� ��� �ֽ��ϴ�.
//strlen�Լ��� ���ڿ��� ���� '\0'�� ã�Ƽ� �� ������ ������ ���� �������
//�����Ǿ� �ֽ��ϴ�
//���� int str_len(char* ptr); �Լ��� �����ϼ���

void main()
{

}
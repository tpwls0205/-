/*	�Լ��� ����� 2���� ����
	1. �ݺ��Ǵ� �ڵ��� ��Ģ���� ã�Ƽ�
	��ȭ�ϴ� ��Ҹ� �Ű����� �����ؼ� �����ش�
	(���� �� ���Ǵϱ� 1���� �׷�ȭ���Ѽ� �̸���
	�ο��ϸ� ���뿡 �ſ� ���ϴ�)
	2. ������ ������ ������ ������ �׷�ȭ(�Լ�)�ϸ�
	��ü �帧�� �ϸ�俬�ϰ� ������ �� �ִ�
*/

/*	C���α׷��� ����
	1. ���ε� ��
	; ������ ���α׷���(���� ����, �б�)
	  �о�ȭ �ý���
	2. FlowChart(������)
	; �������� ���α׷���(�ð��� �帧, ����)
*/

/*
	1. ����� ����
	; �׸�, ��Ű��ó -> �ڵ�ȭ
	2. ����� ����
	; �κ�(����) �ڵ� �ϼ�
	-> ���� �����
	-> �߰� ������ ��ü ���̾ƿ��� ����
*/

#include<stdio.h>

void viewMenu()
{
	printf("\t<�ּҷ� ���� ���α׷�>\n");
	printf("1. �Է�\n");
	printf("2. �˻�\n");
	printf("3. ����\n");
	printf("4. ����\n");
	printf("5. ��ü���\n");
	printf("6. ����\n");
}

int getSelNum()
{	
	int selNum = 0;
	printf("\n ��ȣ�� �����ϼ��� >> ");
	scanf_s("%d", &selNum);

	// �� �Լ��� ��ó���� ������ ������ ���ư� ��
	return selNum;
}

void processWork(int selNum)
{
	if (selNum == 1)
	{
		printf("\n\t�Է�ó�� �Ͽ����ϴ�~\n");
	}
	else if (selNum == 2)
	{
		printf("\n\t�˻�ó�� �Ͽ����ϴ�~\n");
	}
	else if (selNum == 3)
	{
		printf("\n\t����ó�� �Ͽ����ϴ�~\n");
	}
	else if (selNum == 4)
	{
		printf("\n\t����ó�� �Ͽ����ϴ�~\n");
	}
	else if (selNum == 5)
	{
		printf("\n\t��ü���ó�� �Ͽ����ϴ�~\n");
	}
	else if (selNum == 6)
	{
		printf("\n\t���α׷� �����ϰڽ��ϴ�~\n");
	}
}

void main()
{
	// getSelNum() �Լ��� ������ ������ �ٸ� ����, �̸��� ���̾��� �ٸ�����
	int selNum = 0;

	printf("%#x\n", main);
	printf("%#x\n", viewMenu);
	printf("%#x\n", getSelNum);
	printf("%#x\n", processWork);

	// 1. �޴� �����ֱ�
	viewMenu();

	// 2. ����� �Է�
	selNum = getSelNum();

	// 3. ó��
	processWork(selNum);
}
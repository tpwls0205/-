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

	return selNum;
}

void inputAddress()
{
	printf("\n\t�Է�ó�� �Ͽ����ϴ�~\n\n");
}

void searchAddress()
{
	printf("\n\t�˻�ó�� �Ͽ����ϴ�~\n\n");
}

void updateAddress()
{
	printf("\n\t����ó�� �Ͽ����ϴ�~\n\n");
}

void deleteAddress()
{
	printf("\n\t����ó�� �Ͽ����ϴ�~\n\n");
}

void printAllAddress()
{
	printf("\n\t��ü���ó�� �Ͽ����ϴ�~\n\n");
}

void exitApp()
{
	printf("\n\t���α׷� �����ϰڽ��ϴ�~\n\n");
}

void processWork(int selNum)
{
	switch (selNum)
	{
	case 1:
		inputAddress();
		break;
	case 2:
		searchAddress();
		break;
	case 3:
		updateAddress();
		break;
	case 4:
		deleteAddress();
		break;
	case 5:
		printAllAddress();
		break;
	case 6:
		exitApp();
		break;
	default:
		printf("�߸��Է��ϼ̽��ϴ�");
		break;
	}
}

void main()
{
	int selNum = 0;

	// ����ó���� ���� �� �ٽ� �޴��� ��Ÿ�� �� �ֵ���
	// ���� ���� ó���� �Ѵ�.
	while (1)
	{
		viewMenu();

		selNum = getSelNum();

		processWork(selNum);
	}
}
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
	if (selNum == 1)
	{
		inputAddress();
	}
	else if (selNum == 2)
	{
		searchAddress();
	}
	else if (selNum == 3)
	{
		updateAddress();
	}
	else if (selNum == 4)
	{
		deleteAddress();
	}
	else if (selNum == 5)
	{
		printAllAddress();
	}
	else if (selNum == 6)
	{
		exitApp();
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
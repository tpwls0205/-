#include "turboc.h"

// ���� ��� �ǹ��ִ� ���ڸ� ����Ѵ�
// ó�� ���� �������ʹ� �ڵ����� 1�� �����Ѵ�
enum {
	INPUT_ADDR=1,
	SEARCH_ADDR,
	UPDATE_ADDR,
	DELETE_ADDR,
	PRINTALL_ADDR,
	EXIT_ADDR
};

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
	case INPUT_ADDR:
		inputAddress();
		break;
	case SEARCH_ADDR:
		searchAddress();
		break;
	case UPDATE_ADDR:
		updateAddress();
		break;
	case DELETE_ADDR:
		deleteAddress();
		break;
	case PRINTALL_ADDR:
		printAllAddress();
		break;
	case EXIT_ADDR:
		exitApp();
		break;
	default:
		printf("\n\t�߸��Է��ϼ̽��ϴ�\n\n");
		break;
	}
}

void laterProcess()
{
	getchar();				// scanf_s���� �Էµ� \n�� ó��
	getchar();				// �ƹ� �Է� �ޱ�(ȭ�� ��� ����)
	clrscr();				// ȭ��û��
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

		laterProcess();			// ��ó��
	}
}
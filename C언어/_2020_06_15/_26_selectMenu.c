/*	������ 3���� �Ӽ�
	1. = ���ʿ� �ִ� ��� : �̸��� ��Ī�ϴ� ����
	2. = �����ʿ� �ִ� ��� : �̸� ������ ����ִ� ��
	3. &num : num������ �ּ� (�ش� ������ ������ġ)
*/

#include<stdio.h>

void main()
{
	int selNum = 0;

	// 1. �޴� �����ֱ�
	printf("\t<�ּҷ� ���� ���α׷�>\n");
		printf("1. �Է�\n");
		printf("2. �˻�\n");
		printf("3. ����\n");
		printf("4. ����\n");
		printf("5. ��ü���\n");
		printf("6. ����\n");

	// 2. ����� �Է�
		printf("\n ��ȣ�� �����ϼ��� >> ");
		scanf_s("%d", &selNum);
		// scanf_s("%d", &selNum, sizeof(selNum));

	// 3. ó��
		if (selNum == 1)
		{
			printf("�Է�ó�� �Ͽ����ϴ�~\n");
		}
		else if (selNum == 2)
		{
			printf("�˻�ó�� �Ͽ����ϴ�~\n");
		}
		else if (selNum == 3)
		{
			printf("����ó�� �Ͽ����ϴ�~\n");
		}
		else if (selNum == 4)
		{
			printf("����ó�� �Ͽ����ϴ�~\n");
		}
		else if (selNum == 5)
		{
			printf("��ü���ó�� �Ͽ����ϴ�~\n");
		}
		else if (selNum == 6)
		{
			printf("���α׷� �����ϰڽ��ϴ�~\n");
		}
}
// �Լ��� �𸣸� �Լ�Ŭ�� �ϰ� f1Ű ������ ����â���� �Ѿ

#include <stdio.h>
#include <conio.h>

void main() {
	
	printf("1. �ּ� �Է�\n");
	printf("2. �ּ� �˻�\n");
	printf("3. �ּ� ����\n");
	printf("4. �ּ� ����\n");
	printf("5. ���α׷� ����\n");

	printf("��ȣ�� �����ϼ��� >> \n");
	//char sel = getchar();	// ���� �ְ� enter�� �������
	char sel = _getch();	// ���ڸ� ������ �Է�
	printf("%c �� �����ϼ̽��ϴ�\n", sel);

}
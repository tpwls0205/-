#include "Human.h"
#include "ComputerEngineer.h"
#include "Developer.h"
#include "ServerManager.h"

/*
	1. Overloading(����)
		; ������ �Լ����� ����(��, �Ű������� �ٸ���)
	2. Overriding(������)
		; �ֿ켱��
		  ������ ���� ������
		  �θ� ������ �Լ��� �ٽ� ����(������)
		  �� �Լ��� �ֿ켱�̴�
*/

void main()
{
	Human Hu;
	ComputerEngineer Co;
	ServerManager Se;
	Hu.info();		// �޸� info
	cout << endl;
	Co.info();		// ��ǻ�� �����Ͼ� info >> Ȯ���Ų����.
	cout << endl;
	Hu.work();		// �޸� work
	cout << endl;
	Se.work();		// �޸տ� �ִ� work�� ����.
	cout << endl << endl << endl;
	Developer dev("ȫ�浿", 24, 3, 12);
	dev.eat();		// Human�� ������ �״��
	dev.overTime(); // ComputerEnginner�� ������ �Լ��� Ȯ�� : Overriding(������, ������ �Ϳ��� Ȯ��/����)
	dev.info();		// Ȯ�� ������
	dev.neverEndingStudy(); // �θ�ü���� �������� �ʰ� ���Ӱ� �߰�
	dev.sleep();	// ���� ������
}
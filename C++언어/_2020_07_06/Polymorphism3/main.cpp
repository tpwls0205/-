#include "Developer.h"
#include "Human.h"
#include <iostream>

using namespace std;

void main()
{
	Human human;
	human.play();

	Developer dev;
	dev.play();

	/*	virtual : �����Լ�
				  ��ǻ�(��ü�� ����) �Լ�
	*/
	// �ּ� = ��ü(��ü)
	Human* hu = &dev;
	hu->play();
}
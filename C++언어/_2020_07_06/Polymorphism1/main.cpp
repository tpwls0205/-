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

	/*	play() �Լ��� ���� ��
		virtual Ű���带 �ٿ��ָ�
		�θ� ������ ������ ����
		�ڽ� ��ü�� �Լ��� ȣ���� �� �ִ�.
	*/
	Human* hu = &dev;
	hu->play();
}
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

	/*	�θ� ������ ���� = �ڽ� ��ü
		1. play()�� virtual �Լ��� �ƴ� ���
		; �����Ϸ��� hu�� �ڷ����� Human�� ���� ����
		������ �� Human::play()��� ���Ѵ�
		(���� ���ε�)
		2. play()�� virtual �Լ��� ���
		; �����Ϸ��� �̸� �Լ��� �ּҸ� ���ε����� �ʴ´�.
		���� �ÿ� ��ü�� vptr�� ���ؼ� ���� ���̺���
		play()�Լ��� ã�Ƽ� �����Ѵ�.
		(���� ���ε�)
	*/
	Human* hu = &dev;
	hu->play();
}
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

	/* C++������ �������̶�� ������ �����ϱ� ���ؼ�
	   ������ ���� ������ �����Ͽ���.
	   �θ��� ������ ������ �ڽ� ��ü�� ���� �� �ִ�.
	*/
	Human* hu = &dev;
	hu->play();			// Human::play() ȣ��

}
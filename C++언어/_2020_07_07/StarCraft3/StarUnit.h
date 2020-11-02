#pragma once
#include <combaseapi.h>
// #define interface class
/*	
	�߻� �޼��尡 ���ԵǾ� �����Ƿ� �߻� Ŭ�����̴�.
	��, ��� �޼���(��� �Լ�)�� �߻� �޼����̹Ƿ�
	�������̽���� ǥ���Ѵ�.

	<�������̽��� ����>
	1. Ŭ���� ������ �迭 : ����
	2. �Ű�����
	3. ������ �ڽ� ��ü�� ��� ���Ҹ�
	4. ������ ����
	5. ����, ������ ����
*/

interface StarUnit
{
public:
	/*	
		���� ���� �Լ�(�߻� �޼���) : �����ΰ� ����, ��ü x
	*/
	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void die() = 0;
};


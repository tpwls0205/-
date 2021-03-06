#pragma once
#include <combaseapi.h>
// #define interface class
/*	
	추상 메서드가 포함되어 있으므로 추상 클래스이다.
	단, 모든 메서드(멤버 함수)가 추상 메서드이므로
	인터페이스라고 표현한다.

	<인터페이스의 역할>
	1. 클래스 포인터 배열 : 관리
	2. 매개변수
	3. 오로지 자식 객체를 담는 역할만
	4. 유연한 연결
	5. 설계, 디자인 패턴
*/

interface StarUnit
{
public:
	/*	
		순수 가상 함수(추상 메서드) : 구현부가 없는, 객체 x
	*/
	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void die() = 0;
};


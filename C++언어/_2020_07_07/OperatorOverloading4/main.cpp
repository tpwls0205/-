/*
	<연산자 오버로딩>
	연산자 == 기호
	기호 => 직관적인 느낌
	클래스에서
	개발자가 연산기호의 직관적인 느낌을 살려
	재정의(편집)하게 해주는 기능으로써
	연산자를 함수로 편집하게 해준다.
*/

#include "Position.h"

void main()
{
	Position pos(10, 10);
	// 5.operator + (pos);		숫자는 객체가 아니기 때문에 불가능
	// operator+(5, pos);       전역함수 호출
	Position pos1 = 5 + pos;
	pos1.showPosition();
}
#include "Human.h"
#include "ComputerEngineer.h"
#include "Developer.h"
#include "ServerManager.h"

/*
	1. Overloading(과적)
		; 동일한 함수명이 많다(단, 매개변수가 다르다)
	2. Overriding(재정의)
		; 최우선의
		  이전의 것을 덮었다
		  부모가 물려준 함수를 다시 재사용(재정의)
		  내 함수가 최우선이다
*/

void main()
{
	Human Hu;
	ComputerEngineer Co;
	ServerManager Se;
	Hu.info();		// 휴먼 info
	cout << endl;
	Co.info();		// 컴퓨터 엔지니어 info >> 확장시킨거임.
	cout << endl;
	Hu.work();		// 휴먼 work
	cout << endl;
	Se.work();		// 휴먼에 있는 work를 수정.
	cout << endl << endl << endl;
	Developer dev("홍길동", 24, 3, 12);
	dev.eat();		// Human이 물려준 그대로
	dev.overTime(); // ComputerEnginner가 물려준 함수를 확장 : Overriding(재정의, 물려준 것에서 확장/변경)
	dev.info();		// 확장 재정의
	dev.neverEndingStudy(); // 부모객체에는 존재하지 않고 새롭게 추가
	dev.sleep();	// 변경 재정의
}
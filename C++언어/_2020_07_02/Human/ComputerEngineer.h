#pragma once
#include "Human.h"
class ComputerEngineer : public Human
{
protected:
	int nComputer;

public:
	ComputerEngineer(string name="컴퓨터 엔지니어", int age=0, int nComputer=0);
	~ComputerEngineer();

public:
	void overTime();		// 새로 추가한 함수
	void info();			// 부모의 것을 그대로 쓰거나, 확장, 변경할 수 있다.
};


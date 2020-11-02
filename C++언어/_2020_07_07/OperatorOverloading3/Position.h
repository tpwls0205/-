#pragma once
class Position
{
private:
	int x, y;

public:
	Position(int x = 0, int y = 0);
public:
	void showPosition();
	Position& operator++();		// 전위증가연산자
	Position operator++(int);	// 후위증가연산자 
	Position operator+(Position pos);	// 객체+객체
	Position operator+(int num);		// 객체+정수
};


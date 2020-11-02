#pragma once
#include <iostream>
using namespace std;

class Human
{
protected:		// 제3자 한테는 private , 자식한테는 public
	string name;
	int age;

public:
	Human(string name = "사람", int age = 0);
	~Human();

public:
	void eat();
	void sleep();
	void work();
	void info();
};


#pragma once
#include <iostream>
using namespace std;

class Human
{
protected:		// ��3�� ���״� private , �ڽ����״� public
	string name;
	int age;

public:
	Human(string name = "���", int age = 0);
	~Human();

public:
	void eat();
	void sleep();
	void work();
	void info();
};


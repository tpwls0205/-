#pragma once
#include <iostream>
#include "Gun.h"

using namespace std;

class Police : public Gun
{
private:
	string hat = "��������";
	string suit = "������";
public:
	void wearSuit()
	{
		cout << hat << "�� �����ϴ�" << endl;
		cout << suit << "�� �����ϴ�" << endl;
	}

};


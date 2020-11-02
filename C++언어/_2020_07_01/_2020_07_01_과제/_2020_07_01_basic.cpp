//1. main()�� ���� ����� ������ ������ TowerŬ������ �ۼ��ϼ���
//
//���̴� 1����
//���̴� 100����

//#include <iostream>
//
//using namespace std;
//
//class Tower
//{
//private:
//	int height;
//
//public:
//	Tower()
//	{
//		height = 1;
//	}
//	Tower(int _Height)
//	{
//		 height = _Height;
//	}
//	~Tower()
//	{
//
//	}
//public:
//	int getHeight()
//	{
//		return height;
//	}
//};
//
//void main()
//{
//	Tower myTower;
//	Tower seoulTower(100);
//	cout << "���̴� " << myTower.getHeight() << "����" << endl;
//	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
//}


//2. ��¥�� �ٷ�� Date Ŭ������ �ۼ��ϰ��� �մϴ�.
//Date�� �̿��ϴ� main()�� �������� ������ �����ϴ�.
//Ŭ���� Date�� �ۼ��Ͽ� �Ʒ� ���α׷��� �߰��ϼ���.
//
//1945�� 8�� 15��
//2014, 3, 20

// 1945/8/15 �� ����.

#include <iostream>

using namespace std;

class Date
{
private:
	int year, month, day = 0;
	string birth;
public:
	Date(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	Date(string _birth)
	{
		birth = _birth;
	}
	~Date()
	{}

public:
	void show()
	{
		string change[3] = {"��","��","��"};
		int cnt = 0;
		for (int i = 0; i < birth.length(); i++)
		{
			if (birth[i] == '/')
			{ 
				cout << change[cnt++] << " "; 
			}
			else
			{
				cout << birth[i];
			}
		}
		cout << change[cnt] << endl;
	}
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
};

void main()
{
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}

//3. Box.h, Box.cpp, main.cpp�� ��������

//#include <iostream>
//#include "Box.h"
//using namespace std;
//
//int main() {
//	Box b(10, 2);
//	b.draw();
//	cout << endl;
//	b.setSize(7, 4);
//	b.setFill('^');
//	b.draw();
//}
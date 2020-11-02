//1. main()의 실행 결과가 다음과 같도록 Tower클래스를 작성하세요
//
//높이는 1미터
//높이는 100미터

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
//	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
//	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
//}


//2. 날짜를 다루는 Date 클래스를 작성하고자 합니다.
//Date를 이용하는 main()과 실행결과는 다음과 같습니다.
//클래스 Date를 작성하여 아래 프로그램에 추가하세요.
//
//1945년 8월 15일
//2014, 3, 20

// 1945/8/15 로 찍힘.

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
		string change[3] = {"년","월","일"};
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

//3. Box.h, Box.cpp, main.cpp로 나누세요

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
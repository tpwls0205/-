//1. Point 클래스를 상속받은 ColorPoint클래스를 작성하고, 완성하세요
#include <iostream>
#include <string>

using namespace std;

class Point {
protected:
	int x, y;
public:
	Point(){}
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
	~Point(){}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point
{
private:
	string k;
public:
	ColorPoint(int x, int y, string k)
	{
		
	}
	~ColorPoint()
	{
	}
	void setPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setColor(string k)
	{
		this->k = k;
	}
	void show()
	{
		cout << this->k << "색으로 (" << this->x << "," << this->y << ")에 위치한 점입니다." << endl;
	}
};

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}

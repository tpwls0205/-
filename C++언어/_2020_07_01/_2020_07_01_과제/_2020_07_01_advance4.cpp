//4. int타입의 정수를 객체화한 Integer 클래스를 작성하세요.
//Integer 클래스를 활용하는 코드는 다음과 같습니다.
// 못했다..
#include <iostream>
#include <string>

using namespace std;

class Integer
{
private:
	int n;
	string m;

public:
	Integer(int _n)
	{
		n = _n;
	}
	Integer(string _m)
	{
		m = _m;
	}
	~Integer()
	{

	}
	int set()
	{

	}
	void get()
	{

	}
	void isEven()
	{

	}
};

void main()
{
	Integer n(30);
	cout << n.get() << ' ';		// 30출력
	n.set(50);
	cout << n.get() << ' ';		// 50출력

	Integer m("300");
	cout << m.get() << ' ';		// 300출력
	cout << m.isEven();			// true(정수로 1) 출력
}

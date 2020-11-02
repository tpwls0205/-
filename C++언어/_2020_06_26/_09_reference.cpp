#include <iostream>

using namespace std;

void swapPtr(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

// 래퍼런스 : 별명, 김두한 == 긴또깡
// 포인터로 접근하는 건 세밀한 작업, c언어
// c++에서는 대규모 프로젝트를 위해 래퍼런스 라는 것을 사용
// &의 모양은 같지만 주소를 지칭하는 게 아님
// int 형 ra(변수)만을 가르키는 래퍼런스
// 1. 포인터의 Low레벨느낌을 제거
// 2. 포인터 (포인터 연산을 통해 시스템의 다른 부분을 접근할 수
//			있는데 이런 것이 프로그래밍의 잠재적 위험을 가져올 수 있다.
//			=> 그래서 제한적인 해당 변수만의 접근을 허용하는 방식으로 바꾼 것
void swapRef(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

void main()
{
	int num0 = 10, num1 = 20;
	cout << "num0: " << num0 << endl;
	cout << "num1: " << num1 << endl;
	//swapPtr(&num0, &num1);
	swapRef(num0, num1);
	cout << "num0: " << num0 << endl;
	cout << "num1: " << num1 << endl;
}
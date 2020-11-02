#pragma once
#include <iostream>

using namespace std;

/*  순수 가상 함수가 1개이상이 있으면
	추상 클래스(Abstract Class)라 부른다
	이 클래스는 객체를 만들 수 없다

	무조건 상속을 전제로 한다.
	
	main에서 Employee 객체 선언 자체를 할 수 없다.
*/

class Employee
{
private:
	string name;
	string companyNum;
public:
	virtual void inputEmployee();
	virtual void showEmployee();
	virtual int calcPay() = 0;		// 순수 가상 함수, = 0 : 구현부가 없는 것
// 자식 3클래스 : 정규직, 임시직, 일용직 => 급여의 체계가 다르다. 부모가 일괄적으로 내려주는게 무의미(어짜피 자식이 재정의해야함)
};

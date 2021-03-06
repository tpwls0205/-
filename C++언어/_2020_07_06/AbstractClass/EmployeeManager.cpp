#include "EmployeeManager.h"
#include <iostream>
#include "RegularEmployee.h"
#include "TempEmployee.h"
#include "DailyEmployee.h"

using namespace std;

void EmployeeManager::showMenu()
{
	cout << "1. 사원입력" << endl;
	cout << "2. 사원전체출력" << endl;
	cout << "3. 프로그램 종료" << endl;
}
int EmployeeManager::getSelNum()
{
	int num = 0;
	cout << "메뉴를 선택 >> ";
	cin >> num;
	return num;
}
void EmployeeManager::insertEmployee()
{
	if (this->empNum == EMP_NUM)
	{
		cout << "더 이상 입력할 수 없습니다." << endl;
		return;
	}
	cout << "---사원 종류를 선택하세요---" << endl;
	cout << "1. 정규직" << endl;
	cout << "2. 임시직" << endl;
	cout << "3. 일용직" << endl;
	int sel = getSelNum();

	if (sel == 1)
	{
		RegularEmployee* RegularEmp = new RegularEmployee();
		RegularEmp->inputEmployee();
		
		this->employee[this->empNum] = RegularEmp;
		this->empNum++;
	}
	else if (sel == 2)
	{
		TempEmployee* TempEmp = new TempEmployee();
		TempEmp->inputEmployee();

		this->employee[this->empNum] = TempEmp;
		this->empNum++;
	}
	else if (sel == 3)
	{
		DailyEmployee* DailyEmp = new DailyEmployee();
		DailyEmp->inputEmployee();

		this->employee[this->empNum] = DailyEmp;
		this->empNum++;
	}
	else
	{
		cout << "잘못입력하셨습니다. " << endl;
		return;
	}
}
void EmployeeManager::showAllEmployee()
{
	for (int i = 0; i < this->empNum; i++)
	{
		employee[i]->showEmployee();
	}
}
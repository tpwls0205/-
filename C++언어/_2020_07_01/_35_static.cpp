/*	static ��� ������ Ŭ������ �����ϰ� �����ϴ� �����̹Ƿ�
	�ַ� ��ü���� ���������� / �����ϰ� 
	�����ϴ� �����͸� �����ؼ� ����Ѵ�.
*/
#include <iostream>

using namespace std;

#define NAME_LEN 30

class Bitcamp
{
private:
	/* �Ϲ� ��������� ��ü������ ��ü���� �����ȴ�	
	*/
	char name[NAME_LEN];
	int studentCnt = 0;
	//int SumStudentCnt = 0;
	
	/* class����� static ��������� �����ȴ�
	   ��ü���ٵ� ���� �����ȴ�
	   �ƹ��� ��ü�� ���Ƶ� Ŭ������ ������ ������ �����Ѵ�
	   ��� ��ü�� �� static��������� ������ �� �ִ�.
	*/
	/* static�� ��ü�Ҽ��� �ƴ϶� Ŭ���� �Ҽ��̴�.
	   �ٸ�, ��ü�ε� ���ٰ����ϴ�.
	*/
	static int bitcampStudentCnt;

public:
	Bitcamp(const char* _name, int _studentCnt)
	{
		strncpy_s(name, sizeof(name), _name, strlen(_name) + 1);
		studentCnt = _studentCnt;

		bitcampStudentCnt += _studentCnt;
		//SumStudentCnt += _studentCnt;
	}
	~Bitcamp() {}

	void showInfo()
	{
		cout << "������ : " << name << endl;
		cout << "�л��� : " << studentCnt << endl;
	}

	static int getBitcampStudentCnt()
	{
		return bitcampStudentCnt;
	}

	/*int getSumStudentCnt()
	{
		return SumStudentCnt;
	}*/

};

// static ��������� �ʱ�ȭ ���
int Bitcamp::bitcampStudentCnt = 0;

void main()
{
	Bitcamp bitSeocho("��Ʈķ�� ����", 300);
	Bitcamp bitGangnam("��Ʈķ�� ����", 120);
	Bitcamp bitJongro("��Ʈķ�� ����", 200);
	Bitcamp bitSinchon("��Ʈķ�� ����", 150);
	Bitcamp bitSeomyun("��Ʈķ�� ����", 22);

	bitSeocho.showInfo();
	bitGangnam.showInfo();
	bitJongro.showInfo();
	bitSinchon.showInfo();
	bitSeomyun.showInfo();

	cout << "��Ʈķ���� ���л����� " << Bitcamp::getBitcampStudentCnt() << " �Դϴ�" << endl;
	//cout << "��Ʈķ���� ���л����� " << bitSeomyun.getSumStudentCnt() << " �Դϴ�" << endl;
}
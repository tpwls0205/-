#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������
#include<time.h> // �ð����� ���


int main_01(int argc, char** argv) {
	// ����� ���� �� (������) : ����ü : �������� ���� / Ŭ������ �ƴϴ�. c++�� ū ������
	// 1. ����ü�� ����
	// 2. ����ü�� ���� ����
	// 3. ����ü�� ���� �ȿ� ������� ó�� -> ����ü�ȿ� ����ִ� �������� ������ �θ�. / �Լ��� ������ �������� ���� ����μ� �ȿ� ���� �� �ִ�.
	// ��� �����ϴ� ���
	// 1. ������.����� / �̸��϶��� .(��)
	// 2. �����ͺ�����(�ּ�)->����� / �ּ��϶��� -> ȭ��ǥ												

	return 0;
}

// ����ü�� ���� ��������ó�� ���� ����⿡ �����Ѵ�.
// �迭�� ����ü�� ������ �����͸� ���������� ������ �ִ�. / �迭�� �ڷ����� ��� �����ֵ�, ����ü�� �������� �ڷ����� ���� �� �ִ�.
struct car {
	// member
	int code;
	char name[80];
	double price;
};

int main_02(int argc, char** argv) {
	struct car myCar = { 1, "Grandure", 1000.10};						// ��������, struct car : car���� �� ���� �ڷ����� �̸��̴� �򰥸��� ���� c++�� ������ 
																		// ����� ����ִ� ������ �°� Ÿ�Կ� �°� �ۼ�
	printf("{%d, %s, %lf}\n",
		myCar.code, myCar.name, myCar.price								// ����ü�� �ȿ� ������� �ݺ����� �� �� ����. �ϳ��ϳ� �� ������Ѵ�.
		);

	return 0;
}

int main_03(int argc, char** argv) {
	struct car myCar = { 1, "Grandure", 1000.10 };				

	// ����ü ������ �����Ѵ�.
	// ��¥ �����Ѵ�. ( ���� ���� ) / ������ �����ϴ� ���� ��������	
	struct car uCar = myCar;
	
	printf("%p vs %p \n", myCar.name, uCar.name);							// %p -> �ּҸ� �˷��� 
	printf("{%d, %s, %lf}\n",												// ���� ����� �ּҴ� �ٸ����� �Ȱ����� �ϳ��� ������ �ٸ� �ּҿ� ����Ű�
		uCar.code, uCar.name, uCar.price									// ���� ����� �ϳ��� �ּҰ� ���� �ִٰ� ��ũ�� �ɾ��ִ� ����.
	);

	return 0;
}

// #define Car struct car								// Car�� struct car�� �ٲ㼭 �����ض�. ������ ġȯ, �ڷ����� �ƴ�, ��õ����� �ƴ�
typedef	struct car Car;								// �ڷ������� ���� ��� / c����� ��� / ���� �ڷ������� struct car�ε� Car�� ���� �ڷ��������� ����ϰڴ�.
typedef unsinged int _uint;							// ����ü�Ӹ��� �ƴ϶� ���̸��� �ڷ������� �ٲٱ� ���� ����� �� �ִ�.
typedef struct car {								// ����ü �տ� typedf ��ġ�� }�� ; ���̿� �������� �̸��� ������ �� ����.
	// member
	int code;
	char name[80];
	double price;
}CAR, UCAR, ICAR;


int main(int argc, char** argv) {
	typedef struct car ic;
	// ����ü�� �̸��� ª��, �ٸ��� ����ϰ� ���� ��.
	Car mycar;
	printf("%d\n", sizeof(Car));
	printf("%d\n", sizeof(mycar));
		// ����ü �⺻ ũ�� ���� : ������� ���� ���� ũ�� ���´�.

	return 0;
}


#pragma pack(1)				// ����ü �������. 1byte �������� ���缭 ����ü�� ������. ���� �ٸ� �ڷ����� �ִ� ����ü�� ũ�⸦ ���� ���հ� �Ȱ��� ����� ���
typedef struct _rgb_color {
	unsigned char blue : 2;                  //  unsigned char blue;
	unsigned char green : 4;                 // unsigned char green;
	unsigned char red : 2;                   //  unsigned char red;
}RGB;
	// :(�ݷ�) �ڿ� ���ڰ� ���� �� -> ��Ʈ �ʵ� ����ü - �ڷ����� ��� ���ƾ��ϸ�, ��Ʈ�� ������ �ڷ����� ũ��� ���ƾ��� : 2+4+2=8��Ʈ = 1����Ʈ(char)

int main_05(void) {
	printf("%d\n", sizeof(RGB));		// ũ�� byte : �ڷ����� �Ȱ������� ���հ� �Ȱ��� �����µ�, �ڷ����� ���� �ٸ��� ������ ���� �� ũ�� ���´�.


	return 0;
}


#pragma pack(1)				
typedef struct _bits {						// ��Ʈ �ʵ� ����ü, 0�� ��Ʈ~7�� ��Ʈ = 1����Ʈ, ������ ��Ʈ�� �����Ͱ� �ִ��� ������ ������ �� ����.
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
}BITS;

// �ڷᱸ�� -> �ڱ� ���� ����ü
struct _node {
	int data;
	struct _node* prev;					// ����ü ����߿� �����Ͱ� �ִµ�, �������� ���� Ÿ���� ����ü�� ��Ī�� ���� �� -> �ڱ� ���� ����ü
	struct _node* next;
};

int main_06(void) {
	printf("%d\n", sizeof(RGB));


	return 0;
}

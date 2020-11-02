//1. cout << 연산자를 이용해서 구구단을 출력하세요
//2 x 1 = 2  3 x 1 = 3 ..... 9 x 1 = 9
//......
//2 x 9 = 18
//
//2. 키보드로부터 2개의 정수를 읽어서 큰 수를 출력하세요
//
//3. 소수점을 가지는 5개의 실수를 입력받아 제일 큰 수를 출력하세요
//
//4. < Enter > 키가 입력될 때까지 문자들을 읽고, 입력된 문자 'x'의
//개수를 화면에 출력하세요.
//
//
//5. "yes"가 입력될 때까지 종료하지 않는 프로그램을 작성해세요.입력은 cin.getline() 함수를 사용하세요
//
//6. ';'으로 5개의 이름을 구분해서 입력받아, 각 이름을 끊어내여 화면에 출력하세요.
//그리고 가장 긴 이름을 판별해서 나타내세요.
//cin.getline(str, 100, ';');
//홍길동; 임꺽정; 장길산; 일지매; 모짜르트;
//1:홍길동
//2 : 임꺽정
//3 : 장길산
//4 : 일지매
//5 : 모짜르트
//
//7. 이름, 주소, 나이를 입력받아 출력하세요.
//
//8. 문자열을 하나 입력받고 문자열의 부분 문자열을 출력하세요
//hello
//h
//he
//hel
//hell
//hello
//

//1. cout << 연산자를 이용해서 구구단을 출력하세요
//2 x 1 = 2  3 x 1 = 3 ..... 9 x 1 = 9
//......
//2 x 9 = 18
#include <iostream>

using namespace std;

void main1()
{
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{	
			int multiply = 0;
			multiply = i * j;
			cout << i << "x" << j << "=" << multiply << " ";
		}
		cout << endl;
	}
}

//2. 키보드로부터 2개의 정수를 읽어서 큰 수를 출력하세요
void main2()
{
	int i = 0;
	int j = 0;
	cin >> i >> j;
	if (i > j)
	{
		cout << i;
	}
	else if (j > i)
	{
		cout << j;
	}
	else
	{
		cout << "두 수는 같은 수 입니다. ";
		return;
	}
}

//3. 소수점을 가지는 5개의 실수를 입력받아 제일 큰 수를 출력하세요
void main3()
{
	double i[5] = { 0 };
	double max = 0;
	cout << "5개의 실수를 입력 : ";
	for (int j = 0; j < 5; j++)
	{
		cin >> i[j];
		if (j == 0)
		{
			max = i[j];
		}
		if (max < i[j])
		{
			max = i[j];
		}
	}
	cout << "가장 큰 실수는 : " << max;
}

//4. < Enter > 키가 입력될 때까지 문자들을 읽고, 입력된 문자 'x'의
//개수를 화면에 출력하세요.
void main4()
{
	char x[100] = { 0 };
	int xcnt = 0;
	cin.getline(x, sizeof(x), '\n');
	for (int i = 0; i < 100; i++)
	{
		if (x[i] == 'x')
		{
			xcnt++;
		}
	}
	cout << "입력된 문자 x의 개수는 : " << xcnt;
}

//5. "yes"가 입력될 때까지 종료하지 않는 프로그램을 작성해세요.입력은 cin.getline() 함수를 사용하세요
void main5()
{
	char i[100] = { 0 };
	char j[4] = "yes";
	while (1)
	{	
		cin.getline(i, sizeof(i));
		if (0 == strcmp(j,i))	// 중간에 들어온건안됌
		{
			break;
		}
	}
}

//6. ';'으로 5개의 이름을 구분해서 입력받아, 각 이름을 끊어내여 화면에 출력하세요.
//그리고 가장 긴 이름을 판별해서 나타내세요.
//cin.getline(str, 100, ';');
//홍길동; 임꺽정; 장길산; 일지매; 모짜르트;
//1:홍길동
//2 : 임꺽정
//3 : 장길산
//4 : 일지매
//5 : 모짜르트
void main()
{
	char name[100] = { 0 };
	char nlong[100] = { 0 };
	cout << "5명의 이름을 적어주세요 : ";
	for (int i = 0; i < 5; i++)
	{												// cin.getline : ; 만나기 전까지 name배열에 문자를 저장
		cin.getline(name, sizeof(name), ';');		// ;만나면 그 전까지 입력된 문자를 버퍼에 저장
		cout << endl << i + 1 << " : " << name;		// 다시 name배열의 0번요소에서부터 저장
		if (i == 0)									// '\n' 를 만나면 앞서 저장된 버퍼에서 부터 ;까지 입력된 문자를
		{											// for문이 한번 돌때 하나씩 뽑아냄
			strcpy_s(nlong, name);
		}
		if (i != 0 && strlen(nlong) < strlen(name))
		{
			strcpy_s(nlong, name);
		}
	}
	cout << endl << " 가장 긴 이름은 : " << nlong << endl;
}

//7. 이름, 주소, 나이를 입력받아 출력하세요.
void main7()
{
	char name[100] = { 0 };
	char address[100] = { 0 };
	int age = { 0 };
	cout << "이름과 주소, 나이를 입력하세요 : ";
	cin >> name >> address >> age;
	cout << name << " " << address << " " << age;
}

//8. 문자열을 하나 입력받고 문자열의 부분 문자열을 출력하세요
//hello
//h
//he
//hel
//hell
//hello

void main8()
{
	char hello[100] = { 0 };
	int cnt = 0;
	cout << "문자열 입력 : ";
	cin >> hello;
	for (int i = 0; i < strlen(hello); i++)
	{	
		for (int j = 0; j <= i; j++)
		{
			cout << hello[j];
			cout << endl;
		}
	}
}
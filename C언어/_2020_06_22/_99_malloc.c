/*	메모리 동적할당
	포인터의 3번째 용법
	- 힙영역에 할당
	- 필요할 때 할당/삭제 마음대로 할 수 있음
	- 큰 메모리가 필요할 때
*/

/*	char name[20]은 지역변수임으로
	getName()함수를 벗어나면 값을 전혀 보장할 수가 없다.
*/
#include <stdio.h>

char* getName()
{
	char name[20];						// 지역변수의 한계, 주소값을 넘겨줄 수 있지만 값은 함수가 종료하면서 사라짐.
	printf("이름 입력: ");
	fgets(name, sizeof(name) - 1, stdin);
	printf("이름 : %s\n", name);
	printf("name : %p\n", name);
	return name;
}

void main()
{
	char* pName = getName();
	printf("name : %p\n", pName);
	printf("이름: %s\n", pName);
}
/*	메모리 동적할당
	포인터의 3번째 용법
	- 힙영역에 할당
	- 필요할 때 할당/삭제 마음대로 할 수 있음
	- 큰 메모리가 필요할 때
*/
/*	전역변수
	- 메모리가 사라지지 않는다
	- 하지만 처음에 할당크기를 무조건 정해야 한다
	- 함수호출시마다 새로운 메모리를 추가하는 것은 불가능하다
*/

#include <stdio.h>

char name[20];

char* getName()
{
	printf("이름 입력: ");
	fgets(name, sizeof(name) - 1, stdin);
	printf("이름 : %s\n", name);
	printf("name : %p\n", name);
	return name;
}

void main()
{	
	char* names[3] = { NULL };
	for (int i = 0; i < 3; i++)
	{
		names[i] = getName();
		printf("name : %p\n", names[i]);
		printf("이름: %s\n", names[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", names[i]);
	}
}
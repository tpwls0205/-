/*���ڿ� ǥ��*/
#include <stdio.h>

void main()
{
	char sname[6] = { 'k','o','r','e','a','\0' };
	char nname[6] = "korea";
	char name[] = "Korea";
	char* cname = "Corea";	// ������, ������ ���ڿ��� ���ڴ�

	// �迭�� �̸��� �迭 ������ġ
	// �����ּҸ� �������� '\0'�� ���������� �д´�
	printf("%s\n", sname);
	printf("%s\n", nname);
	printf("%s\n", name);
	printf("%s\n", cname);
	printf("\n");

	sname[0] = nname[0] = name[0] = 'C';
	printf("%s\n", sname);
	printf("%s\n", nname);
	printf("%s\n", name);
	printf("%s\n", cname);

	cname[0] = 'K';
	printf("%s\n", cname);
}
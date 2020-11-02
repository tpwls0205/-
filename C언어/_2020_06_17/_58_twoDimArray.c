#include <stdio.h>

void main()
{
	int arr[2][3] = { 0 };

	printf("傈眉农扁 : %d\n", sizeof(arr));
	printf("1青农扁 : %d\n", sizeof(arr[0]));
	printf("2青农扁 : %d\n", sizeof(arr[1]));
	printf("夸家农扁 : %d\n", sizeof(arr[0][0]));
	printf("\n");
	printf("傈眉矫累林家 : %d\n", arr);
	printf("1青矫累林家 : %d\n", arr[0]);
	printf("2青矫累林家 : %d\n", arr[1]);
	printf("1夸家矫累林家 : %d\n", &arr[0][0]);
	printf("1俺夸家 : %d\n", arr[0][0]);
}
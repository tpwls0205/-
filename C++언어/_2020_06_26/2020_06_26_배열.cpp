//1. 길이가 5인 int형 배열을 선언해서 5개의 정수를 입력받습니다.
//이중 최대값, 최소값, 총합, 평균을 구하세요.
//
//2. char형 1차원배열을 선언 후 "Good Morning"로 초기화 하세요.
//그리고 문장을 출력하세요.
//
//3. 영단어를 입력받고 영단어를 역순으로 뒤집으세요.
//단, 널값은 그대로여야 합니다.
//역순으로 전환한 값을 출력하세요.
//
//4. 길이가 5인 int형 배열 arr을 선언하고
//1, 2, 3, 4, 5로 초기화한다.
//마지막 요소를 가리키는 ptr을 선언하고
//ptr을 감소하는 연산으로 배열의 요소를 모두 더하여 결과를
//출력한다.
//
//5. 길이가 6인 배열 arr 1, 2, 3, 4, 5, 6 으로 초기화한 다음
//배열에 저장된 값의 순서를 6, 5, 4, 3, 2, 1로 변경한다.
//배열의 앞과 뒤를 가리키는 포인터 변수 2개를 선언해서
//이를 활용하여 저장된 값의 순서를 바꿔야 한다.
//
//6. 숫자를 포함한 문자열을 입력받아서 그 안에 존재하는 숫자의 총합을
//구하세요.
//
//예를 들어 q1df3kf9lj3의 경우는
//1 + 3 + 9 + 3을 출력해야 합니다.
//
//7. 20byte char 배열 3개를 만듭니다.
//배열에 문자열을 두개를 입력받습니다.
//나머지배열에 두개의 문자열을 연결하여 붙여넣습니다.
//즉 korea, student를 입력받았다면
//세번째 배열에는 koreastudent가 저장되어 출력하여야 합니다.
//
//
//8. 사용자로부터 이름과 나이를 다음의 형식에 맞춰서 하나의 문자열로
//입력받습니다.
//홍길동 32
//임꺽정 17
//
//그래서 이름과 나이 사이에는 공백이 삽입되어야 합니다.
//이름과 나이가 같은지 다른지 판단하여 출력하는 프로그램을 작성하세요.

//1. 길이가 5인 int형 배열을 선언해서 5개의 정수를 입력받습니다.
//이중 최대값, 최소값, 총합, 평균을 구하세요.
#include <iostream>

using namespace std;

void main1()
{
	int num[5] = { 0 };
	int sum = 0;
	double avg = 0;
	int min = 0;
	int max = 0;
	printf("5개의 정수를 입력해주세요 : ");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &num[i]);
		if (i == 0)
		{
			max = num[i];
			min = num[i];
		}
		if (max < num[i])
		{
			max = num[i];
		}
		if (min > num[i])
		{
			min = num[i];
		}
		sum += num[i];
	}
	avg = (double)sum / 5;
	printf("최소값 : %d\n최대값 : %d\n총합 : %d\n평균 : %.2lf", min, max, sum, avg);
}

//2. char형 1차원배열을 선언 후 "Good Morning"로 초기화 하세요.
//그리고 문장을 출력하세요.

void main2()
{
	char Hello[15] = { 'G','o','o','d',' ','M','o','r','n','i','n','g' };
	char Hello1[15] = "Good Morning";
	printf("%s", Hello);
	printf("\n");
	printf("%s", Hello1);
}

//3. 영단어를 입력받고 영단어를 역순으로 뒤집으세요.
//단, 널값은 그대로여야 합니다.
//역순으로 전환한 값을 출력하세요.

void main3()
{
	char eng[10] = { 0 };
	int leng = 0;
	printf("영단어를 입력하세요 : ");
	scanf_s("%s", eng, sizeof(eng));
	leng = strlen(eng);						// 5글자 입력받았으면 leng = 5
	for (int i = leng - 1; i >= 0; i--)		// 5-1부터 0까지 감소
	{
		printf("%c", eng[i]);				// 4번요소부터 한글자씩 뽑아내고 감소
	}
}

//4. 길이가 5인 int형 배열 arr을 선언하고
//1, 2, 3, 4, 5로 초기화한다.
//마지막 요소를 가리키는 ptr을 선언하고
//ptr을 감소하는 연산으로 배열의 요소를 모두 더하여 결과를
//출력한다.

void main4()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int sum = 0;
	int *ptr = &arr[4];
	for (int i = 5; i > 0; i--)
	{
		sum += *ptr--;
	}
	printf("%d", sum);
}

//5. 길이가 6인 배열 arr 1, 2, 3, 4, 5, 6 으로 초기화한 다음
//배열에 저장된 값의 순서를 6, 5, 4, 3, 2, 1로 변경한다.
//배열의 앞과 뒤를 가리키는 포인터 변수 2개를 선언해서
//이를 활용하여 저장된 값의 순서를 바꿔야 한다.

void main5()
{
	int arr[6] = { 1,2,3,4,5,6 };
	int* start = &arr[0];
	int* last = &arr[5];
	int temp, i;
	cout << "배열의 순서는 :" << endl;
	for (i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "배열의 역순은 :" << endl;
	for (i = 0; i < 3; i++)
	{
		temp = *start;
		*start = *last;
		*last = temp;
		start++;
		last--;
	}
	for (i = 0; i < 6; i++)
		cout << arr[i] << endl;
}

//6. 숫자를 포함한 문자열을 입력받아서 그 안에 존재하는 숫자의 총합을
//구하세요.
//
//예를 들어 q1df3kf9lj3의 경우는
//1 + 3 + 9 + 3을 출력해야 합니다.
void main6()
{
	char cha[100] = { 0 };
	int sum = 0;
	cout << "문자와 숫자 아무거나 입력 : " << endl;
	scanf_s("%s", cha, sizeof(cha));
	for (int i = 0; i < strlen(cha); i++)
	{	
		
		if (cha[i]>='0' && cha[i]<='9')
		{
			printf("%d번째 숫자 : %d\n", i + 1, cha[i]-'0');
			sum += cha[i]-'0';
		}
	}
	printf("숫자의 총합은 : %d", sum);
}

//7. 20byte char 배열 3개를 만듭니다.
//배열에 문자열을 두개를 입력받습니다.
//나머지배열에 두개의 문자열을 연결하여 붙여넣습니다.
//즉 korea, student를 입력받았다면
//세번째 배열에는 koreastudent가 저장되어 출력하여야 합니다.
void main7()
{
	char i[20] = { 0 };
	char* iptr = &i[0];
	char j[20] = { 0 };
	char* jptr = &j[0];
	char k[20] = { 0 };
	char* kptr = &k[0];
	printf("korea 를 입력해주세요 : ");
	scanf_s("%s", i, sizeof(i));
	for (int inum = 0; inum < strlen(i); inum++)
	{
		*kptr = *iptr;
		k[inum] = *kptr;
		kptr++;
		iptr++;
		printf("%c", k[inum]);
		if (inum == strlen(i) - 1)
		{	
			printf("\nstudent 를 입력해주세요 : ");
			scanf_s("%s", j, sizeof(j));
			for (int jnum = strlen(i); jnum < strlen(i)+strlen(j); jnum++)
			{	
				*kptr = *jptr;
				k[jnum] = *kptr;
				kptr++;
				jptr++;
				printf("%c", k[jnum]);
			}
			printf("\n%s", k);
		}
	}
}

//8. 사용자로부터 이름과 나이를 다음의 형식에 맞춰서 하나의 문자열로
//입력받습니다.
//홍길동 32
//임꺽정 17
//
//그래서 이름과 나이 사이에는 공백이 삽입되어야 합니다.
//이름과 나이가 같은지 다른지 판단하여 출력하는 프로그램을 작성하세요.
void main()
{
	getchar();
	char nameAge0[30];											// 배열1 선언
	char nameAge1[30];											// 배열2 선언

	printf("이름과 나이를 띄어쓰기로 구분해서 입력: ");
	fgets(nameAge0, sizeof(nameAge0) - 1, stdin);				// 사용자한테 키보드입력받음/ 널값공간을 남겨둘려고
	nameAge0[strlen(nameAge0) - 1] = 0;							// 마지막 문자를 널문자로 만듬

	printf("이름과 나이를 띄어쓰기로 구분해서 입력: ");
	fgets(nameAge1, sizeof(nameAge1) - 1, stdin);
	nameAge1[strlen(nameAge1) - 1] = 0;

	char name0[30] = {0};
	char age0[10] = {0};
	int cnt0 = 0;
	int flag0 = 0;   //0이면 이름, 1이면 나이
	for (int i = 0; i < strlen(nameAge0) + 1; i++)
	{
		if (nameAge0[i] != 0x20)   // ' '							// 스페이스바가 아니면 if문으로
		{
			if (flag0 == 0)											// 스페이스바가 아니면서 문자면
				name0[cnt0++] = nameAge0[i];							// i번째 배열의 문자를 name배열에 넣는다.
			else if (flag0 == 1)										// 스페이스바가 아니면서 숫자면
			{
				age0[cnt0++] = nameAge0[i];							// i번째 배열의 숫자를 age배열에 넣는다.
			}
		}
		else {														// 스페이스바를 만났다면
			flag0 = 1;												// 문자가 끝나고 다음으로 age(숫자)를 받을차례기 때문에
			name0[cnt0] = 0;											// name(문자)배열의 끝. 널값추가
			cnt0 = 0;												// age에서 숫자를 카운트하기위해 초기화
		}
	}
	
	char name1[30] = {0};
	char age1[10] = {0};
	int cnt1 = 0;
	int flag1 = 0;   //0이면 이름, 1이면 나이
	for (int i = 0; i < strlen(nameAge1) + 1; i++)
	{
		if (nameAge1[i] != 0x20)   // ' '
		{
			if (flag1 == 0)
				name1[cnt1++] = nameAge1[i];
			else if (flag1 == 1)
			{
				age1[cnt1++] = nameAge1[i];
			}
		}
		else {
			flag1 = 1;
			name1[cnt1] = 0;
			cnt1 = 0;
		}
	}
	
	if (strlen(nameAge0) != strlen(nameAge1))
	{
		printf("두 문자열은 불일치합니다. ");
		return;
	}
	int namecnt = 0;
	int agecnt = 0;
	int g = 0;
	for (int i = 0; i < strlen(nameAge1) + 1; i++)
	{
		if (g == 0)
		{
			if (name0[i] == name1[i])
			{
				if (namecnt == strlen(name1))
				{
					g = 1;
				}
				namecnt++;
				continue;
			}
			else if (name0[i] != name1[i])
			{
				printf("두 문자열은 불일치합니다. ");
				break;
			}
		}
		for (int j = 0; j < strlen(nameAge1) + 1; j++)
		{
			if (g == 1)
			{
				if (age0[j] == age1[j])
				{
					if (agecnt == strlen(age1))
					{
						printf("두 문자열은 일치합니다. ");
					}
					agecnt++;
					continue;
				}
				else if (age0[j] != age1[j])
				{
					printf("두 문자열은 불일치합니다. ");
					exit(0);
				}
			}
		}
	}
}
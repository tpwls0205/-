//1. ���̰� 5�� int�� �迭�� �����ؼ� 5���� ������ �Է¹޽��ϴ�.
//���� �ִ밪, �ּҰ�, ����, ����� ���ϼ���.
//
//2. char�� 1�����迭�� ���� �� "Good Morning"�� �ʱ�ȭ �ϼ���.
//�׸��� ������ ����ϼ���.
//
//3. ���ܾ �Է¹ް� ���ܾ �������� ����������.
//��, �ΰ��� �״�ο��� �մϴ�.
//�������� ��ȯ�� ���� ����ϼ���.
//
//4. ���̰� 5�� int�� �迭 arr�� �����ϰ�
//1, 2, 3, 4, 5�� �ʱ�ȭ�Ѵ�.
//������ ��Ҹ� ����Ű�� ptr�� �����ϰ�
//ptr�� �����ϴ� �������� �迭�� ��Ҹ� ��� ���Ͽ� �����
//����Ѵ�.
//
//5. ���̰� 6�� �迭 arr 1, 2, 3, 4, 5, 6 ���� �ʱ�ȭ�� ����
//�迭�� ����� ���� ������ 6, 5, 4, 3, 2, 1�� �����Ѵ�.
//�迭�� �հ� �ڸ� ����Ű�� ������ ���� 2���� �����ؼ�
//�̸� Ȱ���Ͽ� ����� ���� ������ �ٲ�� �Ѵ�.
//
//6. ���ڸ� ������ ���ڿ��� �Է¹޾Ƽ� �� �ȿ� �����ϴ� ������ ������
//���ϼ���.
//
//���� ��� q1df3kf9lj3�� ����
//1 + 3 + 9 + 3�� ����ؾ� �մϴ�.
//
//7. 20byte char �迭 3���� ����ϴ�.
//�迭�� ���ڿ��� �ΰ��� �Է¹޽��ϴ�.
//�������迭�� �ΰ��� ���ڿ��� �����Ͽ� �ٿ��ֽ��ϴ�.
//�� korea, student�� �Է¹޾Ҵٸ�
//����° �迭���� koreastudent�� ����Ǿ� ����Ͽ��� �մϴ�.
//
//
//8. ����ڷκ��� �̸��� ���̸� ������ ���Ŀ� ���缭 �ϳ��� ���ڿ���
//�Է¹޽��ϴ�.
//ȫ�浿 32
//�Ӳ��� 17
//
//�׷��� �̸��� ���� ���̿��� ������ ���ԵǾ�� �մϴ�.
//�̸��� ���̰� ������ �ٸ��� �Ǵ��Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.

//1. ���̰� 5�� int�� �迭�� �����ؼ� 5���� ������ �Է¹޽��ϴ�.
//���� �ִ밪, �ּҰ�, ����, ����� ���ϼ���.
#include <iostream>

using namespace std;

void main1()
{
	int num[5] = { 0 };
	int sum = 0;
	double avg = 0;
	int min = 0;
	int max = 0;
	printf("5���� ������ �Է����ּ��� : ");
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
	printf("�ּҰ� : %d\n�ִ밪 : %d\n���� : %d\n��� : %.2lf", min, max, sum, avg);
}

//2. char�� 1�����迭�� ���� �� "Good Morning"�� �ʱ�ȭ �ϼ���.
//�׸��� ������ ����ϼ���.

void main2()
{
	char Hello[15] = { 'G','o','o','d',' ','M','o','r','n','i','n','g' };
	char Hello1[15] = "Good Morning";
	printf("%s", Hello);
	printf("\n");
	printf("%s", Hello1);
}

//3. ���ܾ �Է¹ް� ���ܾ �������� ����������.
//��, �ΰ��� �״�ο��� �մϴ�.
//�������� ��ȯ�� ���� ����ϼ���.

void main3()
{
	char eng[10] = { 0 };
	int leng = 0;
	printf("���ܾ �Է��ϼ��� : ");
	scanf_s("%s", eng, sizeof(eng));
	leng = strlen(eng);						// 5���� �Է¹޾����� leng = 5
	for (int i = leng - 1; i >= 0; i--)		// 5-1���� 0���� ����
	{
		printf("%c", eng[i]);				// 4����Һ��� �ѱ��ھ� �̾Ƴ��� ����
	}
}

//4. ���̰� 5�� int�� �迭 arr�� �����ϰ�
//1, 2, 3, 4, 5�� �ʱ�ȭ�Ѵ�.
//������ ��Ҹ� ����Ű�� ptr�� �����ϰ�
//ptr�� �����ϴ� �������� �迭�� ��Ҹ� ��� ���Ͽ� �����
//����Ѵ�.

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

//5. ���̰� 6�� �迭 arr 1, 2, 3, 4, 5, 6 ���� �ʱ�ȭ�� ����
//�迭�� ����� ���� ������ 6, 5, 4, 3, 2, 1�� �����Ѵ�.
//�迭�� �հ� �ڸ� ����Ű�� ������ ���� 2���� �����ؼ�
//�̸� Ȱ���Ͽ� ����� ���� ������ �ٲ�� �Ѵ�.

void main5()
{
	int arr[6] = { 1,2,3,4,5,6 };
	int* start = &arr[0];
	int* last = &arr[5];
	int temp, i;
	cout << "�迭�� ������ :" << endl;
	for (i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "�迭�� ������ :" << endl;
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

//6. ���ڸ� ������ ���ڿ��� �Է¹޾Ƽ� �� �ȿ� �����ϴ� ������ ������
//���ϼ���.
//
//���� ��� q1df3kf9lj3�� ����
//1 + 3 + 9 + 3�� ����ؾ� �մϴ�.
void main6()
{
	char cha[100] = { 0 };
	int sum = 0;
	cout << "���ڿ� ���� �ƹ��ų� �Է� : " << endl;
	scanf_s("%s", cha, sizeof(cha));
	for (int i = 0; i < strlen(cha); i++)
	{	
		
		if (cha[i]>='0' && cha[i]<='9')
		{
			printf("%d��° ���� : %d\n", i + 1, cha[i]-'0');
			sum += cha[i]-'0';
		}
	}
	printf("������ ������ : %d", sum);
}

//7. 20byte char �迭 3���� ����ϴ�.
//�迭�� ���ڿ��� �ΰ��� �Է¹޽��ϴ�.
//�������迭�� �ΰ��� ���ڿ��� �����Ͽ� �ٿ��ֽ��ϴ�.
//�� korea, student�� �Է¹޾Ҵٸ�
//����° �迭���� koreastudent�� ����Ǿ� ����Ͽ��� �մϴ�.
void main7()
{
	char i[20] = { 0 };
	char* iptr = &i[0];
	char j[20] = { 0 };
	char* jptr = &j[0];
	char k[20] = { 0 };
	char* kptr = &k[0];
	printf("korea �� �Է����ּ��� : ");
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
			printf("\nstudent �� �Է����ּ��� : ");
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

//8. ����ڷκ��� �̸��� ���̸� ������ ���Ŀ� ���缭 �ϳ��� ���ڿ���
//�Է¹޽��ϴ�.
//ȫ�浿 32
//�Ӳ��� 17
//
//�׷��� �̸��� ���� ���̿��� ������ ���ԵǾ�� �մϴ�.
//�̸��� ���̰� ������ �ٸ��� �Ǵ��Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
void main()
{
	getchar();
	char nameAge0[30];											// �迭1 ����
	char nameAge1[30];											// �迭2 ����

	printf("�̸��� ���̸� ����� �����ؼ� �Է�: ");
	fgets(nameAge0, sizeof(nameAge0) - 1, stdin);				// ��������� Ű�����Է¹���/ �ΰ������� ���ܵѷ���
	nameAge0[strlen(nameAge0) - 1] = 0;							// ������ ���ڸ� �ι��ڷ� ����

	printf("�̸��� ���̸� ����� �����ؼ� �Է�: ");
	fgets(nameAge1, sizeof(nameAge1) - 1, stdin);
	nameAge1[strlen(nameAge1) - 1] = 0;

	char name0[30] = {0};
	char age0[10] = {0};
	int cnt0 = 0;
	int flag0 = 0;   //0�̸� �̸�, 1�̸� ����
	for (int i = 0; i < strlen(nameAge0) + 1; i++)
	{
		if (nameAge0[i] != 0x20)   // ' '							// �����̽��ٰ� �ƴϸ� if������
		{
			if (flag0 == 0)											// �����̽��ٰ� �ƴϸ鼭 ���ڸ�
				name0[cnt0++] = nameAge0[i];							// i��° �迭�� ���ڸ� name�迭�� �ִ´�.
			else if (flag0 == 1)										// �����̽��ٰ� �ƴϸ鼭 ���ڸ�
			{
				age0[cnt0++] = nameAge0[i];							// i��° �迭�� ���ڸ� age�迭�� �ִ´�.
			}
		}
		else {														// �����̽��ٸ� �����ٸ�
			flag0 = 1;												// ���ڰ� ������ �������� age(����)�� �������ʱ� ������
			name0[cnt0] = 0;											// name(����)�迭�� ��. �ΰ��߰�
			cnt0 = 0;												// age���� ���ڸ� ī��Ʈ�ϱ����� �ʱ�ȭ
		}
	}
	
	char name1[30] = {0};
	char age1[10] = {0};
	int cnt1 = 0;
	int flag1 = 0;   //0�̸� �̸�, 1�̸� ����
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
		printf("�� ���ڿ��� ����ġ�մϴ�. ");
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
				printf("�� ���ڿ��� ����ġ�մϴ�. ");
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
						printf("�� ���ڿ��� ��ġ�մϴ�. ");
					}
					agecnt++;
					continue;
				}
				else if (age0[j] != age1[j])
				{
					printf("�� ���ڿ��� ����ġ�մϴ�. ");
					exit(0);
				}
			}
		}
	}
}
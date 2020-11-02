#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������
#include<time.h> // �ð����� ���

// ����ü�� �����͵� �����鸸 �ִ°� // Ŭ������ ����ü�� �Լ������ ���ĳ�����  ------- �� ���� �������� ����ص־���!!

// data ���� ���� ������ó�� �� �ݵ�� �ϳ��� �����ϴ� ��� / �������� �����͸� �ٷ���� �ݵ�� �ϳ��ϳ��� �����ؾ��Ѵ�.
struct _car{
	int number;									// ��
	double price;								// �������
	time_t in;									// ������ �ð�, ��������� ��ȣ�� ����.
	time_t out;									// ������ �ð�, ��������� ��ȣ�� ����.
};
typedef struct _car Car;

// Car�� ���� �� ����(����)�ؾ��ϴϱ� - Ÿ���� �Ȱ���.- �迭�� ����ϰڱ���
Car list[20];									// Car�� �迭�� �����.
int seq = 0;
int hasEmpty(void) {
	// ����ִ� ? ���¸� ��� ǥ���� ���̳�??
	for (int i = 0; i < 20; ++i) {
		if (list[i].number == 0); {						// ����ִٴ� ���� �ѹ��� 0�ΰɷ� ǥ���ϰڴ�.
			return i;									// ��������� i��� ��ҹ�ȣ�� ��ȯ�ϰڴ�.
		}
	}
	return -1;	// ���ڸ��� ����. 50�� ������ ���ư�.
}
int goHome() {
	time_t now = time(NULL);					// ������忡���� �ð�, unsigned int �� 4����Ʈ�ε� time_t�� longlongŸ���̶� 8����Ʈ�� �Դ´�. �� ©���� ǥ��ȴ�.
	struct tm tm;
	localtime_s(&tm, &now);					    // �ð� ��� ���	printf("\n now : %lld\n", now/(60*60));
	int h = tm.tm_hour;
	int m = tm.tm_min;
	if (h > 18); {                              // printf("%d�� %d�� \n", h, m);
		return 0;								// ��ٽð��̴�.
	}
	return 1;
}

//	clock_t ct = clock();						// cpu�� ����ð�, clock�� longŸ�� 4����Ʈ = int 4����Ʈ. ũ�Ⱑ �´�. / �츮 ���α׷��� ������� �󸶳� �ƴ���
//	printf("\n clock : %d\n", ct);


int main(int argc, char** argv) {
	printf("// �������Դϴ�. ���� ������ �������Դϴ�.\n");
	do {
		printf("[1]IN [2]OUT >");	// Ű�����Է� �޴� �Լ� : getchar();	/ getchar(); �� �ΰ� ���ľ��� �Է��� ���� ���� 2�������� 1���� ������ �ڿ� getchar�� �ٽ� �������ش�.
		char key = getchar(); getchar();   // getchar : �������ڸ� �Է��� �� ������ enter�� �ľ� ���̳���. / enter���� �����ؼ� �Է��� ���� ������ŭ �ݺ������Ѵ�.
			if (key == '1') {
				printf("// ���� ������ �ִ�.\n");
				printf("// ������ �� �� ������ ������?");
				if (hasEmpty() != -1) {
					printf("// ������ �� �ִ�.\n");
					Car car;
					printf("������ȣ >");
					scanf_s("%d", &car.number);		// Ű���忡�� �Է¹��� �ڷḦ ���ϴ� �ڷ������� ��ȯ����, ����ȣ 4�ڸ� �����ޱ�
					car.price = 1000.0;				// �⺻���
					car.in = time(NULL);			// ���� �ð�
					// ������Ű��
					list[seq] = car;				// seq��� ��������, �ϳ��� ������Ű����
					++seq;
				}
				else {
					printf("// �� �ڸ��� ������ �������Ѵ�.\n");
				}
			}
			if (key == '2') {
				printf("// ���� ������ �ִ�.\n");
				printf("������ȣ >");
					int num;
				scanf_s("%d", &num);
				Car car;
				for (int i = 0; i < 20; ++i) {
					if (num == list[i].number) {			// ���������� �´��� ���غ�����.
						car = list[i];
						printf("// ���� �������� �� �ڸ��� �����.\n");
						list[i].number = 0; // �� �ڸ���� �ǹ��� ��
						break;
					}
				}
				if (car.number != 0) {
					printf("// ����� �ּ���\n");
					car.out = time(NULL);
					// �ð� ����(������ �ð�)
					car.price += 5000.0;
					printf("��� : %lf\n", car.price);
				}
				
			
			}
	} while (goHome());															// ��� �ð��� ���� �ȵ�����..!, ������ ���;� ����� �� ���� c����� ������ 0
			printf("// ��� �ð��� �Ǿ ������ ���Թ��� ��װ� ���� ����.\n");	// ��� �ð��� ������..!

	return 0;
}

/*

typedef struct _car* PCar;				// P�� �پ������� �����Ͷ�� �����Ѵ�.
typedef struct _car ACar[12];			// �迭�̱���

int main_02(int argc, char** argv) {
	ACar list;				// struct _car listp[12]; �� �ǹ̰� ����
	PCar now = &list[0];	// struct _car *now; �� �ǹ̰� ����
	Car temp;

	printf("%d\n", sizeof(list));

	temp = list[0];		// ����ü ������ ����
	temp.number = 11;
	temp.price = 1000.0;

	return 0;
}


struct _car {
	int number;
	double price;
};

int main_01(int argc, char** argv) {

	struct _car t;
	t.number = 1003;				// ������� ���� ���� t.
	t.price = 1000.0;

	// �ּ�->�����
	(&t)->number = 2003;			// ����ּ�->����� = �� ����

	// ������ ������ �ּҴ�.
	struct _car* cp;
	cp = &t;
	cp->price = 2000.0;

	(*cp).number = 3003;			// �����Ϳ� *(��) �����Ŵ� �̸���ģ�ſ� ����. t��� �̸��� ������.

	// ���� �򰥸��ٸ� -> ȭ��ǥ�� ���� ���.

	return 0;
}

*/
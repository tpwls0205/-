#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  
#define SIZE 100
#pragma warning (disable:4996)

typedef struct person {                    
    char crime[SIZE];  // ���˸�
    char name[SIZE];  // �̸�
    char sex[SIZE];   // ����
    char zone[SIZE];    // ������
    char height[SIZE];  // ����
    char weight[SIZE];  // ������
    char money[SIZE];   // �����

} PERSON;

void menu();
PERSON get_record();
void print_record(PERSON data);
void add_record(FILE* fp);
void search_record_a(FILE* fp);
void search_record_b(FILE* fq);
void update_record(FILE* fp, FILE* fq);
void delete_record(FILE* fp, FILE* fq);
void inclear(void);

int main(void)
{
    FILE* fp, * fq;
    int select, i;
    // ���� ������ �߰� ���� �����Ѵ�.
    if ((fp = fopen("address.dat", "a+")) == NULL || (fq = fopen("newaddress.dat", "a+")) == NULL)
    {
        fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�");
        exit(1);
    }
    while (1)
    {
        menu();  // �޴��� ǥ���Ѵ�.
        printf("�޴��� �����ϼ���: "); scanf("%d", &select);  getchar();   // ����ڷκ��� ������ �޴´�. ���ڸ� �Է¹����� while������ ���ư���.
        void inclear(void);                                                // �߸��� ������ ���ۿ� ����Ȱ� �������ش�? �ణ �׷� �ǹ��ΰŰ���.
        switch (select)
        {
        case 1: add_record(fp); break;  // �����͸� �߰��Ѵ�.
        case 2: update_record(fp, fq); break;  // �����͸� �����Ѵ�.
        case 3:
            printf("1. ���� ��, 2. ���� �� : ");  scanf("%d", &i);  getchar();
            if (i == 1)
            {
                search_record_a(fp); break;  // �����͸� Ž���Ѵ�.
            }
            else if (i == 2)
            {
                search_record_b(fq); break;  // �����͸� Ž���Ѵ�.
            }
            break;
        case 4: delete_record(fp, fq); break; // �����͸� �����Ѵ�.
        case 5: return 0;   // ������.
        }
    }
    fclose(fp); // ������ �ݴ´�
    fclose(fq); // ������ �ݴ´�
    return 0;
}


void inclear(void)
{
    int ch;                                                                           
    while ((ch = getchar()) != EOF && ch != '\n');     // inclear : ������ ���̰ų� ���๮�ڸ� �Է¹����� �ƴ϶��.. �ݺ��Ѵ�.
}

// ����ڷκ��� �����͸� �޾Ƽ� ����ü�� ��ȯ�Ѵ�
PERSON get_record()
{
    PERSON data;
    void inclear(void);

    printf(" ���˸� : ");   gets_s(data.crime, sizeof(data.crime));
    printf(" �̸� : ");   gets_s(data.name, sizeof(data.name));
    printf(" ���� : ");  gets_s(data.sex, sizeof(data.sex));
    printf(" ������ : ");  gets_s(data.zone, sizeof(data.zone));
    printf(" ���� : ");   gets_s(data.height, sizeof(data.height));
    printf(" ������ : ");   gets_s(data.weight, sizeof(data.weight));
    printf(" ����� : ");  gets_s(data.money, sizeof(data.money));

    return data;
}

// ����ü �����͸� ȭ�鿡 ����Ѵ�.
void print_record(PERSON data)
{
    printf(" ���˸� : %s \n", data.crime);
    printf(" �̸� : %s \n", data.name);
    printf(" ���� : %s \n", data.sex);
    printf(" ������ : %s \n", data.zone);
    printf(" ���� : %s \n", data.height);
    printf(" ������ : %s \n", data.weight);
    printf(" ����� : %s \n", data.money);

}

// �޴��� ȭ�鿡 ǥ���ϴ� �Լ�
void menu()
{
    printf("=======================================================\n");
    printf("  1. �߰�\n  2. ����\n  3. �˻�\n  4. �˰�\n  5. ������\n");
    printf("=======================================================\n");
}

// �����͸� �߰��Ѵ�.
void add_record(FILE* fp)
{
    PERSON data;
    data = get_record();  // ����ڷκ��� �����͸� �޾Ƽ� ����ü�� ����
    fseek(fp, 0, SEEK_END);  // ������ ������ ����. / fseek(����������, �̵���ũ��, ������)
    fwrite(&data, sizeof(data), 1, fp);  // ����ü �����͸� ���Ͽ� ����. / fwrite(����, ����ũ��, ����Ƚ��, ����������)
}


// ������ �����ϱ� �� ���� : �����͸� Ž���Ѵ�. 
void search_record_a(FILE* fp)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET);  // fp������ ó������ ����.
    void inclear(void);
    printf("Ž���ϰ��� �ϴ� ����� �̸� : ");
    gets_s(name, sizeof(name));  //�̸��� �Է¹޴´�.
    while (!feof(fp)) {  //������ ������ �ݺ��Ѵ�.
        fread(&data, sizeof(data), 1, fp); // ���� ��ġ���� �����͸� �д´�.
        if (strcmp(data.name, name) == 0)  //�̸��� ���Ѵ�.
        {
            print_record(data);  //��ġ�ϸ� �����͸� ȭ�鿡 ����Ѵ�.
            break;
        }
    }
}

// ������ ������ �� ���� : �����͸� Ž���Ѵ�.
void search_record_b(FILE* fq)
{
    char name[SIZE];
    PERSON data;
    fseek(fq, 0, SEEK_SET);  // fp������ ó������ ����.
    void inclear(void);
    printf("Ž���ϰ��� �ϴ� ����� �̸� : ");
    gets_s(name, sizeof(name));  //�̸��� �Է¹޴´�.
    while (!feof(fq)) {  //������ ������ �ݺ��Ѵ�.
        fread(&data, sizeof(data), 1, fq); // ���� ��ġ���� �����͸� �д´�.
        if (strcmp(data.name, name) == 0)  //�̸��� ���Ѵ�.
        {
            print_record(data);  //��ġ�ϸ� �����͸� ȭ�鿡 ����Ѵ�.
            break;
        }
    }
}

// �����͸� �����Ѵ�.
void update_record(FILE* fp, FILE* fq)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET);  // ������ ó������ ����.
    void inclear(void);
    printf("������ ����� �̸� �Է� : ");
    gets_s(name, sizeof(name));  //�̸��� �Է¹޴´�. 
    printf("\n ���� ���Դϴ�... \n");
    while (!feof(fp)) {  //������ ������ �ݺ��Ѵ�.
        fread(&data, sizeof(data), 1, fp); // ���� ��ġ���� �����͸� �д´�.
        if (strcmp(data.name, name) == 0)  //�̸��� ���Ѵ�.
        {
            data = get_record(data);  //��ġ�ϸ� �����͸� �����Ѵ�.
            printf("������ ���� �Ϸ�\n");
            print_record(data);  //������ �����͸� ����Ѵ�.
            fwrite(&data, sizeof(data), 1, fq);  // ����ü �����͸� ���Ͽ� ����.
            break;
        }
    }
}

void delete_record(FILE* fp, FILE* fq)
{
    char name[SIZE];
    PERSON data;
    printf("�˰��� ����� �̸� �Է� : ");
    gets_s(name, sizeof(name));
    printf("\n �˰� �Ϸ�! �����͸� �����մϴ�. \n");
}

// �߰� - �˰Ű� �Ǹ��� ��ǻ�����忡���� ������ �����Ȱű� ������ 1�������ڸ� ���� �� ����� ���� ������ ����� �����ִ�.
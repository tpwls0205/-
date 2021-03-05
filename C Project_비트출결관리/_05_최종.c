#include "turboc.h"
#include <time.h>

#define DATA_NUM 50   // ����ü �迭 ����
#pragma warning(disable:4996)   // ��ť��Ƽ ��������

enum {
    // ������ �޴�
    IN_BITCAMP = 1,
    OUT_BITCAMP,
    SEARCH_DATA,                
    EXIT_1,
    // ������ �޴�
    UPDATE_DATA = 1,
    DELETE_DATA,
    ADD_DATA,
    EXIT_2
};

// ������ ����
typedef struct students {
    char name[30];   // �̸�
    int tardy;       // ����
    int absent;      // �Ἦ
    int earlyOut;    // ����
}Std;

Std _std[DATA_NUM] = { 0 };      // ������ ����ü �迭
int stdCnt = 0;                  // ������ �ο���

// �����
void menu1();                          // ������ �޴���
void menu2();                          // ������ �޴���
int selFunction();                     // ���ϴ� ����� ��ȣ�� �Է¹޴� �Լ�

int funcExecution1(int selFunction);   // �������� ����� ���� �Լ�
time_t inBitcamp();                    // ���                                                  
void outBitcamp(time_t b);             // ���                                                 
void searchData();                     // ��ȸ

int funcExecution2(int selFunction);   // �������� ����� ���� �Լ�
void updateData();                     // ����
void deleteData();                     // ����
void addData();                        // �߰�


void menu1() {   // ������ �޴�
    printf("\t��������������������\n");
    printf("\t����1.    ���   ����\n");
    printf("\t����2.    ���   ����\n");
    printf("\t����3.    ��ȸ   ����\n");
    printf("\t����4.    ����   ����\n");
    printf("\t��������������������\n\n");
}

void menu2() {   // ������ �޴�

    printf("\t��������������������\n");
    printf("\t����1.    ����   ����\n");
    printf("\t����2.    ����   ����\n");
    printf("\t����3.    �߰�   ����\n");
    printf("\t����4.    ����   ����\n");
    printf("\t��������������������\n\n");

}

int selFunction() {   // ���ϴ� ��� �Է�
    int num = 0;
    printf("���ϴ� ����� �Է����ּ��� >> ");
    scanf_s("%d", &num);
    getchar();

    return num;
}

int funcExecution1(int selFunction) {   // ����� ��� ����
    static time_t b = 0;
    switch (selFunction) {
    case IN_BITCAMP:
        b = inBitcamp();
        break;
    case OUT_BITCAMP:
        outBitcamp(b);
        break;
    case SEARCH_DATA:           
        searchData();
        break;
    case EXIT_1:
        return 0;
        break;
    default:
        printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
        break;
    }
    return 1;
}

int funcExecution2(int selFunction) {   // ������ ��� ����

    switch (selFunction) {
    case UPDATE_DATA:
        updateData();
        break;
    case DELETE_DATA:
        deleteData();
        break;
    case ADD_DATA:
        addData();
        break;
    case EXIT_2:
        return 0;
        break;
    default:
        printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
        break;
    }
}

time_t inBitcamp() {

    int a = 0;                                                      // ������ a ���� ����
    time_t ttime = 0;                                               // Ÿ���� ttime ���� ����

    while (1) {                                                     // ���ѷ���

        printf("\n");
        printf("��ٱ�� ����Դϴ�.\n\n");

        time_t t = time(NULL);                                      // Ÿ���� ���� t�� ���� �ʱ�ȭ
        struct tm tm = *localtime(&t);                              // ����t�� ����ð��� ��� 
                                                                    // �� �ð����� ����ü tm����� �Է��Ѵ�
        printf("����ð� : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        ttime = tm.tm_hour;                                         // tm��� �� �ð����� ttime ������ ����

        Std std_ = { 0 };                                           // std ����ü std_���� ����
        printf("�̸� �Է�: ");          
        fgets(std_.name, sizeof(std_.name), stdin);                 // std_����ü�� ����, ����ũ�⸸ŭ, Ű�����Է��� �޴´�.
        std_.name[strlen(std_.name) - 1] = '\0';                    // ���ڿ� �� �ι��ڷ� ����˸�

        printf("����Ͻðڽ��ϱ�? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);      
        
        if (a == 1) {
            int ts = 0;                                             // ������ ts ����
            if (tm.tm_hour <= 9) {                                  // tm_hour = �� ttime�� 9���� �۰ų� ������ (����) �������
                printf("��������ϼ̽��ϴ�. ������Դϴ�\n");

            }
            if (tm.tm_hour > 9) {                                   // tm_hour = �� ttime�� 9���� ũ�� (����) ����!!
                printf("�����ϼ̽��ϴ�. �й��ϼ���! \n\n");

                for (int i = 0; i < stdCnt; i++)                    // �����̶�� ����ü�迭�� ��ϵ� ��� �� ������ ������� ����ǥ�ø� �ϰڴ�.
                {
                    if (!strcmp(_std[i].name, std_.name))           // ���� i��° ����ü�迭 ���Ӱ�, �Է¹��� ����ü ������ ��ġ�Ѵٸ�
                    {                                               // ��, �̹� �ѹ� ������ �� ������� ���Ӱ� ������ �ʰ� �� ����� ������
                        _std[i].tardy++; ts = 1; break;             // �ش� i��° �̸��� ������� ������ �߰��ϰ� ts���� 1�� ����ڴ�.
                    }
                }                                                   // for���� ���ͼ� 1�̸� �Ʒ��� if���� ��������
                if (ts == 0)                                        // ts = 1 ���� ���޾Ҵٸ� ��, ��ġ���� �ʾҴٸ�
                {
                    strcpy(_std[stdCnt].name, std_.name);  _std[stdCnt].tardy++;        // ���ڿ��� ī���Ѵ�. �Է¹��� �̸���
                    stdCnt++;                                                           // ����ü�迭 �ش� �̸�����, ������ �߰�
                }                                                                       // ���� �������� �̵�

            }
        }
        return ttime;                                                // ttime = �� h���� ��ȯ
        if (a == 0) {
            break;
        }

    }
}

void outBitcamp(time_t b) {

    time_t intime = b;

    while (1) {
        int ts = 0;
        int a = 0;

        printf("\n");
        printf("��ٱ�� ����Դϴ�.\n\n");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("����ð� : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        Std std_ = { 0 };
        printf("�̸� �Է�: ");
        fgets(std_.name, sizeof(std_.name), stdin);
        std_.name[strlen(std_.name) - 1] = '\0';


        printf("����Ͻðڽ��ϱ�? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);

        if (a == 1) {

            time_t outtime = tm.tm_hour;
            time_t result = outtime - intime;
            // ��ٽð� - ��ٽð�
            if (result < 5) {
                printf("�ð��� ������� �ʽ��ϴ�. �Ἦ�Դϴ� ! \n\n");

                for (int i = 0; i < stdCnt; i++) {
                    if (!strcmp(_std[i].name, std_.name)) {
                        _std[i].absent++; ts = 1; break;
                    }
                }
                if (ts == 0) {
                    strcpy(_std[stdCnt].name, std_.name); _std[stdCnt].absent++;
                    stdCnt++;
                }

                break;
            }
            if (result >= 5 && result < 9) {
                printf("��� ���°�����?. �����Դϴ� ! \n\n");
                for (int i = 0; i < stdCnt; i++) {
                    if (!strcmp(_std[i].name, std_.name)) {
                        _std[i].earlyOut++; ts = 1; break;
                    }
                }
                if (ts == 0) {
                    strcpy(_std[stdCnt].name, std_.name); _std[stdCnt].earlyOut++;
                    stdCnt++;
                }
                break;
            }
            if (result >= 9) {
                printf("��������ϼ̽��ϴ�. ������Դϴ� \n\n");
                break;
            }
        }

        if (a == 0) {
            break;
        }
    }
}

void searchData() {
    char name[20] = { 0 };
    printf("�˻��� �̸� �Է�: ");
    fgets(name, sizeof(name) - 1, stdin);
    name[strlen(name) - 1] = 0;
    for (int i = 0; i < stdCnt; i++)
    {
        if (!strcmp(_std[i].name, name)) {
            printf("�̸� : %s\n", _std[i].name);
            printf("����Ƚ�� : %d\n", _std[i].tardy);
            printf("����Ƚ�� : %d\n", _std[i].earlyOut);
            printf("�ἮȽ�� : %d\n", _std[i].absent);
        }
    }
}

void updateData() {
    printf("\n");
    printf("���� ����Դϴ�.\n\n");
}

void deleteData() {
    printf("\n");
    printf("���� ����Դϴ�.\n\n");
}

void addData() {

    Std* std_ = NULL;
    std_ = &_std[stdCnt];
    printf("�̸� �Է�: ");
    fgets(std_->name, sizeof(std_->name), stdin);
    std_->name[strlen(std_->name) - 1] = '\0';
    stdCnt++;

    FILE* fp = NULL;
    fopen_s(&fp, "students.txt", "a+t");
    fputs(std_->name, fp);
    fputc('\n', fp);
    fclose(fp);

    printf("\n");
    printf("������ ������ �߰��Ǿ����ϴ�.\n\n");

}


void showData() {

    for (int i = 0; i < stdCnt; i++) {
    printf("\n--------------------------\n");
    printf("�̸� : %s\n", _std[i].name);
    printf("����Ƚ�� : %d\n", _std[i].tardy);
    printf("����Ƚ�� : %d\n", _std[i].earlyOut);
    printf("�ἮȽ�� : %d\n", _std[i].absent);
    printf("\n--------------------------\n");
    }

    return 1;
}

void main() {

    int selNum1 = 0;

    int runTime = 1;      // 1�̸� �ݺ�, 0�̸� ����
    int x = 0;            // ������ & ������ ���� ����

    int a = 0;            // ��й�ȣ�� �Է¹޴� �Լ�
    int passWord = 1234;   // �������� �н�����
    int isPassword = 0;      // �н����� ������� ����

    printf("��Ʈķ�� ������ ���α׷��Դϴ� ! \n");
    printf("������ �������̸� 1(������) / �����ڸ� 2(������) ���� �Է����ּ��� : ");
    scanf_s("%d", &x);

    while (runTime) {

        if (x == 1) {      // ������
            menu1();
            selNum1 = selFunction();
            runTime = funcExecution1(selNum1);
        }

        if (x == 2) {      // ������

            if (isPassword == 0)
            {
                printf("��й�ȣ �Է��ϼ��� : ");

                scanf_s("%d", &a);
                if (a == passWord)
                    isPassword = 1;      // ��й�ȣ�� �ѹ� ����Ǹ� �׵ڷ� else ������ ����ؼ� ����
                else {
                    printf("��й�ȣ Ʋ�Ƚ��ϴ� !\n");
                }
            }
            else
            {
                menu2();
                selNum1 = selFunction();
                runTime = funcExecution2(selNum1);
            }
        }
    }
}
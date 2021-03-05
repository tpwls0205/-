#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  
#define SIZE 100
#pragma warning (disable:4996)

typedef struct person {                    
    char crime[SIZE];  // 범죄명
    char name[SIZE];  // 이름
    char sex[SIZE];   // 성별
    char zone[SIZE];    // 거주지
    char height[SIZE];  // 신장
    char weight[SIZE];  // 몸무게
    char money[SIZE];   // 현상금

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
    // 이진 파일을 추가 모드로 오픈한다.
    if ((fp = fopen("address.dat", "a+")) == NULL || (fq = fopen("newaddress.dat", "a+")) == NULL)
    {
        fprintf(stderr, "입력을 위한 파일을 열 수 없습니다");
        exit(1);
    }
    while (1)
    {
        menu();  // 메뉴를 표시한다.
        printf("메뉴를 선택하세요: "); scanf("%d", &select);  getchar();   // 사용자로부터 정수를 받는다. 문자를 입력받으면 while문으로 돌아간다.
        void inclear(void);                                                // 잘못들어간 값들이 버퍼에 저장된걸 삭제해준다? 약간 그런 의미인거같다.
        switch (select)
        {
        case 1: add_record(fp); break;  // 데이터를 추가한다.
        case 2: update_record(fp, fq); break;  // 데이터를 수정한다.
        case 3:
            printf("1. 수정 전, 2. 수정 후 : ");  scanf("%d", &i);  getchar();
            if (i == 1)
            {
                search_record_a(fp); break;  // 데이터를 탐색한다.
            }
            else if (i == 2)
            {
                search_record_b(fq); break;  // 데이터를 탐색한다.
            }
            break;
        case 4: delete_record(fp, fq); break; // 데이터를 삭제한다.
        case 5: return 0;   // 나가기.
        }
    }
    fclose(fp); // 파일을 닫는다
    fclose(fq); // 파일을 닫는다
    return 0;
}


void inclear(void)
{
    int ch;                                                                           
    while ((ch = getchar()) != EOF && ch != '\n');     // inclear : 파일의 끝이거나 개행문자를 입력받은게 아니라면.. 반복한다.
}

// 사용자로부터 데이터를 받아서 구조체로 반환한다
PERSON get_record()
{
    PERSON data;
    void inclear(void);

    printf(" 범죄명 : ");   gets_s(data.crime, sizeof(data.crime));
    printf(" 이름 : ");   gets_s(data.name, sizeof(data.name));
    printf(" 성별 : ");  gets_s(data.sex, sizeof(data.sex));
    printf(" 거주지 : ");  gets_s(data.zone, sizeof(data.zone));
    printf(" 신장 : ");   gets_s(data.height, sizeof(data.height));
    printf(" 몸무게 : ");   gets_s(data.weight, sizeof(data.weight));
    printf(" 현상금 : ");  gets_s(data.money, sizeof(data.money));

    return data;
}

// 구조체 데이터를 화면에 출력한다.
void print_record(PERSON data)
{
    printf(" 범죄명 : %s \n", data.crime);
    printf(" 이름 : %s \n", data.name);
    printf(" 성별 : %s \n", data.sex);
    printf(" 거주지 : %s \n", data.zone);
    printf(" 신장 : %s \n", data.height);
    printf(" 몸무게 : %s \n", data.weight);
    printf(" 현상금 : %s \n", data.money);

}

// 메뉴를 화면에 표시하는 함수
void menu()
{
    printf("=======================================================\n");
    printf("  1. 추가\n  2. 수정\n  3. 검색\n  4. 검거\n  5. 나가기\n");
    printf("=======================================================\n");
}

// 데이터를 추가한다.
void add_record(FILE* fp)
{
    PERSON data;
    data = get_record();  // 사용자로부터 데이터를 받아서 구조체에 저장
    fseek(fp, 0, SEEK_END);  // 파일의 끝으로 간다. / fseek(파일포인터, 이동할크기, 기준점)
    fwrite(&data, sizeof(data), 1, fp);  // 구조체 데이터를 파일에 쓴다. / fwrite(버퍼, 쓰기크기, 쓰기횟수, 파일포인터)
}


// 수정을 실행하기 전 파일 : 데이터를 탐색한다. 
void search_record_a(FILE* fp)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET);  // fp파일의 처음으로 간다.
    void inclear(void);
    printf("탐색하고자 하는 사람의 이름 : ");
    gets_s(name, sizeof(name));  //이름을 입력받는다.
    while (!feof(fp)) {  //파일의 끝까지 반복한다.
        fread(&data, sizeof(data), 1, fp); // 현재 위치에서 데이터를 읽는다.
        if (strcmp(data.name, name) == 0)  //이름을 비교한다.
        {
            print_record(data);  //일치하면 데이터를 화면에 출력한다.
            break;
        }
    }
}

// 수정을 실행한 후 파일 : 데이터를 탐색한다.
void search_record_b(FILE* fq)
{
    char name[SIZE];
    PERSON data;
    fseek(fq, 0, SEEK_SET);  // fp파일의 처음으로 간다.
    void inclear(void);
    printf("탐색하고자 하는 사람의 이름 : ");
    gets_s(name, sizeof(name));  //이름을 입력받는다.
    while (!feof(fq)) {  //파일의 끝까지 반복한다.
        fread(&data, sizeof(data), 1, fq); // 현재 위치에서 데이터를 읽는다.
        if (strcmp(data.name, name) == 0)  //이름을 비교한다.
        {
            print_record(data);  //일치하면 데이터를 화면에 출력한다.
            break;
        }
    }
}

// 데이터를 수정한다.
void update_record(FILE* fp, FILE* fq)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET);  // 파일의 처음으로 간다.
    void inclear(void);
    printf("수정할 사람의 이름 입력 : ");
    gets_s(name, sizeof(name));  //이름을 입력받는다. 
    printf("\n 수정 중입니다... \n");
    while (!feof(fp)) {  //파일의 끝까지 반복한다.
        fread(&data, sizeof(data), 1, fp); // 현재 위치에서 데이터를 읽는다.
        if (strcmp(data.name, name) == 0)  //이름을 비교한다.
        {
            data = get_record(data);  //일치하면 데이터를 수정한다.
            printf("데이터 수정 완료\n");
            print_record(data);  //수정된 데이터를 출력한다.
            fwrite(&data, sizeof(data), 1, fq);  // 구조체 데이터를 파일에 쓴다.
            break;
        }
    }
}

void delete_record(FILE* fp, FILE* fq)
{
    char name[SIZE];
    PERSON data;
    printf("검거한 사람의 이름 입력 : ");
    gets_s(name, sizeof(name));
    printf("\n 검거 완료! 데이터를 삭제합니다. \n");
}

// 추가 - 검거가 되면은 컴퓨터입장에서는 내용이 수정된거기 때문에 1번범죄자를 수정 후 기록이 없다 수정전 기록이 남아있다.
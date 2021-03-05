#include "turboc.h"
#include <time.h>

#define DATA_NUM 50   // 구조체 배열 길이
#pragma warning(disable:4996)   // 시큐리티 오류무시

enum {
    // 수강생 메뉴
    IN_BITCAMP = 1,
    OUT_BITCAMP,
    SEARCH_DATA,                
    EXIT_1,
    // 관리자 메뉴
    UPDATE_DATA = 1,
    DELETE_DATA,
    ADD_DATA,
    EXIT_2
};

// 수강생 정보
typedef struct students {
    char name[30];   // 이름
    int tardy;       // 지각
    int absent;      // 결석
    int earlyOut;    // 조퇴
}Std;

Std _std[DATA_NUM] = { 0 };      // 수강생 구조체 배열
int stdCnt = 0;                  // 수강생 인원수

// 선언부
void menu1();                          // 수강생 메뉴얼
void menu2();                          // 관리자 메뉴얼
int selFunction();                     // 원하는 기능의 번호를 입력받는 함수

int funcExecution1(int selFunction);   // 수강생의 기능을 가진 함수
time_t inBitcamp();                    // 출근                                                  
void outBitcamp(time_t b);             // 퇴근                                                 
void searchData();                     // 조회

int funcExecution2(int selFunction);   // 관리자의 기능을 가진 함수
void updateData();                     // 수정
void deleteData();                     // 삭제
void addData();                        // 추가


void menu1() {   // 수강생 메뉴
    printf("\t――――――――――\n");
    printf("\t｜｜1.    출근   ｜｜\n");
    printf("\t｜｜2.    퇴근   ｜｜\n");
    printf("\t｜｜3.    조회   ｜｜\n");
    printf("\t｜｜4.    종료   ｜｜\n");
    printf("\t――――――――――\n\n");
}

void menu2() {   // 관리자 메뉴

    printf("\t――――――――――\n");
    printf("\t｜｜1.    수정   ｜｜\n");
    printf("\t｜｜2.    삭제   ｜｜\n");
    printf("\t｜｜3.    추가   ｜｜\n");
    printf("\t｜｜4.    종료   ｜｜\n");
    printf("\t――――――――――\n\n");

}

int selFunction() {   // 원하는 기능 입력
    int num = 0;
    printf("원하는 기능을 입력해주세요 >> ");
    scanf_s("%d", &num);
    getchar();

    return num;
}

int funcExecution1(int selFunction) {   // 사용자 기능 고르기
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
        printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
        break;
    }
    return 1;
}

int funcExecution2(int selFunction) {   // 관리자 기능 고르기

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
        printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
        break;
    }
}

time_t inBitcamp() {

    int a = 0;                                                      // 정수형 a 변수 선언
    time_t ttime = 0;                                               // 타임형 ttime 변수 선언

    while (1) {                                                     // 무한루프

        printf("\n");
        printf("출근기록 기능입니다.\n\n");

        time_t t = time(NULL);                                      // 타임형 변수 t의 값을 초기화
        struct tm tm = *localtime(&t);                              // 변수t에 현재시간을 담고 
                                                                    // 그 시간값을 구조체 tm멤버에 입력한다
        printf("현재시각 : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        ttime = tm.tm_hour;                                         // tm멤버 중 시간값을 ttime 변수에 저장

        Std std_ = { 0 };                                           // std 구조체 std_변수 선언
        printf("이름 입력: ");          
        fgets(std_.name, sizeof(std_.name), stdin);                 // std_구조체에 네임, 네임크기만큼, 키보드입력을 받는다.
        std_.name[strlen(std_.name) - 1] = '\0';                    // 문자열 끝 널문자로 종료알림

        printf("출근하시겠습니까? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);      
        
        if (a == 1) {
            int ts = 0;                                             // 정수형 ts 선언
            if (tm.tm_hour <= 9) {                                  // tm_hour = 즉 ttime이 9보다 작거나 같으면 (오전) 정상출근
                printf("정상출근하셨습니다. 출근중입니다\n");

            }
            if (tm.tm_hour > 9) {                                   // tm_hour = 즉 ttime이 9보다 크면 (오전) 지각!!
                printf("지각하셨습니다. 분발하세요! \n\n");

                for (int i = 0; i < stdCnt; i++)                    // 지각이라면 구조체배열에 등록된 사람 중 지각한 사람에게 지각표시를 하겠다.
                {
                    if (!strcmp(_std[i].name, std_.name))           // 만약 i번째 구조체배열 네임과, 입력받은 구조체 네임이 일치한다면
                    {                                               // 즉, 이미 한번 지각이 된 사람에게 새롭게 만들지 않고 그 사람의 지각을
                        _std[i].tardy++; ts = 1; break;             // 해당 i번째 이름의 사람에게 지각을 추가하고 ts값을 1로 만들겠다.
                    }
                }                                                   // for문을 나와서 1이면 아래에 if문을 지나가고
                if (ts == 0)                                        // ts = 1 값을 못받았다면 즉, 일치하지 않았다면
                {
                    strcpy(_std[stdCnt].name, std_.name);  _std[stdCnt].tardy++;        // 문자열을 카피한다. 입력받은 이름을
                    stdCnt++;                                                           // 구조체배열 해당 이름에게, 지각을 추가
                }                                                                       // 다음 공간으로 이동

            }
        }
        return ttime;                                                // ttime = 즉 h값을 반환
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
        printf("퇴근기록 기능입니다.\n\n");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("현재시각 : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        Std std_ = { 0 };
        printf("이름 입력: ");
        fgets(std_.name, sizeof(std_.name), stdin);
        std_.name[strlen(std_.name) - 1] = '\0';


        printf("퇴근하시겠습니까? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);

        if (a == 1) {

            time_t outtime = tm.tm_hour;
            time_t result = outtime - intime;
            // 퇴근시간 - 출근시간
            if (result < 5) {
                printf("시간이 충분하지 않습니다. 결석입니다 ! \n\n");

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
                printf("어디 아픈가봐요?. 조퇴입니다 ! \n\n");
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
                printf("정상퇴근하셨습니다. 퇴근중입니다 \n\n");
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
    printf("검색할 이름 입력: ");
    fgets(name, sizeof(name) - 1, stdin);
    name[strlen(name) - 1] = 0;
    for (int i = 0; i < stdCnt; i++)
    {
        if (!strcmp(_std[i].name, name)) {
            printf("이름 : %s\n", _std[i].name);
            printf("지각횟수 : %d\n", _std[i].tardy);
            printf("조퇴횟수 : %d\n", _std[i].earlyOut);
            printf("결석횟수 : %d\n", _std[i].absent);
        }
    }
}

void updateData() {
    printf("\n");
    printf("수정 기능입니다.\n\n");
}

void deleteData() {
    printf("\n");
    printf("삭제 기능입니다.\n\n");
}

void addData() {

    Std* std_ = NULL;
    std_ = &_std[stdCnt];
    printf("이름 입력: ");
    fgets(std_->name, sizeof(std_->name), stdin);
    std_->name[strlen(std_->name) - 1] = '\0';
    stdCnt++;

    FILE* fp = NULL;
    fopen_s(&fp, "students.txt", "a+t");
    fputs(std_->name, fp);
    fputc('\n', fp);
    fclose(fp);

    printf("\n");
    printf("수강생 정보가 추가되었습니다.\n\n");

}


void showData() {

    for (int i = 0; i < stdCnt; i++) {
    printf("\n--------------------------\n");
    printf("이름 : %s\n", _std[i].name);
    printf("지각횟수 : %d\n", _std[i].tardy);
    printf("조퇴횟수 : %d\n", _std[i].earlyOut);
    printf("결석횟수 : %d\n", _std[i].absent);
    printf("\n--------------------------\n");
    }

    return 1;
}

void main() {

    int selNum1 = 0;

    int runTime = 1;      // 1이면 반복, 0이면 종료
    int x = 0;            // 수강생 & 관리자 구분 변수

    int a = 0;            // 비밀번호를 입력받는 함수
    int passWord = 1234;   // 임의지정 패스워드
    int isPassword = 0;      // 패스워드 통과여부 변수

    printf("비트캠프 출결관리 프로그램입니다 ! \n");
    printf("본인이 수강생이면 1(수강생) / 관리자면 2(관리자) 번을 입력해주세요 : ");
    scanf_s("%d", &x);

    while (runTime) {

        if (x == 1) {      // 수강생
            menu1();
            selNum1 = selFunction();
            runTime = funcExecution1(selNum1);
        }

        if (x == 2) {      // 관리자

            if (isPassword == 0)
            {
                printf("비밀번호 입력하세요 : ");

                scanf_s("%d", &a);
                if (a == passWord)
                    isPassword = 1;      // 비밀번호가 한번 통과되면 그뒤로 else 구문을 계속해서 실행
                else {
                    printf("비밀번호 틀렸습니다 !\n");
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
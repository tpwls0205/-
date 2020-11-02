#include "turboc.h"
#include <iostream>
using namespace std;

// keyboard 입력
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

// 난이도 조절 및 종료키
#define PGUP 73
#define PGDN 81
#define ESC 27

// 보드 시작위치
#define BX 5
#define BY 1

// 게임 스크린
#define BW 10
#define BH 20

// define global
void DrawScreen();
void DrawBoard();

BOOL ProcessKey();
void PrintBrick(BOOL Show);
int GetAround(int x, int y);

BOOL MoveDown();
void TestFull();
void DrawNext();
void PrintInfo();
void MakeNewBrick();
//main();

enum {
    EMPTY,             // 값이 아무것도 지정안되있으면 처음 숫자는 0
    B1, B2,            // 다음 숫자부터는 +1씩 증가해서 값을 저장해둔다.
    B3, B4, 
    B5, B6, 
    B7, B8, 
    B9, B10, 
    WALL };

char* arTile[] = { ". ","■",
"●","★","♣","☎","◆","♠",
"♥","♨","♬","□" };

int board[BW + 2][BH + 2];
int nx, ny;         // 현재 블럭의 x,y 좌표
int brick[3];       // 블럭
int nbrick[3];      // 임의로 다음 나올꺼
int score;          // 점수
int bricknum;       // 생성된 블럭개수
int level;          // 난이도

void main()
{
    int nFrame, nStay;
    int x, y;

    setcursortype(NOCURSOR);    // 커서 없앰
    randomize();                // 난수 생성
    level = 6;                  // 레벨 지정

    for (; ;) {
        clrscr();               // 화면 초기화
        // 벽과 빈공간 생성 -> 보드 초기화
        for (x = 0; x < BW + 2; x++) {          // 11까지
            for (y = 0; y < BH + 2; y++) {      // 21까지
                board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;  // x,y가 시작이거나 끝이면 11, 아니면 0
            }
        }
        DrawScreen();
        nFrame = 20;
        score = 0;
        bricknum = 0;
        //처음 떨어질 벽돌
        MakeNewBrick();
        for (; ;) {
            bricknum++;
            // nbrick에 make를 하므로  brick(현재)로 복사해줌
            memcpy(brick, nbrick, sizeof(brick));                   // memcpy = 배열복사 2번째 -> 1번째, 크기만큼 
            // 다음에 떨어질 벽돌 만들기
            MakeNewBrick();                                         // 벽돌생성
            // main 화면 옆에 있는 화면 그리기
            DrawNext();                                             // 우측 벽돌과, 벽돌테두리 생성
            // 벽돌 생성위치
            nx = BW / 2;                                            // 가로의 반       
            ny = 3;
            // 현재 떨어지는 벽돌 계속 그려주기
            PrintBrick(TRUE);
            // 생성위치까지 블럭이 차 있으면 게임 오버
            if (GetAround(nx, ny) != EMPTY) break;

            nStay = nFrame;
            for (; ;) {
                //gotoxy(0, 0);
                //printf("stay %2d frame %2d brick %2d", nStay, nFrame, bricknum); delay(100);
                // stay가 계속 줄어 들다가 frame(일정시간)과 같아지면 한칸 내려옴
                if (--nStay == 0) {
                    nStay = nFrame;
                    if (MoveDown()) break; // 블럭이 천천히 내려옴
                }
                if (ProcessKey()) break; // 플레이어 키 입력
                delay(1000 / 20); // 키 입력이 너무 빠르지 않게 딜레이
            }

            // 벽돌이 10개 생성될 때마다 frame이 1씩 줄어
            // 벽돌이 머무는 시간이 줄어듬 (난이도 느낌)
            if (bricknum % 10 == 0 && nFrame > 5) {
                nFrame--;
            }
        }
        clrscr();
        gotoxy(30, 12); puts("G A M E  O V E R");
        gotoxy(25, 14); puts("다시 시작하려면 Y를 누르세요");
        if (tolower(getch()) != 'y') break;
    }
    setcursortype(NORMALCURSOR);
}

// 스크린 그리기
void DrawScreen()
{
    int x, y;

    // 게임 메인 스크린
    for (x = 0; x < BW + 2; x++) {              // 11까지
        for (y = 0; y < BH + 2; y++) {          // 21까지
            gotoxy(BX + x * 2, BY + y);         // 전체 스크린을 돌면서, x는 특수문자를 받기때문에
            puts(arTile[board[x][y]]);          // 해당하는 arTile배열 안에 문자를 출력
        }
    }

    gotoxy(50, 3); puts("Hexa Ver 1.0");
    gotoxy(50, 5); puts("좌우:이동, 위:회전, 아래:내림");
    gotoxy(50, 6); puts("공백:전부 내림, ESC:종료");
    gotoxy(50, 7); puts("P:정지,PgUp,PgDn:난이도 조절");
    DrawNext();
    PrintInfo();
}
// board 전체 그리기
void DrawBoard()
{
    int x, y;

    for (x = 1; x < BW + 1; x++) {
        for (y = 1; y < BH + 1; y++) {
            gotoxy(BX + x * 2, BY + y);
            puts(arTile[board[x][y]]);
        }
    }
}
// 키보드 입력 처리
BOOL ProcessKey()
{
    int ch;
    int t;

    if (kbhit()) {
        ch = getch();                                               // getch함수는 1byte만 받을 수 있다 : 아스키코드 값을 받고
        if (ch == 0xE0 || ch == 0) {                                // 확장키(방향키,펑션키)를 입력받았다면 2byte
            ch = getch();                                           // getch로 한번 더 입력받아서 값을 뽑아낸다
            switch (ch) {
            case LEFT:                                              // 키보드 입력값이 방향키 왼쪽이면
                if (GetAround(nx - 1, ny) == EMPTY) {               // 왼쪽이면서 , 왼쪽한칸이 빈공간이면
                    PrintBrick(FALSE);                              // 공백을 출력한다
                    nx--;                                           // nx좌표를 왼쪽으로 --
                    PrintBrick(TRUE);                               // 블럭을 출력한다
                }
                break;
            case RIGHT:                                             // 키보드 입력값이 방향키 오른쪽이면
                if (GetAround(nx + 1, ny) == EMPTY) {               // 오른쪽이면서, 오른쪽한칸이 빈공간이면
                    PrintBrick(FALSE);                              // 공백을 출력한다
                    nx++;                                           // nx좌표를 오른쪽으로 ++
                    PrintBrick(TRUE);                               // 블럭을 출력한다
                }
                break;
            case UP:                                                // 키보드 입력값이 방향키 위쪽이면
                PrintBrick(FALSE);                                  // 공백을 출력한다
                t = brick[0];                                       // 0번 블럭을 t에 저장
                brick[0] = brick[1];                                // 1번 블럭을 0번 블럭에 저장(위치 옮김)
                brick[1] = brick[2];                                // 2번 블럭을 1번 블럭에 저장(위치 옮김)
                brick[2] = t;                                       // 0번 블럭을 2번 블럭에 저장(위치 옮김)
                PrintBrick(TRUE);                                   // 블럭을 출력한다
                break;
            case DOWN:                                              // 키보드 입력값이 방향키 아래쪽이면
                if (MoveDown()) {                                   // 한칸씩 내린다
                    return TRUE;                                    // 참 값을 반환한다
                }
                break;
            case PGDN:                                              // 키보드 입력값이 pgdn이면
                if (level > 2) {                                    // 현재 레벨이 3이상이면
                    level--;                                        // 레벨을 감소한다
                    PrintInfo();                                    // 게임정보 화면을 출력
                }
                break;
            case PGUP:                                              // 키보드 입력값이 pgup이면
                if (level < 10) {                                   // 현재 레벨이 9이하이면
                    level++;                                        // 레벨을 증가한다
                    PrintInfo();                                    // 게임정보 화면을 출력
                }
                break;
            }
        }
        else {                                                      // 0xE0도 아니고 0도 아니면
            switch (tolower(ch)) {                                  // ch를 소문자로 변환한다, p값을 받을려고
            case ' ':                                               // 공백이라면
                while (MoveDown() == FALSE) { ; }                   // 한칸씩 내리는게 거짓이라면 루프 돌려서 참이되면
                return TRUE;                                        // 참값을 반환한다
            case ESC:                                               // 키보드 입력값이 esc라면
                exit(0);                                            // 강제종료
            case 'p':                                               // 키보드 입력값이 p라면
                clrscr();                                           // 클리어
                gotoxy(15, 10);                                     // x15 y10으로 가서
                puts("Tetris 잠시 중지. 다시 시작하려면 아무 키나 누르세요.");     // 출력
                getch();                                                        // 키를 입력받으면
                clrscr();                                                       // 클리어
                DrawScreen();                                                   // 다시 게임을 그린다
                PrintBrick(TRUE);                                               // 블럭을 출력한다
                break;
            }
        }
    }
    return FALSE;
}
// 벽돌 출력
void PrintBrick(BOOL Show)                              // show에 저장된 참, 거짓 값을 받아온다
{
    int i;

    for (i = 0; i < 3; i++) {
        gotoxy(BX + nx * 2, BY + ny + i);               // 벽돌위치, i는 벽돌이 3개니까
        puts(arTile[Show ? brick[i] : EMPTY]);          // show:true? false?값을 받아서 벽돌 / 아니면 빈칸
    }
}
// 주위에 벽돌이 있는지 체크
int GetAround(int x, int y)
{
    int i, k = EMPTY;                                   // i, k는 0번배열 값을 저장한다

    for (i = 0; i < 3; i++) {
        k = max(k, board[x][y + i]);                    // 0과 보드에 있는 x,y좌표의 값을 비교해서 큰값을 k에 저장
    }
    return k;                                           // k를 반환
}
// 밑으로 한칸씩 내려옴
BOOL MoveDown()
{
    if (GetAround(nx, ny + 1) != EMPTY) {               // k를 받아와서 공백이아니면
        TestFull();                                     // 움직일 수 있는지 판별하는 함수호출
        return TRUE;                                    // 참값을 반환
    }
    PrintBrick(FALSE);                                  // 공백을 출력
    ny++;                                               // 블럭의 y좌표를 아래로 한칸
    PrintBrick(TRUE);                                   // 블럭을 출력
    return FALSE;                                       // 거짓값을 반환
}

void TestFull()
{
    int i, x, y;
    int t, ty;
    BOOL Remove;
    static int arScoreInc[] = { 0,1,3,7,15,30,100,500 };                // 획득 점수배열
    int count = 0;
    BOOL Mark[BW + 2][BH + 2];

    // 배열에 기록
    for (i = 0; i < 3; i++) {
        board[nx][ny + i] = brick[i];                                   // 블럭i번째를 보드배열에 좌표기록
    }

    for (;;) {                                                          // 무한루프
        // 연속 무늬 점검
        memset(Mark, 0, sizeof(Mark));                                  // mark 0번부터 mark배열의 크기만큼 0으로 값을 채운다
        Remove = FALSE;                                                 // remove에 거짓값을 저장
        for (y = 1; y < BH + 1; y++) {                                   
            for (x = 1; x < BW + 1; x++) {
                t = board[x][y];                                        // x,y의 좌표값을 t에 저장
                if (t == EMPTY) continue;                               // t가 빈공간이면 for문을 다시 시작

                // 수평
                if (board[x - 1][y] == t && board[x + 1][y] == t) {     // x,y좌표의 t값과 왼쪽, 오른쪽에 있는 t값과 같다면
                    for (i = -1; i <= 1; i++) Mark[x + i][y] = TRUE;    // x좌표의 -1부터 1까지는 참
                    Remove = TRUE;                                      // 참값을 remove에 저장
                }
                // 수직
                if (board[x][y - 1] == t && board[x][y + 1] == t) {     // x,y좌표의 t값이 위, 아래에 있는 t값과 같다면
                    for (i = -1; i <= 1; i++) Mark[x][y + i] = TRUE;    // y좌표의 -1부터 1까지는 참
                    Remove = TRUE;                                      // 참값을 remove에 저장
                }
                // 우하향
                if (board[x - 1][y - 1] == t && board[x + 1][y + 1] == t) { // x,y좌표의 t값이 왼쪽위, 오른쪽아래와 t값이 같다면
                    for (i = -1; i <= 1; i++) Mark[x + i][y + i] = TRUE;    // x,y좌표의 -1부터 1까지는 참
                    Remove = TRUE;                                          // 참값을 remove에 저장
                }
                // 좌하향
                if (board[x + 1][y - 1] == t && board[x - 1][y + 1] == t) { // x,y좌표의 t값이 오른쪽위, 왼쪽아래와 t값이 같다면
                    for (i = -1; i <= 1; i++) Mark[x - i][y + i] = TRUE;    // x,y좌표의 -1부터 1까지는 참
                    Remove = TRUE;                                          // 참값을 remove에 저장
                }
            }
        }

        if (Remove == FALSE) return;                                        // t가 공백이라서 for문을 빠져 나왔다면 그대로 리턴

        // 제거 애니메이션
        // 깜빡임
        for (i = 0; i < 6; i++) {
            for (y = 1; y < BH + 1; y++) {
                for (x = 1; x < BW + 1; x++) {
                    if (board[x][y] != EMPTY && Mark[x][y] == TRUE) {       // x,y좌표에 공백이아니면서 mark[x,y]가 참: 즉, 근처에서 짝을 맞췄을때
                        gotoxy(BX + x * 2, BY + y);                         // 최초 생성좌표로 간다
                        puts(arTile[i % 2 ? EMPTY : board[x][y]]);          // 모르겠다. i%2 = 0이면 공백, x,y
                    }
                }
            }
            delay(150);
        }

        // 무늬 삭제하면 한칸씩내려온다.
        for (y = 1; y < BH + 1; y++) {                                      
            for (x = 1; x < BW + 1; x++) {                                  
                if (board[x][y] != EMPTY && Mark[x][y] == TRUE) {           // x,y좌표에 공백이아니면서 mark[x,y]가 참: 즉, 근처에서 짝을 맞췄을때
                    for (ty = y; ty > 1; ty--) {                            // 3개 블럭의 밑단부터 첫번째 블럭까지
                        board[x][ty] = board[x][ty - 1];                    // 위에 블럭의 좌표값을 밑에 블럭에 저장
                    }
                    board[x][1] = EMPTY;                                    // 윗단을 블럭배열 0번으로 채운다
                    count++;                                                // 삭제된 블럭 개수 카운팅
                }
            }
        }
        // 연속된 무늬 삭제 후 다시 그림
        DrawBoard();
        score += arScoreInc[min(count / 3, 7)];                             // 3개를 없앴으면 점수배열 0번 점수 추가
        PrintInfo();                                                        // 작은 점수를 점수카운팅에 추가
    }
}
// 옆에 게임 정보창 및 다음 벽돌
void DrawNext()
{
    int x, y, i;
    // 옆 게임창 벽
    for (x = 50; x <= 70; x += 2) {
        for (y = 12; y <= 18; y++) {
            gotoxy(x, y);
            puts(arTile[(x == 50 || x == 70 || y == 12 || y == 18) ? WALL : EMPTY]);
        }
    }

    // 다음 벽돌
    for (i = 0; i < 3; i++) {
        gotoxy(60, 14 + i);
        puts(arTile[nbrick[i]]);
    }
}

// 게임화면 오른쪽 정보칸
void PrintInfo()
{
    gotoxy(50, 9); printf("난이도 : %d  ", level);
    gotoxy(50, 10); printf("점수 : %d     ", score);
    gotoxy(50, 11); printf("벽돌 : %d 개  ", bricknum);
}
// 새로운 벽돌을 만드는데 level만큼의 벽돌 종류 중에 랜덤하게 만듬
// 3개의 벽돌이 모두 같으면 다시 만듬
void MakeNewBrick()
{
    int i;

    do {
        for (i = 0; i < 3; i++) {
            nbrick[i] = random(level) + 1;      // 1~6까지 중 아무거나
        }
    } while (nbrick[0] == nbrick[1] && nbrick[1] == nbrick[2] && nbrick[0] == nbrick[2]);   // 같은문자 3개는 다시돌린다.
}

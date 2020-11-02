#include "turboc.h"
#include <iostream>
using namespace std;

// keyboard �Է�
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

// ���̵� ���� �� ����Ű
#define PGUP 73
#define PGDN 81
#define ESC 27

// ���� ������ġ
#define BX 5
#define BY 1

// ���� ��ũ��
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
    EMPTY,             // ���� �ƹ��͵� �����ȵ������� ó�� ���ڴ� 0
    B1, B2,            // ���� ���ں��ʹ� +1�� �����ؼ� ���� �����صд�.
    B3, B4, 
    B5, B6, 
    B7, B8, 
    B9, B10, 
    WALL };

char* arTile[] = { ". ","��",
"��","��","��","��","��","��",
"��","��","��","��" };

int board[BW + 2][BH + 2];
int nx, ny;         // ���� ���� x,y ��ǥ
int brick[3];       // ��
int nbrick[3];      // ���Ƿ� ���� ���ò�
int score;          // ����
int bricknum;       // ������ ������
int level;          // ���̵�

void main()
{
    int nFrame, nStay;
    int x, y;

    setcursortype(NOCURSOR);    // Ŀ�� ����
    randomize();                // ���� ����
    level = 6;                  // ���� ����

    for (; ;) {
        clrscr();               // ȭ�� �ʱ�ȭ
        // ���� ����� ���� -> ���� �ʱ�ȭ
        for (x = 0; x < BW + 2; x++) {          // 11����
            for (y = 0; y < BH + 2; y++) {      // 21����
                board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;  // x,y�� �����̰ų� ���̸� 11, �ƴϸ� 0
            }
        }
        DrawScreen();
        nFrame = 20;
        score = 0;
        bricknum = 0;
        //ó�� ������ ����
        MakeNewBrick();
        for (; ;) {
            bricknum++;
            // nbrick�� make�� �ϹǷ�  brick(����)�� ��������
            memcpy(brick, nbrick, sizeof(brick));                   // memcpy = �迭���� 2��° -> 1��°, ũ�⸸ŭ 
            // ������ ������ ���� �����
            MakeNewBrick();                                         // ��������
            // main ȭ�� ���� �ִ� ȭ�� �׸���
            DrawNext();                                             // ���� ������, �����׵θ� ����
            // ���� ������ġ
            nx = BW / 2;                                            // ������ ��       
            ny = 3;
            // ���� �������� ���� ��� �׷��ֱ�
            PrintBrick(TRUE);
            // ������ġ���� ���� �� ������ ���� ����
            if (GetAround(nx, ny) != EMPTY) break;

            nStay = nFrame;
            for (; ;) {
                //gotoxy(0, 0);
                //printf("stay %2d frame %2d brick %2d", nStay, nFrame, bricknum); delay(100);
                // stay�� ��� �پ� ��ٰ� frame(�����ð�)�� �������� ��ĭ ������
                if (--nStay == 0) {
                    nStay = nFrame;
                    if (MoveDown()) break; // ���� õõ�� ������
                }
                if (ProcessKey()) break; // �÷��̾� Ű �Է�
                delay(1000 / 20); // Ű �Է��� �ʹ� ������ �ʰ� ������
            }

            // ������ 10�� ������ ������ frame�� 1�� �پ�
            // ������ �ӹ��� �ð��� �پ�� (���̵� ����)
            if (bricknum % 10 == 0 && nFrame > 5) {
                nFrame--;
            }
        }
        clrscr();
        gotoxy(30, 12); puts("G A M E  O V E R");
        gotoxy(25, 14); puts("�ٽ� �����Ϸ��� Y�� ��������");
        if (tolower(getch()) != 'y') break;
    }
    setcursortype(NORMALCURSOR);
}

// ��ũ�� �׸���
void DrawScreen()
{
    int x, y;

    // ���� ���� ��ũ��
    for (x = 0; x < BW + 2; x++) {              // 11����
        for (y = 0; y < BH + 2; y++) {          // 21����
            gotoxy(BX + x * 2, BY + y);         // ��ü ��ũ���� ���鼭, x�� Ư�����ڸ� �ޱ⶧����
            puts(arTile[board[x][y]]);          // �ش��ϴ� arTile�迭 �ȿ� ���ڸ� ���
        }
    }

    gotoxy(50, 3); puts("Hexa Ver 1.0");
    gotoxy(50, 5); puts("�¿�:�̵�, ��:ȸ��, �Ʒ�:����");
    gotoxy(50, 6); puts("����:���� ����, ESC:����");
    gotoxy(50, 7); puts("P:����,PgUp,PgDn:���̵� ����");
    DrawNext();
    PrintInfo();
}
// board ��ü �׸���
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
// Ű���� �Է� ó��
BOOL ProcessKey()
{
    int ch;
    int t;

    if (kbhit()) {
        ch = getch();                                               // getch�Լ��� 1byte�� ���� �� �ִ� : �ƽ�Ű�ڵ� ���� �ް�
        if (ch == 0xE0 || ch == 0) {                                // Ȯ��Ű(����Ű,���Ű)�� �Է¹޾Ҵٸ� 2byte
            ch = getch();                                           // getch�� �ѹ� �� �Է¹޾Ƽ� ���� �̾Ƴ���
            switch (ch) {
            case LEFT:                                              // Ű���� �Է°��� ����Ű �����̸�
                if (GetAround(nx - 1, ny) == EMPTY) {               // �����̸鼭 , ������ĭ�� ������̸�
                    PrintBrick(FALSE);                              // ������ ����Ѵ�
                    nx--;                                           // nx��ǥ�� �������� --
                    PrintBrick(TRUE);                               // ���� ����Ѵ�
                }
                break;
            case RIGHT:                                             // Ű���� �Է°��� ����Ű �������̸�
                if (GetAround(nx + 1, ny) == EMPTY) {               // �������̸鼭, ��������ĭ�� ������̸�
                    PrintBrick(FALSE);                              // ������ ����Ѵ�
                    nx++;                                           // nx��ǥ�� ���������� ++
                    PrintBrick(TRUE);                               // ���� ����Ѵ�
                }
                break;
            case UP:                                                // Ű���� �Է°��� ����Ű �����̸�
                PrintBrick(FALSE);                                  // ������ ����Ѵ�
                t = brick[0];                                       // 0�� ���� t�� ����
                brick[0] = brick[1];                                // 1�� ���� 0�� ���� ����(��ġ �ű�)
                brick[1] = brick[2];                                // 2�� ���� 1�� ���� ����(��ġ �ű�)
                brick[2] = t;                                       // 0�� ���� 2�� ���� ����(��ġ �ű�)
                PrintBrick(TRUE);                                   // ���� ����Ѵ�
                break;
            case DOWN:                                              // Ű���� �Է°��� ����Ű �Ʒ����̸�
                if (MoveDown()) {                                   // ��ĭ�� ������
                    return TRUE;                                    // �� ���� ��ȯ�Ѵ�
                }
                break;
            case PGDN:                                              // Ű���� �Է°��� pgdn�̸�
                if (level > 2) {                                    // ���� ������ 3�̻��̸�
                    level--;                                        // ������ �����Ѵ�
                    PrintInfo();                                    // �������� ȭ���� ���
                }
                break;
            case PGUP:                                              // Ű���� �Է°��� pgup�̸�
                if (level < 10) {                                   // ���� ������ 9�����̸�
                    level++;                                        // ������ �����Ѵ�
                    PrintInfo();                                    // �������� ȭ���� ���
                }
                break;
            }
        }
        else {                                                      // 0xE0�� �ƴϰ� 0�� �ƴϸ�
            switch (tolower(ch)) {                                  // ch�� �ҹ��ڷ� ��ȯ�Ѵ�, p���� ��������
            case ' ':                                               // �����̶��
                while (MoveDown() == FALSE) { ; }                   // ��ĭ�� �����°� �����̶�� ���� ������ ���̵Ǹ�
                return TRUE;                                        // ������ ��ȯ�Ѵ�
            case ESC:                                               // Ű���� �Է°��� esc���
                exit(0);                                            // ��������
            case 'p':                                               // Ű���� �Է°��� p���
                clrscr();                                           // Ŭ����
                gotoxy(15, 10);                                     // x15 y10���� ����
                puts("Tetris ��� ����. �ٽ� �����Ϸ��� �ƹ� Ű�� ��������.");     // ���
                getch();                                                        // Ű�� �Է¹�����
                clrscr();                                                       // Ŭ����
                DrawScreen();                                                   // �ٽ� ������ �׸���
                PrintBrick(TRUE);                                               // ���� ����Ѵ�
                break;
            }
        }
    }
    return FALSE;
}
// ���� ���
void PrintBrick(BOOL Show)                              // show�� ����� ��, ���� ���� �޾ƿ´�
{
    int i;

    for (i = 0; i < 3; i++) {
        gotoxy(BX + nx * 2, BY + ny + i);               // ������ġ, i�� ������ 3���ϱ�
        puts(arTile[Show ? brick[i] : EMPTY]);          // show:true? false?���� �޾Ƽ� ���� / �ƴϸ� ��ĭ
    }
}
// ������ ������ �ִ��� üũ
int GetAround(int x, int y)
{
    int i, k = EMPTY;                                   // i, k�� 0���迭 ���� �����Ѵ�

    for (i = 0; i < 3; i++) {
        k = max(k, board[x][y + i]);                    // 0�� ���忡 �ִ� x,y��ǥ�� ���� ���ؼ� ū���� k�� ����
    }
    return k;                                           // k�� ��ȯ
}
// ������ ��ĭ�� ������
BOOL MoveDown()
{
    if (GetAround(nx, ny + 1) != EMPTY) {               // k�� �޾ƿͼ� �����̾ƴϸ�
        TestFull();                                     // ������ �� �ִ��� �Ǻ��ϴ� �Լ�ȣ��
        return TRUE;                                    // ������ ��ȯ
    }
    PrintBrick(FALSE);                                  // ������ ���
    ny++;                                               // ���� y��ǥ�� �Ʒ��� ��ĭ
    PrintBrick(TRUE);                                   // ���� ���
    return FALSE;                                       // �������� ��ȯ
}

void TestFull()
{
    int i, x, y;
    int t, ty;
    BOOL Remove;
    static int arScoreInc[] = { 0,1,3,7,15,30,100,500 };                // ȹ�� �����迭
    int count = 0;
    BOOL Mark[BW + 2][BH + 2];

    // �迭�� ���
    for (i = 0; i < 3; i++) {
        board[nx][ny + i] = brick[i];                                   // ��i��°�� ����迭�� ��ǥ���
    }

    for (;;) {                                                          // ���ѷ���
        // ���� ���� ����
        memset(Mark, 0, sizeof(Mark));                                  // mark 0������ mark�迭�� ũ�⸸ŭ 0���� ���� ä���
        Remove = FALSE;                                                 // remove�� �������� ����
        for (y = 1; y < BH + 1; y++) {                                   
            for (x = 1; x < BW + 1; x++) {
                t = board[x][y];                                        // x,y�� ��ǥ���� t�� ����
                if (t == EMPTY) continue;                               // t�� ������̸� for���� �ٽ� ����

                // ����
                if (board[x - 1][y] == t && board[x + 1][y] == t) {     // x,y��ǥ�� t���� ����, �����ʿ� �ִ� t���� ���ٸ�
                    for (i = -1; i <= 1; i++) Mark[x + i][y] = TRUE;    // x��ǥ�� -1���� 1������ ��
                    Remove = TRUE;                                      // ������ remove�� ����
                }
                // ����
                if (board[x][y - 1] == t && board[x][y + 1] == t) {     // x,y��ǥ�� t���� ��, �Ʒ��� �ִ� t���� ���ٸ�
                    for (i = -1; i <= 1; i++) Mark[x][y + i] = TRUE;    // y��ǥ�� -1���� 1������ ��
                    Remove = TRUE;                                      // ������ remove�� ����
                }
                // ������
                if (board[x - 1][y - 1] == t && board[x + 1][y + 1] == t) { // x,y��ǥ�� t���� ������, �����ʾƷ��� t���� ���ٸ�
                    for (i = -1; i <= 1; i++) Mark[x + i][y + i] = TRUE;    // x,y��ǥ�� -1���� 1������ ��
                    Remove = TRUE;                                          // ������ remove�� ����
                }
                // ������
                if (board[x + 1][y - 1] == t && board[x - 1][y + 1] == t) { // x,y��ǥ�� t���� ��������, ���ʾƷ��� t���� ���ٸ�
                    for (i = -1; i <= 1; i++) Mark[x - i][y + i] = TRUE;    // x,y��ǥ�� -1���� 1������ ��
                    Remove = TRUE;                                          // ������ remove�� ����
                }
            }
        }

        if (Remove == FALSE) return;                                        // t�� �����̶� for���� ���� ���Դٸ� �״�� ����

        // ���� �ִϸ��̼�
        // ������
        for (i = 0; i < 6; i++) {
            for (y = 1; y < BH + 1; y++) {
                for (x = 1; x < BW + 1; x++) {
                    if (board[x][y] != EMPTY && Mark[x][y] == TRUE) {       // x,y��ǥ�� �����̾ƴϸ鼭 mark[x,y]�� ��: ��, ��ó���� ¦�� ��������
                        gotoxy(BX + x * 2, BY + y);                         // ���� ������ǥ�� ����
                        puts(arTile[i % 2 ? EMPTY : board[x][y]]);          // �𸣰ڴ�. i%2 = 0�̸� ����, x,y
                    }
                }
            }
            delay(150);
        }

        // ���� �����ϸ� ��ĭ�������´�.
        for (y = 1; y < BH + 1; y++) {                                      
            for (x = 1; x < BW + 1; x++) {                                  
                if (board[x][y] != EMPTY && Mark[x][y] == TRUE) {           // x,y��ǥ�� �����̾ƴϸ鼭 mark[x,y]�� ��: ��, ��ó���� ¦�� ��������
                    for (ty = y; ty > 1; ty--) {                            // 3�� ���� �شܺ��� ù��° ������
                        board[x][ty] = board[x][ty - 1];                    // ���� ���� ��ǥ���� �ؿ� ���� ����
                    }
                    board[x][1] = EMPTY;                                    // ������ ���迭 0������ ä���
                    count++;                                                // ������ �� ���� ī����
                }
            }
        }
        // ���ӵ� ���� ���� �� �ٽ� �׸�
        DrawBoard();
        score += arScoreInc[min(count / 3, 7)];                             // 3���� �������� �����迭 0�� ���� �߰�
        PrintInfo();                                                        // ���� ������ ����ī���ÿ� �߰�
    }
}
// ���� ���� ����â �� ���� ����
void DrawNext()
{
    int x, y, i;
    // �� ����â ��
    for (x = 50; x <= 70; x += 2) {
        for (y = 12; y <= 18; y++) {
            gotoxy(x, y);
            puts(arTile[(x == 50 || x == 70 || y == 12 || y == 18) ? WALL : EMPTY]);
        }
    }

    // ���� ����
    for (i = 0; i < 3; i++) {
        gotoxy(60, 14 + i);
        puts(arTile[nbrick[i]]);
    }
}

// ����ȭ�� ������ ����ĭ
void PrintInfo()
{
    gotoxy(50, 9); printf("���̵� : %d  ", level);
    gotoxy(50, 10); printf("���� : %d     ", score);
    gotoxy(50, 11); printf("���� : %d ��  ", bricknum);
}
// ���ο� ������ ����µ� level��ŭ�� ���� ���� �߿� �����ϰ� ����
// 3���� ������ ��� ������ �ٽ� ����
void MakeNewBrick()
{
    int i;

    do {
        for (i = 0; i < 3; i++) {
            nbrick[i] = random(level) + 1;      // 1~6���� �� �ƹ��ų�
        }
    } while (nbrick[0] == nbrick[1] && nbrick[1] == nbrick[2] && nbrick[0] == nbrick[2]);   // �������� 3���� �ٽõ�����.
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <algorithm>
#include <Windows.h>
#include <time.h>
#pragma warning (disable:4996)

FILE* out = fopen("ranking.txt","a");

double score[100];

#define WallH   22 // ��
#define WallC   22 // ��
#define EnemyCountt   1 // �� ���� ����

int mapWall[WallH][WallC] = { 0 };    // 2�� �迭 ��
const int MapWallH = 1; // �׵θ� ����� 1
const int MapWallH2 = 21; // �׵θ� ����� 2 


int ShowMap(void)
{
    system("cls");
    int iy = 19, ix = 10; // ���� ���� ��ǥ
    mapWall[iy][ix] = 9; // ����

    for (int r = 1; r < WallH; ++r) // �� : H
    {
        for (int c = 1; c < WallC; ++c) // �� : W
        {
            mapWall[MapWallH][c] = -1; // ������ ��ǥ�� -1 �ֱ�
            mapWall[MapWallH2][c] = -1; ////
        }
        mapWall[r][MapWallH] = -1; // �׵θ� ��ǥ�� -1 �ֱ�
        mapWall[r][MapWallH2] = -1; ////
    }

    for (int r = 1; r < WallH; ++r) // �� : H
    {
        for (int c = 1; c < WallC; ++c) // �� : W
        {
            printf("%s", (mapWall[r][c] == -1) ? "��" : (mapWall[r][c] == 9) ? "��" : "��"); // ���� �� ���
        }
        putchar('\n');
    }
    return 0;
}

void print_ranking(double mine) {
    FILE* in = fopen("ranking.txt", "r");
    printf("\n-----------------------------------------\n");
    int ridx = 0;
    while(1){
        fscanf(in, "%lf", &score[ridx++]);
        if (feof(in))break;
    }
    score[ridx++] = mine;
    std::sort(score, score + ridx);
    for (int i = ridx; i >= 0; i--) {
        if ((int)score[i] == 0)continue;
        printf("rank%d : %.1lf��\n", ridx - i, score[i]);
    }
    printf("\n-----------------------------------------\n");
}

int Move(void)
{
    int game_over_chek = 0; // GAME OVER üũ
    int* gmae_over_chekP; // GAME OVER CHEK ������ 
    gmae_over_chekP = &game_over_chek;
    char Game_over[20] = "GAME OVER";  // GAME OVER �� ����� ����  ����

    int iy = 19, ix = 10; // ���� ���� ��ġ

    int stratEnemyLine = 2; // ���� ���� �� ��ġ ����

    int enemy_make_chek = EnemyCountt; // ������� ���� ���� �����ϴ� ����
    int enemy_same_chek[EnemyCountt] = { 0 }; // ������� ���� �����͸� �����ϴ� 1�� �迭
    srand(time(NULL)); // rand �⺻ ���� �����ϴ� srand
    time_t ti = time(NULL); // �ð� ����

    if (ti % 10 == 0) // ���ܰ� �Ǵ� ti % 10 = 0�϶��� ó�� / Time Exception
    {
        ti += 1;
    }

    double GameTime;
    GameTime = GetTickCount(); // �÷��� �ð� üũ�� �Լ�

    ShowMap(); // ���� �� ���


    while (1)
    {
        system("cls"); // ȭ�� ����

        time_t ti_chek_0 = ti % 10; // �� ���� üũ
        time_t ti_chek_1 = 0; // ���� ���� ���� �ð��� ��� ���� / while�� �ݺ����� ���� ���� ����

        if (ti_chek_0 != 0 && ti_chek_0 != ti_chek_1) // �� �ʸ��� ��� // 0�϶��� ������ �ȵǳ� ������ if�� �ش� ��츦 �ذ���. ( Exception )
        {
            for (int i = 0; i < EnemyCountt;)
            {
                for (int ii = 0; ii < EnemyCountt;) // �����Ǵ� ��ǥ�� �ߺ��Ǿ� ���� ��������� �ʴ� ��츦 �����ϴ� for��
                {
                    int o = rand() % 20 + 1; // ���� ���� 2 ~ 20
                    if (o > 1 && o < 21) // ���� �׵θ� �ȿ��� �����ǰ� ������
                    {
                        if (enemy_same_chek[i] != o) // �ߺ� üũ, ���� �ߺ��� �� ���� �������� �ʰ� rand���� �ٽ� �ݺ��ȴ�.
                        {
                            mapWall[stratEnemyLine][o] = 2; // 2�� + o���� ���� �߰�
                            ++i; // ������ ���� count ������ �ö�. EnemyCountt�� ������ ����ŭ ���� �����Ǹ� �ݺ� ����.
                            ++ii;
                        }
                    }
                }
            }
        }

        for (int r = 1; r < WallH; ++r) // �� ��º�
        {
            for (int c = 1; c < WallC; ++c)
            {
                printf("%s", (mapWall[r][c] == 9) ? "��" : // �ش� ��ǥ�� 9�Ͻ� ������ ǥ��
                    (mapWall[r][c] == -1) ? "��" : // -1�̸� �׵θ��� ���
                    (mapWall[r][c] == 2) ? "��" : "��"); // 2�� ���� ��µǰ�, �ƴϸ� �� �������� ��µȴ�
                if (mapWall[r][c] == 11)
                {
                    *gmae_over_chekP = 1; // �ش� ��ǥ�� 11 = ������ ���� ��ġ�� ��ġ�� �浹 ó���Ѵ�. game_over_chek ���� + 1
                }
            }
            putchar('\n'); // �� 1ĭ ������
        }

        if (game_over_chek == 1) // �浹 ó���� ���� ������
        {
            for (int r = 1; r < WallH; ++r)
            {
                for (int c = 1; c < WallC; ++c)
                {
                    mapWall[r][c] = 0; // ��� �� �����
                }
            }
            printf("��� : %.1lf��\n", (GetTickCount() - GameTime) / 1000); // �÷��� �ð��� ����Ѵ�.
            fprintf(out,"%.1lf\n", (GetTickCount() - GameTime) / 1000);
            //fclose(out);
            printf("%s\n", Game_over); // ���� ���� ������ ��� 
            print_ranking((GetTickCount() - GameTime) / 1000);

            return 1; // ���ο� 1�� ��ȯ�Ͽ�, ������ �÷��� �� �й� ó�� �Ǿ����� �˸���.
        }

        if (_kbhit()) // ���� �̵�
        {
            char ch = _getch(); // ������ �ʴ� �Է�

            if (ch == '\r') // ���� Ű�� �Է� �� ���ο� 0�� ��ȯ�Ͽ� ���� ó���Ѵ�.
            {
                return 0;
            }

            if (ch == 'w' || ch == 'W') // �������� �̵�
            {
                if (mapWall[iy - 1][ix] == -1) // �̵��Ϸ��� ��ġ�� �׵θ��̸� �������� �ʴ´�.
                {
                }
                else
                {
                    mapWall[iy][ix] = 0; // �̵��ϱ� ���� ��ǥ�� ���� 0 ó���Ѵ�.
                    --iy;
                }
            }
            if (ch == 's' || ch == 'S') // �Ʒ������� �̵�
            {
                if (mapWall[iy + 1][ix] == -1)
                {
                }
                else
                {
                    mapWall[iy][ix] = 0;
                    ++iy;
                }
            }
            if (ch == 'a' || ch == 'A') // �������� �̵�
            {
                if (mapWall[iy][ix - 1] == -1)
                {
                }
                else
                {
                    mapWall[iy][ix] = 0;
                    --ix;
                }
            }
            if (ch == 'd' || ch == 'D') // ���������� �̵�
            {
                if (mapWall[iy][ix + 1] == -1)
                {
                }
                else
                {
                    mapWall[iy][ix] = 0;
                    ++ix;
                }
            }
            mapWall[iy][ix] = 9; // �̵��� ��ġ�� �ʿ� �����Ͽ� �����Ѵ�.
        }
        if (ti_chek_0 != 0 && ti_chek_0 != ti_chek_1) //  �ð� üũ
        {
            for (int r = WallH; r > MapWallH - 1; --r)
            {
                for (int c = WallC; c > MapWallH - 2; --c)
                {
                    if (mapWall[r][c] == 2) // �ش� ��ǥ�� ���̶��
                    {
                        if (mapWall[r + 1][c] == -1) // ���� �̵��Ϸ��� ��ġ�� �׵θ����
                        {
                            mapWall[r][c] = 0; // ���� �Ҹ��Ѵ�.
                        }
                        else
                        {
                            mapWall[r + 1][c] += 2; // �� 1ĭ �̵�
                            mapWall[r][c] = 0; // ���� �̵��� ������ ����
                        }
                    }
                }
            }
            ti_chek_1 = ti_chek_0; // ���� �ð��� ���� ó���Ͽ�, ���� �ݺ��ÿ� �� �����ͷ� ����Ѵ�.
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    int GameST = 0; // ������ �÷��� �� �й� �Ǿ�����, �ƴϸ� �߰��� ���� ���״����� �ľ��Ѵ�.

    while (1)
    {

        GameST = Move(); // ST������ Move�� ���� ��ȯ �޴´�. 1�̸� �÷��� �� �й�, 0�̸� ���� ����

        if (GameST == 1) // ������ �÷��� �� �й��� ���
        {
            char Key = 0;
            printf(" ��� [ 0 ]  \t\n"); // 0Ű�� �Է��ϸ� �絵�� �Ѵ�.
            scanf(" %c", &Key); // Ű �Էº�

            if (Key == '0') // 0�� �Է��ϸ� �絵��
            {

            }
            else
            {
                break; // 0 �̿��� ���̸� ����
            }
        }
        else if (GameST == 0) // ������ ���߿� ������ ������ ���
        {
            break; // ����ó���Ѵ�.
        }
    }


    printf("\t\n\t ���� ���� \n");
    return 0;
}
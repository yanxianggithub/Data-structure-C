//
// Created by Yanxiang on 2021/5/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define row 10
#define col 10
struct Point {
    int i, j, up, down, left, right;
};
int a[row][col] = {0};
static int n = 0, in, inn, out, outt;
void Edge();
void Path();
void Input();
void Random();
void Display();
void Display_o();

int main()
{
    Edge();
    Input();
    Random();
    Path();
    Display();
    Display_o();
    return 0;
}

void Edge()
{
    for (int i = 0; i < col; i++)
    {
        a[0][i] = -1;
        a[row - 1][i] = -1;
    }
    for (int i = 0; i < row; i++)
    {
        a[i][0] = -1;
        a[i][col - 1] = -1;
    }
}

void Random()
{
    int i, j;
    for (int k = 0; k < row * 4; k++)
    {
        i = rand() % row;
        j = rand() % col;
        if (a[i][j] == 0)
            a[i][j] = -1;
    }
}

void Display()
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void Display_o()
{
    int i, j;
    printf("-------------------------------\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            if(a[i][j]==0||a[i][j]==-1)
            {
                printf("   ");
            }else
            {
                printf("%3d", a[i][j]);
            }
        }
        printf("\n");
    }
}

void Input()
{
    begin:
    printf("输入起点：");
    scanf("%d%d", &in, &inn);
    if (a[in][inn] != -1)
    {
        a[in][inn] = -2;
    } else
    {
        printf("入口不合理！");
        goto begin;
    }
    printf("输入终点：");
    scanf("%d%d", &out, &outt);
    if (a[out][outt] != -1)
    {
        a[out][outt] = -3;
    } else
    {
        printf("出口不合理！");
        goto begin;
    }
}

void Path()
{
    struct Point point[30];
    int i = in, j = inn;
    int b[row][col] = {0};
    memcpy(b, a, sizeof(int) * row * col);
    goto fetch;
    while (1)
    {
        if (point[n].down == 0)
        {
            i++;
            n++;
            goto fetch;
        } else if (point[n].up == 0)
        {
            i--;
            n++;
            goto fetch;
        } else if (point[n].right == 0)
        {
            j++;
            n++;
            goto fetch;
        } else if (point[n].left == 0)
        {
            j--;
            n++;
            goto fetch;
        } else
        {
            b[point[n].i][point[n].j] = -1;
            n--;
            i = point[n].i;
            j = point[n].j;
        }
        fetch:
        {
            point[n].i = i;
            point[n].j = j;
            point[n].up = b[i - 1][j];
            point[n].down = b[i + 1][j];
            point[n].left = b[i][j - 1];
            point[n].right = b[i][j + 1];
            b[i][j] = n + 1;
        };
        if (point[n].up == -3 || point[n].down == -3 || point[n].left == -3 || point[n].right == -3)break;
    }
    printf("-------------------------------\n");
    for (int k = 0; k < col; k++)
    {
        for (int l = 0; l < row; l++)
        {
            if (b[k][l] > 1)
            {
                a[k][l] = b[k][l] - 1;
            }
        }
    }
}
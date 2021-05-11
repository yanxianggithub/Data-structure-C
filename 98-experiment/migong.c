//
// Created by Yanxiang on 2021/5/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define row 10
#define col 10
typedef struct {
    int cent,up,down,left,right;
}Point;
int a[row][col] = {0};
static int in, inn, out, outt;

void Edge();

void Display();

void Random();

void Path();

void Input();

int main()
{
    Edge();
    Input();
    Random();
    Path();
    Display();

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

void Path()
{
    int b[row][col] = {0};
    memcpy(b, a, sizeof(int) * row * col);
    int x,y;
    x=in;y=inn;
    Point point;
    point.cent=b[x][y];
    point.up=b[x][y-1];
    point.down=b[x][y+1];
    point.left=b[x-1][y];
    point.right=b[x+1][y];
    while (1)
    {
        switch (rand() %4)
        {
            case 1:if(point.up==0)
                {
                    point.cent=point.up;
                }else break;
            case 2:if(point.down==0)
                {
                    point.cent=point.down;
                } else break;
            case 3:if(point.left==0)
                {
                    point.cent=point.left;
                }else break;
            case 4:if(point.right==0)
                {
                    point.cent=point.right;
                } else break;
            default: point.cent=-1;
        }
        if(point.up==-3||point.down==-3||point.right==-3||point.left==-3) return;
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
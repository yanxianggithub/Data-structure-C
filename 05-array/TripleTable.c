#include <stdio.h>
#define MAXSIZE 10
#define DataType int
typedef struct
{
    int i, j;   /* 非零元素的行、列号 */
    DataType v; /* 非零元素的值 */
} triple;
typedef struct
{
    triple data[MAXSIZE]; /* 非零元素的三元组表 */
    int m, n, t;          /* 稀疏矩阵的行数、列数和非零元素的个数 */
} tripletable;
void Print(tripletable M);
tripletable transmatrix(tripletable a);
tripletable fasttranstri(tripletable a);
int compare(int a1, int b1, int a2, int b2);
//Status Value(tripletable M, ElemType &e, int i, int j);
//void TSMatrix_Add(TSMatrix *A, TSMatrix *B, TSMatrix *C);

int main()
{
    tripletable A,B;
    A.m = 4;
    A.n = 5;
    A.t = 5;
    A.data[1].i = 1;
    A.data[1].j = 2;
    A.data[1].v = 7;
    A.data[2].i = 1;
    A.data[2].j = 4;
    A.data[2].v = 4;
    A.data[3].i = 2;
    A.data[3].j = 1;
    A.data[3].v = 3;
    A.data[4].i = 3;
    A.data[4].j = 5;
    A.data[4].v = 1;
    A.data[5].i = 4;
    A.data[5].j = 2;
    A.data[5].v = 6;
    Print(A);
    printf("\n");

}
/*Status Value(tripletable M, ElemType &e, int i, int j)
{
    if (i < 1 || i > M.m || j < 1 || j > M.n)
        return 0;
    else
    {
        for (p = 1; p <= M.t; p++)
            if (M.data[p].i == i && M.data[p].j == j)
            {
                e = M.data[p].v;
                return 1;
            }
            else if (M.data[p].i > i || M.data[p].i == i && M.data[p].j > j)
                break;
        e = 0;
        return 1;
    }
}*/
void Print(tripletable M)
{
    int p = 1;
    for (int i = 1; i <= M.m; i++)
    {
        for (int j = 1; j <= M.n; j++)
            if (p <= M.t && M.data[p].i == i && M.data[p].j == j)
                printf("% 4d", M.data[p++].v);
            else
                printf("% 4d", 0);
        printf("\n");
    }
}
tripletable transmatrix(tripletable a)
{ /* 将稀疏矩阵a转置，结果通过函数名返回 */
    tripletable b;
    int p, q, col;
    b.m = a.n;
    b.n = a.m;
    b.t = a.t; /* 初始化 */
    if (b.t)
    { /* 把a中每一个非零元素转换到b中相应位置 */
        q = 0;
        for (col = 1; col <= a.n; col++) /* 按列号作扫描，做cols趟 */
            for (p = 0; p < a.t; p++)    /* 在数据中找列号为col的三元组 */
                if (a.data[p].j == col)
                {
                    b.data[q].i = col;         /* 新三元组的行号* /
                        b.data[q].j=a.data[p].i;     /* 新三元组的列号 */
                    b.data[q].v = a.data[p].v; /* 新三元组的值*/
                    q++;
                }
    }
    return (b);
}
tripletable fasttranstri(tripletable a)
{
    tripletable b;
    int p, q, col, k;
    int num[a.n + 1], pot[a.n + 1];
    b.m = a.n;
    b.n = a.m;
    b.t = a.t;
    if (b.t)
    {
        for (col = 1; col <= a.n; ++col)
            num[col] = 0;         /* 对数组num初始化 */
        for (k = 0; k < a.t; ++k) /* 计算a中每一列含非零元素的个数 */
            ++num[a.data[k].j];
        pot[1] = 0; /*计算a中第col列中第一个非零元素在b中的序号*/
        for (col = 2; col <= a.n; ++col)
            pot[col] = pot[col - 1] + num[col - 1];
        for (p = 0; p < a.t; ++p)
        { /* 把a中每一个非零元素插入到b中的相应位置 */
            col = a.data[p].j;
            q = pot[col];
            b.data[q].i = a.data[p].j;
            b.data[q].j = a.data[p].i;
            b.data[q].v = a.data[p].v;
            ++pot[col]; //修改为下次该列元素该存储的位置
        }
    }
    return (b);
}
int compare(int a1, int b1, int a2, int b2)
{
    if (a1 > a2)
        return (1);
    else if (a1 < a2)
        return (-1);
    else if (b1 > b2)
        return (1);
    if (b1 < b2)
        return (-1);
    else
        return (0);
}
/*
void TSMatrix_Add(TSMatrix *A, TSMatrix *B, TSMatrix *C)
{
    int pa, pb, pc, ce;
    C->mu = A->mu;
    C->nu = A->nu;
    C->tu = 0;
    pa = 1;
    pb = 1;
    pc = 0;
    while (pa <= A->tu && pb <= B->tu)
        switch (compare(A->data[pa].i, A->data[pa].j, B->data[pb].i, B->data[pb].j))
        {
        case 1:
            pc++;
            C->data[pc].i = B->data[pb].i;
            C->data[pc].j = B->data[pb].j;
            C->data[pc].e = B->data[pb].e;
            pb++;
            break;
        case 0:
            ce = A->data[pa].e + B->data[pb].e;
            if (ce)
            {
                pc++;
                C->data[pc].i = A->data[pa].i;
                C->data[pc].j = A->data[pa].j;
                C->data[pc].e = ce;
            }
            pa++;
            pb++;
            break;
        case -1:
            pc++;
            C->data[pc].i = A->data[pa].i;
            C->data[pc].j = A->data[pa].j;
            C->data[pc].e = A->data[pa].e;
            pa++;
            break;
        }
    while (pa <= A->tu)
    {
        pc++;
        C->data[pc].i = A->data[pa].i;
        C->data[pc].j = A->data[pa].j;
        C->data[pc].e = A->data[pa].e;
        pa++;
    }
    while (pb <= B->tu)
    {
        pc++;
        C->data[pc].i = B->data[pb].i;
        C->data[pc].j = B->data[pb].j;
        C->data[pc].e = B->data[pb].e;
        pb++;
    }
    C->tu = pc;
} // TSMatrix_Add
*/
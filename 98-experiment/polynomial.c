//
// Created by Administrator on 2021/4/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DataTypepi double
#define DataTypepn int
typedef struct node
{
    DataTypepi pi;
    DataTypepn pn;
    struct node *next;
} LNode, *SingleLinkList;

SingleLinkList Creat_SingleLinkList(void)
{
    SingleLinkList H = (SingleLinkList)malloc(sizeof(LNode));
    if (H)
        H->next = NULL;
    return H;
}

void Destroy_SingleLinkList(SingleLinkList H)
{
    SingleLinkList p = H, q;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    H = NULL;
}

int Length_SingleLinkList(SingleLinkList H)
{
    SingleLinkList p = H;
    int count = -1;
    while (p)
    {
        p = p->next;
        count++;
    }
    return (count);
}

SingleLinkList Locate_SingleLinkList_Pos(SingleLinkList H, int i)
{
    int j = 0;
    SingleLinkList p = H;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (j != i || !p)
    {
        printf("参数 i 错或单链表不存在");
        return (NULL);
    }
    return (p);
}

SingleLinkList Locate_SingleLinkList_Value(SingleLinkList H, DataTypepn pn)
{
    SingleLinkList p = H->next, q;
    while (p && p->pn != pn)
        p = p->next;
    return (p);
}

int Insert_SingleLinkList(SingleLinkList H, int i, DataTypepi pi, DataTypepn pn)
{
    SingleLinkList q, p = Locate_SingleLinkList_Pos(H, i - 1);
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    q = (SingleLinkList)malloc(sizeof(LNode));
    if (!q)
    {
        printf("申请空间失败");
        return (0);
    }

    q->pi = pi;
    q->pn = pn;
    q->next = p->next;
    p->next = q;

    return 1;
}

int Delete_SingleLinkList(SingleLinkList H, int i)
{
    SingleLinkList p, q;
    if (H == NULL || H->next == NULL)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_SingleLinkList_Pos(H, i - 1);
    if (p == NULL || p->next == NULL)
    {
        printf("参数 i 错");
        return (0);
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return (1);
}

/*
SingleLinkList Merge(SingleLinkList A, SingleLinkList B)
{
    int ii = 1;
    SingleLinkList p = B->next;
    SingleLinkList q = Creat_SingleLinkList();
    while (p)
    {
        if (!Locate_SingleLinkList_Value(A, p->pn))
        {
            Insert_SingleLinkList(q, ii, p->pi, p->pn);
            ii++;
        } else if (Locate_SingleLinkList_Value(A, p->pn))
        {
            double pin = Locate_SingleLinkList_Value(A, p->pn)->pi + p->pi;
            if(pin)
            {
                Insert_SingleLinkList(q, ii, pin, p->pn);
                ii++;
            }else
            {
                Delete_SingleLinkList(p,ii);
            }
        }
        p = p->next;
    }
    return q;
}
 */
SingleLinkList Add(SingleLinkList A, SingleLinkList B)
{
    SingleLinkList C = Creat_SingleLinkList();
    SingleLinkList p1 = A->next, p2 = B->next, p3 = C;
    int ii = 1;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pn < p2->pn)
        {
            Insert_SingleLinkList(C, ii, p1->pi, p1->pn);
            p1 = p1->next;
            ii++;
        }
        else if (p1->pn > p2->pn)
        {
            Insert_SingleLinkList(C, ii, p2->pi, p2->pn);
            p2 = p2->next;
            ii++;
        }
        else
        {
            if (p1->pi + p2->pi)
            {
                Insert_SingleLinkList(C, ii, p1->pi + p2->pi, p1->pn);
                ii++;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p3->next)
        p3 = p3->next;
    p1 == NULL ? (p3->next = p2) : (p3->next = p1);
    return C;
}

double Sum_polynomial(SingleLinkList C, double x)
{
    double sum = 0;
    while (C->next)
    {
        sum += (C->next->pi) * pow(x, C->next->pn);
        C = C->next;
    }
    return sum;
}

void Display_SingleLinkList(SingleLinkList A)
{
    while (A->next != NULL)
    {
        printf("%.fX^%d", A->next->pi, A->next->pn);
        if (A->next->next)
        {
            printf(A->next->next->pi > 0 ? " +" :" ");
        }
        else
        {
            printf("\n");
        }
        A = A->next;
    }
}

int main()
{
    SingleLinkList C;
    SingleLinkList A = Creat_SingleLinkList();
    SingleLinkList B = Creat_SingleLinkList();
    Insert_SingleLinkList(A, 1, 1, 1);
    Insert_SingleLinkList(A, 2, 4, 2);
    Insert_SingleLinkList(A, 3, 1, 4);
    Insert_SingleLinkList(A, 4, 6, 5);
    Insert_SingleLinkList(A, 5, 1, 6);
    Insert_SingleLinkList(A, 6, 1, 7);
    Insert_SingleLinkList(B, 1, 2, 1);
    Insert_SingleLinkList(B, 2, 4, 2);
    Insert_SingleLinkList(B, 3, 1, 3);
    Insert_SingleLinkList(B, 4, -4, 4);
    Insert_SingleLinkList(B, 5, 1, 5);
    Insert_SingleLinkList(B, 6, 1, 6);
    Insert_SingleLinkList(B, 7, 1, 7);
    Insert_SingleLinkList(B, 8, 2, 8);
    printf("A:");
    Display_SingleLinkList(A);
    printf("B:");
    Display_SingleLinkList(B);
    C = Add(A, B);
    printf("Add:");
    Display_SingleLinkList(C);
    printf("输入x的值:");
    double x;
    scanf("%lf", &x);
    printf("计算结果:%.2f\n", Sum_polynomial(C, x));
    return 0;
}
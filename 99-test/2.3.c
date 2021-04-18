//
// Created by asus on 2021/4/14.
//
#include <stdio.h>
#include <stdlib.h>

#define DataType int

typedef struct node {
    DataType data;
    struct node *next;
} LNode, *SingleLinkList;

SingleLinkList Creat_SingleLinkList(void)
{
    SingleLinkList H;
    H = (SingleLinkList) malloc(sizeof(LNode));
    if (H)
        H->next = NULL;
    return H;
}

SingleLinkList Locate_SingleLinkList_Pos(SingleLinkList H, DataType i)
{
    SingleLinkList p;
    int j = 0;
    p = H;
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
SingleLinkList Locate_SingleLinkList_Value(SingleLinkList H, DataType x)
{
    SingleLinkList p = H->next;
    while (p && p->data != x)
        p = p->next;
    return (p);
}

int Insert_SingleLinkList(SingleLinkList H, int i, DataType x)
{
    SingleLinkList p, q;
    p = Locate_SingleLinkList_Pos(H, i - 1);
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    q = (SingleLinkList) malloc(sizeof(LNode));
    if (!q)
    {
        printf("申请空间失败");
        return (0);
    }
    q->data = x;
    q->next = p->next;
    p->next = q;
    return 1;
}

void Display_LinkList(SingleLinkList LL)
{
    while (LL->next != NULL)
    {
        printf("%d\n", (*LL).next->data);
        LL = LL->next;
    }
}

SingleLinkList Merge(SingleLinkList A,SingleLinkList B)
{
    DataType x;
    SingleLinkList p;
    p=B->next;
    while (p)
    {
        x=p->data;
        if(!Locate_SingleLinkList_Value(A,x))
            Insert_SingleLinkList(A,1,x);
        p=p->next;
    }
    return A;
}

SingleLinkList sortLinkList(SingleLinkList L)
{
    SingleLinkList p, q, min;
    int temp;
    for (p = L->next; p->next != NULL; p = p->next)
    {
        min = p;
        for (q = p->next; q; q = q->next)
        {
            if (q->data < min->data)
            {
                min = q;
            }
        }
        if (min != p)
        {
            temp = p->data;
            p->data = min->data;
            min->data = temp;
        }
    }
    return L;
}

int main()
{
    SingleLinkList A, B;
    A = Creat_SingleLinkList();
    B = Creat_SingleLinkList();
    Insert_SingleLinkList(A, 1, 1);
    Insert_SingleLinkList(B, 1, 3);
    Insert_SingleLinkList(A, 2, 2);
    Insert_SingleLinkList(B, 2, 4);
    Insert_SingleLinkList(A, 3, 4);
    Insert_SingleLinkList(B, 3, 5);
    Insert_SingleLinkList(A, 4, 5);
    Insert_SingleLinkList(B, 4, 7);
    Insert_SingleLinkList(A, 5, 6);
    Insert_SingleLinkList(B, 5, 8);
    sortLinkList(Merge(A,B));
    Display_LinkList(A);
    return 0;
}

//
// Created by asus on 2021/4/12.
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

void Display_SingleLinkList(SingleLinkList LL)
{
    while (LL->next != NULL)
    {
        printf("%d\n", (*LL).next->data);
        LL = LL->next;
    }
}

void DeleteAB(SingleLinkList S, int A, int B)
{
    SingleLinkList p = S, q;
    while (p->next)
    {

        if (p->next->data >= A && p->next->data <= B)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }else
        p = p->next;
    }
}


int main()
{
    SingleLinkList S = Creat_SingleLinkList();
    for (int i = 1; i < 11; ++i)
    {
        Insert_SingleLinkList(S, i, i);
    }
    DeleteAB(S, 4, 6);
    Display_SingleLinkList(S);
    return 0;
}
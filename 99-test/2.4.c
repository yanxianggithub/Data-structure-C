//
// Created by asus on 2021/4/14.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} LNode, *SingleLinkList;

SingleLinkList Creat_LinkList(void)
{
    SingleLinkList H;
    H = (SingleLinkList)malloc(sizeof(LNode));
    if (H)
        H->next = NULL;
    return H;
}

SingleLinkList Locate_LinkListi(SingleLinkList H, int i)
{
    SingleLinkList p;
    int j;
    p = H;
    j = 0;
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

int Insert_LinkList(SingleLinkList H, int i, int x)
{
    SingleLinkList p, q;
    p = Locate_LinkListi(H, i - 1);
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
    q->data = x;
    q->next = p->next;
    p->next = q;
    return 1;
}

int Del_LinkList(SingleLinkList H, int i)
{
    SingleLinkList p, q;
    if (H == NULL || H->next == NULL)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_LinkListi(H, i - 1);
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

void Display_LinkList(SingleLinkList LL)
{
    while (LL->next != NULL)
    {
        printf("%d\n", (*LL).next->data);
        LL = LL->next;
    }
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
    SingleLinkList LL;
    LL = Creat_LinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_LinkList(LL, i, 11 - i);
    }
    Display_LinkList(LL);
    sortLinkList(LL);
    Display_LinkList(LL);

    return 0;
}



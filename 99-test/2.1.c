//
// Created by asus on 2021/4/11.
//
#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct node
{
    DataType data;
    struct node *next;
} LNode, *SingleLinkList;

SingleLinkList Creat_SingleLinkList(void)
{
    SingleLinkList H;
    H = (SingleLinkList)malloc(sizeof(LNode));
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
void Display_SingleLinkList(SingleLinkList LL)
{
    while (LL->next != NULL)
    {
        printf("%d\n", (*LL).next->data);
        LL = LL->next;
    }
}
void DeleteRe(SingleLinkList S)
{
    SingleLinkList p,q;
    p=S->next;
    while (p->next!=NULL)
    {
        q=p->next;
        while (q->next!=NULL)
        {
            if (p->data==q->data)
            {
                p->next=p->next->next;
            }
            else
            {
                q=q->next;
            }
        }
        p=p->next;
    }
}

int main()
{
    SingleLinkList S;
    S=Creat_SingleLinkList();
    Insert_SingleLinkList(S,1,1);
    Insert_SingleLinkList(S,2,2);
    Insert_SingleLinkList(S,3,2);
    Insert_SingleLinkList(S,4,3);
    Insert_SingleLinkList(S,5,4);
    Insert_SingleLinkList(S,6,3);
    Insert_SingleLinkList(S,7,2);
    Display_SingleLinkList(S);
    printf("\n");
    DeleteRe(S);
    Display_SingleLinkList(S);
    return 0;
}
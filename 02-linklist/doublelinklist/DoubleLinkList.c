#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkList.h"

int main()
{
    DLinkList DL;
    DL = Creat_DoubleLinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_DoubleLinkList(DL, i, i);
    }                           /*双向链表赋值*/
    Display_DoubleLinkList(DL); //输出双向链表
    //Locate_DoubleLinkListi(DL, 2); //检索链表位置2元素
    //Del_DoubleLinkList(DL, 2);     //删除链表位置2元素
    //Display_DoubleLinkList(DL);
    //Destroy_DoubleLinkList(DL);

    return 0;
}

DLinkList Creat_DoubleLinkList(void)
{
    DLinkList H;
    H = (DLinkList)malloc(sizeof(DuNode));
    if (H) /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        H->next = NULL;
    H->prior = NULL;
    return H;
}

/*void Destroy_DoubleLinkList(DLinkList H)
{
    return 0;
}*/

int Length_DoubleLinkList(DLinkList H)
{
    return 0;
}

DLinkList Locate_DoubleLinkListi(DLinkList H, int i)
{
    DLinkList p;
    int j = 0;
    p = H;

    while (p && j < i)
    { /*查找第i个结点*/
        p = p->next;
        j++;
    } /*while*/
    if (j != i || !p)
    {
        printf("参数 i 错或单链表不存在");
        return (NULL);
    } /*第i个结点不存在*/
    return (p);
}

DLinkList Locate_DoubleLinkListx(DLinkList H, int x)
{
    return 0;
}

int Insert_DoubleLinkList(DLinkList H, int i, int x)
{ /*返回参数：成功标志，0不成功，1成功*/
    DLinkList p, s;
    p = Locate_DoubleLinkListi(H, i); /*找第i个结点地址*/
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    s = (DLinkList)malloc(sizeof(DuNode));
    if (!s)
    {
        printf("申请空间失败");
        return (0);
    }                    /*申请空间失败，不能插入*/
    s->prior = p->prior; /*新结点插入在第i个结点的前面*/
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return 1; /*插入成功，则返回*/
}

int Del_DoubleLinkList(DLinkList H, int i)
{ /*删除单链表H上的第i个结点;返回参数：0不成功，1成功*/
    DLinkList p;
    if (H == NULL || H->next == NULL)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_DoubleLinkListi(H, i); /*找第i个结点地址*/
    if (p == NULL || p->next == NULL)
    {
        printf("参数 i 错");
        return (0); /*第i个结点不存在*/
    }
    p->prior->next = p->next;  /*p指向第i个结点*/
    p->next->prior = p->prior; /*从链表中删除*/
    free(p);                   /*释放p*/
    return (1);
}

void Display_DoubleLinkList(DLinkList DL)
{
    while (DL->next != NULL)
    {
        printf("%d\n", (*DL).next->data);
        DL = DL->next;
    }
}

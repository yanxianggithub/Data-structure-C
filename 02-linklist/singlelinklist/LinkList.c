#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main()
{
    CircleLinkList LL;
    LL = Creat_LinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_LinkList(LL, i, i);
    }                     //插入数据
    Display_LinkList(LL); //输出链表
    Reverse_LinkList(LL); //逆置链表
    Display_LinkList(LL); //输出逆置链表
    printf("Length:");
    printf("%d  ", Length_LinkList(LL));
    Del_LinkList(LL, 2);
    printf("%d", Length_LinkList(LL));
    josephus_LinkList(LL, 3, 3);
    Destroy_LinkList(LL);

    return 0;
}
CircleLinkList Creat_LinkList(void)
{ /*创建空单链表，入口参数：无；返回值：单链表的头指针，0代表创建失败，非0表成功*/
    CircleLinkList H;
    H = (CircleLinkList)malloc(sizeof(LNode));
    if (H) /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        H->next = NULL;
    return H;
}

void Destroy_LinkList(CircleLinkList H)
{ /*入口参数：单链表头指针的地址，出口参数：无*/
    CircleLinkList p, q;
    p = H;
    while (p != NULL) /*释放单链表的所有结点*/
    {
        q = p;
        p = p->next;
        free(q);
    }         /*while */
    H = NULL; /*将头指针变为零表示单链表不存在*/
}

int Length_LinkList(CircleLinkList H)
{                   /* 求单链表表长，入口参数：单链表头指针，出口参数：表长，-1表示
       单链表不存在。*/
    CircleLinkList p = H; /* p指向头结点*/
    int count = -1; /*H带头结点所以从－1开始*/
    while (p)
    { /* p所指的是第 count + 1 个结点*/
        p = p->next;
        count++;
    } /*while */
    return (count);
}

CircleLinkList Locate_LinkListi(CircleLinkList H, int i)
{
    CircleLinkList p;
    int j;
    p = H;
    j = 0;
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

CircleLinkList Locate_LinkListx(CircleLinkList H, int x)
{ /*在单链表中查找值为x的结点，入口参数：单链表指针，检索元素,出口参数：找到后返回其指针，否则返回NULL*/
    CircleLinkList p = H->next;
    while (p && p->data != x)
        p = p->next;
    return (p);
}

int Insert_LinkList(CircleLinkList H, int i, int x)
{ /*返回参数：成功标志，0不成功，1成功*/
    CircleLinkList p, q;
    p = Locate_LinkListi(H, i - 1); /*找第i-1个结点地址*/
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    q = (CircleLinkList)malloc(sizeof(LNode));
    if (!q)
    {
        printf("申请空间失败");
        return (0);
    } /*申请空间失败，不能插入*/
    q->data = x;
    q->next = p->next; /*新结点插入在第i-1个结点的后面*/
    p->next = q;
    return 1; /*插入成功，则返回*/
}

void Reverse_LinkList(CircleLinkList H)
{
    CircleLinkList p;
    p = H->next;
    H->next = NULL;
    while (p)
    {
        CircleLinkList q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    } /*while*/
}

int Del_LinkList(CircleLinkList H, int i)
{ /*删除单链表H上的第i个结点;返回参数：0不成功，1成功*/
    CircleLinkList p, q;
    if (H == NULL || H->next == NULL)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_LinkListi(H, i - 1); /*找第i-1个结点地址，见算法2.10*/
    if (p == NULL || p->next == NULL)
    {
        printf("参数 i 错");
        return (0); /*第i个结点不存在*/
    }
    q = p->next;       /*q指向第i个结点*/
    p->next = q->next; /*从链表中删除*/
    free(q);           /*释放*s */
    return (1);
}

void Display_LinkList(CircleLinkList LL)
{
    while (LL->next != NULL)
    {
        printf("%d\n", (*LL).next->data);
        LL = LL->next;
    }
}

int josephus_LinkList(CircleLinkList josephus_Link, int s, int m)
{ /*返回值：1表示成功，0表示表中没有元素*/
    CircleLinkList p, pre;
    int count; /*p指向当前结点，pre指向其前驱结点*/
    if (!josephus_Link)
    {
        printf("表中无元素");
        return (0);
    }
    p = josephus_Link;
    for (count = 1; count < s; count++) /*查找第s个结点，用p指向第s个结点*/
        p = p->next;
    printf("out josephus number:");
    while (p != p->next)
    { /*不是最后一个元素,输出 n-1个元素个结点*/
        for (count = 1; count < m; count++)
        {
            pre = p;
            p = p->next;
        }
        printf("% d\t", p->data);
        pre->next = p->next;
        free(p);
        p = pre->next;
    }                         /*while*/
    printf("% d\t", p->data); /*输出最后一个元素个结点*/
    free(p);
    return 1;
}

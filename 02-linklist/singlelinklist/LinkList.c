#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main()
{
    LinkList LL;
    LL=Creat_LinkList();
    Insert_LinkList(LL,1,5);
    Insert_LinkList(LL,2,6);
    Insert_LinkList(LL,3,7);
    Insert_LinkList(LL,4,8);
    Display_LinkList(LL);
    return 0;
}
LinkList Creat_LinkList(void)
{ /*创建空单链表，入口参数：无；返回值：单链表的头指针，0代表创建失败，非0表成功*/
    LinkList H;
    H = (LinkList)malloc(sizeof(LNode));
    if (H) /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        H->next = NULL;
    return H;
}

void Destroy_LinkList(LinkList H)
{ /*入口参数：单链表头指针的地址，出口参数：无*/
    LinkList p, q;
    p = H;
    while (p != NULL) /*释放单链表的所有结点*/
    {
        q = p;
        p = p->next;
        free(q);
    }         /*while */
    H = NULL; /*将头指针变为零表示单链表不存在*/
}

int Length_LinkList(LinkList H)
{                   /* 求单链表表长，入口参数：单链表头指针，出口参数：表长，-1表示
       单链表不存在。*/
    LinkList p = H; /* p指向头结点*/
    int count = -1; /*H带头结点所以从－1开始*/
    while (p)
    { /* p所指的是第 count + 1 个结点*/
        p = p->next;
        count++;
    } /*while */
    return (count);
}

LinkList Locate_LinkListi(LinkList H, int i)
{
    LinkList p;
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

LinkList Locate_LinkListx(LinkList H, int x)
{ /*在单链表中查找值为x的结点，入口参数：单链表指针，检索元素,出口参数：找到后返回其指针，否则返回NULL*/
    LinkList p = H->next;
    while (p && p->data != x)
        p = p->next;
    return (p);
}

int Insert_LinkList(LinkList H, int i, int x)
{ /*返回参数：成功标志，0不成功，1成功*/
    LinkList p, q;
    p = Locate_LinkListi(H, i - 1); /*找第i-1个结点地址*/
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    q = (LinkList)malloc(sizeof(LNode));
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

int Del_LinkList(LinkList H, int i)
{ /*删除单链表H上的第i个结点;返回参数：0不成功，1成功*/
    LinkList p, q;
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

void Display_LinkList(LinkList LL)
{
    while(LL->next!=NULL)
    {
        printf("%d\n",(*LL).next->data);
        LL=LL->next;
    }
}
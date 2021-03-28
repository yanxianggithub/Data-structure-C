#include "CircleLinkList.h"

int main()
{
    CircleLinkList CL;
    CL = Creat_CircleLinkList();
    for (int i = 1; i <= 5; i++)
    {
        Insert_CircleLinkList(CL, i, i);
    }
    Display_CircleLinkList(CL, 12);
}

CircleLinkList Creat_CircleLinkList(void)
{ /*创建空循环链表，入口参数：无；返回值：循环链表的头指针，0代表创建失败，非0表成功*/
    CircleLinkList H;
    H = (CircleLinkList)malloc(sizeof(CNode));
    if (H) /*确认创建头结点创建是否成功，若成功，修改循环链表头结点的指针域为0表空表*/
        H->next = H;
    H->prior = H;
    return H;
}
void Destroy_CircleLinkList(CircleLinkList H)
{ /*入口参数：循环链表头指针的地址，出口参数：无*/
    CircleLinkList p, q;
    p = H;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    H = NULL;
}

int Length_DoubleLinkList(CircleLinkList H)
{
    CircleLinkList p = H; /* p指向头结点*/
    int count = 0;        /*H带头结点所以从－1开始*/
    while (p->next != H)
    { /* p所指的是第 count + 1 个结点*/
        p = p->next;
        count++;
    } /*while */
    return (count);
}

CircleLinkList Locate_CircleLinkList_Pos(CircleLinkList H, int i)
{
    CircleLinkList p = H;
    int j = 0;
    while (p->next != H && j < i)
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
CircleLinkList Locate_CircleLinkList_Value(CircleLinkList H, int x)
{
    CircleLinkList p = H->next;
    while (p->next == H && p->data != x)
        p = p->next;
    return (p);
}
int Insert_CircleLinkList(CircleLinkList H, int i, int x)
{
    /*返回参数：成功标志，0不成功，1成功*/
    CircleLinkList p, S;
    p = Locate_CircleLinkList_Pos(H, i - 1); /*找第i-1个结点地址*/
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    S = (CircleLinkList)malloc(sizeof(CNode));
    if (!S)
    {
        printf("申请空间失败");
        return (0);
    } /*申请空间失败，不能插入*/
    if (p == H)
    {
        S->data = x;
        S->next = p->next;
        p->next->prior = S;
        S->prior = p;
        p->next = S;
    }
    else
    {
        S->data = x;
        p->prior->next = S; /*新结点插入在第i-1个结点的后面*/
        S = p->prior;
        S->next = p;
        p->prior = S;
    }
    return 1; /*插入成功，则返回*/
}

int Delete_CircleLinkList(CircleLinkList H, int i)
{ /*删除循环链表H上的第i个结点;返回参数：0不成功，1成功*/
    CircleLinkList p;
    if (H == NULL || H->next == H)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_CircleLinkList_Pos(H, i - 1); /*找第i-1个结点地址，见算法2.10*/
                                             //    if (p == NULL || p->next == NULL)
                                             //    {
                                             //        printf("参数 i 错");
                                             //        return (0); /*第i个结点不存在*/
                                             //    }

    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p); /*释放 S */
    return (1);
}

void Display_CircleLinkList(CircleLinkList CL, int a)
{
    for (int i = 1; i <= a; i++)
    {
        printf("%d  ", CL->next->data);
        CL = CL->next;
    }
}

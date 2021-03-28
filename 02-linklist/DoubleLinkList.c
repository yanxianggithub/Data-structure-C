#include "DoubleLinkList.h"

int main()
{
    DoubleLinkList DL;
    DL = Creat_DoubleLinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_DoubleLinkList(DL, i, i);
    }                                                         /*双向链表赋值*/
    Display_DoubleLinkList(DL);                               //输出双向链表
    printf("\n%d\n", Locate_DoubleLinkList_Pos(DL, 2)->data); //检索链表位置2元素
    Delete_DoubleLinkList(DL, 2);                                //删除链表位置2元素
    Display_DoubleLinkList(DL);
    Destroy_DoubleLinkList(DL);

    return 0;
}

DoubleLinkList Creat_DoubleLinkList(void)
{ /*创建空单链表，入口参数：无；返回值：单链表的头指针，0代表创建失败，非0表成功*/
    DoubleLinkList H;
    H = (DoubleLinkList)malloc(sizeof(DNode));
    if (H) /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        H->next = NULL;
    H->prior = NULL;
    return H;
}

void Destroy_DoubleLinkList(DoubleLinkList H)
{
    DoubleLinkList p, q;
    p = H;
    while (p != NULL) /*释放双向链表的所有结点*/
    {
        q = p;
        p = p->next;
        free(q);
    }         /*while */
    H = NULL; /*将头指针变为零表示双向链表不存在*/
}

int Length_DoubleLinkList(DoubleLinkList H)
{
    DoubleLinkList p = H; /* p指向头结点*/
    int count = -1;       /*H带头结点所以从－1开始*/
    while (p)
    { /* p所指的是第 count + 1 个结点*/
        p = p->next;
        count++;
    } /*while */
    return (count);
}

DoubleLinkList Locate_DoubleLinkList_Pos(DoubleLinkList H, int i)
{
    DoubleLinkList p;
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

DoubleLinkList Locate_DoubleLinkList_Value(DoubleLinkList H, int x)
{
    return 0;
    /*归中算法*/
}

int Insert_DoubleLinkList(DoubleLinkList H, int i, int x)
{ /*返回参数：成功标志，0不成功，1成功*/
    DoubleLinkList p, s;
    p = Locate_DoubleLinkList_Pos(H, i - 1); /*找第i个结点地址*/
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    s = (DoubleLinkList)malloc(sizeof(DNode));
    if (!s)
    {
        printf("申请空间失败");
        return (0);
    } /*申请空间失败，不能插入*/
    if (p->next == NULL)
    {
        s->data = x;
        p->next = s;
        s->prior = p;
        s->next = NULL;
    }
    else
    {
        s->data = x;
        s->prior = p->prior;
        p->prior->next = s;
        s->next = p;
        p->prior = s;
    }
    /*新结点插入在第i个结点的前面*/

    return 1; /*插入成功，则返回*/
}

int Delete_DoubleLinkList(DoubleLinkList H, int i)
{ /*删除双向链表H上的第i个结点;返回参数：0不成功，1成功*/
    DoubleLinkList p;
    if (H == NULL || H->next == NULL)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_DoubleLinkList_Pos(H, i); /*找第i - 1个结点地址*/
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

void Display_DoubleLinkList(DoubleLinkList DL)
{
    if (DL->next == NULL)
        printf("empty");
    while (DL->next != NULL)
    {
        printf("%d  ", DL->next->data);
        DL = DL->next;
    }
}

#include "CircleLinkList.h"

int main()
{
    CircleLinkList CL;
    CL = Creat_CircleLinkList();
    for(int i = 1;i <=5 ;i++)
    {
        Insert_CircleLinkList(CL,i,i);
    }
    Display_CircleLinkList(CL,12);
    Delete_CircleLinkList(CL,2);
    printf("\n");
    Display_CircleLinkList(CL,12);


}

CircleLinkList Creat_CircleLinkList(void)
{ /*创建空单链表，入口参数：无；返回值：单链表的头指针，0代表创建失败，非0表成功*/
    CircleLinkList H;
    H = (CircleLinkList)malloc(sizeof(CNode));
    if (H) /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        H->next = H;
    return H;
}
void Destroy_CircleLinkList(CircleLinkList H)
{ /*入口参数：单链表头指针的地址，出口参数：无*/
}

CircleLinkList Locate_CircleLinkList_Pos(CircleLinkList H, int i)
{
    CircleLinkList p;
    int j = 0;
    p = H;
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
    while (p && p->data != x)
        p = p->next;
    return (p);
}
int Insert_CircleLinkList(CircleLinkList H, int i, int x)
{
    /*返回参数：成功标志，0不成功，1成功*/
    CircleLinkList p, s;
    p = Locate_CircleLinkList_Pos(H, i - 1); /*找第i-1个结点地址*/
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    s = (CircleLinkList)malloc(sizeof(CNode));
    if (!s)
    {
        printf("申请空间失败");
        return (0);
    } /*申请空间失败，不能插入*/
    if(p->next == H)
    {
        s->data=x;
        s->next = p;
        p->next=s;
    }else
        {
            s->data = x;
            s->next = p->next; /*新结点插入在第i-1个结点的后面*/
            p->next = s;
        }
    return 1; /*插入成功，则返回*/
}
int Delete_CircleLinkList(CircleLinkList H, int i)
{ /*删除单链表H上的第i个结点;返回参数：0不成功，1成功*/
    CircleLinkList p, s;
    if (H == NULL || H->next == H)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_CircleLinkList_Pos(H, i - 1); /*找第i-1个结点地址，见算法2.10*/
    if (p == NULL || p->next == NULL)
    {
        printf("参数 i 错");
        return (0); /*第i个结点不存在*/
    }
    s = p->next;       /*s指向第i个结点*/
    p->next = s->next; /*从链表中删除*/
    free(s);           /*释放*s */
    return (1);
}
void Display_CircleLinkList(CircleLinkList CL,int a)
{
    for(int i = 1;i <= a;i++)
    {
        printf("%d  ", CL->next->data);
        CL = CL->next;
    }
}

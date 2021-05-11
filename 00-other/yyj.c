#include <stdio.h>
#include <stdlib.h>

#define DataType float
typedef struct node {
    float p;
    unsigned int e;/*每个元素数据信息*/
    struct node *next; /*存放后继元素的地址*/
} LNode, *SingleLinkList;

SingleLinkList Creat_SingleLinkList(void)
{ /*创建空单链表，入口参数：无；返回值：单链表的头指针，0代表创建失败，非0表成功*/
    SingleLinkList H;
    H = (SingleLinkList) malloc(sizeof(LNode));
    if (H) /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        H->next = NULL;
    return H;
}

void Destroy_SingleLinkList(SingleLinkList H)
{ /*入口参数：单链表头指针的地址，出口参数：无*/
    SingleLinkList pr, q;
    pr = H;
    while (pr != NULL) /*释放单链表的所有结点*/
    {
        q = pr;
        pr = pr->next;
        free(q);
    }         /*while */
    H = NULL; /*将头指针变为零表示单链表不存在*/
}

int Length_SingleLinkList(SingleLinkList H)
{                         /* 求单链表表长，入口参数：单链表头指针，出口参数：表长，-1表示
       单链表不存在。*/
    SingleLinkList pr = H; /* p指向头结点*/
    int count = -1;       /*H带头结点所以从－1开始*/
    while (pr)
    { /* p所指的是第 count + 1 个结点*/
        pr = pr->next;
        count++;
    } /*while */
    return (count);
}

SingleLinkList Locate_SingleLinkList_Pos(SingleLinkList H, DataType i)
{
    SingleLinkList pr;
    int j = 0;
    pr = H;
    while (pr && j < i)
    { /*查找第i个结点*/
        pr = pr->next;
        j++;
    } /*while*/
    if (j != i || !pr)
    {
        printf("参数 i 错或单链表不存在");
        return (NULL);
    } /*第i个结点不存在*/
    return (pr);
}

SingleLinkList Locate_SingleLinkList_Value(SingleLinkList H, DataType x)
{ /*在单链表中查找值为x的结点，入口参数：单链表指针，检索元素,出口参数：找到后返回其指针，否则返回NULL*/
    SingleLinkList pr = H->next;
    while (pr && pr->p != x)
        pr = pr->next;
    return (pr);
}

int Insert_SingleLinkList(SingleLinkList H, int i, float x, unsigned int y)
{ /*返回参数：成功标志，0不成功，1成功*/
    SingleLinkList pr, q;
    pr = Locate_SingleLinkList_Pos(H, i - 1); /*找第i-1个结点地址*/
    if (!pr)
    {
        printf("i有误");
        return (0);
    }
    q = (SingleLinkList) malloc(sizeof(LNode));
    if (!q)
    {
        printf("申请空间失败");
        return (0);
    } /*申请空间失败，不能插入*/
    q->p = x;
    q->e = y;
    q->next = pr->next; /*新结点插入在第i-1个结点的后面*/
    pr->next = q;
    return 1; /*插入成功，则返回*/
}

int Delete_SingleLinkList(SingleLinkList H, int i)
{ /*删除单链表H上的第i个结点;返回参数：0不成功，1成功*/
    SingleLinkList pr, q;
    if (H == NULL || H->next == NULL)
    {
        printf("空表不能删除");
        return (0);
    }
    pr = Locate_SingleLinkList_Pos(H, i - 1); /*找第i-1个结点地址，见算法2.10*/
    if (pr == NULL || pr->next == NULL)
    {
        printf("参数 i 错");
        return (0); /*第i个结点不存在*/
    }
    q = pr->next;       /*q指向第i个结点*/
    pr->next = q->next; /*从链表中删除*/
    free(q);           /*释放*s */
    return (1);
}

void Display(SingleLinkList L1)
{
    while (L1->next)
    {
        printf("%.fX^%d",L1->next->p,L1->next->e);
        if (L1->next->next)
        {
            printf(L1->next->next->p > 0 ? " +" :" ");
        }
        L1=L1->next;
    }
}


void Add_LNode(SingleLinkList P1, SingleLinkList P2)
{
    SingleLinkList Pre_Item, Cur_Item1, Cur_Item2;
    Pre_Item = P1;
    Cur_Item1 = P1->next;
    Cur_Item2 = P2->next;
    while (Cur_Item1 && Cur_Item2)
    {
        if (Cur_Item1->e == Cur_Item2->e)
        {
            Cur_Item1->p = Cur_Item1->p + Cur_Item2->p;
            if (Cur_Item1->p == 0)
            {
                Pre_Item->next = Cur_Item1->next;
                free(Cur_Item1);
                Cur_Item1 = Pre_Item->next;
                Cur_Item2 = Cur_Item2->next;
            } else
            {
                Pre_Item = Cur_Item1;
                Cur_Item1 = Cur_Item1->next;
                Cur_Item2 = Cur_Item2->next;
            }
        } else if (Cur_Item1->e < Cur_Item2->e)
        {
            Pre_Item = Cur_Item1;
            Cur_Item1 = Cur_Item1->next;
        } else
        {
            SingleLinkList temp;
            if (!(temp = (SingleLinkList) malloc(sizeof(LNode))))
            {
                printf("内存不足!\n");
                exit(0);
            }
            temp->p = Cur_Item2->p;
            temp->e = Cur_Item2->e;
            temp->next = Cur_Item1;
            Pre_Item->next = temp;
            Pre_Item = Pre_Item->next;
            Cur_Item2 = Cur_Item2->next;
        }
    }
    while (Cur_Item2)
    {
        SingleLinkList temp;
        if (!(temp = (SingleLinkList) malloc(sizeof(LNode))))
        {
            printf("内存不足!\n");
            exit(0);
        }
        temp->p = Cur_Item2->p;
        temp->e = Cur_Item2->e;
        temp->next = NULL;
        Pre_Item->next = temp;
        Pre_Item = Pre_Item->next;
        Cur_Item2 = Cur_Item2->next;
    }
}

int main()
{
    SingleLinkList L1,L2;
    L1 = Creat_SingleLinkList();
    L2 = Creat_SingleLinkList();
    Insert_SingleLinkList(L1,1,1,1);
    Insert_SingleLinkList(L1,2,3,2);
    Insert_SingleLinkList(L1,3,4,3);
    Insert_SingleLinkList(L1,4,2,4);
    Insert_SingleLinkList(L1,5,4,5);
    Insert_SingleLinkList(L1,6,2,6);
    Insert_SingleLinkList(L2,1,1,1);
    Insert_SingleLinkList(L2,2,3,2);
    Insert_SingleLinkList(L2,3,1,3);
    Insert_SingleLinkList(L2,4,5,4);
    Insert_SingleLinkList(L2,5,4,5);
    Insert_SingleLinkList(L2,6,6,6);
    Add_LNode(L1,L2);
    Display(L1);
    printf("\n");
    return 0;
}
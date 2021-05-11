#include<stdio.h>
#include<stdlib.h>
#define DataType float
typedef struct node {
    DataType data;
    unsigned int e;
    struct node *next;
} Polynomial, *P_Polynomial;

P_Polynomial Creat_P_Polynomial(void)
{/*创建空单链表，入口参数：无；返回值：单链表的头指针，0代表创建失败，非0表成功*/
    P_Polynomial H;
    H = (P_Polynomial) malloc(sizeof(Polynomial));
    if (H)   /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        H->next = NULL;
    return H;
}

P_Polynomial Locate_P_Polynomial(P_Polynomial H, int i)
{
    P_Polynomial p;
    int j;
    p = H;
    j = 0;
    while (p && j < i)
    {    /*查找第i个结点*/
        p = p->next;
        j++;
    } /*while*/
    if (j != i || !p)
    {
        printf("参数 i 错或单链表不存在");
        return (NULL);
    }     /*第i个结点不存在*/
    return (p);
}

int Insert_P_Polynomial(P_Polynomial H, int i, DataType data, int e)
{ /*返回参数：成功标志，0不成功，1成功*/
    P_Polynomial p, q;
    p = Locate_P_Polynomial(H, i - 1);  /*找第i-1个结点地址*/
    if (!p)
    {
        printf("i有误");
        return (0);
    }
    q = (P_Polynomial) malloc(sizeof(Polynomial));
    if (!q)
    {
        printf("申请空间失败");
        return (0);
    }     /*申请空间失败，不能插入*/
    q->data = data;
    q->e = e;
    q->next = p->next;     /*新结点插入在第i-1个结点的后面*/
    p->next = q;
    return 1;     /*插入成功，则返回*/
}

int Del_P_Polynomial(P_Polynomial H, int i)
{/*删除单链表H上的第i个结点;返回参数：0不成功，1成功*/
    P_Polynomial p, q;
    if (H == NULL || H->next == NULL)
    {
        printf("空表不能删除");
        return (0);
    }
    p = Locate_P_Polynomial(H, i - 1);  /*找第i-1个结点地址，见算法2.10*/
    if (p == NULL || p->next == NULL)
    {
        printf("参数 i 错");
        return (0);    /*第i个结点不存在*/
    }
    q = p->next;        /*q指向第i个结点*/
    p->next = q->next;   /*从链表中删除*/
    free(q);            /*释放*s */
    return (1);
}

void Add_Polynomial(P_Polynomial P1, P_Polynomial P2)
{
    P_Polynomial Pre_Item, Cur_Item1, Cur_Item2;
    Pre_Item = P1;
    Cur_Item1 = P1->next;
    Cur_Item2 = P2->next;
    while (Cur_Item1 && Cur_Item2)
    {
        if (Cur_Item1->e == Cur_Item2->e)
        {
            Cur_Item1->data = Cur_Item1->data + Cur_Item2->data;
            if (Cur_Item1->data == 0)
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
            P_Polynomial temp;
            if (!(temp = (P_Polynomial) malloc(sizeof(Polynomial))))
            {
                printf("内存不足!\n");
                exit(0);
            }
            temp->data = Cur_Item2->data;
            temp->e = Cur_Item2->e;
            temp->next = Cur_Item1;
            Pre_Item->next = temp;
            Pre_Item = Pre_Item->next;
            Cur_Item2 = Cur_Item2->next;
        }
    }
    while (Cur_Item2)
    {
        P_Polynomial temp;
        if (!(temp = (P_Polynomial) malloc(sizeof(Polynomial))))
        {
            printf("内存不足!\n");
            exit(0);
        }
        temp->data = Cur_Item2->data;
        temp->e = Cur_Item2->e;
        temp->next = NULL;
        Pre_Item->next = temp;
        Pre_Item = Pre_Item->next;
        Cur_Item2 = Cur_Item2->next;
    }
}

void input(P_Polynomial P)
{
    int i=1;
    while (1)
    {
        float a;
        int b;
        scanf("%f%d",&a,&b);
        if(a==0||b==0)return;
        Insert_P_Polynomial(P,i++,a,b);
    }
}
void Display(P_Polynomial P1)
{
    while (P1->next)
    {
        printf("%.fX^%d",P1->next->data,P1->next->e);
        if (P1->next->next)
        {
            printf(P1->next->next->data > 0 ? " +" :" ");
        }
        P1=P1->next;
    }
}

main()
{
    P_Polynomial P1,P2;
    P1 = Creat_P_Polynomial();
    P2 = Creat_P_Polynomial();
    printf("输入格式:data e 输入0 0表示结束\n");
    printf("请输入多项式一:\n");input(P1);
    printf("请输入多项式二:\n");input(P2);
    printf("\nA = ");Display(P1);
    printf("\nB = ");Display(P2);
    printf("\n合并结果:\nC =");
    Add_Polynomial(P1,P2);Display(P1);
    return 0;
}

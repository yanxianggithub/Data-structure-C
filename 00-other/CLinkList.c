#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} LNode, *LinkList;

LinkList Creat_LinkList(void)
{
    LinkList H;
    H = (LinkList)malloc(sizeof(LNode));
    if (H)
        H->next = H;
    return H;
}

LinkList Locate_LinkListi(LinkList H, int i)
{
    LinkList p;
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

int Insert_LinkList(LinkList H, int i, int x)
{
    LinkList p, q;
    p = Locate_LinkListi(H, i - 1);
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
    }

    q->data = x;
    q->next = p->next;
    p->next = q;
    q->next = H->next;
    return 1;
}

void Del_LinkList(LinkList H, int x) //删除操作
{
    LinkList p, q;
    p = H;
    if (p == NULL) //首先判断链表是否为空
    {
        printf("这是一个空指针 无法删除\n");
        return;
    }
    if (x == 1) //如果删除的是头节点
    {

        for (q = H; q->next != H; q = q->next);
        p = H->next;
        H = H->next->next;
        q->next = H;
        free(p);
    }else
    {
        for (int i =2; i < x; i++)
        {
            q = p->next;
            p = q;
        }
        p = q->next;
        q->next = p->next;
        free(p);
    }
}

void Display_LinkList(LinkList LL)
{
    for (int i = 1; i <= 20; i++)
    {
        printf("%d ", LL->next->data);
        LL = LL->next;
    }
}

int main()
{

    LinkList LL;
    int p;
    LL = Creat_LinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_LinkList(LL, i, i);
    }
    Display_LinkList(LL);
    printf("ppppppppppppp:");
    scanf("%d", &p);
    Del_LinkList(LL,p);
    Display_LinkList(LL);
    return 0;
}
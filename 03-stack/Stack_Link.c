#include "Stack_Link.h"

int main()
{
    int a;
    int *x=&a;
    PLinkStack SL;
    SL = Init_LinkStack();
    Push_LinkStack(SL, 1);
    Push_LinkStack(SL, 2);
    Push_LinkStack(SL, 3);
    Push_LinkStack(SL, 4);
    Push_LinkStack(SL, 5);
    Pop_LinkStack(SL, x);
    printf("%d ",a);
}

PLinkStack Init_LinkStack(void)
{ /*初始化链栈，入口参数：空，返回值：
           链栈指针，null表示初始化失败*/
    PLinkStack S;
    S = (PLinkStack)malloc(sizeof(LinkStack));
    if (S)
        S->top = NULL;
    return (S);
}

void Destroy_LinkStack(PLinkStack LS)
{ /*销毁链栈，入口参数：为要销毁的链栈指针地址，无返回值*/
    PStackNode p, q;
    if (LS)
    {
        p = LS->top;
        while (p)
        {
            q = p;
            p = p->next;
            free(q);
        }
        free(LS);
    }
    LS = NULL;
}

int Empty_LinkStack(PLinkStack S)
{ /*判断链栈是否为空，入口参数：链栈指针，返回值：
      1表示栈空，0表示栈非空*/
    return (S->top == NULL);
}

int Push_LinkStack(PLinkStack S, DataType x)
{
    PStackNode p;
    p = (PStackNode)malloc(sizeof(StackNode));
    if (!p)
    {
        printf("内存溢出");
        return (0);
    }
    p->data = x;
    p->next = S->top;
    S->top = p;
    return (1);
}

int Pop_LinkStack(PLinkStack S, DataType *x)
{
    PStackNode p;
    if (Empty_LinkStack(S))
    {
        printf("栈空，不能出栈");
        return (0);
    }
    *x = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    return (1);
}

int GetTop_LinkStack(PLinkStack S, DataType *x)
{ /*返回值：1表示出栈成功，0表示失败*/
    if (Empty_LinkStack(S))
    {
        printf("栈空");
        return (0);
    }
    *x = S->top->data;
    return (1);
}

void Display_LinkStack(PLinkStack S)
{

}

#include "Stack_Link.h"

int main()
{
    PLinkStack SL;
    SL = Init_LinkStack();
    for (int i = 1; i < 6; ++i)
    {
        Push_LinkStack(SL, i);
    }
    for (int i = 1; i < 6; ++i)
    {
        printf("%d", Pop_LinkStack(SL));
    }

}

PLinkStack Init_LinkStack(void)
{ /*初始化链栈，入口参数：空，返回值：
           链栈指针，null表示初始化失败*/
    PLinkStack S;
    S = (PLinkStack) malloc(sizeof(LinkStack));
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
    p = (PStackNode) malloc(sizeof(StackNode));
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

int Pop_LinkStack(PLinkStack S)
{
    DataType value;
    PStackNode p;
    if (Empty_LinkStack(S))
    {
        printf("栈空，不能出栈");
        return (0);
    }
    value = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    return value;
}

int GetTop_LinkStack(PLinkStack S)
{ /*返回值：1表示出栈成功，0表示失败*/
    if (Empty_LinkStack(S))
    {
        printf("栈空");
        return (0);
    }
    DataType value = S->top->data;
    return value;
}

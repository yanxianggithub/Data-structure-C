#include "Stack_Array.h"

int main()
{
    PSeqStack S;
    S = Init_Stack();
    for (int i = 1; i < 6; ++i)
    {
        Push_SeqStack(S, i);
    }
    for (int i = 1; i < 6; ++i)
    {
        printf("%d",Pop_SeqStack(S));
    }

    Destory_SeqStack(S);
}

PSeqStack Init_Stack()
{
    PSeqStack S;
    S = (PSeqStack)malloc(sizeof(SeqStack));
    if (S)
        S->top = -1;
    return S;
}

int Empty_SeqStack(PSeqStack S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}

int Push_SeqStack(PSeqStack S, DataType x)
{
    if (S->top == MAXSIZE)
        return 0;
    else
    {
        S->top++;
        S->data[S->top] = x;
        return 1;
    }
}

DataType Pop_SeqStack(PSeqStack S)
{
    DataType value;
    if (Empty_SeqStack(S))
        return 0;
    else
    {
        value = S->data[S->top];
        S->top--;
        return value;
    }
}

DataType GetTop_SeqStack(PSeqStack S)
{
    if (Empty_SeqStack(S))
        return 0;
    else
    {
        DataType value = S->data[S->top];
        return value;
    }
}

void Destory_SeqStack(PSeqStack S)
{
    if (S)
        free(S);
    S = NULL;
    return;
}

void Display_SeqStack(PSeqStack S)
{
    if (!S)
    {
        printf("空栈");
    }
    else
    {
        for (int t = S->top; t >= 0; t--)

            printf("%d  ", S->data[t]);
    }
}

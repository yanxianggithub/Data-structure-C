#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define DataType int

typedef struct
{
    int data[MAXSIZE];
    int top;
}SeqStack, *PSeqStack;

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
int Palindrome(PSeqStack S,char *a)
{
    int poo=0;
    for (int i = 0; a[i]!='@'; ++i)
    {
        if(a[i]!= Pop_SeqStack(S))poo=1;
    }
    return poo;
}
void Destory_SeqStack(PSeqStack S)
{
    if (S)
        free(S);
    S = NULL;
    return;
}

int main()
{
    PSeqStack S = Init_Stack();
    int i=0;
    char a[50],b[50];
    printf("Input String:");
    scanf("%s",b);
    while (b[i])
    {
        a[i]=b[i];
        i++;
    }
    a[i]='@';
    for (int i = 0; a[i]!='@'; ++i)
    {
        Push_SeqStack(S, a[i]);
    }
    if(Palindrome(S,a)==0)
    {
        printf("Yes!");
    }else
    {
        printf("No!");
    }

}

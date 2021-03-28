#include "Stack_Array.h"

int main()
{
    int *x=NULL;
    PSeqStack S;
    S=Init_Stack();
    Push_SeqStack(S,1);
    Push_SeqStack(S,2);
    Push_SeqStack(S,3);
    Push_SeqStack(S,4);
    Push_SeqStack(S,5);
    Display_SeqStack(S);
    /*
    Pop_SeqStack(S,x);
    printf("\n%d\n",*x);
    Display_SeqStack(S);
    printf("\n");
    Destory_SeqStack(S);
    Display_SeqStack(S);
     */
}

PSeqStack Init_Stack()
{
    PSeqStack S;
    S = (PSeqStack)malloc(sizeof(SeqStack));
    if(S)S->top=-1;
    return S;
}

int Empty_SeqStack(PSeqStack S)
{
    if(S->top==-1)return 1;
    else return 0;
}

int Push_SeqStack(PSeqStack S,int x)
{
    if(S->top==MAXSIZE)return 0;
    else
    {
        S->top++;
        S->data[S->top]=x;
        return 1;
    }
}

int Pop_SeqStack(PSeqStack S,int *x)
{
    if(Empty_SeqStack(S))return 0;
    else
    {
        *(x)=S->data[S->top];
        S->top--;
        return 1;
    }
}

int GetTop_SeqStack(PSeqStack S,int *x)
{
    if(Empty_SeqStack(S))return 0;
    else *x=S->data[S->top];
}

void Destory_SeqStack(PSeqStack S) {
    if (S)free(S);
    S = NULL;
    return;
}

void Display_SeqStack(PSeqStack S)
{
    for(S->top;S->top >= 0;S->top--)
    {
        printf("%d  ",S->data[S->top]);
    }
}
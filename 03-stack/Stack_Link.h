#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int top;
} SeqStack, *PSeqStack;

PSeqStack Init_Stack();
int Empty_SeqStack(PSeqStack S);
int Push_SeqStack(PSeqStack S, int x);
int Pop_SeqStack(PSeqStack S, int *x);
int GetTop_SeqStack(PSeqStack S, int *x);
void Destory_SeqStack(PSeqStack S);
void Display_SeqStack(PSeqStack S);
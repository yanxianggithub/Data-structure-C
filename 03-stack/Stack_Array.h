#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define DataType int
typedef struct
{
    DataType data[MAXSIZE];
    int top;
}SeqStack, *PSeqStack;

PSeqStack Init_Stack();
int Empty_SeqStack(PSeqStack S);
int Push_SeqStack(PSeqStack S,DataType x);
DataType Pop_SeqStack(PSeqStack S);
DataType GetTop_SeqStack(PSeqStack S);
void Destory_SeqStack(PSeqStack S);
void Display_SeqStack(PSeqStack S);

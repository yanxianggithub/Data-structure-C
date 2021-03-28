#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define DataType int

typedef struct node
{
      DataType data[MAXSIZE];
      int length;
} SeqList, *PSeqList;

PSeqList Init_SeqList(void);
void Destroy_SeqList(PSeqList *PL);
int Length_SeqList(PSeqList PL);
int Location_SeqList(PSeqList PL, DataType x);
int Insert_SeqList(PSeqList PL, int i, DataType x);
int Delete_SeqList(PSeqList PL, int i);
void Reverse_SeqList(PSeqList PL);
int merge_SeqList(PSeqList A, PSeqList B, PSeqList C);
void Display_SeqList(PSeqList PL);
int josephus_SeqList(PSeqList josephus_seq, int s, int m);
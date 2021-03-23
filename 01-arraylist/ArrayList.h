#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct node
{
      int data[MAXSIZE];
      int length;
} SeqList, *PSeqList;

PSeqList Init_SeqList(void);
void Destroy_SeqList(PSeqList *PL);
int Length_SeqList(PSeqList PL);
int Location_SeqList(PSeqList PL, int x);
int Insert_SeqList(PSeqList PL, int i, int x);
int Delete_SeqList(PSeqList PL, int i);
void Reverse_SeqList(PSeqList PL);
int merge_SeqList(PSeqList A, PSeqList B, PSeqList C);
void Display_SeqList(PSeqList PL);
int josephus_SeqList(PSeqList josephus_seq, int s, int m);
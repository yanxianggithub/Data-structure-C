#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define DataType int

typedef struct node
{
      DataType data[MAXSIZE];
      int length;
} SeqList, *PSeqList;

PSeqList Init_SeqList(void)
{
    PSeqList PL;
    PL = (PSeqList)malloc(sizeof(SeqList));
    if (PL)
        PL->length = 0;
    return (PL);
}

void Destroy_SeqList(PSeqList *PL)
{
    if (*PL)
        free(*PL);
    *PL = NULL;
    return;
}

int Insert_SeqList(PSeqList PL, int i, DataType x)
{
    int j;
    if (!PL)
    {
        printf("表不存在");
        return (-2);
    }
    if (PL->length >= MAXSIZE)
    {
        printf("表溢出");
        return (-1);
    }
    if (i < 1 || i > PL->length + 1)
    {
        printf("插入位置不合法");
        return (0);
    }
    for (j = PL->length - 1; j >= i - 1; j--)
        PL->data[j + 1] = PL->data[j];
    PL->data[i - 1] = x;
    PL->length++;
    return (1);
}

void Reverse_SeqList(PSeqList PL)
{
    int temp;
    for (int i = 1; i <= PL->length / 2; i++)
    {
        temp = PL->data[i - 1];
        PL->data[i - 1] = PL->data[PL->length - i];
        PL->data[PL->length - i] = temp;
    }
}

void Display_SeqList(PSeqList PL)
{
    for (int i = 0; i < PL->length; i++)
        printf("%d  ", PL->data[i]);
}

int main()
{
    PSeqList PL;
    PL = Init_SeqList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_SeqList(PL, i, i);
    }
    Display_SeqList(PL);
    Reverse_SeqList(PL);
    printf("\n");
    Display_SeqList(PL);
    return 0;
}
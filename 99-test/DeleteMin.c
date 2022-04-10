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
    if (PL) /*若SL=0表示分配失败*/
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
        return (-1);
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

void Display_SeqList(PSeqList PL)
{
    for (int i = 0; i < PL->length; i++)
        printf("%d  ", PL->data[i]);
}
int Delete_Min(PSeqList PL)
{
    if (PL->length == 0)
    {
        printf("error");
        return;
    }
    int min = PL->data[0];
    int pos = 0;
    for (int i = 1; i < PL->length;i++)
    if (PL->data[i] < min)
    {
        min = PL->data[i];
        pos = i;
    }
    PL->data[pos] = PL->data[PL->length - 1];
    PL->length--;
    return min;
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
    printf("\n");
    printf("%d\n", DeleteMin(PL));
    Display_SeqList(PL);
    return 0;
}
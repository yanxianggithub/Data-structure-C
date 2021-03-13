#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    PSeqList PL;
    PL = Init_SeqList();
    Insert_SeqList(PL,1,5);
    Insert_SeqList(PL,2,6);
    Insert_SeqList(PL,3,7);
    Insert_SeqList(PL,4,8);
    Display_SeqList(PL);

    return 0;
}

PSeqList Init_SeqList(void)
{
    /*创建一顺序表，入口参数无，返回一个指向顺序表的指针
    指针值为零表示分配空间失败*/
    PSeqList PL;
    PL = (PSeqList)malloc(sizeof(SeqList));
    if (PL) /*若SL=0表示分配失败*/
        PL->length = 0;
    return (PL);
}

void Destroy_SeqList(PSeqList *PL)
{
    /*销毁顺序表，入口参数：为要销毁的顺序表指针地址
    无返回值*/
    if (*PL)
        free(*PL);

    *PL = NULL;
    return;
}

int Length_SeqList(PSeqList PL)
{
    /*求顺序表的长度，入口参数：为顺序表指针
    返回表长，-1表示表不存在*/
    if (PL)
        return (PL->length);
    return (-1);
}

int Location_SeqList(PSeqList PL, int x)
{
    /*顺序表检索，入口参数：为顺序表指针，检索元素，
    返回元素位置，-1表示表不存在，0表示查找失败*/
    int i = 0;
    if (!PL)
    {
        printf("表不存在");
        return (-1);
        /*表不存在，不能检索*/
    }
    while (i < PL->length && PL->data[i] != x)
        i++;
    if (i >= PL->length)
        return 0;
    else
        return (i + 1);
}

int Insert_SeqList(PSeqList PL, int i, int x)
{
    int j;
    if (!PL)
    {
        printf("表不存在");
        return (-2);
    } /*表不存在，不能插入*/
    if (PL->length >= MAXSIZE)
    {
        printf("表溢出");
        return (-1);
    } /*表空间已满，不能插入*/
    if (i < 1 || i > PL->length + 1)
    { /*检查插入位置的合法性*/
        printf("插入位置不合法");
        return (0);
    }
    for (j = PL->length - 1; j >= i - 1; j--)
        PL->data[j + 1] = PL->data[j];
    /* 移动元素 */
    PL->data[i - 1] = x;
    /*新元素插入*/
    PL->length++;
    /*表长加 1*/
    return (1);
    /*插入成功，返回*/
}

int Delete_SeqList(PSeqList PL, int i)
{
    /*顺序表删除，入口参数：顺序表指针，删除元素位置，
    返回标志1表示成功，0表示删除位置不合法，-1表示表不存在*/
    int j;
    if (!PL)
    {
        printf("表不存在");
        return (-1);
    } /*表不存在，不能删除元素*/
    if (i < 1 || i > PL->length)
    {
        /*检查删除位置的合法性*/
        printf("删除位置不合法");
        return (0);
    }
    for (j = i; j < PL->length; j++)
        PL->data[j - 1] = PL->data[j];
    /*向上移动*/
    PL->length--;
    return (1);
    /*删除成功*/
}

void Reverse_SeqList(PSeqList PL)
{
    int i;
    int x;
    for (i = 1; i <= PL->length / 2; i++)
    {
        x = PL->data[i - 1];
        /*完成元素ai与an - i+1交换*/
        PL->data[i - 1] = PL->data[PL->length - i];
        PL->data[PL->length - i] = x;
    } /* for */
}

int merge_SeqList(PSeqList A, PSeqList B, PSeqList C)
{
    /*入口参数：指向三个顺序表的指针，返回值：0表示失败，1表示成功*/
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    if (A->length + B->length >= MAXSIZE)
    {
        printf("C表空间不足");
        return (0);
    }
    while (i < A->length && j < B->length)
    {
        if (A->data[i] < B->data[j])
            C->data[k++] = A->data[i++];
        else
            C->data[k++] = B->data[j++];
    } /*while*/
    while (i < A->length)
        C->data[k++] = A->data[i++];
    //复制剩余部分
    while (j < B->length)
        C->data[k++] = B->data[j++];
    //复制剩余部分
    C->length = k;
    return (1);
    /*合并成功*/
}

void Display_SeqList(PSeqList PL)
{
    for (int i = 0; i < PL->length; i++)
        printf("%d\t", PL->data[i]);
}


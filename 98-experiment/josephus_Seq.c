#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
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

int Length_SeqList(PSeqList PL)
{
    if (PL)
        return (PL->length);
    return (-1);
}

int Location_SeqList(PSeqList PL, DataType x)
{
    int i = 0;
    if (!PL)
    {
        printf("������");
        return (-1);
    }
    while (i < PL->length && PL->data[i] != x)
        i++;
    if (i >= PL->length)
        return 0;
    else
        return (i + 1);
}

int Insert_SeqList(PSeqList PL, int i, DataType x)
{
    int j;
    if (!PL)
    {
        printf("������");
        return (-2);
    }
    if (PL->length >= MAXSIZE)
    {
        printf("�����");
        return (-1);
    }
    if (i < 1 || i > PL->length + 1)
    {
        printf("����λ�ò��Ϸ�");
        return (0);
    }
    for (j = PL->length - 1; j >= i - 1; j--)
        PL->data[j + 1] = PL->data[j];
    PL->data[i - 1] = x;
    PL->length++;
    return (1);
}

int Delete_SeqList(PSeqList PL, int i)
{
    int j;
    if (!PL)
    {
        printf("������");
        return (-1);
    }
    if (i < 1 || i > PL->length)
    {
        printf("ɾ��λ�ò��Ϸ�");
        return (0);
    }
    for (j = i; j < PL->length; j++)
        PL->data[j - 1] = PL->data[j];
    PL->length--;
    return (1);
}

int josephus_SeqList(PSeqList josephus_seq, int s, int m)
{
    int s1, i, w;
    if (!josephus_seq->length)
    {
        printf("������Ԫ��");
        return (0);
    }
    s1 = s - 1;
    printf("out josephus number:\n");
    for (i = josephus_seq->length; i > 0; i--)
    {
        s1 = (s1 + m - 1) % i;
        w = josephus_seq->data[s1];
        printf("��%d��ѡ��;\n", w);
        Delete_SeqList(josephus_seq, s1 + 1);
    }
    return (1);
}

int main()
{
    int people,s,m;
    PSeqList PL = Init_SeqList();
    printf("����������");
    scanf("%d",&people);
    for (int i = 1; i <= people; i++)
    {
        Insert_SeqList(PL, i, i);
    }
    printf("��������￪ʼ��");
    scanf("%d",&s);
    printf("�����ÿ�������ˣ�");
    scanf("%d",&m);
    printf("\n");
    josephus_SeqList(PL, s, m);
    Destroy_SeqList(PL);
    return 0;
}
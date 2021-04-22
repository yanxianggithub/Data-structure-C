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
    /*����һ˳�����ڲ����ޣ�����һ��ָ��˳����ָ��
    ָ��ֵΪ���ʾ����ռ�ʧ��*/
    PSeqList PL;
    PL = (PSeqList)malloc(sizeof(SeqList));
    if (PL) /*��SL=0��ʾ����ʧ��*/
        PL->length = 0;
    return (PL);
}

void Destroy_SeqList(PSeqList *PL)
{
    /*����˳�����ڲ�����ΪҪ���ٵ�˳���ָ���ַ
    �޷���ֵ*/
    if (*PL)
        free(*PL);

    *PL = NULL;
    return;
}

int Length_SeqList(PSeqList PL)
{
    /*��˳���ĳ��ȣ���ڲ�����Ϊ˳���ָ��
    ���ر���-1��ʾ������*/
    if (PL)
        return (PL->length);
    return (-1);
}

int Location_SeqList(PSeqList PL, DataType x)
{
    /*˳����������ڲ�����Ϊ˳���ָ�룬����Ԫ�أ�
    ����Ԫ��λ�ã�-1��ʾ�����ڣ�0��ʾ����ʧ��*/
    int i = 0;
    if (!PL)
    {
        printf("������");
        return (-1);
        /*�����ڣ����ܼ���*/
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
    } /*�����ڣ����ܲ���*/
    if (PL->length >= MAXSIZE)
    {
        printf("�����");
        return (-1);
    } /*��ռ����������ܲ���*/
    if (i < 1 || i > PL->length + 1)
    { /*������λ�õĺϷ���*/
        printf("����λ�ò��Ϸ�");
        return (0);
    }
    for (j = PL->length - 1; j >= i - 1; j--)
        PL->data[j + 1] = PL->data[j];
    /* �ƶ�Ԫ�� */
    PL->data[i - 1] = x;
    /*��Ԫ�ز���*/
    PL->length++;
    /*���� 1*/
    return (1);
    /*����ɹ�������*/
}

int Delete_SeqList(PSeqList PL, int i)
{
    /*˳���ɾ������ڲ�����˳���ָ�룬ɾ��Ԫ��λ�ã�
    ���ر�־1��ʾ�ɹ���0��ʾɾ��λ�ò��Ϸ���-1��ʾ������*/
    int j;
    if (!PL)
    {
        printf("������");
        return (-1);
    } /*�����ڣ�����ɾ��Ԫ��*/
    if (i < 1 || i > PL->length)
    {
        /*���ɾ��λ�õĺϷ���*/
        printf("ɾ��λ�ò��Ϸ�");
        return (0);
    }
    for (j = i; j < PL->length; j++)
        PL->data[j - 1] = PL->data[j];
    /*�����ƶ�*/
    PL->length--;
    return (1);
    /*ɾ���ɹ�*/
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
#include<stdio.h>
#include<stdlib.h>
#define DataType float
typedef struct node {
    DataType data;
    unsigned int e;
    struct node *next;
} Polynomial, *P_Polynomial;

P_Polynomial Creat_P_Polynomial(void)
{/*�����յ�������ڲ������ޣ�����ֵ���������ͷָ�룬0������ʧ�ܣ���0��ɹ�*/
    P_Polynomial H;
    H = (P_Polynomial) malloc(sizeof(Polynomial));
    if (H)   /*ȷ�ϴ���ͷ��㴴���Ƿ�ɹ������ɹ����޸ĵ�����ͷ����ָ����Ϊ0��ձ�*/
        H->next = NULL;
    return H;
}

P_Polynomial Locate_P_Polynomial(P_Polynomial H, int i)
{
    P_Polynomial p;
    int j;
    p = H;
    j = 0;
    while (p && j < i)
    {    /*���ҵ�i�����*/
        p = p->next;
        j++;
    } /*while*/
    if (j != i || !p)
    {
        printf("���� i �����������");
        return (NULL);
    }     /*��i����㲻����*/
    return (p);
}

int Insert_P_Polynomial(P_Polynomial H, int i, DataType data, int e)
{ /*���ز������ɹ���־��0���ɹ���1�ɹ�*/
    P_Polynomial p, q;
    p = Locate_P_Polynomial(H, i - 1);  /*�ҵ�i-1������ַ*/
    if (!p)
    {
        printf("i����");
        return (0);
    }
    q = (P_Polynomial) malloc(sizeof(Polynomial));
    if (!q)
    {
        printf("����ռ�ʧ��");
        return (0);
    }     /*����ռ�ʧ�ܣ����ܲ���*/
    q->data = data;
    q->e = e;
    q->next = p->next;     /*�½������ڵ�i-1�����ĺ���*/
    p->next = q;
    return 1;     /*����ɹ����򷵻�*/
}

int Del_P_Polynomial(P_Polynomial H, int i)
{/*ɾ��������H�ϵĵ�i�����;���ز�����0���ɹ���1�ɹ�*/
    P_Polynomial p, q;
    if (H == NULL || H->next == NULL)
    {
        printf("�ձ���ɾ��");
        return (0);
    }
    p = Locate_P_Polynomial(H, i - 1);  /*�ҵ�i-1������ַ�����㷨2.10*/
    if (p == NULL || p->next == NULL)
    {
        printf("���� i ��");
        return (0);    /*��i����㲻����*/
    }
    q = p->next;        /*qָ���i�����*/
    p->next = q->next;   /*��������ɾ��*/
    free(q);            /*�ͷ�*s */
    return (1);
}

void Add_Polynomial(P_Polynomial P1, P_Polynomial P2)
{
    P_Polynomial Pre_Item, Cur_Item1, Cur_Item2;
    Pre_Item = P1;
    Cur_Item1 = P1->next;
    Cur_Item2 = P2->next;
    while (Cur_Item1 && Cur_Item2)
    {
        if (Cur_Item1->e == Cur_Item2->e)
        {
            Cur_Item1->data = Cur_Item1->data + Cur_Item2->data;
            if (Cur_Item1->data == 0)
            {
                Pre_Item->next = Cur_Item1->next;
                free(Cur_Item1);
                Cur_Item1 = Pre_Item->next;
                Cur_Item2 = Cur_Item2->next;
            } else
            {
                Pre_Item = Cur_Item1;
                Cur_Item1 = Cur_Item1->next;
                Cur_Item2 = Cur_Item2->next;
            }
        } else if (Cur_Item1->e < Cur_Item2->e)
        {
            Pre_Item = Cur_Item1;
            Cur_Item1 = Cur_Item1->next;
        } else
        {
            P_Polynomial temp;
            if (!(temp = (P_Polynomial) malloc(sizeof(Polynomial))))
            {
                printf("�ڴ治��!\n");
                exit(0);
            }
            temp->data = Cur_Item2->data;
            temp->e = Cur_Item2->e;
            temp->next = Cur_Item1;
            Pre_Item->next = temp;
            Pre_Item = Pre_Item->next;
            Cur_Item2 = Cur_Item2->next;
        }
    }
    while (Cur_Item2)
    {
        P_Polynomial temp;
        if (!(temp = (P_Polynomial) malloc(sizeof(Polynomial))))
        {
            printf("�ڴ治��!\n");
            exit(0);
        }
        temp->data = Cur_Item2->data;
        temp->e = Cur_Item2->e;
        temp->next = NULL;
        Pre_Item->next = temp;
        Pre_Item = Pre_Item->next;
        Cur_Item2 = Cur_Item2->next;
    }
}

void input(P_Polynomial P)
{
    int i=1;
    while (1)
    {
        float a;
        int b;
        scanf("%f%d",&a,&b);
        if(a==0||b==0)return;
        Insert_P_Polynomial(P,i++,a,b);
    }
}
void Display(P_Polynomial P1)
{
    while (P1->next)
    {
        printf("%.fX^%d",P1->next->data,P1->next->e);
        if (P1->next->next)
        {
            printf(P1->next->next->data > 0 ? " +" :" ");
        }
        P1=P1->next;
    }
}

main()
{
    P_Polynomial P1,P2;
    P1 = Creat_P_Polynomial();
    P2 = Creat_P_Polynomial();
    printf("�����ʽ:data e ����0 0��ʾ����\n");
    printf("���������ʽһ:\n");input(P1);
    printf("���������ʽ��:\n");input(P2);
    printf("\nA = ");Display(P1);
    printf("\nB = ");Display(P2);
    printf("\n�ϲ����:\nC =");
    Add_Polynomial(P1,P2);Display(P1);
    return 0;
}

#include "sorting.h"

int main()
{
    char *FileName1 = "Fruit.txt";
    char *FileName2 = "Cake.txt";
//    WriteFile(FileName1,Fruit);
//    WriteFile(FileName2,Cake);
    ReadFile(FileName1,Fruit);
    BubbleSort(Fruit);
    ReadFile(FileName2,Cake);
    HeapSort(Cake);
    struct Goods goods[2*size];
    MergeSort(goods);
    return 0;
}

void WriteFile(char *FileName, struct Goods *s)
{
    FILE *fp = NULL;
    if ((fp = fopen(FileName, "w")) == NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    for (int i = 1; i <= s[0].price; i++)
    {
        //scanf("%s %d",s->name,&s->price);
        fprintf(fp, "%s %d\n", s[i].name,s[i].price);
    }
    fclose(fp);
}

void ReadFile(char *FileName,struct Goods *s)
{
    FILE *fp = NULL;
    fp = fopen(FileName, "r");
    if (!fp)
    {
        printf("error!\n");
        exit(-1);
    }
    for (int i = 1; i <= size; i++)
    {
        fscanf(fp, "%s %d\n", s[i].name,&s[i].price);
    }
    fclose(fp);
}

void BubbleSort(struct Goods *s)
{
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 2; j <= size; ++j)
        {
            if (s[j].price > s[j - 1].price)
            {
                s[0] = s[j];
                s[j] = s[j - 1];
                s[j - 1] = s[0];
            }
        }
    }
    s[0].price = size;
    WriteFile("Fruits.txt", s);
}

void HeapAdjust(struct Goods *s, int n, int m)
{
    struct Goods rc = s[n];
    for (int j = 2 * n; j <= m; j = j * 2)
    {
        if (j < m && s[j].price > s[j + 1].price)
            j++;
        if (rc.price < s[j].price)break;
        s[n] = s[j];
        n = j;
    }
    s[n] = rc;
}

void HeapSort(struct Goods *s)
{
    int i;
    for (i = size / 2; i > 0; i--)
    {
        HeapAdjust(s, i, size);
    }
    for (i = size; i > 1; i--)
    {
        s[0] = s[1];
        s[1] = s[i];
        s[i] = s[0];
        HeapAdjust(s, 1, i - 1);
    }
    s[0].price = size;
    WriteFile("Cakes.txt", s);
}

void Merge(struct Goods r[], struct Goods rf[], int u, int v, int t)
{
    int i, j, k;
    for (i = u, j = v + 1, k = u; i <= v && j <= t; ++k)
    {
        if (r[i].price >= r[j].price)
        {
            rf[k] = r[i];
            i++;
        } else
        {
            rf[k] = r[j];
            j++;
        }
    }
    while (i <= v) { rf[k++] = r[i++]; }
    while (j <= t) { rf[k++] = r[j++]; }
}

void MSort(struct Goods p[], struct Goods p1[], int n, int t)
{
    int m;
    struct Goods p2[2*size + 1];
    if (n == t)p1[n] = p[n];
    else
    {
        m = (n + t) / 2;
        MSort(p, p2, n, m);
        MSort(p, p2, m + 1, t);
        Merge(p2, p1, n, m, t);
    }
}

void MergeSort(struct Goods *s)
{
    int buff = size;            //定义缓冲区大小
    struct Goods s1[buff + 1], s2[buff + 1];
        char FileName1[] = "Fruits.txt";
        char FileName2[] = "Cakes.txt";
        FILE *fp1 = NULL, *fp2 = NULL;
        fp1 = fopen(FileName1, "r");
        fp2 = fopen(FileName2, "r");
        for (int i = 1; i <= buff; i++)
        {
            fscanf(fp1, "%s %d\n", s1[i].name,&s1[i].price);
            fscanf(fp2, "%s %d\n", s2[i].name,&s2[i].price);
        }
        fclose(fp1);
        fclose(fp2);
        MSort(s, s, 1, buff);
        s[0].price = 2 * buff;
       WriteFile("goods.txt", s);
}
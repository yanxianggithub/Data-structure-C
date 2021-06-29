//
// Created by Yanxiang on 2021/6/6.
//
#include "sort.h"

int main()
{
    char *FileName = "student.txt";
    struct Student yiban[SIZE / 2 + 1], erban[SIZE / 2 + 1];
    ReadFile(FileName);
    Divide(yiban, erban);
    BubbleSort(yiban);
    HeapSort(erban);
    MergeSort(stu);
    return 0;
}

void WriteFile(char *FileName, struct Student *s)
{
    FILE *fp = NULL;
    if ((fp = fopen(FileName, "w")) == NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    for (int i = 1; i <= s[0].Number; i++)
    {
//        scanf("%d %s %s %s", &stu[i].number, stu[i].name, stu[i].sex, stu[i].class);
        fprintf(fp, "%-8d %-8s %-4s %-6d %-6d\n", s[i].Number, s[i].Name, s[i].Sex, s[i].Class, s[i].Grade);
    }
    fclose(fp);
}

void ReadFile(char *FileName)
{
    FILE *fp = NULL;
    fp = fopen(FileName, "r");
    if (!fp)
    {
        printf("error!\n");
        exit(-1);
    }
    for (int i = 1; i <= SIZE; i++)
    {
        fscanf(fp, "%d %s %s %d\n", &stu[i].Number, stu[i].Name, stu[i].Sex, &stu[i].Class);
    }
    fclose(fp);
    srand((unsigned) time(NULL));
    for (int i = 1; i <= SIZE; ++i)
    {
        stu[i].Grade = 400 + rand() % 200;
    }
//    for (int j = 1; j <= SIZE; j++)
//    {
//        printf("%d\t%s\t%s\t%d\t%d\n", stu[j].Number, stu[j].Name, stu[j].Sex, stu[j].Class, stu[j].Grade);
//    }
}

void Divide(struct Student *s1, struct Student *s2)
{
    int y = 1, e = 1;
    for (int i = 1; i <= SIZE; ++i)
    {
        if (stu[i].Class == 191)s1[y++] = stu[i];
        else s2[e++] = stu[i];
    }
    s1[0].Number = SIZE / 2;
    s2[0].Number = SIZE / 2;
}

void BubbleSort(struct Student *s)
{
    int buff = s[0].Number;
    for (int i = 1; i <= buff; ++i)
    {
        for (int j = 2; j <= buff - i; ++j)
        {
            if (s[j].Grade > s[j - 1].Grade)
            {
                s[0] = s[j];
                s[j] = s[j - 1];
                s[j - 1] = s[0];
            }
        }
    }
    s[0].Number = buff;
    WriteFile("BubbleSort.txt", s);
//    for (int j = 1; j <= s[0].Number; j++)
//    {
//        printf("%d\t%s\t%s\t%d\t%d\n", s[j].Number, s[j].Name, s[j].Sex, s[j].Class,s[j].Grade);
//    }
}

void HeapAdjust(struct Student *s, int n, int m)
{
    struct Student rc = s[n];
    for (int j = 2 * n; j <= m; j = j * 2)
    {
        if (j < m && s[j].Grade > s[j + 1].Grade)
            j++;
        if (rc.Grade < s[j].Grade)break;
        s[n] = s[j];
        n = j;
    }
    s[n] = rc;
}

void HeapSort(struct Student *s)
{
    int i;
    int buff = s[0].Number;
    for (i = buff / 2; i > 0; i--)
    {
        HeapAdjust(s, i, buff);
    }
    for (i = buff; i > 1; i--)
    {
        s[0] = s[1];
        s[1] = s[i];
        s[i] = s[0];
        HeapAdjust(s, 1, i - 1);
    }
    s[0].Number = buff;
    WriteFile("HeapSort.txt", s);
//    for (int j = 1; j <= s[0].Number; j++)
//    {
//        printf("%d\t%s\t%s\t%d\t%d\n", s[j].Number, s[j].Name, s[j].Sex, s[j].Class,s[j].Grade);
//    }
}

void Merge(struct Student r[], struct Student rf[], int u, int v, int t)
{
    int i, j, k;
    for (i = u, j = v + 1, k = u; i <= v && j <= t; ++k)
    {
        if (r[i].Grade >= r[j].Grade)
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

void MSort(struct Student p[], struct Student p1[], int n, int t)
{
    int m;
    struct Student p2[SIZE + 1];
    if (n == t)p1[n] = p[n];
    else
    {
        m = (n + t) / 2;
        MSort(p, p2, n, m);
        MSort(p, p2, m + 1, t);
        Merge(p2, p1, n, m, t);
    }
}

void MergeSort(struct Student *s)
{
    int buff = SIZE / 2;            //定义缓冲区大小
    struct Student s1[buff + 1], s2[buff + 1];
    //    scanf("%s%s",FileName1,FileName2);
    char FileName1[] = "BubbleSort.txt";
    char FileName2[] = "HeapSort.txt";
    FILE *fp1 = NULL, *fp2 = NULL;
    fp1 = fopen(FileName1, "r");
    fp2 = fopen(FileName2, "r");
    for (int i = 1; i <= buff; i++)
    {
        fscanf(fp1, "%d %s %s %d %d\n", &s1[i].Number, s1[i].Name, s1[i].Sex, &s1[i].Grade, &s1[i].Class);
        fscanf(fp2, "%d %s %s %d %d\n", &s2[i].Number, s2[i].Name, s2[i].Sex, &s2[i].Grade, &s2[i].Class);
    }
    fclose(fp1);
    fclose(fp2);
    MSort(s, s, 1, 2 * buff);
    s[0].Number = 2 * buff;
    for (int j = 1; j <= SIZE; j++)
    {
        printf("%d\t%s\t%s\t%d\t%d\n", s[j].Number, s[j].Name, s[j].Sex, s[j].Class,s[j].Grade);
    }
    WriteFile("students.txt", s);
}
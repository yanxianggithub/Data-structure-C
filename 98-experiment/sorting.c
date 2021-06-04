//
// Created by asus on 2021/5/28.
//
#include "sorting.h"

int main()
{
    struct Student boy[SIZE], girl[SIZE];
    char *FileName="Table.txt";
    ReadFile(FileName);
    Divide(boy, girl);
    BubbleSort(boy);
    HeapSort(girl);


    return 0;
}

void WriteFile(char *FileName,struct Student *s)
{
    FILE *fp = NULL;
    if ((fp = fopen(FileName, "w")) == NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    for (int i = 1; i < s[0].number; i++)
    {
        //scanf("%d %s %s %s", &stu[i].number, stu[i].name, stu[i].sex, stu[i].class);
        fprintf(fp, "%d %s %s %s\n", s[i].number, s[i].name, s[i].sex, s[i].class);
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
    for (int i = 1; i < SIZE; i++)
    {
        fscanf(fp, "%d %s %s %s\n", &stu[i].number, stu[i].name, stu[i].sex, stu[i].class);
    }
    fclose(fp);
//    for (int j = 1; j < SIZE; j++)
//    {
//        printf("%d\t%s\t%s\t%s\n", stu[j].number, stu[j].name, stu[j].sex, stu[j].class);
//    }
}

void Divide(struct Student *boy, struct Student *girl)
{
    boy[0].number = 1, girl[0].number = 1;
    char is_boy[4] = {'\304', '\320', '\0', '\0'};
    for (int i = 1; i < SIZE; ++i)
    {
        if (strcmp(stu[i].sex, is_boy) == 0)
            boy[boy[0].number++] = stu[i];
        else girl[girl[0].number++] = stu[i];
    }
}

void BubbleSort(struct Student *s)
{
    int size = s[0].number;
    for (int i = 1; i < size; ++i)
    {
        for (int j = 2; j <= size - i; ++j)
        {
            if (s[j].number < s[j - 1].number)
            {
                s[0] = s[j];
                s[j] = s[j - 1];
                s[j - 1] = s[0];
            }
        }
    }
    s[0].number=size;
    WriteFile("BubbleSort.txt",s);
//    for (int j = 1; j < size; j++)
//    {
//        printf("%d\t%s\t%s\t%s\n", s[j].number, s[j].name, s[j].sex, s[j].class);
//    }
}

void HeapAdjust(struct Student *s, int n, int m)
{
    struct Student rc=s[n];
    for (int j = 2 * n; j <= m; j = j * 2)
    {
        if (j < m && s[j].number < s[j + 1].number)
            j++;
        if (rc.number > s[j].number)break;
        s[n] = s[j];
        n = j;
    }
    s[n] = rc;
}

void HeapSort(struct Student *s)
{
    int i;
    int size = s[0].number-1;
    for (i = size / 2; i > 0; i--)
    {
        HeapAdjust(s, i, size);
    }
    for (i = size; i > 1; i--)
    {
        s[0]=s[1];
        s[1]=s[i];
        s[i]=s[0];
        HeapAdjust(s,1 , i - 1);
    }
    s[0].number=size + 1;
    WriteFile("HeapSort.txt",s);
//    for (int j = 1; j <= size; j++)
//    {
//        printf("%d\t%s\t%s\t%s\n", s[j].number, s[j].name, s[j].sex, s[j].class);
//    }
}
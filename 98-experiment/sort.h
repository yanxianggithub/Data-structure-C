//
// Created by asus on 2021/6/6.
//
#ifndef DATA_STRUCTURE_C_SORTING_H
#define DATA_STRUCTURE_C_SORTING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 78
struct Student{
    int Number;
    char Name[8];
    char Sex[4];
    int Class;
    int Grade;
}stu[SIZE];
void ReadFile(char *FileName);
void WriteFile(char *FileName,struct Student *s);
void HeapAdjust(struct Student *s,int n,int m);
void HeapSort(struct Student *s);
void Divide(struct Student *s1,struct Student *s2);
void BubbleSort(struct Student *s);
void Merge(struct Student r[], struct Student rf[], int u, int v, int t);
void MSort(struct Student p[],struct Student p1[],int n,int t);
void MergeSort(struct Student *s);
#endif //DATA_STRUCTURE_C_SORTING_H

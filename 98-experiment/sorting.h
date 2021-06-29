//
// Created by asus on 2021/6/6.
//
#ifndef DATA_STRUCTURE_C_SORTING_H
#define DATA_STRUCTURE_C_SORTING_H
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct Goods{
    char name[10];
    int price;
}Fruit[size],Cake[size];
void ReadFile(char *FileName,struct Goods *s);
void WriteFile(char *FileName,struct Goods *s);
void HeapAdjust(struct Goods *s, int n, int m);
void HeapSort(struct Goods *s);
void Divide(struct Goods *s1,struct Goods *s2);
void BubbleSort(struct Goods *s);
void Merge(struct Goods r[], struct Goods rf[], int u, int v, int t);
void MSort(struct Goods p[],struct Goods p1[],int n,int t);
void MergeSort(struct Goods *s);
#endif //DATA_STRUCTURE_C_SORTING_H

//
// Created by asus on 2021/5/28.
//

#ifndef DATA_STRUCTURE_C_SORTING_H
#define DATA_STRUCTURE_C_SORTING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 79
struct Student{
    int number;
    char name[8];
    char sex[4];
    char class[12];
}stu[SIZE];
void ReadFile(char *FileName);
void WriteFile(char *FileName,struct Student *s);
void HeapAdjust(struct Student *s,int n,int m);
void HeapSort(struct Student *s);
void BubbleSort(struct Student *s);
void Divide(struct Student *boy,struct Student *girl);
#endif //DATA_STRUCTURE_C_SORTING_H

//
// Created by asus on 2021/3/23.
//
#ifndef DATA_STRUCTURE_C_CIRCLELINKLIST_H
#define DATA_STRUCTURE_C_CIRCLELINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct node
{
    DataType data;             /*每个元素数据信息*/
    struct node *prior, *next; /*存放后继元素的地址*/
} CNode, *CircleLinkList;

CircleLinkList Creat_CircleLinkList(void);
void Destroy_CircleLinkList(CircleLinkList H);
int Length_DoubleLinkList(CircleLinkList H);
CircleLinkList Locate_CircleLinkList_Pos(CircleLinkList H, int i);
CircleLinkList Locate_CircleLinkList_Value(CircleLinkList H, int x);
int Insert_CircleLinkList(CircleLinkList H, int i, int x);
int Delete_CircleLinkList(CircleLinkList H, int i);
void Display_CircleLinkList(CircleLinkList CL, int a);

#endif //DATA_STRUCTURE_C_CIRCLELINKLIST_H

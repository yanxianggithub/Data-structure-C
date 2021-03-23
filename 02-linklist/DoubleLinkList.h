//
// Created by asus on 2021/3/21.
//
#ifndef DATA_STRUCTURE_C_DOUBLELINKLIST_H
#define DATA_STRUCTURE_C_DOUBLELINKLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;                  /*每个元素数据信息*/
    struct node *prior, *next; /*存放后继元素的地址*/
} DNode, *DoubleLinkList;

DoubleLinkList Creat_DoubleLinkList(void);
void Destroy_DoubleLinkList(DoubleLinkList H);
int Length_DoubleLinkList(DoubleLinkList H);
DoubleLinkList Locate_DoubleLinkList_Pos(DoubleLinkList H, int i);
DoubleLinkList Locate_DoubleLinkList_Value(DoubleLinkList H, int x);
int Insert_DoubleLinkList(DoubleLinkList H, int i, int x);
int Delete_DoubleLinkList(DoubleLinkList H, int i);
void Display_DoubleLinkList(DoubleLinkList DL);

#endif //DATA_STRUCTURE_C_DOUBLELINKLIST_H

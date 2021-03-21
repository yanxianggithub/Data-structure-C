//
// Created by asus on 2021/3/21.
//
#ifndef DATA_STRUCTURE_C_DOUBLELINKLIST_H
#define DATA_STRUCTURE_C_DOUBLELINKLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          /*每个元素数据信息*/
    struct node *prior,*next; /*存放后继元素的地址*/
} DNode, *DoubleLinkList;









#endif //DATA_STRUCTURE_C_DOUBLELINKLIST_H

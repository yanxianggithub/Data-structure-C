#pragma once
#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct node
{
    DataType data;     /*每个元素数据信息*/
    struct node *next; /*存放后继元素的地址*/
} LNode, *SingleLinkList;

SingleLinkList Creat_SingleLinkList(void);
void Destroy_SingleLinkList(SingleLinkList H);
int Length_SingleLinkList(SingleLinkList H);
SingleLinkList Locate_SingleLinkList_Pos(SingleLinkList H, int i);
SingleLinkList Locate_SingleLinkList_Value(SingleLinkList H, int x);
int Insert_SingleLinkList(SingleLinkList H, int i, int x);
int Delete_SingleLinkList(SingleLinkList H, int i);
void Reverse_SingleLinkList(SingleLinkList H);
void Display_SingleLinkList(SingleLinkList LL);
int josephus_SingleLinkList(SingleLinkList josephus_Link, int s, int m);
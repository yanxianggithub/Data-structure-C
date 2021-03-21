#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          /*每个元素数据信息*/
    struct node *next; /*存放后继元素的地址*/
} LNode, *SingleLinkList;

SingleLinkList Creat_LinkList(void);
void Destroy_LinkList(SingleLinkList H);
int Length_LinkList(SingleLinkList H);
SingleLinkList Locate_LinkListi(SingleLinkList H, int i);
SingleLinkList Locate_LinkListx(SingleLinkList H, int x);
int Insert_LinkList(SingleLinkList H, int i, int x);
int Del_LinkList(SingleLinkList H, int i);
void Reverse_LinkList(SingleLinkList H);
void Display_LinkList(SingleLinkList LL);
int josephus_LinkList(SingleLinkList josephus_Link, int s, int m);
#pragma once

typedef struct node
{
    int data;          /*每个元素数据信息*/
    struct node *next; /*存放后继元素的地址*/
} LNode, *LinkList;

LinkList Creat_LinkList(void);
void Destroy_LinkList(LinkList H);
int Length_LinkList(LinkList H);
LinkList Locate_LinkListi(LinkList H, int i);
LinkList Locate_LinkListx(LinkList H, int x);
int Insert_LinkList(LinkList H, int i, int x);
int Del_LinkList(LinkList H, int i);
void Display_LinkList(LinkList LL);

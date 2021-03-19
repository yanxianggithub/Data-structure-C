#pragma once

typedef struct node
{
    int data;          /*每个元素数据信息*/
    struct node *next; /*存放后继元素的地址*/
} LNode, *CircleLinkList;

CircleLinkList Creat_LinkList(void);
void Destroy_LinkList(CircleLinkList H);
int Length_LinkList(CircleLinkList H);
CircleLinkList Locate_LinkListi(CircleLinkList H, int i);
CircleLinkList Locate_LinkListx(CircleLinkList H, int x);
int Insert_LinkList(CircleLinkList H, int i, int x);
int Del_LinkList(CircleLinkList H, int i);
void Reverse_LinkList(CircleLinkList H);
void Display_LinkList(CircleLinkList LL);
int josephus_LinkList(CircleLinkList josephus_Link, int s, int m);
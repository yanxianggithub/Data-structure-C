#pragma once

typedef struct node
{
    int data;
    struct node *prior, *next;
} DuNode, *DLinkList;

DLinkList Creat_DoubleLinkList(void);
void Destroy_DoubleLinkList(DLinkList H);
int Length_DoubleLinkList(DLinkList H);
DLinkList Locate_DoubleLinkListi(DLinkList H, int i);
DLinkList Locate_DoubleLinkListx(DLinkList H, int x);
int Insert_DoubleLinkList(DLinkList H, int i, int x);
int Del_DoubleLinkList(DLinkList H, int i);
void Display_DoubleLinkList(DLinkList LL);
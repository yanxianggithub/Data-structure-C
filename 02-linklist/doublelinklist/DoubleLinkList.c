#include <stdio.h>
#include "DoubleLinkList.h"

int main()
{
}

DLinkList Creat_DoubleLinkList(void)
{
    DLinkList DL;
    DL = (DLinkList)malloc(sizeof(DuNode));
    if (DL) /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
        DL->next = NULL;
    return DL;
}

void Destroy_DoubleLinkList(DLinkList H)
{
    printf("LL");
}

int Length_DoubleLinkList(DLinkList H)
{
}

DLinkList Locate_DoubleLinkListi(DLinkList H, int i)
{
}

DLinkList Locate_DoubleLinkListx(DLinkList H, int x)
{
}

int Insert_DoubleLinkList(DLinkList H, int i, int x)
{
}

int Del_DoubleLinkList(DLinkList H, int i)
{
}

void Display_DoubleLinkList(DLinkList LL)
{
}

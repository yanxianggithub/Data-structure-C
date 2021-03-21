//
// Created by asus on 2021/3/21.
//
#include "DoubleLinkList.h"

int main()
{
    DoubleLinkList DL;
    DL = Creat_DoubleLinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_DoubleLinkList(DL, i, i);
    }                           /*双向链表赋值*/
    Display_DoubleLinkList(DL); //输出双向链表
    //Locate_DoubleLinkListi(DL, 2); //检索链表位置2元素
    //Del_DoubleLinkList(DL, 2);     //删除链表位置2元素
    //Display_DoubleLinkList(DL);
    //Destroy_DoubleLinkList(DL);

    return 0;
}


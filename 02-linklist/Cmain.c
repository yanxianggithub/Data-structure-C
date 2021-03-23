//
// Created by asus on 2021/3/23.
//
#include "CircleLinkList.h"

int main()
{
    CircleLinkList CL;
    CL = Creat_CircleLinkList();
    for(int i = 1;i <=5 ;i++)
    {
        Insert_CircleLinkList(CL,i,i);
    }
    Display_CircleLinkList(CL,12);
    Delete_CircleLinkList(CL,2);
    printf("\n");
    Display_CircleLinkList(CL,12);


}

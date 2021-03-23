#include "SingleLinkList.h"

int main()
{
    SingleLinkList LL;
    LL = Creat_SingleLinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_SingleLinkList(LL, i, i);
    }                           //插入数据
    Display_SingleLinkList(LL); //输出链表
    Reverse_SingleLinkList(LL); //逆置链表
    Display_SingleLinkList(LL); //输出逆置链表
    printf("Length:");
    printf("%d  ", Length_SingleLinkList(LL));
    Delete_SingleLinkList(LL, 2);
    printf("%d", Length_SingleLinkList(LL));
    josephus_SingleLinkList(LL, 3, 3);
    Destroy_SingleLinkList(LL);

    return 0;
}

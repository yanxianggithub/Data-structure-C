#include"LinkList.h"

int main()
{
    SingleLinkList LL;
    LL = Creat_LinkList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_LinkList(LL, i, i);
    }                     //插入数据
    Display_LinkList(LL); //输出链表
    Reverse_LinkList(LL); //逆置链表
    Display_LinkList(LL); //输出逆置链表
    printf("Length:");
    printf("%d  ", Length_LinkList(LL));
    Del_LinkList(LL, 2);
    printf("%d", Length_LinkList(LL));
    josephus_LinkList(LL, 3, 3);
    Destroy_LinkList(LL);

    return 0;
}



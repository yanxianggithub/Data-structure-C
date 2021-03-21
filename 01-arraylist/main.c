#include "ArrayList.h"

int main()
{
    PSeqList PL;
    PL = Init_SeqList();
    for (int i = 1; i <= 10; i++)
    {
        Insert_SeqList(PL, i, i);
    } //插入10个元素

    Display_SeqList(PL); //输出
    Reverse_SeqList(PL); //逆置
    printf("\n");
    Display_SeqList(PL); //输出逆置
    printf("\n");
    printf("%d  ", Length_SeqList(PL)); //返回数组长度
    Delete_SeqList(PL, 3);              //删除数组元素3
    printf("%d", Location_SeqList(PL, 3)); //索引数组下标为3的元素
    printf("\n");
    josephus_SeqList(PL, 2, 2); //约瑟夫环
    Destroy_SeqList(PL); //销毁数组
    return 0;
}

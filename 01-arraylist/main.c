#include"List.h"
int main(){
    SeqList L;
    PSeqList PL;
    PL=&L;
    Init_SeqList();
    Insert_SeqList(PL,1,1);
    Display_SeqList(PL);
}
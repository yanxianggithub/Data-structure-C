#include <stdio.h>
#include<stdlib.h>
#define MaxTreeNodeNum 10
#define DataType int
typedef struct bnode
{
    DataType data;
    struct bnode *lchild, *rchild;
} Bnode, *BTree;

void PreOrder(BTree t);
void InOrder(BTree t);
void PostOrder(BTree t);
int CountTree(BTree t);
int Height(BTree t);
BTree CopyTree(BTree t);
BTree CreateBinTree();
void Print(BTree t);
void Visit(int a);

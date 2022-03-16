#include <stdio.h>

#define MaxTreeNodeNum 100

typedef struct
{
    DataType data[MaxTreeNodeNum];
    int n;
} QBTree;

void PreOrder(BTree t);
void InOder(BTree t);
void PostOrder(BTree t);
int CountTree(BTree t);
int Height(BTree t);


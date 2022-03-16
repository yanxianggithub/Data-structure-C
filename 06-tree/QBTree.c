#include "QBTree.h"

int main()
{
}

void PreOrder(BTree t)
{
    if (t)
    {
        Visit(t->data);
        PreOder(t->lchild);
        PreOder(t->rchild);
    }
}

void InOrder(BTree t)
{
    if (t)
    {
        PreOder(t->lchild);
        Visit(t->data);
        PreOder(t->rchild);
    }
}
void PostOrder(BTree t)
{
    if (t)
    {
        PreOder(t->lchild);
        PreOder(t->rchild);
        Visit(t->data);
    }
}
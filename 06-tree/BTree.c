#include "BTree.h"

int main()
{
    BTree T = CreateBinTree();
    PreOrder(T);
    printf("%d", CountTree(T));
    return 0;
}

BTree CreateBinTree()

{
    BTree t;
    char ch;
    ch = getchar();
    if(ch=='#')
        t == NULL;
        else
        {
            t = (Bnode *)malloc(sizeof(Bnode));
            t->data = ch;
            t->lchild = CreateBinTree();
            t->rchild = CreateBinTree();
        }
        return t;
}
void Visit(int a)
{
    printf("%d", a);
}

void PreOrder(BTree t)
{
    if (t)
    {
        Visit(t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void InOrder(BTree t)
{
    if (t)
    {
        PreOrder(t->lchild);
        Visit(t->data);
        PreOrder(t->rchild);
    }
}
void PostOrder(BTree t)
{
    if (t)
    {
        PreOrder(t->lchild);
        PreOrder(t->rchild);
        Visit(t->data);
    }
}

int CountTree(BTree t)
{
    int lcount, rcount;
    if(t == NULL)
        return 0;
    lcount = CountTree(t->lchild);
    rcount = CountTree(t->rchild);
    return lcount + rcount + 1;
}
int Height(BTree t)
{
    int h1, h2;
    if(t==NULL)
        return 0;
        else
        {
            h1 = Height(t->lchild);
            h2 = Height(t->rchild);
            if(h1>h2)
                return h1 + 1;
            return h2 + 1;
        }
}
BTree CopyTree(BTree t)
{
    BTree p, q, s;
    if(t==NULL)
        return NULL;
    p = CopyTree(t->lchild);
    q = CopyTree(t->rchild);
    s = (BTree *)malloc(sizeof(Bnode));
    s->data = t->data;
    s->lchild = p;
    s->rchild = q;
    return s;
}
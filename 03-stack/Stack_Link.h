#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct node
{
    DataType data;
    struct node *next;
} StackNode, *PStackNode;

typedef struct
{
    PStackNode top;
} LinkStack, *PLinkStack;

PLinkStack Init_LinkStack(void);
void Destroy_LinkStack(PLinkStack LS);
int Empty_LinkStack(PLinkStack S);
int Push_LinkStack(PLinkStack S, DataType x);
int Pop_LinkStack(PLinkStack S);
int GetTop_LinkStack(PLinkStack S);
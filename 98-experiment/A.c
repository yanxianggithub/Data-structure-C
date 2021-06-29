//
// Created by asus on 2021/6/21.
//
# include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 20
typedef struct edgenode {
    int endvex;    /*相邻顶点在顶点表中的下标*/
    int weight;   /*头边的权值*/
    struct edgenode *nextedge;  /*链字段*/
} EdgeNode, *EdgeList;  /*边表中的结点*/
typedef struct {
    int vertex;    /*顶点*/
    EdgeList edgelist;  /*边表头指针*/
} VexNode;   /*顶点表中的结点*/
typedef struct {
    int vexnum;
    int arcnum;
    VexNode *vexs;
} GraphList;

void FindInDegree(GraphList *G, int *indegree);
int TopoSort(GraphList *G, int *ptopo);

int CriticalPath(GraphList *G)
{
    int i, j, k, sum = 0;
    EdgeList p;
    int *ee = (int *) malloc(sizeof(int) *G->vexnum);
    int *le = (int *) malloc(sizeof(int) *G->vexnum);
    int *l = (int *) malloc(sizeof(int) *G->vexnum);
    int *e = (int *) malloc(sizeof(int) *G->vexnum);
    int *topo = (int *) malloc(sizeof(int) *G->vexnum);
    if (TopoSort(G, topo) == 0)
    {
        printf("The AOE network has a cycle!\n");
        getch();
        return (0);
    }
/*求事件可能的最早发生时间*/
    for (i = 0; i < G->vexnum; i++)
        ee[i] = 0;
    for (k = 0; k < G->vexnum; k++)
    {
        i = topo[k];
        p = G->vexs[i].edgelist;
        while (p != NULL)
        {
            j = p->endvex;
            if (ee[i] + p->weight > ee[j])
                ee[j] = ee[i] + p->weight;
            p = p->nextedge;
        }
    }
    sum = ee[G->vexnum - 1];
    for (i = 0; i < G->vexnum; i++)
        e[i] = ee[G->vexnum - 1];
    for (k = G->vexnum - 2; k >= 0; k--)
    {
        i = topo[k];
        p = G->vexs[i].edgelist;
        while (p != NULL)
        {
            j = p->endvex;
            if ((le[j] - p->weight) < le[i])
                le[i] = le[j] - p->weight;
            p = p->nextedge;
        }
    }

    k = 0;
    printf("\nThe Critical Path:\n");
/*求活动ak的最早开始时间e(k) 和最晚开始时间1(k)*/
    printf("\n| Active  |   Early   |   Late    |   L-E    |   IsCritical   \n");
    for (i = 0; i < G->vexnum; i++)
    {
        p = G->vexs[i].edgelist;
        while (p != NULL)
        {
            j = p->endvex;
            e[k] = ee[i];
            l[k] = le[j] - p->weight;
            printf("|   <%d,%d>    |    %4d    |    %4d    |%4d    |  ", i, j, e[k], l[k], l[k] - e[k]);
            if (e[k] == l[k])
                printf("Critical");
            printf("\n");
            k++;
            p = p->nextedge;
        }
    }
    printf("\nThe shortest time is: %d\n", sum);
    getch();
    return (1);
}

void InitGraph(GraphList *G)
{
    int i, vexnum, arcnum, weight = 0;
    int v1, v2;
    EdgeList p;
    printf("Please input the vertexnum and the arcnum-->Form:(x,y)\n");
    scanf("%d,%d", &vexnum, &arcnum);

    G->vexnum = vexnum;
    G->arcnum = arcnum;
    for (i = 0; i < vexnum; i++)
    {
        G->vexs[i].vertex = i + 1;
        G->vexs[i].edgelist = NULL;
    }
    for (i = 0; i < arcnum; i++)
    {
        printf("Please input The %d Edge (For Example: 1,2,10)\n", i + 1);
        scanf("%d, %d, %d", &v1, &v2, &weight);
        if (v1 > G->vexnum || v2 > G->vexnum)
        {
            printf("The Node You Hava Just Input Is Not In The Vexs! !");
            getch();
            exit(0);
        }
        p = (EdgeList) malloc(sizeof(EdgeNode));
        p->endvex = v2;
        p->weight = weight;
        p->nextedge = G->vexs[v1].edgelist;
        G->vexs[v1].edgelist = p;
    }
}

int TopoSort(GraphList *G, int *ptopo)
{
    EdgeList p;
    int i, j, k, nodeno = 0, top = -1;
    int *indegree = (int *) malloc(sizeof(int) * G->vexnum);
    FindInDegree(G, indegree);
    for (i = 0; i < G->vexnum; i++)
        if (indegree[i] == 0)
        { /*静态链式栈*/
            indegree[i] = top;
            top = i;
        }
    while (top != -1)
    {
        j = top;
        top = indegree[top];
        ptopo[nodeno++] = j;
        p = G->vexs[j].edgelist;
        while (p)
        {
            k = p->endvex;
            indegree[k]--;
            if (indegree[k] == 0)
            {
                indegree[k] = top;
                top = k;
            }
            p = p->nextedge;
        }
    }
    free(indegree);
    if (nodeno < G->vexnum)
        return (0);
    else
        return (1);
}
void FindInDegree(GraphList *G, int *indegree)
{
    int i;
    EdgeList p;
    for (i = 0; i < G->vexnum; i++)
        indegree[i] = 0;
    for (i = 0; i < G->vexnum; i++)
    {
        p = G->vexs[i].edgelist;
        while (p)
        {
            ++indegree[p->endvex];
            p = p->nextedge;
        }
    }
}

void TopoSortMenu(void)
{
    int *ptopo;
    int i;
    GraphList *Graph = (GraphList *) malloc(sizeof(GraphList));
    system("cls");
    InitGraph(Graph);
    ptopo = (int *) malloc(sizeof(int) * Graph->vexnum);
    if (TopoSort(Graph, ptopo) != 0)
    {
        printf("\nTopSort Result:\n");
        for (i = 0; i < Graph->vexnum - 1; i++)
            printf("v%d-->", ptopo[i]);
        printf("v%d", ptopo[i]);
    } else
        printf("The AOV network has a cycle!\n");
    getch();
    free(ptopo);
    free(Graph);
}

void CriticalMenu(void)
{
    GraphList *Graph = (GraphList *) malloc(sizeof(GraphList));
    system("cls");
    InitGraph(Graph);
    CriticalPath(Graph);
    free(Graph);
}

void TopoCriticalMenu(void)
{
    char ch;
    while (1)
    {
        system("cls");
        printf("1.Topo Sort\n2.Critical Path\n0.Exit\n");
        ch = getch();
        switch (ch - '0')
        {
            case 0:
                exit(0);
            case 1:
                TopoSortMenu();
                break;
            case 2:
                CriticalMenu();
                break;
            default:
                system("cls");
                continue;
        }
    }
}

int main(void)
{
    TopoCriticalMenu();
}

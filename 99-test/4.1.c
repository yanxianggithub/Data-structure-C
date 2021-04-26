//
// Created by asus on 2021/4/18.
//
#include <stdio.h>
#include <string.h>
void StrDelete(char *S, int i, int m);
int main()
{
    int i, m;
    char x[100];
    printf("input a string:");
    scanf("%s", x);
    printf("input the location:");
    scanf("%d", &i);
    printf("input lenth:");
    scanf("%d", &m);
    StrDelete(x, i, m);
    printf("%s", x);
}

void StrDelete(char *S, int i, int m)
{
    if (i >= strlen(S));
    else if (i + m >= strlen(S))
    {
        S[i - 1] = '\0';
    } else
    {
        int x=0,y=0;
        char p[strlen(S)];
        strcpy(p,S);
        while (p[x])
        {
            if(x<i-1||x>=i+m-1)
                S[y++]=p[x];
            x++;
        }
        S[y]='\0';
    }
}
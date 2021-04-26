//
// Created by asus on 2021/4/18.
//
#include <stdio.h>
#include <string.h>
void st(char* s,char* t);
int main()
{
    char s[]={"hello world"};
    char t[]={"world"};
    st(s,t);
    return 0;
}

void st(char* s,char* t)
{
    if(strstr(s,t) == NULL)printf("No!");
    else printf("Yes!");
}
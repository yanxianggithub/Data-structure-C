//
// Created by asus on 2021/4/23.
//                        A.卡片
//【问题描述】
//小蓝有很多数字卡片，每张卡片上都是数字 0 到 9。
//小蓝准备用这些卡片来拼一些数，他想从 1 开始拼出正整数，每拼一个，
//就保存起来，卡片就不能用来拼其它数了。
//小蓝想知道自己能从 1 拼到多少。
//例如，当小蓝有 30 张卡片，其中 0 到 9 各 3 张，则小蓝可以拼出 1 到 10，
//但是拼 11 时卡片 1 已经只有一张了，不够拼出 11。
//现在小蓝手里有 0 到 9 的卡片各 2021 张，共 20210 张，请问小蓝可以从 1
//拼到多少？
//////////////////////////////////////////////////////////////
//开个数组存下0-9卡牌的数量，
//然后从1开始往后遍历
//每次都分解当前遍历的数
//如果出现卡牌数量为零
//说明当前数无法拼出
//直接输出上一个数
//答案：3181
//////////////////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int count=1;
    int a[10]={2021,2021,2021,2021,2021,2021,2021,2021,2021,2021};
    while (1)
    {
        int i = count;
        while (i)
        {
            if (a[i%10] == 0)
            {
                printf("%d", count-1);
                return 0;
            }
            a[i%10]--;
            i /= 10;
        }
        count++;
    }
}
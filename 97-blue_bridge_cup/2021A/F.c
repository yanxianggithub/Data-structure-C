//
// Created by asus on 2021/4/24.
//                    F.砝码称重
//【问题描述】
//你有一架天平和 N 个砝码，这 N 个砝码重量依次是 W1, W2, · · · , WN。
//请你计算一共可以称出多少种不同的重量？
//注意砝码可以放在天平两边。
//【输入格式】
//输入的第一行包含一个整数 N。
//第二行包含 N 个整数：W1, W2, W3, · · · , WN。
//【输出格式】
//输出一个整数代表答案。
//【样例输入】
//3
//1 4 6
//【样例输出】
//10
//【样例说明】
//能称出的 10 种重量是：1、2、3、4、5、6、7、9、10、11。
//1 = 1；
//2 = 6 − 4 (天平一边放 6，另一边放 4)；
//3 = 4 − 1；
//4 = 4；
//5 = 6 − 1；
//6 = 6；
//7 = 1 + 6；
//9 = 4 + 6 − 1；
//10 = 4 + 6；
//11 = 1 + 4 + 6。
//【评测用例规模与约定】
//对于 50% 的评测用例，1 ≤ N ≤ 15。
//对于所有评测用例，1 ≤ N ≤ 100，N 个砝码总重不超过 100000。
///////////////////////////////////////////////////////

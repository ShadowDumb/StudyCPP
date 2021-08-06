/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 9:22:47
 * @LastEditTime: 2021-08-03 19:57:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \005.随机数\main.cpp
 */
#include <iostream>
#include <time.h>

using namespace std;

int main()
{

    srand(time(0));             // 使用时间作为随机数种子

    int x = rand()%100 + 1;     // 生成 1 到 100 之间的随机数
    cout << x << endl;
    return 0;
}

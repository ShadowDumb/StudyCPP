/*
 * @Author: ShadowDumb
 * @Date: 2021-07-31 16:22:25
 * @LastEditTime: 2021-08-01 18:10:22
 * @LastEditors: Please set LastEditors
 * @Description: 条件编译可以用于注释，也可用于程序调试，测试时使用 #if 1 来执行测试代码，发布后使用 #if 0 来屏蔽测试代码。
 * @FilePath: \002.条件编译\main.cpp
 */

#include <iostream>

using namespace std;

int main()
{
    #if 1 //条件
        cout << "非0\n"; //如果非0则编译这里的代码
    #else
        cout << "为0" << endl; //如果为0则编译这里的代码
    #endif
    return 0;
}

/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 9:12:57
 * @LastEditTime: 2021-08-03 19:56:10
 * @LastEditors: Please set LastEditors
 * @Description: 将数字参数相加并输出结果
 * @FilePath: \004.main函数的参数\.vscode\main.c
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])    // argc 表示运行时的参数的段落数，argv 表示参数
{
    int i, num;
    int s = 0;
    for(i = 1; i < argc; i++)
    {
        num = atoi(argv[i]);        // atoi() 是数字字符串转数字的函数
        s = s + num;
    }
    cout << s << endl;
    return 0;
}

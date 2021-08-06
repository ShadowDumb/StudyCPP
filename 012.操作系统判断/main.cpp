/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 17:49:25
 * @LastEditTime: 2021-08-03 20:12:06
 * @LastEditors: Please set LastEditors
 * @Description: 编译器参数或 Makefile 添加或内置了宏定义，比如 MS VC 的 cl.exe，Linux 的 GNU GCC，在各个平台都有不同的内置宏
 * @FilePath: \012.操作系统判断\main.cpp
 */
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int no_os_flag = 1;
    #ifdef linux
        no_os_flag = 0;
        cout << "Linux" << endl;
    #endif
    #ifdef _UNIX
        no_os_flag = 0;
        cout << "UNIX" << endl;
    #endif
    #ifdef __WINDOWS_
        no_os_flag = 0;
        cout << "Windows" << endl;
    #endif
    #ifdef _WIN32
        no_os_flag = 0;
        cout << "Win32" << endl;
    #endif
    #ifdef __sun
        no_os_flag = 0;
        cout << "Solaris" << endl;
    #endif
    if(no_os_flag)
    {
        cout << "Unknow" << endl;
    }
    return 0;
}

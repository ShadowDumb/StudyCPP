/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 16:34:04
 * @LastEditTime: 2021-08-03 20:11:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \011.数字雨\main.cpp
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(double seconds)   // 延时函数，单位秒，可以是小数
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while(clock() < endwait);
}

int main(int argc, char* argv[])
{
    int count, i;

    if(argv[1] != NULL)
    {
        count = atoi(argv[1]);
    }
    else
    {
        count = 65536;      // 如果没有参数，默认为 65536
    }

    system("color 0a");     // 给终端字体上色

    for(i = 0; i < count; i++)
    {
        if(i%15 == 0)       // 每行达到 15 个就换行
        {
            printf("\n");
            wait(0.1);      // 延时 100 毫秒
        }
        if(rand()%3 == 0)   // 随机生成断点
        {
            printf("\t");
        }
        else
        {
            printf("%c\t", rand()%94 + 32);  // 打印随机生成的字符
        }
    }
    return 0;
}

/*
 * @Author: ShadowDumb
 * @Date: 2021-08-03 14:14:05
 * @LastEditTime: 2021-08-03 19:59:32
 * @LastEditors: Please set LastEditors
 * @Description: 创建两个线程分别打印 1 ~ 50
 * @FilePath: \013.多线程\main.cpp
 */
#include <iostream>
#include <pthread.h>

using namespace std;

pthread_mutex_t lock;               // 定义锁

void* myfunc(void* args)            // 输出  1 ~ 50
{
    pthread_mutex_lock(&lock);      // 加锁，使得各个线程执行时不冲突，但锁定的代码段只能同时被一个线程运行
    int i;
    for(i = 1; i <= 50; i++)
    {
        cout << i << endl;
    }
    pthread_mutex_unlock(&lock);    // 解锁
    return NULL;
}

int main()
{
    // 创建线程变量
    pthread_t th1;
    pthread_t th2;

    // 初始化锁
    pthread_mutex_init(&lock, NULL);

    // 创建线程
    pthread_create(&th1, NULL, myfunc, NULL);
    pthread_create(&th2, NULL, myfunc, NULL);

    // 等待线程结束
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}

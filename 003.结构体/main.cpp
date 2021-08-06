/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 09:01:55
 * @LastEditTime: 2021-08-03 20:09:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \003.结构体\main.cpp
 */
#include <iostream>
#include <string.h>

using namespace std;

struct student
{
    int id;
    char name[20];
    float score;
};

int main()
{
    student a;
    a.id = 1001;
    strcpy(a.name, "张三");
    a.score = 87.5;

    cout << a.id << endl;
    cout << a.name << endl;
    cout << a.score << endl;

    return 0;
}

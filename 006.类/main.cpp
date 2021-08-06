/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 09:37:40
 * @LastEditTime: 2021-08-03 20:08:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \006.类\main.cpp
 */
#include <iostream>

using namespace std;

class Cube
{
    public:     // 类访问修饰符，可选 public, private, protected
        float length;       // 长度
        float breadth;      // 宽度
        float height;       // 高度
        float Volume()      // 体积
        {
            return length * breadth * height;
        }
        float Surface();    // 表面积，类成员函数声明
};

float Cube::Surface()       // 在类的外部定义类成员函数，但需要先在类的内部声明
{
    return ((length * breadth) + (length * height) + (breadth * height)) * 2;
}

int main(int argc, char* argv[])
{
    Cube Cube1;
    float Volume;       // 存储体积
    float Surface;      // 存储表面积

    if ((argv[1] != NULL) && (argv[2] != NULL) && (argv[3] != NULL))
    {
        Cube1.length = atoi(argv[1]);       // atoi 是数字字符串转数字的函数
        Cube1.breadth = atoi(argv[2]);
        Cube1.height = atoi(argv[3]);
    }
    else
    {
        cout << "请输入立方体长度：";
        cin >> Cube1.length;
        cout << "请输入立方体宽度：";
        cin >> Cube1.breadth;
        cout << "请输入立方体高度：";
        cin >> Cube1.height;
    }

    Volume = Cube1.Volume();
    Surface = Cube1.Surface();

    cout << "立方体的体积：" << Volume << endl;
    cout << "立方体的表面积：" << Surface << endl;

    return 0;
}

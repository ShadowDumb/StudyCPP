/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 10:29:32
 * @LastEditTime: 2021-08-03 20:10:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \007.类的派生\main.cpp
 */
#include <iostream>

using namespace std;

class Round
{
    protected:
        float Radius;       // 半径
};

class Ball:Round
{
    public:
        void SetRadius( float radius);
        float GetRadius();
        float GetSurface();
};

void Ball::SetRadius( float radius )
{
    Radius = radius;
}

float Ball::GetRadius()
{
    return Radius;
}

float Ball::GetSurface()
{
    return 4 * 3.14159 * Radius * Radius;
}

int main(int argc, char* argv[])
{
    float Radius;
    float Surface;
    Ball a;

    if(argv[1] != NULL)
    {
        Radius = atoi(argv[1]);
    }
    else
    {
        cout << "请输入球体半径：";
        cin >> Radius;
    }

    a.SetRadius(Radius);
    Surface = a.GetSurface();

    cout << "球体表面积为：" << Surface << endl;

    return 0;
}

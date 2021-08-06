/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 15:52:11
 * @LastEditTime: 2021-08-03 20:11:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \010.重载函数\main.cpp
 */
#include <iostream>

using namespace std;

class PrintData
{
    public:
        void print(int i)
        {
            cout << "整数为：" << i << endl;
        }
        void print(double f)
        {
            cout << "小数为：" << f << endl;
        }
        void print(char c[])
        {
            cout << "字符串：" << c << endl;
        }
};

int main(int argc, char* argv[])
{
    PrintData pd;
    if(argv[1] != NULL)
    {
        pd.print(atoi(argv[1]));
        pd.print(atof(argv[1]));
        pd.print(argv[1]);
    }
}

/*
 * @Author: ShadowDumb
 * @Date: 2021-08-04 09:24:40
 * @LastEditTime: 2021-08-04 10:20:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \015.文件操作\main.cpp
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char Data[100];

    ofstream writefile;
    writefile.open("test.txt", ios::app);

    cout << "请输入：";
    cin >> Data;
    cin.ignore();
    writefile << Data << endl;
    writefile.close();

    ifstream readfile;
    readfile.open("test.txt", ios::in);
    cout << "读取……" << endl;
    readfile >> Data;
    cout << Data << endl;
    readfile.close();

    return 0;
}

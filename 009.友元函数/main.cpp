/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 15:09:12
 * @LastEditTime: 2021-08-03 20:11:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \009.友元函数\main.cpp
 */
#include <iostream>

using namespace std;

class MAP
{
    private:
        int ROW;
        int COLUME;
    public:
        friend int GetMAP(MAP table);
        void SetROW(int row);
        void SetCOLUME(int colume);
};

int GetMAP(MAP table)
{
    return table.ROW * table.COLUME;
}

void MAP::SetROW(int row)
{
    ROW = row;
}

void MAP::SetCOLUME(int colume)
{
    COLUME = colume;
}

int main(int argc, char* argv[])
{
    MAP table;
    int map;

    if((argv[1] != NULL) && (argv[2] != NULL))
    {
        table.SetROW(atoi(argv[1]));
        table.SetCOLUME(atoi(argv[2]));
    }

    map = GetMAP(table);

    cout << map;
}

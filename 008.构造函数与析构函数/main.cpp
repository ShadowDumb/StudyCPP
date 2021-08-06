/*
 * @Author: ShadowDumb
 * @Date: 2021-08-01 11:08:00
 * @LastEditTime: 2021-08-03 20:10:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \008.构造函数与析构函数\main.cpp
 */
#include <iostream>
#include <cstring>

using namespace std;

class student
{
    protected:
        int ID;
        char NAME[50];
        float SCORE;
};

class DianXinBan:student
{
    public:
        void SetID(int id);
        void SetNAME(const char *name);
        void SetSCORE(float score);
        int GetID();
        char* GetNAME();
        float GetSCORE();
        DianXinBan();       // 构造函数，在创建类时自动执行
        ~DianXinBan();      // 析构函数，在删除类时自动执行
};

void DianXinBan::SetID(int id)
{
    ID = id;
}

void DianXinBan::SetNAME(const char* name)
{
    strcpy(NAME, name);
}

void DianXinBan::SetSCORE(float score)
{
    SCORE = score;
}

int DianXinBan::GetID()
{
    return ID;
}

char* DianXinBan::GetNAME()
{
    return NAME;
}

float DianXinBan::GetSCORE()
{
    return SCORE;
}

DianXinBan::DianXinBan()
{
    cout << "已创建类" << endl;
    SetID(1001);
    SetNAME("张三");
    SetSCORE(85.5);
}

DianXinBan::~DianXinBan()
{
    cout << "已删除类" << endl;
}

int main(int argc, char* argv[])
{
    int id;
    char name[50];
    char *p, i;
    float score;
    DianXinBan student1;

    if ((argv[1] != NULL) && (argv[2] != NULL) && (argv[3] != NULL))
    {
        student1.SetID(atoi(argv[1]));
        student1.SetNAME(argv[2]);
        student1.SetSCORE((float) atof(argv[3]));
    }

    id = student1.GetID();

    p = student1.GetNAME();
    for(i = 0; *p != '\0'; i++)
    {
        name[i] = *p;
        p++;
    }

    score = student1.GetSCORE();

    cout << "学号：" << id << endl;
    cout << "姓名：" << name << endl;
    cout << "分数：" << score << endl;

    return 0;
}

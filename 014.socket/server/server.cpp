/*
 * @Author: ShadowDumb
 * @Date: 2021-08-04 17:06:08
 * @LastEditTime: 2021-08-06 16:05:18
 * @LastEditors: Please set LastEditors
 * @Description: 客户端向服务端发送指令，服务端执行指令，此为服务端
 * @FilePath: /C++/socket/server/server.cpp
 */
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int main(int argc, char* argv[])
{
    int serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    char buffer[1024];

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);

    // 配置协议
    serv_addr.sin_family = AF_INET;
    if((argv[1] != NULL) && (argv[2] != NULL))
    {
        serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
        serv_addr.sin_port = htons(atoi(argv[2]));
    }
    else
    {
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        serv_addr.sin_port = htons(12345);
    }

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));   // 绑定
    listen(serv_sock, 20);                                              // 监听

    cout << "Waiting for connection..." << endl;
    while(1)
    {
        int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);   // 等待客户端发送数据并接受
        recv(clnt_sock, buffer, 1024, 0);   // 获取客户端发送的数据
        cout << "Get command: " << buffer;  // 打印
        if(atoi(buffer) == 123)             // 如果是 123 则关闭程序
        {
            cout << "exit" << endl;
            break;
        }

        system(buffer);                     // 将客户端发送的数据以命令形式执行

        memset(buffer, 0, sizeof(buffer));

        close(clnt_sock);
    }

    return 0;
}

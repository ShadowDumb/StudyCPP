/*
 * @Author: ShadowDumb
 * @Date: 2021-08-04 17:05:59
 * @LastEditTime: 2021-08-06 16:04:30
 * @LastEditors: Please set LastEditors
 * @Description: 客户端向服务端发送指令，服务端执行指令，此为客户端
 * @FilePath: /C++/socket/client/client.cpp
 */
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int main(int argc, char* argv[])
{
    char send_buffer[1024];

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

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

    while(1)
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));     // 连接服务端

        cout << "Input command: ";
        fgets(send_buffer, sizeof(send_buffer), stdin);                     // 输入，如果此处用 cin，输入的空格会将空格两边的字符串隔开
        send(sock, send_buffer, strlen(send_buffer), 0);                    // 发送

        if(atoi(send_buffer) == 123)
        {
            cout << "exit" << endl;
            break;
        }

        memset(send_buffer, 0, sizeof(send_buffer));

        close(sock);
    }

    return 0;
}

/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：通过封装的TcpSocket类实现服务端程序 
*           1. 创建套接字
*           2. 绑定地址信息
*           3. 开始监听
*           4. 获取连接成功的客户端新建socket
*           5. 通过新建的客户端socket与客户端进行通信
*           6. 关闭套接字
================================================================*/

#include "tcpsocket.hpp"

int main (int argc, char *argv[])
{
    if (argc != 3) {
        std::cout<<"./tcp_srv ip port\n";
        return -1;
    }
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);
    TcpSocket sock;

    CHECK_RET(sock.Socket());
    CHECK_RET(sock.Bind(ip, port));
    CHECK_RET(sock.Listen());

    TcpSocket client;
    if (sock.Accept(client) == false){
    }

    _person_info_t person;
    recv(client.GetFd(), &person, sizeof(_person_info_t), 0);
    std::cout<<"name:"<<person.name<<" sex:"<<person.sex<<" age:"<<person.age<<std::endl;

    sock.Close();
    return 0;
}

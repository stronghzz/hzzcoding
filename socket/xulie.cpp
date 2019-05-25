/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：通过封装的TcpSocket类实现网络通信客户端 
*           1. 创建套接字
*           2. 向服务端发起连接请求
*           3. 收发数据
*           4. 关闭套接字
================================================================*/
#include "tcpsocket.hpp"
#include <signal.h>

void sigcb(int no){
    std::cout<<"recv signo:"<<no<<std::endl;
}
int main (int argc, char *argv[])
{
    if (argc != 3) {
        std::cout<<"./tcp_cli ip port\n";
        return -1;
    }
    signal(SIGPIPE, sigcb);
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    TcpSocket sock;
    CHECK_RET(sock.Socket());
    CHECK_RET(sock.Connect(ip, port));
    
    _person_info_t info;
    memset(&info, 0x00, sizeof(_person_info_t));
    strcpy(info.name,"jianhua");
    strcpy(info.sex, "nan");
    info.age = 18;
    send(sock.GetFd(), &info, sizeof(_person_info_t), 0);   

    sock.Close();
    return 0;
}
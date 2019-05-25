/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：使用udpsocket类完成udp服务端程序 
================================================================*/

#include "udpsocket.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("./udp_srv ip port\n");
        return -1;
    }
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    UdpSocket sock;
    //1. 创建套接字
    CHECK_RET(sock.Socket());
    CHECK_RET(sock.Bind(ip, port));

    while(1) {
        std::string buf;
        struct sockaddr_in cli_addr;
        sock.Recv(buf, &cli_addr);
        printf("client say:%s\n", buf.c_str());

        std::cout<<"server say:";
        fflush(stdout);
        std::cin >> buf;
        sock.Send(buf, cli_addr);
    }
    sock.Close();
    return 0;
}

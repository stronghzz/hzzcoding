/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述： 
================================================================*/
#include "udpsocket.hpp"

int main (int argc, char *argv[])
{
    if (argc != 3){
        printf("./udp_cli ip port\n");
        return -1;
    }
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    struct sockaddr_in srv_addr;
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    srv_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    UdpSocket sock; 
    CHECK_RET(sock.Socket());

    while(1){
       std::string buf;
       std::cout<<"client say:";
       fflush(stdout);
       std::cin>>buf;
       sock.Send(buf, srv_addr);

       buf.clear();
       sock.Recv(buf);
       std::cout<<"server say:"<<buf<<std::endl;
    }
    sock.Close();
    return 0;
}

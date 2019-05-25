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
#include <pthread.h>

void *thr_start(void *arg){

    TcpSocket *client = (TcpSocket*)arg;
    while(1){
        std::string buf;
        client->Recv(buf);
        std::cout<<"client say:"<<buf<<std::endl;

        std::cout<<"server say:";
        fflush(stdout);
        std::cin>>buf;
        client->Send(buf);
    }
    delete client;
    return NULL;
}
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

    while(1) {
        //程序卡在accept是因为用户无法获知客户端的新连接什么时候到来
        //如果能知道什么时候到来就不会阻塞；只需要在来的时候调用一次就行
        TcpSocket *client = new TcpSocket();
        if (sock.Accept(*client) == false){
            continue;
        }
        pthread_t tid;
        pthread_create(&tid, NULL, thr_start, (void*)client);
        pthread_detach(tid);
    }
    sock.Close();
    return 0;
}

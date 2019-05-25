/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：封装TcpSocket类，向外提供轻便的socket接口 
*       1. 创建套接字   
*       2. 未套接字绑定地址
*       3. 客户端向服务端发起连接请求
*       3. 服务端开始监听
*       4. 服务端获取一个已经连接成功客户端的新建socket
*       5. 客户端与服务端收发数据
*       6. 关闭套接字
================================================================*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define CHECK_RET(q) if((q) == false){ return -1; }

struct _person_info_t{
    char name[16];
    char sex[4];
    int age;
};

class TcpSocket
{
    public:
        TcpSocket():_sockfd(-1){
        }
        ~TcpSocket(){
        }
        int GetFd() {
            return _sockfd;
        }
        bool Socket() {
            _sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (_sockfd < 0) {
                std::cout<<"socket error\n";
                return false;
            }
            return true;
        }
        bool Bind(std::string &ip, uint16_t port) {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);

            int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
            if (ret < 0) {
                std::cout<<"bind error\n";
                return false;
            }
            return true;
        }
        //开始监听，设置服务端的同一时间最大并发连接数
        bool Listen(int baklog = 5) {
            //int listen(int sockfd, int backlog);
            //sockfd:   套接字描述符
            //backlog： backlog设置内核中已完成连接队列的最大节点数量
            int ret = listen(_sockfd, baklog);
            if (ret < 0) {
                std::cout<<"listen error\n";
                return false;
            }
            return true;
        }
        //获取连接成功客户端socket，并且返回客户端的地址信息
        bool Accept(TcpSocket &sock, struct sockaddr_in *addr = NULL){
            //int accept(int sockfd, sockaddr *addr,socklen_t *addrlen);
            //  sockfd: 套接字描述符
            //  addr：  用于存储客户端地址信息
            //  addrlen：用于设置想要的地址长度和保存实际的地址长度
            //返回值：为客户算连接新建的socket描述符，  失败-1
            //接下来与客户端的通信都是通过这个socket描述符实现的
            struct sockaddr_in _addr;
            socklen_t len = sizeof(struct sockaddr_in);
            int newfd = accept(_sockfd, (struct sockaddr*)&_addr, &len);
            if (newfd < 0) {
                std::cout<<"accept error\n";
                return false;
            }
            sock.SetFd(newfd);
            if (addr != NULL) {
                memcpy(addr, &_addr, len);
            }
            return true;
        }
        //客户端向服务端发起连接请求
        bool Connect(std::string &ip, uint16_t port) {
            //int connect(int sockfd, struct sockaddr *addr,
            //  socklen_t addrlen);
            //  sockfd: 套接字描述符
            //  addr：  服务端监听地址信息
            //  addrlen：地址信息长度
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);
            int ret = connect(_sockfd, (struct sockaddr*)&addr, len);
            if (ret < 0) {
                std::cout<<"connect error\n";
                return false;
            }
            return true;
        }
        //通信接口：tcp服务端也可以直接先发送数据(因为连接已经建立成功)
        bool Recv(std::string &buf) {
            //ssize_t recv(int sockfd, void *buf, size_t len, int flags)
            //sockfd:   套接字描述符
            //buf：     存储接收的数据
            //len：     想要接收的长度
            //flags:    0-阻塞接收   
            //          MSG_PEEK-接收数据但是数据不从接收缓冲区移除
            //返回值：实际接收的字节数/对端关闭连接返回0    错误：-1
            char tmp[1024] = {0};
            int ret = recv(_sockfd, tmp, 1024, 0);
            if (ret == 0) {
                std::cout<<"peer shutdown\n";
                return false;
            }else if (ret < 0) {
                std::cout<<"recv errno\n";
                return false;
            }
            buf.assign(tmp, ret);
            return true;
        }
        bool Send(std::string &buf) {
            //ssize_t send(int sockfd, void *buf, size_t len, int flags)
            //返回值：实际发送的字节数      失败：-1
            //若连接已经断开，发送会触发异常
            int ret = send(_sockfd, buf.c_str(), buf.size(), 0);
            if (ret < 0) {
                std::cout<<"send error\n";
                return false;
            }
            return true;
        }
        bool Close() {
            close(_sockfd);
            _sockfd = -1;
            return true;
        }
        void SetFd(int sockfd) {
            _sockfd = sockfd;
        }
    private:
        int _sockfd;
};

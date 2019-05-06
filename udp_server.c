/*  这是一个非常简单的udp服务端程序
 *  功能是：客户端与服务端的聊天程序
 *  网络编程步骤：
 *      1. 创建套接字
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    //1. 创建套接字
    //int socket(int domain, int type, int protocol);
    //  domain: 地址域
    //      AF_INET     ipv4协议
    //  type：  套接字类型
    //      SOCK_STREAM 流式套接字    
    //      SOCK_DGRAM  数据报套接字
    //  protocol:   协议类型
    //      0-默认；流式套接字默认tcp协议，数据报套接字默认udp协议
    //  返回值：套接字描述符，失败：-1
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("socket error!!\n");
        return -1;
    }
    //struct sockaddr 
    //struct sockaddr_in
    //struct sockaddr_in6
    //2. 为socket绑定地址信息，确定socket能够操作缓冲区中的哪些数据
    //  int bind(int sockfd, struct sockaddr *addr,socklen_t addrlen);
    //      sockfd: 套接字描述符
    //      addr：  要绑定的地址信息
    //      addrlen:地址信息的长度
    //
    //      端口号是0-65535之间的的一个数字，0-1024不推荐使用
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = inet_addr("192.168.3.32");
    //inet_pton(AF_IENT, "192.168.122.132", &addr.sin_addr);
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = bind(sockfd, (struct sockaddr*)&addr, len);
    if (ret < 0) {
        perror("bind error");
        close(sockfd);
        return -1;
    }
    //3.接收数据
    //ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags
    //      struct sockaddr *src_addr, socklen_t *addrlen);
    //      sockfd: socket描述符
    //      buf：   用于将存储接收的数据
    //      len：   想要接收的数据长度
    //      flags： 0-默认是说如果缓冲区没有数据，那么我就阻塞等待
    //      src_addr：  用于确定数据的发送端地址信息
    //      addrlen：   地址信息的长度
    //      返回值：实际接收的数据长度 ,-1：失败
    while (1) {
        //接收数据
        char buff[1024] = {0};
        struct sockaddr_in cli_addr;
        len = sizeof(struct sockaddr_in);
        ssize_t rlen = recvfrom(sockfd, buff, 1023, 0,
                (struct sockaddr*)&cli_addr, &len);
        if (rlen < 0) {
            perror("recvfrom error");
            close(sockfd);
            return -1;
        }
        printf("client[%s:%d] say:%s\n", 
                inet_ntoa(cli_addr.sin_addr),
                ntohs(cli_addr.sin_port), buff);
        //发送数据
        //ssize_t sendto(int sockfd, const void *buf, size_t len, 
        //  int flag, struct sockaddr *dest_addr,socklen_t addrlen)
        //  sockfd: socket描述符，发送数据的时候就是通过这个socket
        //      所绑定的地址来发送
        //  buf：   要发送的数据
        //  len：   要发送的数据长度
        //  flag：  0-默认阻塞式发送
        //  dest_addr： 数据要发送到的对端地址
        //  addrlen：   地址信息长度
        //  返回值：返回实际的发送数据长度，失败返回-1
        memset(buff, 0x00, 1024);
        scanf("%s", buff);
        sendto(sockfd, buff, strlen(buff), 0,
                (struct sockaddr*)&cli_addr, len);
    }
    close(sockfd);
    return 0;
}

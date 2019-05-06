/*  这是一个tcp服务端程序，它的功能是简单的服务端聊天程序
 *  tcp是有连接的面向字节流的可靠传输
 *      1. 创建socket
 *      2. 为socket绑定地址
 *      3. 开始监听:可以开始接收客户端的连接请求
 *      4. 获取连接建立成功的新socket:
 *      5. 接收数据
 *      6. 发送数据
 *      7. 关闭socket
 *  监听socket和后边新建立的socket的关系
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: ./tcp_server ip port\n");
        return -1;
    }
    //1. 创建socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket error");
        return -1;
    }
    //2. 为socket绑定地址信息
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = bind(sockfd, (struct sockaddr*)&addr, len);
    if (ret < 0) {
        perror("bind error");
        return -1;
    }
    //3. 监听
    //  int listen(int sockfd, int backlog);
    //  sockfd:     socket描述符
    //  backlog：   最大的同时并发连接数
    if (listen(sockfd, 5) < 0) {
        perror("listen error");
        return -1;
    }
    while(1) {
        int new_sockfd;
        struct sockaddr_in cli_addr;
        len = sizeof(struct sockaddr_in);
        //4. 获取连接成功的socket
        //int accept(int sockfd, struct sockaddr *addr, 
        //      socklen_t *addrlen);
        //  sockfd: socket描述符
        //  addr：  新建立连接的客户端地址信息
        //  addrlen：地址信息长度
        //  返回值：返回新的socket连接描述符，失败：-1
        //  new_sockfd 与 lst_sockfd 区别
        //  lst_sockfd这是一个拉皮条的socket，说所有的连接请求的数
        //      据都是发送到这个socket的缓冲区，然后进行处理(会为
        //      这个新连接的客户端新建一个socket)
        //      (这个socket接收到的数据都是连接请求),
        //      (dip dport)
        //  new_sockfd这是一个干活的socket，连接建立成功之后，这个s
        //      ocket有自己的缓冲区，往后这个客户端所发送的数据都
        //      是在这个socket的缓冲区中。
        //      (dip dport sip sport)
        //  accept函数是一个阻塞型的函数，连接成功队列中如果没有新
        //  的连接，那么就会一直阻塞直到有新的客户端连接到来
        new_sockfd = accept(sockfd, (struct sockaddr*)&cli_addr, 
                &len);
        if (new_sockfd < 0) {
            perror("accept error");
            continue;
        }
        printf("new conn %s:%d\n", inet_ntoa(cli_addr.sin_addr),
                ntohs(cli_addr.sin_port));
        while(1) {
            //5. 接收数据
            //ssize_t recv(int sockfd, void *buf, size_t len,int flags)
            //  sockfd: 建立连接成功的socket描述符
            //  buf：   用于接收数据
            //  len：   用于指定接收数据长度
            //  flags：默认0-阻塞式接收
            //  返回值：错误：-1    连接关闭：0     实际接收长度：>0
            char buff[1024] = {0};
            ssize_t rlen = recv(new_sockfd, buff, 1023, 0);
            if (rlen < 0) {
                perror("recv error");
                close(new_sockfd);
                continue;
            }else if (rlen == 0) {
                printf("peer shutdown!!\n");
                close(new_sockfd);
                continue;
            }
            printf("client[%s:%d] say:%s\n", 
                    inet_ntoa(cli_addr.sin_addr),
                    ntohs(cli_addr.sin_port), buff);
            //发送数据
            memset(buff, 0x00, 1024);
            scanf("%s", buff);
            send(new_sockfd, buff, strlen(buff), 0);
        }
    }
    close(sockfd);
    return 0;
}

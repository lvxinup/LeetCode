/*  这是一个tcp的客户端简单聊天程序
 *      1. 创建socket
 *      2. 为socket绑定地址
 *      3. 向服务端发起连接请求
 *      4. 发送数据
 *      5. 接收数据
 *      6. 关闭
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
        printf("Usage:./tcp_client ip port\n");
        return -1;
    }
    //1. 创建socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket error");
        return -1;
    }
    //2. 绑定:客户端程序不推荐绑定地址
    //3. 向服务端发起连接请求
    //int connect(int sockfd, struct sockaddr *addr,
    //      socklen_t addrlen);
    //  sockfd: socket描述符
    //  addr：  要连接的服务端地址
    //  addrlen：   地址信息长度
    //  返回值：成功：0 失败：-1
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = connect(sockfd, (struct sockaddr*)&serv_addr, len);
    if (ret < 0) {
        perror("connect error");
        return -1;
    }
    while(1) {
        //4. 发送数据
        char buff[1024] = {0};
        scanf("%s", buff);
        send(sockfd, buff, strlen(buff), 0);
        //5. 接收数据
        memset(buff, 0x00, 1024);
        ssize_t rlen = recv(sockfd, buff, 1023, 0);
        if (rlen < 0) {
            perror("recv error");
            return -1;
        }else if (rlen == 0) {
            printf("peer shutdown!\n");
            return -1;
        }
        printf("server say:%s\n", buff);
    }
    close(sockfd);
    return 0;
}

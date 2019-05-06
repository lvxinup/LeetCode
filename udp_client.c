/*  这是一个udp简单网络聊天的客户端程序
 *     1. 创建套接字
 *     2. 绑定地址信息
 *     3. 向服务端发送数据
 *     4. 接收服务端返回的数据
 *     5. 关闭socket
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
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("socket error");
        return -1;
    }
    //2. 为套接字绑定地址信息，
    //  客户端程序种，通常我们不推荐手动绑定地址，因为绑定有可能会
    //  因为特殊情况失败，但是客户端发送数据的时候，具体用哪个地址
    //  和端口我们都无所谓，只要数据能成功发送就可以，所以，客户端
    //  程序中我们不手动绑定地址，直到发送数据的时候，操作系统检测
    //  到socket没有绑定地址，会自动选择合适的地址和端口为socket绑
    //  定，这种绑定方式一般不会出错
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.3.32");
    socklen_t len = sizeof(struct sockaddr_in);
    while(1) {
        //3. 发送数据
        char buff[1024] = {0};
        scanf("%s", buff);
        sendto(sockfd, buff, strlen(buff), 0,
                (struct sockaddr*)&serv_addr, len);
        //4. 接收数据 
        memset(buff, 0x00, 1024);
        ssize_t r_len = recvfrom(sockfd, buff, 1023, 0,
                (struct sockaddr*)&serv_addr, &len);
        if (r_len < 0) {
            perror("recvfrom error");
            return -1;
        }
        printf("server say:%s\n", buff);

    }
    close(sockfd);
    return 0;
}

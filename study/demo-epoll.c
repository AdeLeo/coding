#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <epoll.h>
#include <sys/wait.h>

#define SERVPORT 9527
//服务器监听端口号
#define BACKLOG 10
//最大同时连接请求数目

void setnonblocking(int sock)
{
    int opts;
    opts = fcntl(sock, F_GETFL);
    if(opts < 0)
    {
        perror("fcntl(sock,GETFL)");
        exit(1);
    }

    opts = opts|O_NONBLOCK;
    if(fcntl(sock,F_SETFL,opts) < 0)
    {
        perror("fcntl(sock,SETFL,opts)");
        exit(1);
    }
}

void do_use_fd(int client_fd)
{
    const char str[] = "hello world";
    if(send(client_fd, str, sizeof(str), 0) == -1)
    {
        perror("send");
    }
    close(client_fd);
}

int main()
{
    int sockfd;
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    if(sockfd = socket(AF_INET, SOCK_STREAM, 0) == -1)
    {
        perror("socket");
        exit(1);
    }
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(SERVPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(sockfd, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1)
    {
        perror("bind");
        exit(1);
    }
    printf("bind ok\n");
    if(listen(sockfd, BACKLOG) == -1)
    {
        perror("listen");
        exit(1);
    }
    printf("listen ok\n");
    size_t sin_size = sizeof(struct sockaddr_in);

#define MAX_EVENTS 10

    struct epoll_event ev,events[MAX_EVENTS];
    int conn_sock, nfds, epollfd;

    epollfd = epoll_create(10);
    if(epollfd == -1)
    {
        perror("epoll_create");
        exit(1);
    }
    printf("epoll_create\n");

    ev.events = EPOLLIN;
    ev.data.fd = sockfd;
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) == -1)
    {
        perror("epoll_ctl:sockfd");
        exit(1);
    }

    printf("epoll_ctl ok\n");

    while(1)
    {
        printf("start epoll_wait\n");
        nfs = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if(nfs == -1)
        {
            perror("epoll_wait");
            exit(1);
        }
        printf("epoll_wait returns, nfds = %d\n", nfds);

        for(int n = 0; n < nfds; n++)
        {
            if(events[n].data.fd == sockfd)
            {
                conn_sock = accept(sockfd, (struct sockaddr *)&remote_addr, &sin_size);
                if(conn_sock == -1)
                {
                    perror("accept");
                    exit(1);
                }
                setnonblocking(conn_sock);
                ev.events = EPOLLIN|EPOLLET;
                ev.data.fd = conn_sock;
                if(epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1)
                {
                    perror("epoll_ctl:conn_sock");
                    exit(1);
                }
                else
                {
                    do_use_fd(events[n].data.fd);
                }
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#pragma pack(1)
struct Info{
    char letter;
    int val1;
    float val2;
};
#pragma pack(0)

int main(int argc, char const *argv[])
{
    int socket_fd;
    struct sockaddr_in server;
    
    struct Info info = {'j',3,5.0};

    socket_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(socket_fd < 0){
        perror("socket creation failed");
        return 0;
    }

    memset(&server,'0',sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    sendto(socket_fd,&info,sizeof(info),MSG_CONFIRM,(const struct sockaddr *)&server,sizeof(server));

    close(socket_fd);
    return 0;
}

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
	int socket_fd = 0;
	char buff[1024];

	memset(buff,'0',sizeof(buff));

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd<0){
		perror("socket creation failed\n");
		return 0;
	}

	struct sockaddr_in server;
	memset(&server, '0', sizeof(server));

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
	//If the (sin_addr.s_addr) field is set to the constant INADDR_ANY, as defined in netinet/in.h, the caller is requesting that the socket be bound to all network interfaces on the host.

	bind(socket_fd, (struct sockaddr*)&server, sizeof(server));

    listen(socket_fd,10);

    socklen_t addr_size;
    addr_size = sizeof(struct sockaddr_in);
    int in;
	if(in = accept(socket_fd, (struct sockaddr*)&server,&addr_size)){
		int n;
        bzero(buff,256);
		while ((n = recv(in, buff, 255,0)) > 0){
            printf("Server Received: %s\n",buff);
            printf("enter the message: ");
    		bzero(buff,256);
    		fgets(buff,255,stdin);
			send(in, buff, strlen(buff), 0);
			bzero(buff,256);
            }
			close(in);
        }
	close(socket_fd);
}

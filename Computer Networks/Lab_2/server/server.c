//
//  Behnam Dezfouli
//  CSEN, Santa Clara University
//

// This program implements a server that accepts connection from a client and copies the received bytes to a file
//
// The input arguments are as follows:
// argv[1]: Sever's port number



#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


int main (int argc, char *argv[])
{
    char    message[10] = "received!";  // message to be sent to the client when the destination file name is received
    int     net_bytes_read;             // numer of bytes received over socket
    int     socket_fd = 0;              // socket descriptor
    int     connection_fd = 0;          // new connection descriptor
    struct  sockaddr_in serv_addr;      // Address format structure
    char    net_buff[1024];             // buffer to hold characters read from socket
    FILE    *dest_file;                 // pointer to the file that will include the received bytes over socket
    
    
    if (argc < 2) // Note: the name of the program is counted as an argument
    {
        printf ("Port number not specified!\n");
        return 1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
    serv_addr.sin_port = htons (atoi (argv[1]));
    
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socket_fd, (const struct sockaddr*)&serv_addr, sizeof (serv_addr));
    listen(socket_fd, 10);
    connection_fd = accept(socket_fd, (struct sockaddr *)NULL, NULL);
    read(connection_fd, net_buff, 10);
    
    dest_file = fopen(net_buff, "wb");
    printf("Here is the message: %s\n", net_buff);
    memset (net_buff, '\0', sizeof(net_buff));
    
    while((net_bytes_read = read(connection_fd, net_buff, sizeof(net_buff)) > 0)){
        if (net_bytes_read < sizeof (net_buff)){
            fwrite(net_buff, 20, net_bytes_read, dest_file);
            break;
        }
        
        fwrite(net_buff, 20, sizeof (net_buff), dest_file);
        memset(net_buff, '\0', sizeof(net_buff));
    }
    
    close(connection_fd);
    fclose(dest_file);
    
    return 0;
}


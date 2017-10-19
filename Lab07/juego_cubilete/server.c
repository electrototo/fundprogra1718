/*
    Simple udp server
*/
#include <stdio.h> //printf
#include <string.h> //memset
#include <stdlib.h> //exit(0);
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
 
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data
 
void die(char *s)
{
    perror(s);
    exit(1);
}

void imprimir_dados(char *dados) {
    char opciones[6] = {'9', '1', 'J', 'Q', 'K', 'A'};

    char d1, d2, d3, d4, d5;

    d1 = opciones[dados[0] - '0'];
    d2 = opciones[dados[1] - '0'];
    d3 = opciones[dados[2] - '0'];
    d4 = opciones[dados[3] - '0'];
    d5 = opciones[dados[4] - '0'];

    printf("----- ----- ----- ----- -----\n");
    printf("| %c | | %c | | %c | | %c | | %c |\n", d1, d2, d3, d4, d5);
    printf("----- ----- ----- ----- -----\n");
    printf("  0     1     2     3     4\n");
    printf("\n");
}
 
int main(void)
{
    struct sockaddr_in si_me, si_other;
     
    int s, i, slen = sizeof(si_other) , recv_len;
    char buf[BUFLEN];
     
    //create a UDP socket
    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
     
    // zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));
     
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
     
    //bind socket to port
    bind(s , (struct sockaddr*)&si_me, sizeof(si_me));
     
    //keep listening for data
    while(1)
    {
        printf("Waiting for data...");
        fflush(stdout);

        memset(buf, '\0', BUFLEN);
        recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);
         
        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , buf);
        imprimir_dados(buf);
    }
 
    close(s);
    return 0;
}

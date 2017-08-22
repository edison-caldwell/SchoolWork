//#include <iostream>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <limits.h>
#include <unistd.h>
#include <netdb.h>
#include <cctype>
#include <time.h>
#include <iostream>

#define BUFFERSIZE 1024

using namespace std;

int main(int argc, char* argv[])
{
    
	int socketfd;
    	int port;
    	int clientLen;
	struct sockaddr_in serveraddr;
    	struct sockaddr_in clientaddr;
    	struct hostent* hostp;
    	char buffer[BUFFERSIZE];
    	char* hostaddr;
    	int optval;
    	int msg;
    	
	//printf("\n\n%u\n\n", argc);
	
	//printf("\n\n");
	//for(int i = 0; i < argc; i++){
	//	printf("%s\t", argv[i]);
	//}
	//printf("\n\n");

	//char* pause;
	//fgets(pause,sizeof(pause), stdin);

    	if(argc != 2){
		fprintf(stderr, "\n\nusage: %s& <port>\n\n", argv[0]);
        	exit(1);
    	}
    
    
    port = atoi(argv[1]);
    
	if((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("\n\nFailed to create socket\n\n");
		exit(EXIT_FAILURE);
	}
	

	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(port);
	
	if(bind(socketfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0){
		perror("\n\nBind failure\n\n");
		exit(EXIT_FAILURE);
	}
    
    clientLen = sizeof(clientaddr);
	
    //printf("\n\nThe server is ready to recieve.\n\n");
	srand(time(NULL));
    
    while(1){
        memset(&buffer, 0, BUFFERSIZE);
        msg = recvfrom(socketfd, buffer, BUFFERSIZE, 0, (struct sockaddr *) &clientaddr, (socklen_t *) &clientLen);
        
        int drop = rand() % 9;
        //cout << endl << drop << endl;
        if(drop < 3){
            continue;
        }
        
        if(msg < 0){
            perror("\n\nERROR in recvfrom\n\n");
            exit(EXIT_FAILURE);
        }
        
        
        hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        
        if(!hostp){
            perror("\n\nERROR on gethostbyaddr\n\n");
            exit(EXIT_FAILURE);
        }
        
        hostaddr = inet_ntoa(clientaddr.sin_addr);
        if(!hostaddr){
            perror("\n\nERROR on inet_ntoa\n\n");
            exit(EXIT_FAILURE);
        }
        
        printf("\n\nServer recieved datagram from %s (%s)\n", hostp->h_name, hostaddr);
        printf("Server recieved %d/%d bytes: %s\n", strlen(buffer), msg, buffer);
        
        int i = 0;
        while(buffer[i]){
            buffer[i] = toupper(buffer[i]);
            i++;
        }
        
        msg = sendto(socketfd, buffer, strlen(buffer), 0, (struct sockaddr*) &clientaddr, clientLen);
        
        if (msg < 0){
            perror("\n\nERROR in sendto\n\n");
            exit(EXIT_FAILURE);
        }
    }
    
    
	
	return 0;	
}




#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include "stopwatch.h"



#define BUFFSIZE 1024

using namespace std;

int main(int argc, char* argv[])
{
    int socketfd;
    int port;
    int msg;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent* server;
    char* hostname;
    char buffer[BUFFSIZE];
    int count = 0;
    vector<double> RTTs;
    StopWatch timer;
    
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    
    
    if(argc != 3){
	fprintf(stderr, "\n\nusage: %s <hostname> <port>\n\n", argv[0]);
        exit(1);
    }
    
    
    hostname = argv[1];
    port = atoi(argv[2]);
    
    
    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socketfd < 0){
        perror("\n\nERROR opening socket\n\n");
        exit(EXIT_FAILURE);
    }
    
    server = gethostbyname(hostname);
    if(!server){
        fprintf(stderr, "\n\nERROR, no such host: %s\n\n", argv[1]);
        exit(1);
    }
    
    memset((char *) &serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(port);
    
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(struct timeval));
    
    
    while(count < 10){
        memset(buffer, 0, BUFFSIZE);
        //printf("Please enter a message: ");
        //fgets(buffer, BUFFSIZE, stdin);
        
        serverlen = sizeof(serveraddr);
        
        stringstream ss;
        
        ss << "Ping " << count + 1 << " " << timer.Start();
        
        strcpy(buffer, ss.str().c_str());
        
        msg = sendto(socketfd, buffer, strlen(buffer), 0, (struct sockaddr*) &serveraddr, serverlen);
        
        if(msg < 0){
            perror("\n\nERROR in sendto\n\n");
            exit(EXIT_FAILURE);
        }
        
        msg = recvfrom(socketfd, buffer, strlen(buffer), 0, (struct sockaddr*) &serveraddr, (socklen_t *) &serverlen);
        
        timer.Stop();
        
        RTTs.push_back(timer.GetTime());
        
        if(msg < 0){
            printf("\nRequest timed out\n\n");
        }
        else{
            printf("\nServer repsonse: %s\n", buffer);
            cout << "RTT: " << timer.GetTime() << endl << endl;
        }
        
        
        count++;
    }
    
    double min = RTTs[0], max = RTTs[0], avg = 0;
    
    for(int i = 0; i < RTTs.size(); i++)
    {
        avg = avg + RTTs[i];

        if(min > RTTs[i])
            min = RTTs[i];

        if(max < RTTs[i])
            max = RTTs[i];
    }

    avg = avg / RTTs.size();
    
    cout << "The max RTT was " << max << endl;
    cout << "The min RTT was " << min << endl;
    cout << "The average RTT was " << avg << endl << endl;
    return 0;
}

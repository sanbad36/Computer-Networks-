/*
Name:Sanket Badjate
Roll No:6
Assignment No:6
*/
/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//bzero
#include <unistd.h>//i/o operation at system level
#include <sys/types.h>//socket
#include <sys/socket.h>//socket af_net,sockaddr
#include <netinet/in.h>//socket,inaddr_any,in_add,sockaddr_in(sin family)
//1.socket()
//2.bind()
//3.listen()
//4.accept()
//5.read(),write()
void error(const char *msg)//error msg array
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])//command line
{
     int sockfd, newsockfd, portno;//varible declaration
     socklen_t clilen;//length of client msg
     char buffer[255];//max size of char is 255
     struct sockaddr_in serv_addr, cli_addr;//define structure to store ipaddress and tcp
     int n;
//./a.out 4521
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
//st1-create socket store info ip,tcp,internet
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
//if nothing then error occur
     if (sockfd < 0)
        error("ERROR opening socket");
//it store info of server
     bzero((char *) &serv_addr, sizeof(serv_addr));
//port number at place 1 convert int to char
     portno = atoi(argv[1]);
//it store ip,sys address,port num which convert char to network
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
//st2-bind() it bind port address and address
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0)
              error("ERROR on binding");
//st3-listen() it record number of client
     listen(sockfd,5);
//clien varible store client information
     clilen = sizeof(cli_addr);
//st4-acceptt() it accept client information
     newsockfd = accept(sockfd,
                 (struct sockaddr *) &cli_addr,
                 &clilen);
     if (newsockfd < 0)
          error("ERROR on accept");
     while(1)
     {
           bzero(buffer,256);//it have msg
           n = read(newsockfd,buffer,255);
           if (n < 0) error("ERROR reading from socket");
           printf("Client: %s\n",buffer);
          bzero(buffer,256);
          fgets(buffer,255,stdin);
          n = write(newsockfd,buffer,strlen(buffer));
           if (n < 0) error("ERROR writing to socket");
           int i=strncmp("Bye" , buffer, 3);
           if(i == 0)
               break;
     }
     close(newsockfd);//close both socket
     close(sockfd);
     return 0;
}

/*OUTPUT
------Client Side------
linux-15@linux15:~$ gcc clientchat.c -o clientchat
linux-15@linux15:~$ ./clientchat 127.0.0.1 4562
3Client: Hi
Server : hello

How r u?
Server : I am fine
------Server Side------
linux-15@linux15:~$ gcc clientchat.c -o clientchat
linux-15@linux15:~$ ./clientchat 127.0.0.1 4562
3Client: Hi
Server : hello

How r u?
Server : I am fine

*/

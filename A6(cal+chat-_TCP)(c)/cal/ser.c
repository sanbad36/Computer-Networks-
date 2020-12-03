/*
Name:Sanket Badjate
Roll No:6
Assignment No:6
*/

/*
	Server Side
	Please pass port no as command line argument
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>//for socket
#include <sys/socket.h>//for socket
#include <netinet/in.h>//for socket
#include <ctype.h>
//1.create sockt socket()
//2.bind socket bind()
//3.listen connection listen()
//4.send and receive data accept()
//5.read and system calls read(),write()
void error(const char *msg)//char array
{
    perror(msg);//error msg
    exit(1);//exit program
}

int main(int argc, char *argv[])//commnd line
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[1024];//store msg from recieve and send msg from server
     struct sockaddr_in serv_addr, cli_addr;
     int n;
//./a.out and 4521 require if not then error generate
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
//af_inet=ip address
//sock_stream=tcp
//0 system or intenet connection
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
//if above parametrer not present get error
     if (sockfd < 0)
        error("ERROR opening socket");
//sever addreess store
     bzero((char *) &serv_addr, sizeof(serv_addr));
//port no store at arg 1 place
//atoi use for conversion char to int
     portno = atoi(argv[1]);
//af_inet=ip address
//inaddr_any=pc address
//htons=port int to network format
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
//step 1 complete so step 2 find port and server address
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0)
              error("ERROR on binding");
//step3-no of client handle by server
     listen(sockfd,5);
//new address for client
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd,
                 (struct sockaddr *) &cli_addr,
                 &clilen);
     if (newsockfd < 0)
          error("ERROR on accept");



     int num1 , num2 , ans , choice;
 S:  n = write(newsockfd,"Enter Number 1 : ",strlen("Enter Number 1"));         //Ask for Number 1
     if (n < 0) error("ERROR writing to socket");
     read(newsockfd, &num1, sizeof(int));					//Read No 1
     printf("Client - Number 1 is : %d\n" , num1);


     n = write(newsockfd,"Enter Number 2 : ",strlen("Enter Number 2"));         //Ask for Number 2
     if (n < 0) error("ERROR writing to socket");
     read(newsockfd, &num2, sizeof(int));					//Read Number 2
     printf("Client - Number 2 is : %d\n" , num2);


     n = write(newsockfd,"Enter your choice : \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n",strlen("Enter your choice : \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n"));         //Ask for choice
     if (n < 0) error("ERROR writing to socket");
     read(newsockfd, &choice, sizeof(int));					//Read choice
     printf("Client - Choice is : %d\n" , choice);


      switch(choice)
     {
     	case 1:
     		ans = num1 + num2;
     		break;
     	case 2:
     		ans = num1 -num2;
     		break;
     	case 3:
     		ans = num1*num2;
     		break;
     	case 4:
     		ans = num1/num2;
     		break;
     	case 5 :
 		goto Q;
     		break;
     }

     write(newsockfd , &ans , sizeof(int));
     if(choice != 5)
     	goto S;

   Q:  close(newsockfd);
     close(sockfd);
     return 0;
}



/*
Server side terminal:
jj@ubuntu:~/Desktop$ gcc Server.c -o Server
jj@ubuntu:~/Desktop$ ./Server 4562
Client - Number 1 is : 50
Client - Number 2 is : 110
Client - Choice is : 1
Client - Number 1 is : 50
Client - Number 2 is : 60
Client - Choice is : 2
Client - Number 1 is : 4
Client - Number 2 is : 8
Client - Choice is : 3
Client - Number 1 is : 66
Client - Number 2 is : 11
Client - Choice is : 4
Client - Number 1 is : 5
Client - Number 2 is : 7
Client - Choice is : 5
jj@ubuntu:~/Desktop$


Client side Terminal:

jj@ubuntu:~/Desktop$ gcc client.c -o client
jj@ubuntu:~/Desktop$ ./client 192.168.244.139 4562
Server - Enter Number 1
50
Server - Enter Number 2
110
Server - Enter your choice :
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
1
Server - The answer is : 160
Server - Enter Number 1
50
Server - Enter Number 2
60
Server - Enter your choice :
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
2
Server - The answer is : -10
Server - Enter Number 1
4
Server - Enter Number 2
8
Server - Enter your choice :
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
3
Server - The answer is : 32
Server - Enter Number 1
66
Server - Enter Number 2
11
Server - Enter your choice :
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
4
Server - The answer is : 6
Server - Enter Number 1
5
Server - Enter Number 2
7
Server - Enter your choice :
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
5
You chose to exit, Thank You so much.jj@ubuntu:~/Desktop$

*/


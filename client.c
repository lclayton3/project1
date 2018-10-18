#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
/* for printf() and fprintf() */
/* for socket(), connect(), send(), and recv() */ /* for sockaddr_in and inet_addr() */
/* for atoi() */
/* for memset() */
/* for close() */
#define RCVBUFSIZE 32
void DieWithError(char *errorMessage); 
/* Error handling function */
/* Size of receive buffer */ 
int main(int argc, char *argv[])
{
int sock;
struct sockaddr_in echoServAddr; 
unsigned short echoServPort; 
char *servlP;
char *echoString;
char echoBuffer[RCVBUFSIZE]; unsigned int echoStringLen;
int bytesRcvd, totalBytesRcvd;
if ((argc< 3) || (argc> 4)){
	fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
	exit(1);
}
/* Socket descriptor */
/* Echo server address */
/* Echo server port */
/* Server IP address (dotted quad) */ /* String to send to echo server */ /* Buffer for echo string */
/* Length of string to echo */
/* Bytes read in single recv()
and total bytes read */
/* Test for correct number of arguments */
servlP = argv[1]; 
echoString = argv[2] ;
if (argc == 4)
/* First arg' server IP address (dotted quad) */ 
/* Second arg' string to echo */
	echoServPort = atoi(argv[3]); /* Use given port, if any */
else
	echoServPort = 7; 
/* 7 is the well-known port for the echo service */
/* Create a reliable, stream socket using TCP */
if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	DieWithError("socket () failed") ;
/* Construct the server address structure */
memset(&echoServAddr, 0, sizeof(echoServAddr));
echoServAddr.sin_family = AF_INET;
echoServAddr.sin_addr.s_addr = inet_addr(servlP);
echoServAddr.sin_port = htons(echoServPort); 
/* Server port */
/* Establish the connection to the echo server */
if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
	DieWithError(" connect () failed") ;
echoStringLen = strlen(echoString) ; 
/* Determine input length */
/* Send the string to the server */
if (send(sock, echoString, echoStringLen, 0) != echoStringLen)
DieWithError("send() sent a different number of bytes than expected");
/* Receive the same string back from the server */
totalBytesRcvd = 0;
printf("Received: "); /* Setup to print the echoed string */ 
while (totalBytesRcvd < echoStringLen)
{
/* Receive up to the buffer size (minus i to leave space for a null terminator) bytes from the sender */
if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0) 
	DieWithError("recv() failed or connection closed prematurely");
totalBytesRcvd += bytesRcvd; /* Keep tally of total bytes */ 
echoBuffer[bytesRcvd] = '\0'; /* Terminate the string! */ 
printf("%s",echoBuffer); /* Print the echo buffer */
}
printf("\n"); /* Print a final linefeed */
close(sock);
exit(0);
}
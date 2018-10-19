#include <stdio.h> /* for printf() and fprintf() */
#include <sys/socket.h> /* for recv() and send() */
#include <unistd.h> /* for close() */
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define RCVBUFSIZE 32 /* Size of receive buffer */

void DieWithError(char *errorMessage); /* Error handling function */
void first_conversion(char* input, char * output);
void type_change(char type, char * output, char * target);
void HandleTCPClient(int clntSocket){
/* Buffer for echo string */ /* Size of received message */
char echoBuffer[RCVBUFSIZE]; 
int recvMsgSize;
char * var1;
char * var2;
char dest[1024];
char type[2];


/* Receive message from client */
if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
	DieWithError("recv() failed") ;
var1 = echoBuffer;
printf("%s\n", var1);
memcpy( type, &var1[strlen(var1)-1], 1);
type[1] = '\0';
printf("%s\n", type);
strncpy(dest, var1, strlen(var1)-1);
printf("%s\n", dest);
first_conversion(dest, "output.txt");
type_change(type[0], "output.txt", "target.txt");

/* Send received string and receive again until end of transmission */ 
while (recvMsgSize > 0) /* zero indicates end of transmission */
{
/* Echo message back to client */
if (send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize)
	DieWithError("send() failed");
	
/* See if there is more data to receive */
if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
	DieWithError("recv() failed") ; close(clntSocket); 
	 /* Close client socket */

}


close(clntSocket); /* Close client socket */
}
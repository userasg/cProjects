#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include "graph.h"
#include <stdbool.h>


/*State of network constants*/
#define WAITING 0
#define SENTTOCLIENT 1
#define QUIT 2

/*buffers size*/
#define BUFFERSIZE 512

/*standard network functions for setting up socket and reading/writing to/from client*/
void ServerConnection(int socketFD);
void ReadLineFromNetwork(int socketFD, char *buffer, int size);
int readNumberFromNetwork(int netNum, char *buffer);

/*protocol functions*/
int netAdd(Graph *graph, int netNum, int socketFD, int vertex);


int main(int argc, const char * argv[])
{
	int serverSocket = -1;
	int clientConnection;
	unsigned int alen;
	struct sockaddr_in server;
	struct sockaddr_in client;
	int port;

	/*Create socket*/
	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	/*error if cant make socket*/
	if(serverSocket == -1)
	{
		fprintf(stderr, "SOCKET_ERROR: socket cannot be created\n");
	}


	/*Sets up socket addresses*/
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port=atoi(argv[1]));
	server.sin_addr.s_addr = INADDR_ANY;
	/*printf("%d heres port\n",server.sin_port);*/

	/*Bind socket*/

	/*error if cant bind*/
	if(bind(serverSocket, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
	printf("bind() failed\n");
	exit(2);
	}

	/*listening error checking*/
	if(listen(serverSocket, 15) < 0)
	{
	printf("listen() failed\n");
	exit(3);
	}

	while(1)
	{
		/*making a client socket by accepting the connection*/
		alen = sizeof(client);
		clientConnection = accept(serverSocket, (struct sockaddr *)&client, &alen);
		printf("Connection From %x on port %d\n", ntohl(client.sin_addr.s_addr), ntohs(client.sin_port));

		/*calls the server connection with the client socket made*/
		ServerConnection(clientConnection);
		
		/* Close connection with the client*/
		close(clientConnection);
	}
	
	return 0;
}

void ServerConnection(int socketFD)
{

	char outBuffer[256];
	char inBuffer[256];
	int state = WAITING;
	int numInLine=0;
	int netNum=0;

	int vertex=0;

	Graph *graph;



	sprintf(outBuffer, "+OK 2022 Programming Portfolio Route Server\r\n");
	write(socketFD, outBuffer, strlen(outBuffer));
	state = SENTTOCLIENT;

	graph = init_graph();
	
	while(state != QUIT)
	{

		ReadLineFromNetwork(socketFD, inBuffer, 256);

		if(0 == strcmp(inBuffer, "NET-ADD"))
		{
			numInLine = 8;
			netNum = readNumberFromNetwork(numInLine, inBuffer);
			vertex = netAdd(graph, netNum, socketFD, vertex);	
			continue;
		}


		if(0 == strcmp(inBuffer, "QUIT"))
		{
		state = QUIT;
		sprintf(outBuffer, "+OK\r\n");
		write(socketFD, outBuffer, strlen(outBuffer));
		break;
		}

	}
}



/*reads the word from the client side to see what the client has said*/
void ReadLineFromNetwork(int sd, char *buf, int size)
{
	char l[BUFFERSIZE];
	int n;
	int i;
	int j = 0;
	int cline = 0;

	while (true)
	{
		n = read(sd, l, BUFFERSIZE);
		for (i = 0; i < n; i++)
		{
			buf[j] = l[i];
			if (buf[j] == 10 && buf[j - 1] == 13)
			{
				buf[j - 1] = '\0';
				cline = 1;
				break;
			}
		j++;
		}
	if (cline == 1 || n <= 0)
	{
		break;
	}
	}
}

int readNumberFromNetwork(int numInLine, char inBuffer[256])
{
	int netNum = 0;
	char NET[3];
	int j = 0;
	int i = 0;

	i=numInLine;

	while(i<strlen(inBuffer))
	{
		NET[j] = inBuffer[i];
		i++;
		j++;
	}

	netNum= atoi(NET);

	return netNum;
}

int netAdd(Graph *graph, int netNum, int socketFD, int vertex)
{
	Vertex *vertexPointer;
	char outBuffer[256];

	vertexPointer = find_vertex(graph, netNum);

	if(vertexPointer)
	{
		sprintf(outBuffer, "-ERR Vertex exists\r\n");
		write(socketFD, outBuffer, strlen(outBuffer));
	}
	
	else
	{
		add_vertex(graph, netNum);
		vertex++;
		sprintf(outBuffer, "+OK Added %d\r\n", netNum);
		write(socketFD, outBuffer, strlen(outBuffer));
	}

	return vertex;

}


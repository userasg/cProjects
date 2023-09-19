#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

#define kBufSize 8
#define kMULTIQUOTEPORT 1818

void ReadLineFromNetwork(int sd, char *buf, int size);

int main(int argc, const char * argv[])
{
    char buf[256];
    char toSend[256];
    int sd, ret;
    struct sockaddr_in sad;
    struct hostent *phost;
    int quit = 0;
    
    /* Open */
    sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sd == -1)
    {
        fprintf(stderr, "Cannot create socket\n");
        exit(1);
    }

    /* Set up the address of the server */
    memset(&sad, 0, sizeof(sad));
    sad.sin_family = AF_INET;
    sad.sin_port = htons(1818);

    phost = gethostbyname(argv[1]);
    memcpy(&sad.sin_addr, phost->h_addr_list[0], phost->h_length);
    
    ret = connect(sd, (struct sockaddr*)&sad, sizeof(sad));

    /* Access */
    if(ret == 0)
    {
        do
        {
            /* Read from network */
            ReadLineFromNetwork(sd, buf, 256);
            printf("%s\n", buf);
            
            if(0 == strcmp(buf, "BYE"))
            {
                quit = 1;
                break;
            }
            
            /* Reads from Keyboard */
            fgets(buf, 256, stdin);
            buf[strlen(buf)-1] = '\0'; /* Delete newline from end of string */
            
            /* Prepare data for server */
            sprintf(toSend, "%s\r\n", buf);
            
            write(sd, toSend, strlen(toSend));
        } while(quit == 0);
        
    }
    /* Close */
    close(sd);
    
    return 0;
}

void ReadLineFromNetwork(int sd, char *buf, int size)
{
    char l[kBufSize];
    int n;
    int i, j = 0;
    int cline = 0;
    
    do
    {
        n = read(sd, l, kBufSize);
        for(i = 0; i < n; i++)
        {
            buf[j] = l[i];
            if(buf[j] == 10 && buf[j-1] == 13)
            {
                buf[j-1] = '\0';
                cline = 1;
                break;
            }
            j++;
        }
    } while(cline == 0 && n > 0);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
	fprintf(stderr, "Usage: %s decimal-port\n", argv[0]);
	exit(1);
  }

  char *end;
  long int port = strtol(argv[1], &end, 10);
  if(!(argv[1][0] != '\0' && end[0] == '\0')) {
	fprintf(stderr, "Invalid port '%s' (must be decimal)\n", argv[1]);
	exit(1);
  }

  /* construct request, connect to server at port, and send it */
    
    int socket1 = socket(AF_INET, SOCK_STREAM, 0);
    if (socket1 == -1){
        perror("socket error");
        exit(1);
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    char* get = "GET";
    
    if(connect(socket1,(struct sockaddr *) &addr, sizeof(addr)) == -1){
        perror("connect error");
        exit(1);
    }
    
    
    
    if(sendto(socket1,get,strlen(get),0,(struct sockaddr *) &addr,sizeof(addr))==-1){
        perror("sending error");
        exit(1);
    }

}

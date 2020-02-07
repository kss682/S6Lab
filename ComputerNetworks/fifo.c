#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
/*
Fifo - named pipe is special pipe which exists 
even after the process is over and is stored locally 
and can be used by 2 or more processes.
*/
char *FIFO = "fifo";
void user1(){
	char *MESSAGE;
	int pid,fd;
	pid = fork();
	if(pid == 0){
		char *str = "Enter Message of user 1\n";
		write(1,str,strlen(str));
		sleep(1);
		fd = open(FIFO,O_WRONLY);
		sleep(1);
		read(0,MESSAGE,10);
		sleep(1);
		write(fd,MESSAGE,10);
		sleep(1);	
	}
	/*
	else{	char *parent = "Parent process of user 1\n";
		write(1,parent,strlen(parent));
		sleep(1);
	}
	*/
}

void user2(){
	char *RES;
	int pid,fd;
	pid = fork();
	if(pid == 0){
		char *str = "Message from user 1 to user 2 is ";
		fd = open(FIFO,O_RDONLY);
		read(fd,RES,10);
		sleep(1);
		strcat(RES," \n");
		strcat(str,RES);
		write(1,str,strlen(str));
		sleep(1);
	}
	/*	
	else{
		char *parent = "Parent of user 2 is executing";
		write(1,parent,strlen(parent));
		sleep(1);	
	}
	*/
}

int main(){
	mkfifo(FIFO,0666);
	user1();
	user2();		
}

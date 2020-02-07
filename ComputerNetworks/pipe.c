#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

/*
Pipe is a technique used to pass information 
from one process to another.
One way communication.
pipe is temporary , last as long as the process is there 
*/
int main(){
    char *str,*MESSAGE,*RECV;
    int p[2],pid;
    if(pipe(p)<0)
        exit(1);
    pid = fork();
    if(pid == 0){
        //str = "The child process is running \n";
        //write(1,str,strlen(str));
        read(p[0],RECV,12);
        write(1,RECV,strlen(RECV));
    }
    else{
        //str = "The parent process is running \n";
        //write(1,str,strlen(str));
        MESSAGE = "HelloWorld\n";
        write(p[1],MESSAGE,strlen(MESSAGE));
    }
}

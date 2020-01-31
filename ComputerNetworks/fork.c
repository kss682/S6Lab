#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void get_details(){
int pid,ppid,ruid,rguid;
pid = getpid();
ppid = getppid();
ruid = getuid();
rguid = getgid();
printf("\nThe process id is %d",pid);
printf("\nThe process parent id is %d",ppid);
printf("\nThe process user id is %d",ruid);
printf("\nThe process group id is %d",rguid);
printf("\n");
}
int main(){
    int pid,len,var = 10;
    char *str;
    
    pid = fork();
    if(pid == 0){
        str = "This is the child process\n";
        write(1,str,strlen(str));
        sleep(1);
        get_details();
    }
    else{
        str = "This is the parent process\n";
        write(1,str,strlen(str));
        sleep(1);
        get_details();
    }
}

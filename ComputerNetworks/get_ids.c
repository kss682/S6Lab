#include<stdio.h>
#include<unistd.h>

int main(){
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

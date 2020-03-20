#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>


//Message Queue stores the messages in a linked list format
struct message_queue{
	long msg_id;
	char msg_text[100];
} message;

int main(){
	key_t key;
	int msgid;
	key = ftok("progfile",65);	
	msgid = msgget(key,0666 | IPC_CREAT);
	
	message.msg_id = 1;
	printf("message to be sent:");
	scanf("%s",message.msg_text);
	msgsnd(msgid,&message,sizeof(message),0);
	return 0;
}

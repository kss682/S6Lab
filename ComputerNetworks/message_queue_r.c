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
	msgid = msgget(key,666 | IPC_CREAT);
	
	msgrcv(msgid,&message,sizeof(message),1,0);
	
	printf("message recieved is: %s",message.msg_text);

	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}

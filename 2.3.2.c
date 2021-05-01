#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void childTask(){
	printf("Salam Saya anaknya\n");
}
void parentTask(){
	printf("Saya Adalah Bapaknya\n");
}

int main(void) {
for(int i=1;i<13;i++){
	pid_t pid = fork();

	if(pid==0){
		printf("Child process => PPID=%d,PID=%d\n",getppid(),getpid());
		exit(0);
	}
	else{
		printf("Parent Process => PID=%d\n", getpid());
		printf("Waiting for child prcocesses to finnish...\n");
		wait(NULL);	
		printf("Child Prcocess finished.\n");
	}
}

return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void){
char name[10];
printf("Please enter Your Name:");
fgets(name,sizeof(name),stdin);
 for(int i=1; i< 4; i++){

pid_t pid =fork();
	if (pid == 0){
		printf("Your Name is :");
		puts(name);
		printf	("child process => PPID=%d, PID=%d\n", getppid(),getpid());
		exit(0);
	}
	else{
	  printf("Parent Process => PID=%d\n",getpid());
	  printf("waiting for child process to finish..\n");
	  wait(NULL);
	  printf("child process Finished.\n");
	}
  }
return EXIT_SUCCESS;
}


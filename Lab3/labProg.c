#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sigHandler (int);


void sigUsr1(int sigNum){
	printf("Received a SIGUSR1 signal.\n");
} 

void sigUsr2(int sigNum){
	printf("Received a SIGUSR2 signal.\n");
}

void sigHandler(int sigNum){
	printf(" Received an interrupt.\n");
	exit(0);	
}

int main(){
	pid_t child, parent;
	parent = getpid();
	int status;
	if ((child = fork()) < 0){
		perror("Fork failure");
		exit(1);
	}

	else if (child == 0){
		//This is the child! 
		printf("I am the child. PID: %ld\n", (long) getpid());
		while(1){
			sleep(1+(rand()%5));
			switch(rand()%2){
				case 0:
					kill(parent, SIGUSR1);
					break;
				case 1:
					kill(parent, SIGUSR2);
					break;
			}
		}
	}
	else{
		signal(SIGINT, sigHandler);
		signal(SIGUSR1, sigUsr1);
		signal(SIGUSR2, sigUsr2);
		pause();
		waitpid(child, &status, 0);
	}
}


#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 

void* findFile (void* arg);

int filesFound = 0;

int main(){
	pthread_t thread1, thread2;
	void* result1, *result2;
	int status;
	int loopStatus = 1;
	String h;
	while(loopStatus){
		cout << "Enter a file name to search: ";
		cin >> h;
		if(h.compare("exit") == 0)
			loopStatus = 0;
		else{
			if((status = pthread_create (thread1, NULL,  findFile, NULL)) != 0){
				fprintf(stderr, "join error %d: %s\n", status, strerror(status));
				exit(1);
		}	
	}	
}

void* findFile (void* arg){
	
}

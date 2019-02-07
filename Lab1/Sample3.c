#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

int main(){
	char* data1;
	struct termios tp, save;
	
	tcgetattr(0, &tp);
	save = tp;
	tp.c_lflag = ~ECHO;
	do{
	printf("Disabling echo.\n");
	printf("Enter secret word/phrase: ");
	scanf("%s", data1);
	if(!strcmp(data1, "quit"))
		break;
	else if(!strcmp(data1, "ice cream")){
		printf("You entered: %s", data1);
		printf("\n\nDefault behavior restored.");
		printf("\nEnter visible word/phrase: ");
		scanf("%s", data1);
		break;
	
	}} while(1);

	
	return 0;
}




			

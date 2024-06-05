#include <stdio.h>
#include <unistd.h>
#include "../lib/colors.h"

int main(void) {

	int character = '\0';
        
	printf(YELLOW);	
	while ((character = getc(stdin)) != EOF) {
	  putchar(character);
	  fflush(stdout);
	  usleep(50000); // u is mu for microseconds 
	}
	printf(RESET);

	return 0;

}

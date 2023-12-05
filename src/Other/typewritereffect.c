#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) {
	int i = 0;
	char h[] = "Hello World!\nToday we will be discussing an interesting topic!\n0123456789\n";
	int size = strlen(h);
	while (i < size) {
	  putchar(h[i++]);
	  fflush(stdout);
	  usleep(50000); // in microseconds
	}

	return 0;

}

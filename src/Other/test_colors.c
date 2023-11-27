#include <stdio.h>
#include <stdlib.h>
#include "../lib/colors.h"


struct funny_struct {

	void (*print_rgb)(struct funny_struct *);
	char *string;
};

void funny_struct__print_rgb(struct funny_struct *myclr) {
	// struct_data->member is same as (*struct_data).member
	myclr->string = RED "RED" GREEN "GREEN" BLUE "BLUE" "\0";
	printf("%s\n", (*myclr).string);
}

int main(void) {

 struct funny_struct mycolor = { funny_struct__print_rgb, NULL };
 mycolor.print_rgb(&mycolor);
 printf("%s\n", mycolor.string);

 return 0;
}

#include <stdio.h>
/**
 * Author: Isaac Alao
 * Chapter: I
 * Exercise: Verify that the expression getchar() != EOF is 0 or 1
 * Purpose: Reinforce use of getchar() and putchar()
 *
 **/

int main(void) {
    int c;
    
    //Loop through all the characters
    while ((c = getchar()) != EOF)
      printf("%d", c != EOF);

    //Check if the the last input is equal to EOF
    printf("\nThe series of 1s means that the expr getchar() != EOF is true for each character that is != to EOF.\n");
    printf("But this %d means that EOF was found in the given input stream and the expr above was false.", c != EOF);
}
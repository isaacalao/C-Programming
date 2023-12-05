#include <stdio.h>

#define OPTIONS_LENGTH 0b1000
#define READ_OPTION 0b001
#define WRITE_OPTION 0b010
#define EXECUTE_OPTION 0b100 
#define ALL_OPTIONS 0b111

void getoptions(int options);

int main(void) {

  return 0;

}

void getoptions(int options) {
 
 if (options >= OPTIONS_LENGTH) {
   printf("Option limit exceeded!\n");
   return;
 } else {
   if (options & READ_OPTION)
    printf("READ\n");
   if (options & WRITE_OPTION)
    printf("WRITE\n");
   if (options & EXECUTE_OPTION)
    printf("EXECUTE\n");
  }

}

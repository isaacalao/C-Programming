#include <stdio.h>

int main(void) {
 int i = 0;

 loop:
 if (i < 10) {
   printf("Value of i: %d\n", i++);
   goto loop;
 } else {
   goto out;
 }
 out:
  printf("Final value of i: %d\n", i);
  return 0;
}

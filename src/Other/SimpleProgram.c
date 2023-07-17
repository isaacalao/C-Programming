#include "../lib/lib.h"
/**
 * Author: Isaac Alao
 * Chapter: I
 * Exercise: Simple Program
 * Purpose: To reinforce learning
 *
 **/
 // Print odd & even numbers in descending order.  If a number is odd print 6 characters wide & append a newline.
int main(void)
{
 int i=33;
 while ((i--) > 1)
  printf(
   ((i % 2 == 1) ? "%6d\n" : "%d"), i
  );
}

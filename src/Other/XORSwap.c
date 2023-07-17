#include <stdio.h>
#include <stdlib.h>

// Source: Jacob Sorber

int main() {

int x = 55, y = 32;

 printf(
  "Before the swap:\n"
  "x = %d\n"
  "y = %d\n\n",
   x, y
 );

 /*
  It's important to have (x ^= y) on the far left so the result of the operation can xor (y ^= x) 
  [which has been successfully swapped] to acquire the former value of y and assign it to x
 */
 x = ((x ^= y) ^ (y ^= x));

 printf(
  "After the swap:\n"
  "x = %d\n"
  "y = %d\n",
   x, y
 );
 return 0;
}

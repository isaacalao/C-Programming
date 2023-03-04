#include <stdio.h>
/**
 * Author: Isaac Alao
 * Chapter: I
 * Exercise: Counting
 * Purpose: Reinforce use of getchar() and putchar()
 *
 **/

#define IN 1 // inside of a word
#define OUT 0 // outside of a word

int main() {
 int c, // c ➞ character
  lc, // lc ➞ linecount
  wc, // wc ➞ wordcount
  cc, // cc ➞ charactercount
  state; // state ➞ in/out
 c = lc = wc = cc = 0;

 // EOF is NOT a character
 while((c = getchar()) != EOF) {
  /*
    check if we are at the last character of a  "word" and
    check if the current character classifies as whitespace,
    and it increments if the expr yields 1
  */

  wc += (state == IN && (c == ' ' || c == '\n' || c == '\t'));

  // trivial operation
  lc += (c == '\n') ?  1 : 0; cc++;

  // compare again to set state equal to IN or OUT
  state = (
    (c == ' ' || c == '\n' || c == '\t') ?
    OUT : IN
  );
 }

 // these lines are here to satisfy some edge cases
 wc += (state == IN) ? 1 : 0;
 lc += (lc > 0) ? 1 : 0;
 
 // print the number of lines and words
 printf("\tlc:%4d\t\twc:%4d\t\tcc:%4d", lc, wc, cc);
}

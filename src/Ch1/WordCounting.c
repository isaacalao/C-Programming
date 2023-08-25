#include <stdio.h>
/**
 * Author: Isaac Alao
 * Chapter: I
 * Exercise: Counting
 * Purpose: Reinforce the use of getchar() and putchar()
 *
 **/

#define IN 1 // inside of a word
#define OUT 0 // outside of a word

int main(void) {
 int c, // c ➞ character
  lc, // lc ➞ linecount
  wc, // wc ➞ wordcount
  cc, // cc ➞ charactercount
  state; // state ➞ in/out
 c = lc = wc = cc = state = 0;

 // EOF is NOT a character
 while((c = getchar()) != EOF) {
  /*
    check if the previous character was the last character of a "word"
    and check if the current character is classified as whitespace,
    then increment if the cond yields 1
  */

  wc += (state && (c == ' ' || c == '\n' || c == '\t'));

  // just a rudimentary piece of code
  lc += (c == '\n'); cc++;

  // compare again to set state equal to OUT or IN
  state = (
    (c == ' ' || c == '\n' || c == '\t') ?
    OUT : IN
  );
 }

 // this line is here to satisfy some edge cases if there's ≥ 1 char then yield 1 combined with state to increment wc
 wc += ( (lc += (cc > 0)) && state );

 // print the number of lines and words
 printf("\tlc:%4d\t\twc:%4d\t\tcc:%4d", lc, wc, cc);
}

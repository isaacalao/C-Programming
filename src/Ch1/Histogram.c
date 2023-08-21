#include <stdio.h>
/**
 * Author: Isaac Alao
 * Chapter: I
 * Exercise: Data representation of word lengths
 * Purpose: Reinforce the use of getchar() and printf()
 *
 **/

#define IN 1 // inside of a word
#define OUT 0 // outside of a word

int main(void) {
  int c, // c ➞ character
  wc, // wc ➞ wordcount
  max, // longest word 
  len, // len ➞ length
  state; // state ➞ in/out
  c = wc = max = len = state = 0;

 while((c = getchar()) != EOF) {
  
  /*
    check if a previous character was the last character of a "word"
    and check if the current character classifies as whitespace,
    and increment if the expr yields 1
  */

  wc += (state && (c == ' ' || c == '\n' || c == '\t'));
  
  state = (
    (c == ' ' || c == '\n' || c == '\t') ?
    OUT : IN
  );
  
  len += state;

  if (!state && len > 0) {
   max = (max < len) ? (len+1) : max;
   printf((wc/10 < 1) ? "0%d | " : "%d | ", wc);
   for (int i = 0; i++ < len; printf((i != len) ? "▔▔▔" : "▔▔\n"));
   len = 0;
  } 
 }
 printf(" ");
 for (int i = 0; i < max; i++)
   printf((i/10 < 1) ? " 0%d" : " %d", i);
}

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
  
  // Once no longer in a word, print the length of the word in histogram format
  if (!state && len > 0) {
   max = (max < len) ? (len+1) : max; // calculate the word with the highest length
   printf((wc/10 < 1) ? " %d │ " : "%d │ ", wc); // ill explain this later
   for (int i = 0; i++ < len; printf((i != len) ? "━━━" : "━━\n"));
   len = 0;
  } 
 }
 
 for (int i = 0; i < max*2; i++) {
   if (i < max) 
    printf((i == 1) ? "├────" : (i+1 != max) ? "───" : "────\n " ); // and this
   else  
    printf((i%max < 10) ? "  %d" : " %d", i%max); // yup this too...
 }
}

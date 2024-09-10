#include <stdio.h>
/**
 * Author: Isaac Alao
 * Chapter: I
 * Exercise: Data representation of word lengths
 * Purpose: Reinforce the use of getchar() and printf()
 **/

#define IN 1 // inside of a word
#define OUT 0 // outside of a word
#define WHITESPACE_OR_EOF(c) (c == ' ' || c == '\n' || c == '\t' || c == EOF)

int main(void) {
  int c, // c ➞ character
  wc, // wc ➞ wordcount
  max, // longest word 
  len, // len ➞ length
  state; // state ➞ in/out
  c = wc = max = len = state = 0;
 
 while((c = getchar()) != EOF || state) { // includes the very last word of
 
 // Check if the previous character was the last character of a "word"
 // and check if the current character is classified as whitespace,
 // then increment if the cond yields 1

  wc += (state && WHITESPACE_OR_EOF(c));
  len += (state = (WHITESPACE_OR_EOF(c) ? OUT : IN));

  // Once no longer in a word, print 
  // the length of the word in histogram format

  if (!state && len > 0) { 
   // max: highest length; add 1 to avoid complications below;
   max = (max <= len) ? (len+1) : max; 

   // prints the y axis
   printf((wc/10 < 1) ? " %d │ " : "%d │ ", wc); 

   // plots histogram box (i modulates after cond)
   for (int i = 0; i++ < len; printf((i != len) ? "━━━" : "━━\n")); 
   // set len back to 0 for adjacent word
   len = 0; 
  }  
 }
 // (max<<1 == max*2 or max+max)
 for (int i = 0; i < max<<1; i++, printf((i == max << 1) ? "\n" : "")) {
   // [0, max) up to max but not including max
   if (i < max) 
    printf(
        (i == 1 && max != 2) 
        ? "├────" : (i == 1) 
        ?  "├────\n" : (i+1 != max) 
        ? "───" : "────\n " // prints the x axis 
    ); 
   else
    // include double spaces if number < 10 else use single space
    printf((i%max < 10) ? "  %d" : " %d", i%max); 
 }
}

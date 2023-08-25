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
    check if the previous character was the last character of a "word"
    and check if the current character is classified as whitespace,
    then increment if the cond yields 1
  */

  wc += (state && (c == ' ' || c == '\n' || c == '\t'));
  
  state = (
    (c == ' ' || c == '\n' || c == '\t') ?
    OUT : IN
  );
  
  len += state;
  
  // Once no longer in a word, print the length of the word in histogram format
  if (!state && len > 0) {
   max = (max < len) ? (len+1) : max; // max: highest length; add 1 to avoid complications below;
   printf((wc/10 < 1) ? " %d │ " : "%d │ ", wc); // prints the y axis
   for (int i = 0; i++ < len; printf((i != len) ? "━━━" : "━━\n")); // plots histogram box (i modulates after cond)
   len = 0; // set len back to 0 for adjacent word
  } 
 }
 
 for (int i = 0; i < max<<1; i++) { // (max<<1 == max*2 or max+max)
   if (i < max) // [0, max) up to max but not including max
    printf((i == 1) ? "├────" : (i+1 != max) ? "───" : "────\n " ); // prints the x axis 
   else  
    printf((i%max < 10) ? "  %d" : " %d", i%max); // include double spaces if number < 10 else use single space
 } printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
//Symbolic Constants
#define A 232
#define B 3213
/**
 * Author: Isaac Alao
 * Assignment #1: EA & EEA (Cryptography Course)
 * EA Form: a = q(n) + r
 * EEA Form:  newp = p0 - p1(q0 mod n)
 **/

//Proper modular arithmetic
int mod(int a, int n) {
/*
 If a is negative and n is non-negative loop until
 n is greater than the |a| then return the difference of n - a,
 else calculate a mod n normally.
*/
 if (a < 0 && n > 0) {
  a = abs(a); 
  while(a > n) n+=n; 
  return(n-a);
 } else {
  return a%n;
 }
}

//Euclidean Algorithm
int ea(int a, int b) {
 int temp;

 //Make both args positive to compute gcd w/o hassle.
 a = abs(a); b = abs(b);

 /* While true continously reduce b and assign 
  it to a and compute a mod b until b reaches zero.
*/
 while (1)
 {
  if ( a < b ) {
   temp = a; a = b; b = temp;
  }
  else if ( b == 0 )
   return a;
  else {
   temp = a; a = b; b = temp%b;
  }
 }
}

//Extended Euclidean Algorithm
int eea(int b, int n) {
 // Swapping just incase input is mismatched!
 if (b > n) { int temp = b; b = n; n = temp;}
 int p0=0, p1=1, newp, q, r, a=n;

 //Check GCD and perform EEA.

 if (ea(b, n) == 1) {
  while (1)
  {
   //Assignment:
   q = a/b; r = a%b;
   
   //Modular arithmetic helper function:
   newp = mod((p0 - p1*q), n);
   p0 = p1; p1 = newp;
   a = b; b = r;

   // If b equals 1 return newp otherwise if a < 1 then there is no inverse:
   if (b == 1) {
    return newp;
   } else if (a < 1) {
    return -1;
   }
  }
 }
 else return -1;
}

int main(void) {
 int in1, in2, result;

 /*Input(s):
 {
    printf("Enter A: ");
    scanf("%d", &in1);

    printf("Enter B: ");
    scanf("%d", &in2);
 }*/

 //Print statement(s):
 {
    printf("Euclidean Algorithm (GCD) result: %d\nExtended Euclidean Algorithm (Inverse) result: ", result=ea(A, B));

    printf(
      ( (result=eea(A, B)) != -1 ? "%d" : "No inverse" ), result
    );
 }
}

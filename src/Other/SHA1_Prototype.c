#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 ----------------------------------------------------------------------------------------------------------------------------------
 * Author: Isaac Alao
 * Algorithm: SHA-1
 * Source: RFC 3174
 * Purpose: Implement SHA-1 algorithm in C to yield a fixed size output of 160-bits.
 * Status: WIP, there's some limitations as to what this program can compute, as of now it supports UTF-8 (Unicode) text.
 * Note: This implementation is NOT efficient!
 ----------------------------------------------------------------------------------------------------------------------------------
*/

// ROUNDS
#define ROUNDS 80

// BUF SIZE [1M Bytes or 1MB]
#define BUF_SIZE 1000000 

// SYM CONST INTERNAL/INITIAL VALUES [see RFC 3174]
#define H0 0x67452301
#define H1 0xEFCDAB89
#define H2 0x98BADCFE
#define H3 0x10325476
#define H4 0xC3D2E1F0

// BITWISE OPERATION MACROS
#define GETBIT(bitfield, pos) (char)(((bitfield) >> pos) & 0x1) // GET BIT FROM POSITION
#define LEFTROT(bitfield, shiftamt) ((bitfield) << shiftamt) | (((bitfield) >> (32 - shiftamt))) // CIRCULAR LEFT SHIFT

// FUNCTION PROTOTYPES
void sha1(char *message);
void chunk_to_words(char *bit_arr, int start, int end);

// TYPE DEFINITION
typedef unsigned int u32;

// GLOBALS
u32 h0 = H0, h1 = H1, h2 = H2, h3 = H3, h4 = H4;
char word[80][33] = { '\0' };

int main(int argc, char **argv) {
    // char *pangram = "The quick brown fox jumps over the lazy dog";
    
    if (argc == 2) {
        printf("\x1B[32mArg passed!\x1B[0m\n");
        sha1(argv[1]);
    } else {
        u32 i=0, c;
        char *input_msg = malloc((BUF_SIZE)+1);
        
        if (input_msg == NULL) {
         printf("\x1B[31mMalloc was unable to allocate %d bytes!\x1B[0m\n", BUF_SIZE);
         return 1;
        }

        while((c = getchar()) != EOF) {
          if (BUF_SIZE <= i) 
          {
           printf("\x1B[31mSTDIN is over %d bytes!\x1B[0m\n", BUF_SIZE);
           return 1;
          }
          input_msg[i++] = (char)(c);
        }
        input_msg[i] = '\0';
        sha1(input_msg); 
        free(input_msg);
    }
    return 0;
}

void sha1(char *message) {
    int msg_length = strlen(message);
    int inc_to_msg_length = 0, msg_length_bits = msg_length * 8, arr_size = 0;
    
    // SIZE CALCULATION
    while (++msg_length_bits % 512 != 448); 
    
    char bit_arr[(arr_size=(msg_length_bits+64))+1]; // APPEND 64 SINCE 448 (mod 512) ≡ 64 AND ACCOUNT FOR THE NUL TERM
    msg_length_bits = msg_length * 8; // RESET VALUE
    bit_arr[arr_size] = '\0'; // ADD NUL TERM TO THE END OF THE BIT ARR TO PREVENT UNDEFINED BEHAVIOR

    // INITIALIZE BIT ARRAY
    for (int i = 0; i++ < arr_size; bit_arr[i-1] = '0');
    
    for (int i = 0; i < msg_length; i++) {
        u32 ascii = (u32)(*(message+i));
        for (int j = 0; j < 8; j++)
            bit_arr[inc_to_msg_length++] = '0' + GETBIT(ascii, (8-j-1)); // 0 OR 1 in Big-Endian Order
    } bit_arr[inc_to_msg_length] = '1'; // APPEND 1 IN ASCII

    // PADDING
    while (++msg_length_bits % 512 != 448)
        bit_arr[msg_length_bits] = '0'; 
    
    // EXTRA PADDING (INCLUDE LENGTH OF MSG TO BIT_ARR AS BITS)
    for (int i = 0; i < 32; i++) // This was once 8-bits so it was causing problems for the final hash since for many cases the length in bits was > 255
        bit_arr[arr_size-i-1] = '0' + GETBIT(inc_to_msg_length, (i)); // 0 or 1 in Little-Endian Order
    
    // 80 ROUNDS ON EACH 512-BIT MESSAGE
    for (int i = 0; i < (int)(arr_size / 512); i++) {

        // CHUNK TO WORDS
        chunk_to_words(bit_arr, (i*512), ((i+1) * 512));
        
        u32 A = h0;
        u32 B = h1;
        u32 C = h2;
        u32 D = h3;
        u32 E = h4;

        for (int j = 0; j < ROUNDS; j++) 
        {
            u32 F, K_const;
            if (j < 20) {
                F = (B & C) | ((~B) & D);
                K_const = 0x5A827999;
            } else if (j < 40) {
                F = B ^ C ^ D;
                K_const = 0x6ED9EBA1;
            } else if (j < 60) {
                F = (B & C) | (B & D) | (C & D);
                K_const = 0x8F1BBCDC;
            } else {
                F = B ^ C ^ D;
                K_const = 0xCA62C1D6;
            }
            u32 temp = (((u32)LEFTROT(A, 5))+ F) + E + K_const + ((u32)strtoul(word[j], NULL, 2));
            E = D; 
            D = C; 
            C = ((u32)LEFTROT(B, 30)); 
            B = A; 
            A = temp;
        } 
         
        h0 = h0 + A;
        h1 = h1 + B;
        h2 = h2 + C;
        h3 = h3 + D;
        h4 = h4 + E;
    }
   
    fprintf(stdout, "%08x%08x%08x%08x%08x\n", h0, h1, h2, h3, h4);  
}

void chunk_to_words(char *bit_arr, int start, int end) {

    for (int i = start; i < end; i++)               // 16, 32-BIT WORDS FROM A 512-BIT CHUNK
        word[((i % 512) / 32)][i%32] = bit_arr[i];  // THIS DOES NOT ALTER THE NUL TERM AT THE END OF EACH 32-BIT WORD
                                                    // (i % 512) / 32 ENSURES THAT EACH 512-BIT CHUNK IS ASSIGNED TO THE FIRST 16 32-BIT WORDS

    // WORD FILLING [16, 80) 
    for (int i = 16; i < ROUNDS; i++) {
        
        u32 spawn_word = (
                (u32)(strtoul(word[i-3], NULL, 2)) ^ (u32)(strtoul(word[i-8], NULL, 2)) ^
                (u32)(strtoul(word[i-14], NULL, 2)) ^ (u32)(strtoul(word[i-16], NULL, 2))
        );
        
        spawn_word = (u32)LEFTROT(spawn_word, 1);

        for (int j = 0; j < 32; j++) {
            word[i][j] = '0' + GETBIT(spawn_word, (32-j-1)); // 0 OR 1 in Big-Endian Order
        }
    }
}

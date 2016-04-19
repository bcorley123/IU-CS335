/*Filename: mywc.c
*Part of: C335 Lab Assignment 2 *
*Created by: Blake Corley *
*Created on: 1/24/2014 *
*Last Modified by: Blake Corley *
*Last Modified on: 1/25/2014 *
*/


#include <stdio.h>


// counts the # of lines words and chars in a given text file
void main(void){
  
  int c;
  int lines = 0;
  int words = 0;
  int chars = 0;
  

  while ((c = getchar()) != EOF){// checks if a char is white space and acts accordingly

    chars++;
    
    if (c == ' '||c='\t'){
      words++;
    }
    
    if (c == '\n'||c=='\r'||c=='\v'||c=='\f'){
      lines++;
      words++;
    }
  }

    printf("%d  %d  %d \n", lines, words, chars); 
    
 
 


}

/*Filename: stdincap.c *
*Part of: C335 Homework/Lab Assignment HW1 *
*Created by: Blake Corley *
*Created on: 1/26/2014 *
*Last Modified by: Blake Corley *
*Last Modified on: 1/29/2014 *
*/


#include <stdio.h>
#include <stdarg.h>
void main(void){
  int c;

  while ((c = getchar()) != EOF){//runs through file
    putchar(toupper(c));//upppercases and puts chars

  }
}




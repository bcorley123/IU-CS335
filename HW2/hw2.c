/*Filename: hw2.c *
*Part of: C335 Homework 2 *
*Created by: bacorley *
*Created on: 2/13/14 *
*Last Modified by: bacorley *
*Last Modified on: 2/13/14 *
*/

#include <stdio.h>
#include <string.h>

void reverse_in_place(char *s);

int main(int argc, char *argv[]) {
  int i;
  
  /* reverse all the command-line arguments */
  for (i = 1; i < argc; i++) {
    reverse_in_place(argv[i]);
  }
  
  /* print out the reversed arguments, in reverse order */
  for (i = argc - 1; i >= 1; i--) {
    if (i != argc - 1)
      putchar(' '); /* space between args */
    printf("%s", argv[i]);
  }
  putchar('\n');
  
  return 0;
}


//reverse the string of given pointer
void reverse_in_place(char* s){
  
  int len = strlen(s); // get str len
  
  int i; //the index for the value to be swaped on the left
  char first;
  char last;
  int x; //the index for the value to be swaped on the right
  if(len%2==1){// if the string len is odd
    for (i=0; i<=len/2; i++){
      x=(len-i)-1; // set right index
      first=s[i];
      last=s[x];
      s[i]=last; //SWAP
      s[x]=first;
    }
  }
  else{ // if the string len is even
    for (i=0; i<len/2; i++){
      x=(len-i)-1; // set right index
      first=s[i];
      last=s[x];
      s[i]=last;  //SWAP
      s[x]=first;
    }
  }
  
}

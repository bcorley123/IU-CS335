/*Filename: remover.c *
*Part of: C335 Homework 1 *
*Created by: bacorley *
*Created on: 1/24/13 *
*Last Modified by: bacorley *
*Last Modified on: 1/29/13 *
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>


int remover(char source[], char substring[], char result[]);

void main(){
  
  char source[]= "The quick brown fox jumps over the lazy dog";
  char substring[] = "brown fox jumps over the";
  char result[strlen(source)];
  remover(source, substring, result); 
  
  
  
}

int remover(char source[], char substring[], char result[]){
  char *subP = strstr(source, substring); //points to start of sub in source
  if (subP ==  0) return 1;//if sub does not exist bail
  
  int iSource = 0; //index 
  int iResult = 0; //index
  char *sourceP = &source[iSource]; //pointer to source
  
  
  while (*sourceP != '\0'){ //cuts out at end of source
    if (&*subP == &source[iSource]){//trigger at start of sub
      int SizeOfSub = strlen(substring);
      for (SizeOfSub; SizeOfSub > 0; SizeOfSub--){ // get us to the end of sub
        iSource++;
      }
      sourceP = &source[iSource]; 
    }
    result[iResult] = source[iSource];// copy value
    
    iSource++;
    iResult++;
    sourceP = &source[iSource];
  }
  result[iResult] = '\0'; //ends the string
  printf("%s\n", result);
}

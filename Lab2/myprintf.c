/*Filename: myprintf.c
*Part of: C335 Lab Assignment 2 *
*Created by: Blake Corley *
*Created on: 1/24/2014 *
*Last Modified by: Blake Corley *
*Last Modified on: 1/25/2014 *
*/

#include <stdarg.h>
#include <stdio.h>

void printstring(char *p);
void printint(int Int);
void printhex(int Hex);

void myprintf(const char *fmt, ...) {
    const char *p;
    va_list argp;
    int i;
    char *s;

    va_start(argp, fmt);

    for (p = fmt; *p != '\0'; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'c':
            i = va_arg(argp, int);
            putchar(i);
            break;

        case 'd':
            i = va_arg(argp, int);
            printint(i);
            break;

        case 's':
            s = va_arg(argp, char *);
            printstring(s);
            break;

        case 'x':
            i = va_arg(argp, int);
            printhex(i);
            break;

        case '%':
            putchar('%');
            break;
        }
    }
    va_end(argp);

}


// takes an integer and prints a string of ints 
void printint(int Int){
  if(Int < 0){
    Int*=-1;
    putchar(45);
      }
  int nForInt = Int;// two vars of the same value to be used in both while loops
  int nForCount = Int;
  int count=1;
  while (nForCount/10 != 0){ // finds the total number of digit in Int set the # to count 
    count++;
    nForCount=nForCount/10;
  }
  int intArr[count];// array of the digits in reverse order
  int arrI=0;
  while (nForInt != 0){ // peels digits and puts them in reverse order
    int x;
    x = nForInt % 10;
    intArr[arrI]=x;
    arrI++;
    nForInt=nForInt/10;
  }
  int i;
  for(i=count-1;i>-1;i--){// prints digit in reverse order so the come out the same way the came in
    putchar(intArr[i] + 48);
  }
}
  
    
    
// takes array of chars and prints letter by letter
void printstring(char *p){
	int i=0;
  for(i=0;p[i]!='\0';i++){// magic
    putchar(p[i]);
      }
}


void printhex(int Hex){
  
  int iHex = 1;          //index for hex size
  int hexBaseVal  = 1;   //biggest divisable hex val
  
  
  if (Hex < 10){      //if hex is smaller than two digits then print the one val
    printint(Hex);
    return;
  }
  if (Hex < 16){
    switch (Hex){
    case 10: putchar('a'); break;
    case 11: putchar('b'); break;
    case 12: putchar('c'); break;
    case 13: putchar('d'); break;
    case 14: putchar('e'); break;
    default: putchar('f'); break;
      }
    return;
  }
  
  while (Hex != (Hex % hexBaseVal)){  //finds how long the hex will be
    iHex++;
    hexBaseVal*= 16;
    
  }
  iHex--;
  hexBaseVal/= 16;
  
 
  int i = 0;
  for (i=0 ; i < iHex; i++){             // starting from the furthest val on left print that val
    int hexDigVal = Hex / hexBaseVal;   // and then trim down the hex int
    if (hexDigVal < 10){      //for ints      
      printint(hexDigVal);
    }
    else {
      switch (hexDigVal){    //for chars
      case 10: putchar('a'); break;
      case 11: putchar('b'); break;
      case 12: putchar('c'); break;
      case 13: putchar('d'); break;
      case 14: putchar('e'); break;
      default: putchar('f'); break;
      }
    }
    
    Hex = (Hex %  hexBaseVal); //trim hex
    hexBaseVal /= 16;         // drop the bass. wub wub.
    
}
  
}





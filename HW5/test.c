//Blake Corley bacorley          work with absilver

#include <stdio.h>
extern int ADD(int, int);
extern int AND(int, int);
extern int ASR(int, int);
extern int BIC(int, int);
extern int CLZ(int, int);
extern int LSL(int, int);
extern int LSR(int, int);
extern int MVN(int, int);
extern int ORN(int, int, int);
extern int ORR(int, int, int);
extern int RBIT(int, int);
extern int REV(int, int);
extern int REV16(int, int);
extern int ROR(int, int, int);
extern int RSB(int, int);
extern int SUB(int, int);

int a = 6;
int b = 10;
int c;

void main(void){
  
  c = ADD(a, b);
  printf("ADD(%d,%d) = %d\n", a, b, c);
  c = AND(a, b);
  printf("AND(%d,%d) = %d\n", a, b, c);
  c = ASR(a, b);
  printf("ASR(%d,%d) = %d\n", a, b, c);
  c = BIC(a, b);
  printf("BIC(%d,%d) = %d\n", a, b, c);
  c = CLZ(a, b);
  printf("CLZ(%d,%d) = %d\n", a, b, c);
  c = EOR(a, b);
  printf("EOR(%d,%d) = %d\n", a, b, c);
  c = LSL(a, b);
  printf("LSL(%d,%d) = %d\n", a, b, c);
  c = LSR(a, b);
  printf("LSR(%d,%d) = %d\n", a, b, c);
  c = MVN(a, b);
  printf("MVN(%d,%d) = %d\n", a, b, c);
  c = ORN(a, b, b);
  printf("ORN(%d,%d) = %d\n", a, b, b, c);
  c = ORR(a, b, b);
  printf("ORR(%d,%d) = %d\n", a, b, b, c);
  c = RBIT(a, b);
  printf("RBIT(%d,%d) = %d\n", a, b, c);
  c = REV(a, b);
  printf("REV(%d,%d) = %d\n", a, b, c);
  c = REV16(a, b);
  printf("REV16(%d,%d) = %d\n", a, b, c);
  c = ROR(a, b, b);
  printf("ROR(%d,%d,%d) = %d\n", a, b, b, c);
  c = RSB(a, b);
  printf("RSB(%d,%d) = %d\n", a, b, c);
  c = SUB(a, b);
  printf("SUB(%d,%d) = %d\n", a, b, c);

}
<<<<<<< HEAD
=======
  
>>>>>>> 0ed4fd3904e7623723e95fe8ea059f412ac9622f

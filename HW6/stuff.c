#include <stdio.h>
 
#define imm5(x) (((x) >> 6) & 0x1f)
#define imm8(x) (x & 0xff)
#define rdn(x)  (((x) >> 8) & 7)
 
void  printarm(int);
void data_proc(int);
void others(int);
void ascm_imm(int);
void simr(int);
void as_reg(int);
void as_imm(int);
char *regnames[] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"};
 
 int main(){
   callandresponse(1);
   while (1) {
     //int to keep track of times, needs to be passed to printarm to not print introstuff  
     callandresponse(0);
     
   }
 return 0;
 }
 
 int callandresponse(int print_dots){
   int  * hexes[4];
   int  * inst;
   int inputnum = 0;
   while (scanf("%x", &inst) == 1 && inputnum <  4){
     hexes[inputnum] = inst;
     // printf("%x\n", inst);
     inputnum++;
     if (inputnum > 3) break;
   }
   if (print_dots == 1){
      printf(".text \n");
      printf(".syntax unified\n");
      printf(".thumb\n");
   }
   int i;
   //printf("input complete!\n");
   for (i = 0; i < 4; i++){
     printarm(hexes[i]);
             }
  return 0;
 }
 
 void  printarm(int hex){
  
 
   int x = 0x0011; // movs r1, r2
   int y = 0x214b; //  movs r1, #75
   int z = 0x4011;   //ands r1, r2
   int a = hex;//0x1fec;
   //printf("%d\n", rdn(a));
  if((a>>14)==1){
     data_proc(a);
     //printf("aa");
   }
   else if((a>>13)==1){
     //printf("%s",regnames[0]) ;
     ascm_imm(a);
   }
   else if ((a>>13)==0){
     others(a);
   }
   else{
     printf(".hword 0x%x", a);
  }
 
 
}
 
 
 void others(int a){
   int op = ((a>>11) & 3);
   if (op != 3){
     simr(a);
   }
   else{
     if (((a>>10) & 1) == 0){
       as_reg(a);
     }
     else{
       as_imm(a);
     }      
   }
 }
 
  void simr(int a ){
   char *mnemonics[]={"lsls","movs","lsrs","asrs"};
   int op  = ((a>>11)& 0x03);
   int im5 = imm5(a);
   int rd = (a & 7);
   int rm = ((a>>3) & 7);
   if ((op== 0) && (im5==0)){
     op++;
     printf("%x %s  %s, %s \n", a, mnemonics[op],regnames[rd], regnames[rm]);
   }
   else{
     printf("%x %s  %s, %s, #%d\n", a, mnemonics[op],regnames[rd], regnames[rm], im5);
   }
 }
 void as_reg(int a){
   char *mnemonics[]={"adds","subs"};
   int op = ((a>>9) & 1);
   int rm = ((a>>6) & 7);
   int rn = ((a>>3) & 7);
   int rd = (a & 7);
   printf("%x  %s %s, %s, %s\n", a, mnemonics[op],regnames[rd], regnames[rn], regnames[rm]);
 }
 void as_imm(int a){
 char *mnemonics[]={"adds","subs"};
   int op = ((a>>9) & 1);
   int imm3 = ((a>>6) & 7);
   int rn = ((a>>3) & 7);
   int rd = (a & 7);
   printf("%x  %s %s, %s, #%d\n", a, mnemonics[op],regnames[rd], regnames[rn], imm3);
 }
 
 void ascm_imm(int a){
   char *mnemonics[]={"movs","cmp","adds","subs"};
   int i = rdn(a);
   int j  = ((a>>11)& 0x03);
   printf("%x  %s %s, #%d\n", a, mnemonics[j],regnames[i], imm8(a));
 }
 
 
 void data_proc(int a){
   char *mnemonics[]= {"ands","eors","lsls","lsrs", "asrs","adcs","sbcs","rors", \
                      "tst","rsbs","cmp","cmn", "orrs","muls","bics","mvns"};
   int op = ((a>>6) & 0xf);
   int rm = ((a>>3) & 0x7);
   int rdn = (a & 0x7);
   if (op==9){
     printf("%x  %s %s, %s, #%d\n", a, mnemonics[op], regnames[rdn] , regnames[rm], 0 );
   }
   else{
     printf("%x  %s %s, %s\n", a, mnemonics[op], regnames[rdn] , regnames[rm] );
   }
 }

#include <stdio.h>

#define Imm5(x) (((x) >> 6) & 0x1f)
#define Imm8(x) (x & 0xff)
#define ascm_Rdn(x)  (((x) >> 8) & 7)
#define dp_Rdn(x)  ((x) & 7)
#define dp_opcode(x) ((x) >> 6 & 0xf)

void data_proc(int);
//void other(int);
void ascmi(int);
  


  
char *regnames[] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"};

void main(){
  
  int x = 0x0011; // movs r1, r2
  int y = 0x214B; //  movs r1, #75
  int z = 0x4011;   //ands r1, r2
  int a = y;//0x2A79;
  if((a>>14)==2){
    //data_proc(a);
    //printf("aa");
  }
  else if((a>>13)==1){
    printf("%x\n", a);
    ascmi(a);
  }
  else if ((a>>13)==0){
    //others(a);
  }
  else{
    printf(".hword 0x%x", a);
  }
  
  
}

void ascmi(int a){
  char *ascmi_mnemonics[]={"movs","cmp","adds","subs"};
  int hex = a;
  printf("%x", hex);
  int i = ascm_Rdn(a);
  int j = ((a>>11)& 0x03);
  printf("%x  %s %s, #%d\n", a, ascmi_mnemonics[j],regnames[i], Imm8(a));
}


void data_proc(int a){
  char *mnemonics[]= {"ands","eors","lsls","lsrs", "asrs","adcs","sbcs","rors", \
		     "tst","rsbs","cmp","cmn", "orrs","muls","bics","mvns"};
}
  
  


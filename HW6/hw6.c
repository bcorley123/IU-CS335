#include <stdio.h>

#define imm5(x) (((x) >> 6) & 0x1f)
#define imm8(x) (x & 0xff)
#define rdn(x)  (((x) >> 8) & 7)

void  print_assembly(int);
void data_proc(int);
void others(int);
void ascm_imm(int);
void simr(int);
void as_reg(int);
void as_imm(int);
int get_and_print(int);

char *regnames[] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"}; //names of registers

int main(){
  get_and_print(1);
  while (1) {
    get_and_print(0);
    
  }
  return 0;
}

int get_and_print(int print_dots){ //starts by asking for 4 hexes then calls print_assembly using those hexes
  int  * hexes[4];
  int  * inst;
  int inputnum = 0;
  while (scanf("%x", &inst) == 1 && inputnum <  4){//asks for 4 hexes
    hexes[inputnum] = inst;
    // printf("%x\n", inst);
    inputnum++;
    if (inputnum > 3) break;
  }
  if (print_dots == 1){// to make sure its called only once
    printf(".text \n");
    printf(".syntax unified\n");
    printf(".thumb\n");
  }
  int i;
  for (i = 0; i < 4; i++){ //prints the assembly
    print_assembly(hexes[i]);
  }
  return 0;
}

void  print_assembly(int a){ // prints assembly code based on the input hexes
  
  if ((a>>14)==1){
    data_proc(a);//Data-processing register
  }
  else if((a>>13)==1){
    ascm_imm(a);//Add/subtract/compare/move immediate
  }
  else if ((a>>13)==0){
    others(a); // the top three rows in the figure
  }
  else{
    printf(".hword 0x%x\n", a);
  }
}


void others(int a){ //Shift by immediate, move register & Add/subtract register & Add/subtract immediate
  int op = ((a>>11) & 3);
  if (op != 3){
    simr(a); //Shift by immediate
  }
  else{
    if (((a>>10) & 1) == 0){
      as_reg(a); //Add/subtract register
    }
    else{
      as_imm(a); //Add/subtract immediate
    }      
  }
}

void simr(int a ){//Shift by immediate
  char *mnemonics[]={"lsls","movs","lsrs","asrs"};
  int op  = ((a>>11)& 0x03);
  int im5 = imm5(a);
  int rd = (a & 7);
  int rm = ((a>>3) & 7);
  if ((op== 0) && (im5==0)){ // for the movs command
    op++;
    printf("%x %s  %s, %s \n", a, mnemonics[op],regnames[rd], regnames[rm]);
  }
  else{
    printf("%x %s  %s, %s, #%d\n", a, mnemonics[op],regnames[rd], regnames[rm], im5);
  }
}
void as_reg(int a){ //Add/subtract register
  char *mnemonics[]={"adds","subs"};
  int op = ((a>>9) & 1);
  int rm = ((a>>6) & 7);
  int rn = ((a>>3) & 7);
  int rd = (a & 7);
  printf("%x  %s %s, %s, %s\n", a, mnemonics[op],regnames[rd], regnames[rn], regnames[rm]);
}
void as_imm(int a){ //Add/subtract immediate
  char *mnemonics[]={"adds","subs"};
  int op = ((a>>9) & 1);
  int imm3 = ((a>>6) & 7);
  int rn = ((a>>3) & 7);
  int rd = (a & 7);
  printf("%x  %s %s, %s, #%d\n", a, mnemonics[op],regnames[rd], regnames[rn], imm3);
}

void ascm_imm(int a){ //Add/subtract/compare/move immediate
  char *mnemonics[]={"movs","cmp","adds","subs"};
  int i = rdn(a);
  int j  = ((a>>11)& 0x03);
  printf("%x  %s %s, #%d\n", a, mnemonics[j],regnames[i], imm8(a));
}


void data_proc(int a){ //Shift by immediate
  char *mnemonics[]= {"ands","eors","lsls","lsrs", "asrs","adcs","sbcs","rors", \
                      "tst","rsbs","cmp","cmn", "orrs","muls","bics","mvns"};
  int op = ((a>>6) & 0xf);
  int rm = ((a>>3) & 0x7);
  int rdn = (a & 0x7);
  if (op==9){ // if its rsbs 
    printf("%x  %s %s, %s, #%d\n", a, mnemonics[op], regnames[rdn] , regnames[rm], 0 );
  }
  else{
    printf("%x  %s %s, %s\n", a, mnemonics[op], regnames[rdn] , regnames[rm] );
  }
}

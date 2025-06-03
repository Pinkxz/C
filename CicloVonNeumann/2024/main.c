#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hlt 0b00000
#define nop 0b00001
#define not 0b00010
#define movr 0b00011
#define cmp 0b00100
#define ldbo 0b00101
#define stbo 0b00110
#define add 0b00111
#define sub 0b01000
#define mul 0b01001
#define div 0b01010
#define and 0b01011
#define or 0b01100
#define xor 0b01101
#define ld 0b01110
#define st 0b01111
#define movil 0b10000
#define movih 0b10001
#define addi 0b10010
#define subi 0b10011
#define muli 0b10100
#define divi 0b10101
#define lsh 0b10110
#define rsh 0b10111
#define je 0b11000
#define jne 0b11001
#define jl 0b11010
#define jle 0b11011
#define jg 0b11100
#define jge 0b11101
#define jmp 0b11110

int main(void) {
  unsigned char memoria[154];
  unsigned int MBR = 0;
  unsigned int MAR = 0;
  unsigned char IR = 0;
  unsigned char ro0 = 0;
  unsigned char ro1 = 0;
  unsigned char ro2 = 0;
  unsigned int IMM = 0;
  unsigned int PC = 0;
  unsigned char E = 0;
  unsigned char L = 0;
  unsigned char G = 0;
  unsigned int reg[16];
  // Declaracoes para funcionamento do programa
  unsigned char enter = 0;

  // Zerando a memoria
  for (int zero = 0; zero < 154; zero++) {
    memoria[zero] = 0x00;
  }

  for (int Execucao = 0; Execucao < 154; Execucao++) {
    // Busca
    MAR = PC;

    MBR = memoria[MAR] << 8;
    MBR = (MBR | memoria[MAR++]) << 8;
    MBR = (MBR | memoria[MAR++]) << 8;
    MBR = MBR | memoria[MAR++];

    // Decodificação
    IR = MBR >> 27;
    printf("MBR: %b\n", MBR);
    printf("IR: %b\n", IR);

    if (IR == hlt || IR == nop) {
      MBR = 0x00000000;
    }
    if (IR == not ) {
      ro0 = MBR & 0x07800000;
    }
    if (IR == movr || IR == cmp) {
      ro0 = MBR & 0x07800000;
      ro1 = MBR & 0x00780000;
    }
    if (IR == add || IR == sub || IR == mul || IR == div || IR == and ||
        IR == or || IR == xor) {
      ro0 = MBR & 0x07800000;
      ro1 = MBR & 0x0007FFFF;
      /*mbr 1000 0101 0111
      ro0 = 0000 0111 1000 0000 0000 0000 0000 0000
      r0 = 
      */
      ro2 = MBR & 0x00078000;
    }
    if (IR == ld || IR == st) {
      MAR = MBR & 0x007FFFFF;
      ro0 = MBR & 0x07800000;
    }
    if (IR == movil || IR == movih || IR == addi || IR == subi || IR == muli ||
        IR == divi || IR == lsh || IR == rsh) {
      IMM = MBR & 0x007FFFFF;
      ro0 = MBR & 0x07800000;
    }
    if (IR == je || IR == jne || IR == jl || IR == jle || IR == jg ||
        IR == jge || IR == jmp) {
      MAR = MBR & 0x007FFFFF;
    }
    if (IR == ldbo || IR == stbo) {
      MAR = MBR & 0x007FFFFF;
      ro0 = MBR & 0x07800000;
      ro1 = MBR & 0x0007FFFF;

      // Execucao
      if (IR == hlt) { // HALT
        printf("HALT. Execucao Finalizada");
        break;
      } else if (IR == nop) { // NO OPERATION
        PC = PC + 4;
      } else if (IR == not ) { // NOT REGISTER
        reg[ro0] = !reg[ro0];
      } else if (IR == movr) { // movr REGISTER
        reg[ro0] = reg[ro1];
      } else if (IR == cmp) { // cmp REGISTER
        if (reg[ro0] == reg[ro1]) {
          E = 1;
        } else {
          E = 0;
        }
        if (reg[ro0] < reg[ro1]) {
          L = 1;
        } else {
          L = 0;
        }
        if (reg[ro0] > reg[ro1]) {
          G = 1;
        } else {
          G = 0;
        }
      } else if (IR == ldbo) { // ldbo REGISTER

      } else if (IR == stbo) { // stbo REGISTER

      } else if (IR == add) { // add REGISTER
        reg[ro0] = reg[ro1] + reg[ro2];
      } else if (IR == sub) { // sub REGISTER
        reg[ro0] = reg[ro1] - reg[ro2];
      } else if (IR == mul) { // mul REGISTER
        reg[ro0] = reg[ro1] * reg[ro2];
      } else if (IR == div) { // div REGISTER
        reg[ro0] = reg[ro1] / reg[ro2];
      } else if (IR == and) { // and REGISTER
        reg[ro0] = reg[ro1] & reg[ro2];
      } else if (IR == or) { // or REGISTER
        reg[ro0] = reg[ro1] | reg[ro2];
      } else if (IR == ld) { // ld REGISTER
        reg[ro0] = MAR << 32;
      } else if (IR == st) { // st REGISTER
        MAR = reg[ro0] >> 32;
      } else if (IR == movil) { // movil REGISTER
        reg[ro0] = 0x00;
        reg[ro0] = (IMM | 0xFFFF) >> 16;
      } else if (IR == movil) { // movil REGISTER
        reg[ro0] = 0x00;
        reg[ro0] |= (IMM & 0xFFFF) << 16;
      } else if (IR == movih) { // movih REGISTER
        reg[ro0] = 0x00;
        reg[ro0] |= (IMM & 0xFFFF0000) >> 16;
      } else if (IR == addi) {
        reg[ro0] = reg[ro1] + IMM;
      } else if (IR == subi) { // subi REGISTER
        reg[ro0] = reg[ro1] - IMM;
      } else if (IR == muli) { // muli REGISTER
        reg[ro0] = reg[ro1] * IMM;
      } else if (IR == divi) { // divi A REGISTER
        reg[ro0] = reg[ro1] / IMM;
      } else if (IR == lsh) { // lsh REGISTER
        reg[ro0] = reg[ro1] << IMM;
      } else if (IR == rsh) { // rsh REGISTER
        reg[ro0] = reg[ro1] >> IMM;
      } else if (IR == je) { // je REGISTER
        if (E == 1) {
          PC = MAR;
        }
      } else if (IR == jne) { // jne REGISTER
        if (E == 0) {
          PC = MAR;
        }
      } else if (IR == jl) { // jl REGISTER
        if (L == 1) {
          PC = MAR;
        }
      } else if (IR == jle) { // jle REGISTER
        if (L == 1 || E == 1) {
          PC = MAR;
        }
      } else if (IR == jg) { // jg REGISTER
        if (G == 1) {
          PC = MAR;
        }
      } else if (IR == jge) { // jge REGISTER
        if (G == 1 || E == 1) {
          PC = MAR;
        }
      } else if (IR == jmp) { // jmp REGISTER
        PC = MAR;
      }
      printf("feijao2");
      // Dados na tela
      printf("CPU:\n MBR: %08X\n", MBR);
      printf("MAR: 0x%08X\n", MAR);
      printf("IR: 0x%02X\n", IR);
      printf("ro0: 0x%02X\n", ro0);
      printf("ro1: 0x%02X\n", ro1);
      printf("ro2: 0x%02X\n", ro2);
      printf("IMM: 0x%08X\n", IMM);
      printf("PC: 0x%08X\n", PC);
      printf("E: 0x%X\n", E);
      printf("L: 0x%X\n", L);
      printf("G: 0x%X\n", G);
      for (int regPrint = 0; regPrint < 16; regPrint++) {
        printf("reg%d:\t\t0x%08x\n", regPrint, reg[regPrint]);
      }
      for (int impressao = 0; impressao < 154; impressao++) {
        printf("%d:\t\t0x%02x\n", impressao, memoria[impressao]);
      }
      printf("\nPressione ENTER para continuar a execucao do programa.\n");
      scanf("%c", &enter);
    }
  }
  return 0;
}
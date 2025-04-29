#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo os Opcodes em binário
#define hlt 0b00000
#define nop 0b00001
#define add 0b00010
#define sub 0b00011
#define mul 0b00100
#define div 0b00101
#define cmp 0b00110
#define xchg 0b00111
#define and 0b01000
#define or 0b01001
#define xor 0b01010
#define not 0b01011
#define je 0b01100
#define jne 0b01101
#define jl 0b01110
#define jle 0b01111
#define jg 0b10000
#define jge 0b10001
#define jmp 0b10010
#define lda 0b10011
#define ldb 0b10100
#define sta 0b10101
#define stb 0b10110
#define ldrb 0b10111
#define movial 0b11000
#define moviah 0b11001
#define addia 0b11010
#define subia 0b11011
#define mulia 0b11100
#define divia 0b11101
#define lsh 0b11110
#define rsh 0b11111


int main(void) {
  // Declaração dos registradores/memoria:
  unsigned char mem[154];
  unsigned int MBR = 0;
  unsigned short int MAR = 0;
  unsigned short int IBR = 0;
  unsigned char IR = 0;
  unsigned short int IMM = 0;
  unsigned short int PC = 0;
  unsigned char E = 0;
  unsigned char L = 0;
  unsigned char G = 0;
  unsigned char LR = 0;
  unsigned short int A = 0;
  unsigned short int B = 0;
  unsigned short int T = 0;
  // Declaracoes para funcionamento do programa
  unsigned short int Execucao = 0;
  unsigned short int impressao = 0;
  unsigned char enter = 0;
  unsigned short int zero = 0;
  
  // Zerando a memoria
  for (zero = 0; zero < 154; zero++) {
    mem[zero] = 0x00;
  }
  
  for (Execucao = 0; Execucao < 154; Execucao++) {
    // Busca
    MAR = PC;
    if (LR == 0) {
      // Transferindo de memoria para MBR/MBR-IBR
      MBR = mem[MAR++] << 8;
      MBR = (MBR | mem[MAR++]) << 8;
      MBR = (MBR | mem[MAR++]) << 8;
      MBR = MBR | mem[MAR++];
      IBR = MBR << 16;
      IBR = (IBR | MBR);
      MBR = MBR >> 8;
      MBR = MBR >> 8;
      // Decodificacao

      IR = MBR >> 11;
      if (IR == je || IR == jne || IR == jl || IR == jle || IR == jg ||
          IR == jge || IR == jmp || IR == lda || IR == ldb || IR == sta ||
          IR == stb) {
        MAR = MBR & 0x07FF; // What the fuck?
      } else if (IR == movial || IR == moviah || IR == addia || IR == subia ||
                 IR == mulia || IR == divia || IR == lsh || IR == rsh) {
        IMM = MBR & 0x07FF;
      }
      // DecodificacaoIBR
    } else {
      IR = IBR >> 11;
      if (IR == je || IR == jne || IR == jl || IR == jle || IR == jg ||
          IR == jge || IR == jmp || IR == lda || IR == ldb || IR == sta ||
          IR == stb) {
        MAR = IBR & 0x07FF;
      } else if (IR == movial || IR == moviah || IR == addia || IR == subia ||
                 IR == mulia || IR == divia || IR == lsh || IR == rsh) {
        IMM = IBR & 0x07FF;
      }
    }
    // Execucao                     10 Mils Ifs
    if (LR == 0) {
      if (IR == hlt) { // HALT
        Execucao = 155;
        printf("Instrucao HALT: O Programa foi finalizado. Pressione ENTER "
               "para encerra-lo\n");
        scanf("%c", &enter);
        fflush(stdin);
        exit(1);
      } else if (IR == nop) { // NO OPERATION
        LR = 0;
        printf("Instrucao NO OPERATION\n");
      } else if (IR == add) { // ADD REGISTER
        A = A + B;
        PC += 4;
        printf("Instrucao ADD\n");
      } else if (IR == sub) { // SUB REGISTER
        A = A - B;
        PC += 4;
        printf("Instrucao SUB\n");
      } else if (IR == mul) { // Multiply REGISTER
        A = A * B;
        PC += 4;
        printf("Instrucao MUL\n");
      } else if (IR == div) { // DIV REGISTER
        A = A / B;
        PC += 4;
        printf("Instrucao DIV\n");
      } else if (IR == cmp) { // COMPARE REGISTER
        if (A == B) {
          E = 1;
        } else {
          E = 0;
        }
        if (A < B) {
          L = 1;
        } else {
          L = 0;
        }
        if (A > B) {
          G = 1;
        } else {
          G = 0;
        }
        PC += 4;
        printf("Instrucao COMPARE\n");
      } else if (IR == xchg) { // EXCHANGE REGISTER
        T = A << 8;
        T = (T & A) << 8;
        A = B;
        A = (A & B) << 8;
        B = T;
        B = (B & T) << 8;
        PC += 4;
        printf("Instrucao XCHG\n");
      } else if (IR == and) { // And REGISTER
        A = A & B;
        PC += 4;
        printf("Instrucao AND\n");
      } else if (IR == or) { // OR REGISTER
        A = A | B;
        PC += 4;
        printf("Instrucao OR\n");
      } else if (IR == xor) { // xor REGISTER
        A = A ^ B;
        PC += 4;
        printf("Instrucao XOR\n");
      } else if (IR == not ) { // not REGISTER
        A = !A;
        PC += 4;
        printf("Instrucao NOT\n");
        // MAR
      } else if (IR == je) { // Jump if= REGISTER
        if (E == 1) {
          PC = MAR;
          printf("Instrucao JE\n");
        }
      } else if (IR == jne) { // Jump if NOT= REGISTER
        if (E == 0) {
          PC = MAR;
          printf("Instrucao JNE\n");
        }
      } else if (IR == jl) { // JUmp IF < REGISTER
        if (L == 1) {
          PC = MAR;
          printf("Instrucao JL\n");
        }
      } else if (IR == jle) { // JUMP IF LOWER THAN OR EQUAL TO REGISTER
        if (L == 1 || E == 1) {
          PC = MAR;
          printf("Instrucao JLE\n");
        }
      } else if (IR == jg) { // JUMP IF GREATER THAN REGISTER
        if (G == 1) {
          PC = MAR;
          printf("Instrucao JG\n");
        }
      } else if (IR == jge) { // JUMP IF GREATER THAN OR EQUAL TO REGISTER
        if (G == 1 || E == 1) {
          PC = MAR;
          printf("Instrucao JGE\n");
        }
      } else if (IR == jmp) { // JUMP REGISTER
        PC = MAR;
        printf("Instrucao JMP\n");

      } else if (IR == lda) { // LOAD A REGISTER
        MBR = MBR | mem[MAR++];
        A = MBR;
        PC += 4;
        printf("Instrucao LDA\n");

      } else if (IR == ldb) { // LOAD B REGISTER
        MBR = MBR | mem[MAR++];
        B = MBR;
        PC += 4;
        printf("Instrucao LDB\n");

      } else if (IR == sta) { // STORE A REGISTER
        MBR = A << 16;
        mem[MAR++] = MBR << 8;
        mem[MAR] = (mem[MAR] | MBR) << 8;
        PC += 4;
        printf("Instrucao STA\n");
      } else if (IR == stb) { // STORE B REGISTER
        MBR = B << 16;
        mem[MAR++] = MBR << 8;
        mem[MAR] = (mem[MAR] | MBR);
        PC += 4;
        printf("Instrucao STB\n");
      } else if (IR == ldrb) { // LOAD A WITH WORD POINTED BY B REGISTER
        MAR = B;
        MBR = mem[MAR++] << 8;
        MBR = (MBR | mem[MAR++]);
        A = MBR << 16;
        PC += 4;
        printf("Instrucao LDRB\n");
        // immediate
      } else if (IR == movial) { // MOVE IMMEDIATE TO LOWER A:  REGISTER
        A = 0b0000000000000000;
        A = IMM << 8;
        PC += 4;
        printf("Instrucao MOVIAL\n");
      } else if (IR == moviah) { // MOVE IMMEDIATE TO HIGHER A REGISTER
        IMM = IMM << 8;
        IMM = IMM & 0xff00;
        A = A & 0x00ff;
        A = A | IMM;
        PC += 4;
        printf("Instrucao MOVIAH\n");
      } else if (IR == addia) { // ADD A WITH IMMEDIATE REGISTER
        A = A + IMM;
        PC += 4;
        printf("Instrucao ADDIA\n");
      } else if (IR == subia) { // SUBTRACT A WITH IMMEDIATE REGISTER
        A = A - IMM;
        PC += 4;
        printf("Instrucao SUBBIA\n");
      } else if (IR == mulia) { // MULTIPLY A WITH IMMEDIATE REGISTER
        A = A * IMM;
        PC += 4;
        printf("Instrucao MULIA\n");
      } else if (IR == divia) { // div A WITH IMMEDIATE REGISTER
        A = A / IMM;
        PC += 4;
        printf("Instrucao DIVIA\n");
      } else if (IR == lsh) { // LEFT SHIFT REGISTER
        A = A << IMM;
        PC += 4;
        printf("Instrucao LSH\n");
      } else if (IR == rsh) { // RIGHT SHIFT REGISTER
        A = A >> IMM;
        PC += 4;
        printf("Instrucao RSH\n");
      }
      LR = LR + 1;

      // Execucao com IBR
    } else if (LR == 1) {
      if (IR == hlt) { // HALT
        Execucao = 155;
        printf("Instrucao HALT: O Programa foi finalizado. Pressione ENTER "
               "para encerra-lo\n");
        scanf("%c", &enter);
        fflush(stdin);
        exit(1);
      } else if (IR == nop) { // NO OPERATION
        PC += 4;
        printf("Instrucao NO OPERATION\n");
      } else if (IR == add) { // ADD REGISTER
        A = A + B;
        printf("Instrucao ADD\n");
      } else if (IR == sub) { // SUB REGISTER
        A = A - B;
        printf("Instrucao SUB\n");
      } else if (IR == mul) { // Multiply REGISTER
        A = A * B;
        printf("Instrucao MUL\n");
      } else if (IR == div) { // DIV REGISTER
        A = A / B;
        printf("Instrucao DIV\n");
      } else if (IR == cmp) { // COMPARE REGISTER
        if (A == B) {
          E = 1;
        } else {
          E = 0;
        }
        if (A < B) {
          L = 1;
        } else {
          L = 0;
        }
        if (A > B) {
          G = 1;
        } else {
          G = 0;
        }
        printf("Instrucao COMPARE\n");
      } else if (IR == xchg) { // EXCHANGE REGISTER
        T = A << 8;
        T = (T & A) << 8;
        A = B << 8;
        A = (A & B) << 8;
        B = T << 8;
        B = (B & A) << 8;
        printf("Instrucao XCHG\n");
      } else if (IR == and) { // And REGISTER
        A = A & B;
        printf("Instrucao AND\n");
      } else if (IR == or) { // OR REGISTER
        A = A | B;
        printf("Instrucao OR\n");
      } else if (IR == xor) { // xor REGISTER
        A = A ^ B;
        printf("Instrucao XOR\n");
      } else if (IR == not ) { // not REGISTER
        A = !A;
        printf("Instrucao NOT\n");
        // MAR
      } else if (IR == je) { // Jump if= REGISTER
        if (E == 1) {
          PC = MAR;
          printf("Instrucao JE\n");
        }
      } else if (IR == jne) { // Jump if NOT= REGISTER
        if (E == 0) {
          PC = MAR;
          printf("Instrucao JNE\n");
        }
      } else if (IR == jl) { // JUmp IF < REGISTER
        if (L == 1) {
          PC = MAR;
          printf("Instrucao JL\n");
        }
      } else if (IR == jle) { // JUMP IF LOWER THAN OR EQUAL TO REGISTER
        if (L == 1 || E == 1) {
          PC = MAR;
          printf("Instrucao JLE\n");
        }
      } else if (IR == jg) { // JUMP IF GREATER THAN REGISTER
        if (G == 1) {
          PC = MAR;
          printf("Instrucao JG\n");
        }
      } else if (IR == jge) { // JUMP IF GREATER THAN OR EQUAL TO REGISTER
        if (G == 1 || E == 1) {
          PC = MAR;
          printf("Instrucao JGE\n");
        }
      } else if (IR == jmp) { // JUMP REGISTER
        PC = MAR;
        printf("Instrucao JMP\n");

      } else if (IR == lda) { // LOAD A REGISTER
        MBR = mem[MAR++] << 8;
        IBR = MBR | mem[MAR++];
        A = IBR;
        printf("Instrucao LDA\n");

      } else if (IR == ldb) { // LOAD B REGISTER
        MBR = mem[MAR++] << 8;
        IBR = IBR | mem[MAR++];
        B = IBR;
        printf("Instrucao LDB\n");

      } else if (IR == sta) { // STORE A REGISTER
        MBR = A << 16;
        mem[MAR++] = MBR << 8;
        mem[MAR] = (mem[MAR] | MBR);
        printf("Instrucao STA\n");
      } else if (IR == stb) { // STORE B REGISTER
        MBR = B << 16;
        mem[MAR++] = MBR << 8;
        mem[MAR] = (mem[MAR] | MBR);
        printf("Instrucao STB\n");
      } else if (IR == ldrb) { // LOAD A WITH WORD POINTED BY B REGISTER
        MAR = B;
        MBR = mem[MAR++] << 8;
        MBR = (MBR | mem[MAR++]) << 8;
        A = MBR << 16;
        printf("Instrucao LDRB\n");
        // immediate
      } else if (IR == movial) { // MOVE IMMEDIATE TO LOWER A:  REGISTER
        A = 0b0000000000000000;
        A = IMM << 8;
        printf("Instrucao MOVIAL\n");
      } else if (IR == moviah) { // MOVE IMMEDIATE TO HIGHER A REGISTER
        IMM = IMM << 8;
        IMM = IMM & 0xff00;
        A = A & 0x00ff;
        A = A | IMM;
        printf("Instrucao MOVIAH\n");
      } else if (IR == addia) { // ADD A WITH IMMEDIATE REGISTER
        A = A + IMM;
        printf("Instrucao ADDIA\n");
      } else if (IR == subia) { // SUBTRACT A WITH IMMEDIATE REGISTER
        A = A - IMM;
        printf("Instrucao SUBBIA\n");
      } else if (IR == mulia) { // MULTIPLY A WITH IMMEDIATE REGISTER
        A = A * IMM;
        printf("Instrucao MULIA\n");
      } else if (IR == divia) { // div A WITH IMMEDIATE REGISTER
        A = A / IMM;
        printf("Instrucao DIVIA\n");
      } else if (IR == lsh) { // LEFT SHIFT REGISTER
        A = A << IMM;
        printf("Instrucao LSH\n");
      } else if (IR == rsh) { // RIGHT SHIFT REGISTER
        A = A >> IMM;
        printf("Instrucao RSH\n");
      }
      LR = 0;
    }

    // Dados na tela
    printf("CPU:\nA:\t0x%04x\tB:\t0x%04x\tT:\t0x%04x\nMBR:\t0x%08x\tMAR:\t0x%"
           "04x\tIBR:\t0x%08x\nIMM:\t0x%04x\nPC:\t0x%04x\tIR:\t0x%02x\tLR:\t0x%"
           "01x\nE:\t0x%01x\tL:\t0x%01x\tG:\t0x%01x\n\nMemoria:\n ",
           A, B, T, MBR, MAR, IBR, IMM, PC, IR, LR, E, L, G);
    for (impressao = 0; impressao < 154; impressao++) {
      printf("%d:\t\t0x%02x\n", impressao, mem[impressao]);
    }
    impressao = 0;
    printf("\nPressione ENTER para continuar a execucao do programa.\n");
    scanf("%c", &enter);
    fflush(stdin);
  }
}

//Trabalho Incompleto


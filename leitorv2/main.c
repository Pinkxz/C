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

  // Leitor de arquivo
  FILE *arquivo;
  char linha[100];
  char *token;

  // Abre o arquivo para leitura
  arquivo = fopen("programa1.txt", "r");

  // Verifica se o arquivo foi aberto corretamente
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return EXIT_FAILURE;
  }

  // Lê cada linha do arquivo
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    char enderecoInicial[50];
    char tipo[50];
    char conteudo[50];

    // Processamento de cada linha
    for (int i = 0; linha[i] != '\0'; i++) {
      // tokens
      token = strtok(linha, ";");
      int j = 0;

      while (token != NULL && j < 3) {
        if (j == 0)
          strcpy(enderecoInicial, token);
        else if (j == 1)
          strcpy(tipo, token);
        else if (j == 2)
          strcpy(conteudo, token);

        token = strtok(NULL, ";");
        j++;
      }

      // Se for dados
      if (strcmp(tipo, "d") == 0) {
        int palavra = (int)strtol(conteudo, NULL, 16);
      }

      // Se for instrução
      else if (strcmp(tipo, "i") == 0) {

        // 1 token
        token = strtok(conteudo, " ");
        int rx, ry, rz, mar, imm, palavra, opcode = 0;

        if (strcmp(tipo, "hlt") == 0) {
          opcode = hlt;
          palavra = opcode;
        } else if (strcmp(tipo, "nop") == 0) {
          opcode = nop;
          palavra = opcode;
        } else if (strcmp(tipo, "not") == 0) {
          opcode = not ;
          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          rx = atoi(conteudo);
          palavra = (opcode << 27) | rx;
        } else if (strcmp(tipo, "movr") == 0) {
          opcode = movr;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | ry;
        } else if (strcmp(tipo, "cmp") == 0) {
          opcode = cmp;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | ry;
        } else if (strcmp(tipo, "ldbo") == 0) {
          opcode = ldbo;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              mar = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | mar;
        } else if (strcmp(tipo, "stbo") == 0) {
          opcode = stbo;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              mar = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | mar;
        } else if (strcmp(tipo, "add") == 0) {
          opcode = add;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              rz = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
        } else if (strcmp(tipo, "sub") == 0) {
          opcode = sub;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              rz = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
        } else if (strcmp(tipo, "mul") == 0) {
          opcode = mul;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              rz = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
        } else if (strcmp(tipo, "div") == 0) {
          opcode = div;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              rz = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
        } else if (strcmp(tipo, "and") == 0) {
          opcode = and;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              rz = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
        } else if (strcmp(tipo, "or") == 0) {
          opcode = or ;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              rz = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
        } else if (strcmp(tipo, "xor") == 0) {
          opcode = xor;

          int i = 0;
          while (token != NULL && i < 3) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              ry = atoi(conteudo);
            } else if (i == 2) {
              strcpy(conteudo, token);
              rz = atoi(conteudo);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
        } else if (strcmp(tipo, "ld") == 0) {
          opcode = ld;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              mar = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | mar;
        } else if (strcmp(tipo, "st") == 0) {
          opcode = st;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              mar = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | mar;
        } else if (strcmp(tipo, "movil") == 0) {
          opcode = movil;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "movih") == 0) {
          opcode = movih;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "addi") == 0) {
          opcode = addi;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "subi") == 0) {
          opcode = subi;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "muli") == 0) {
          opcode = muli;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "divi") == 0) {
          opcode = divi;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "lsh") == 0) {
          opcode = lsh;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "rsh") == 0) {
          opcode = rsh;

          int i = 0;
          while (token != NULL && i < 2) {
            if (i == 0) {
              strcpy(conteudo, token);
              rx = atoi(conteudo);
            } else if (i == 1) {
              strcpy(conteudo, token);
              imm = (int)strtol(conteudo, NULL, 16);
            }
          }
          palavra = (opcode << 27) | (rx << 19) | imm;
        } else if (strcmp(tipo, "je") == 0) {
          opcode = je;

          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          mar = (int)strtol(conteudo, NULL, 16);
          palavra = (opcode << 27) | mar;
        } else if (strcmp(tipo, "jne") == 0) {
          opcode = jne;

          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          mar = (int)strtol(conteudo, NULL, 16);
          palavra = (opcode << 27) | mar;
        } else if (strcmp(tipo, "jl") == 0) {
          opcode = jl;

          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          mar = (int)strtol(conteudo, NULL, 16);
          palavra = (opcode << 27) | mar;
        } else if (strcmp(tipo, "jle") == 0) {
          opcode = jle;

          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          mar = (int)strtol(conteudo, NULL, 16);
          palavra = (opcode << 27) | mar;
        } else if (strcmp(tipo, "jg") == 0) {
          opcode = jg;

          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          mar = (int)strtol(conteudo, NULL, 16);
          palavra = (opcode << 27) | mar;
        } else if (strcmp(tipo, "jge") == 0) {
          opcode = jge;

          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          mar = (int)strtol(conteudo, NULL, 16);
          palavra = (opcode << 27) | mar;
        } else if (strcmp(tipo, "jmp") == 0) {
          opcode = jmp;

          token = strtok(NULL, " ");
          strcpy(conteudo, token);
          mar = (int)strtol(conteudo, NULL, 16);
          palavra = (opcode << 27) | mar;
        }
        memoria[atoi(enderecoInicial)] = (palavra & 0xFF000000) >> 24;
        memoria[atoi(enderecoInicial) + 1] = (palavra & 0x00FF0000) >> 16;
        memoria[atoi(enderecoInicial) + 2] = (palavra & 0x0000FF00) >> 8;
        memoria[atoi(enderecoInicial) + 3] = (palavra & 0x000000FF);

      } // Fim do tipo == i
    }
  }

  // Fecha o arquivo
  fclose(arquivo);

  return EXIT_SUCCESS;
  // Fim do Leitor de Arquivo

  for (int Execucao = 0; Execucao < 154; Execucao++) {
    // Busca
    MAR = PC;
    MBR = memoria[MAR++] << 8;
    MBR = (MBR | memoria[MAR++]) << 8;
    MBR = (MBR | memoria[MAR++]) << 8;
    MBR = MBR | memoria[MAR++];

    // Decodificação
    IR = MBR >> 27;
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_LINHA 154

// Definindo os opcodes
#define HLT   0b00000 // Ok
#define NOP   0b00001 // Ok
#define LDR   0b00010
#define STR   0b00011
#define ADD   0b00100
#define SUB   0b00101
#define MUL   0b00110
#define DIV   0b00111
#define CMP   0b01000
#define MOVR  0b01001
#define AND   0b01010
#define OR    0b01011
#define XOR   0b01100
#define NOT   0b01101
#define JE    0b01110
#define JNE   0b01111
#define JL    0b10000
#define JLE   0b10001
#define JG    0b10010
#define JGE   0b10011
#define JMP   0b10100
#define LD    0b10101
#define ST    0b10110
#define MOVI  0b10111
#define ADDI  0b11000
#define SUBI  0b11001
#define MULI  0b11010
#define DIVI  0b11011
#define LSH   0b11100
#define RSH   0b11101


// Variáveis principais
unsigned char memoria[TAM_LINHA];
unsigned short int PC, MAR;
unsigned int MBR, IMM;
unsigned char IR, R0, R1;
unsigned char E, L, G;
unsigned short int reg[4];

// Separando a posição da memória
void separaPosicao(char *entrada, char *posicao) {
    sscanf(entrada, "%[^;]", posicao);
}

// Converte hexadecimal para inteiro
int hexaParaInt(const char *hexa) {
    return (int)strtol(hexa, NULL, 16);
}

// Retorna a próxima posição de separador
int proxInstrucao(const char *entrada, int ini, char div) {
    char *p = strchr(entrada + ini, div);
    return p ? (int)(p - entrada) + 1 : strlen(entrada);
}

// Separa a instrução principal
void separaInstrucao(char *entrada, char *instrucao, int ini) {
    int i = 0;
    while (entrada[ini + i] && entrada[ini + i] != '/') {
        instrucao[i] = entrada[ini + i];
        i++;
    }
    if (entrada[ini + i] == '/') instrucao[i++] = '/';
    instrucao[i] = '\0';
}

// Extrai valor em hexadecimal
int extraiValor(char *entrada, int ini) {
    char valorHex[6];
    sscanf(entrada + ini, "%5s", valorHex);
    return hexaParaInt(valorHex);
}

// Obtém o opcode
int getOpcode(const char *op) {
    if (strcmp(op, "hlt") == 0) return HLT;
    if (strcmp(op, "nop") == 0) return NOP;
    if (strcmp(op, "ldr") == 0) return LDR;
    if (strcmp(op, "str") == 0) return STR;
    if (strcmp(op, "add") == 0) return ADD;
    if (strcmp(op, "sub") == 0) return SUB;
    if (strcmp(op, "mul") == 0) return MUL;
    if (strcmp(op, "div") == 0) return DIV;
    if (strcmp(op, "cmp") == 0) return CMP;
    if (strcmp(op, "movr") == 0) return MOVR;
    if (strcmp(op, "and") == 0) return AND;
    if (strcmp(op, "or") == 0) return OR;
    if (strcmp(op, "xor") == 0) return XOR;
    if (strcmp(op, "not") == 0) return NOT;
    if (strcmp(op, "je") == 0) return JE;
    if (strcmp(op, "jne") == 0) return JNE;
    if (strcmp(op, "jl") == 0) return JL;
    if (strcmp(op, "jle") == 0) return JLE;
    if (strcmp(op, "jg") == 0) return JG;
    if (strcmp(op, "jge") == 0) return JGE;
    if (strcmp(op, "jmp") == 0) return JMP;
    if (strcmp(op, "ld") == 0) return LD;
    if (strcmp(op, "st") == 0) return ST;
    if (strcmp(op, "movi") == 0) return MOVI;
    if (strcmp(op, "addi") == 0) return ADDI;
    if (strcmp(op, "subi") == 0) return SUBI;
    if (strcmp(op, "muli") == 0) return MULI;
    if (strcmp(op, "divi") == 0) return DIVI;
    if (strcmp(op, "lsh") == 0) return LSH;
    if (strcmp(op, "rsh") == 0) return RSH;
    return -1;
}

void guardaInstrucao(const char *instrucao, int pos, char *mem) {
    char op[10], arg1[10] = "", arg2[10] = "";
    int opcode = -1, reg1 = 0, reg2 = 0, valor_imm = 0;
    unsigned short cod = 0;

    sscanf(instrucao, "%s %[^,], %s", op, arg1, arg2);
    opcode = getOpcode(op);
    if (opcode == -1) return;

    // Instruções sem operandos (hlt, nop)
    if (strcmp(op, "hlt") == 0 || strcmp(op, "nop") == 0) {
        cod = (opcode << 11);
        mem[pos] = (cod >> 8) & 0xFF;
        mem[pos + 1] = cod & 0xFF;
        return;
    }

    // Instrução com 1 registrador (not)
    if (strcmp(op, "not") == 0) {
        if (arg1[0] == 'r' || arg1[0] == 'R')
            reg1 = atoi(arg1 + 1);
        cod = (opcode << 11) | (reg1 << 9);
        mem[pos] = (cod >> 8) & 0xFF;
        mem[pos + 1] = cod & 0xFF;
        return;
    }

    // Instruções de salto (1 MAR)
    if (
        strcmp(op, "je") == 0 || strcmp(op, "jne") == 0 ||
        strcmp(op, "jl") == 0 || strcmp(op, "jle") == 0 ||
        strcmp(op, "jg") == 0 || strcmp(op, "jge") == 0 ||
        strcmp(op, "jmp") == 0
    ) {
        valor_imm = (int)strtol(arg1, NULL, 16);
        cod = (opcode << 11);
        mem[pos] = (cod >> 8) & 0xFF;
        mem[pos + 1] = 0x00;
        mem[pos + 2] = valor_imm & 0xFF;
        return;
    }

    // Instruções com dois registradores
    if (arg1[0] == 'r' || arg1[0] == 'R') reg1 = atoi(arg1 + 1);
    if (arg2[0] == 'r' || arg2[0] == 'R') {
        reg2 = atoi(arg2 + 1);
        cod = (opcode << 11) | (reg1 << 9) | (reg2 << 7);
        mem[pos] = (cod >> 8) & 0xFF;
        mem[pos + 1] = cod & 0xFF;
    } else if (strlen(arg2) > 0) {
        // Instruções com imediato
        valor_imm = (int)strtol(arg2, NULL, 16);
        cod = (opcode << 11) | (reg1 << 9);
        mem[pos] = (cod >> 8) & 0xFF;
        mem[pos + 1] = (valor_imm >> 8) & 0xFF;  // byte alto
        mem[pos + 2] = valor_imm & 0xFF;         // byte baixo

    }
}


// Decodifica linha de texto e armazena na memória
void decodificaStringEGuardaNaMemoria(char *entrada, unsigned char *memoria) {
    char posicao[6], instrucao[50];
    int ini = 0;

    memset(posicao, '\0', sizeof(posicao));
    memset(instrucao, '\0', sizeof(instrucao));

    separaPosicao(entrada, posicao);
    int pos = hexaParaInt(posicao);
    ini = proxInstrucao(entrada, ini, ';');

    // Pega o tipo direto
    char tipo = entrada[ini];
    ini = proxInstrucao(entrada, ini, ';');

    if (tipo == 'i') {
        separaInstrucao(entrada, instrucao, ini);
        if (pos >= TAM_LINHA - 1) return;
        guardaInstrucao(instrucao, pos, (char *)memoria);
    } else if (tipo == 'd') {
        int valor = extraiValor(entrada, ini);
        if (pos >= TAM_LINHA - 1) return;
        memoria[pos] = (valor >> 8) & 0xFF;
        memoria[pos] = valor & 0xFF;
    }
}

// Carrega arquivo na memória
void carregar_memoria(const char* nome_arquivo) {
    printf("Carregando arquivo...\n");
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    char linha[TAM_LINHA];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        decodificaStringEGuardaNaMemoria(linha, memoria);
    }

    fclose(arquivo);
}

// Main
int main() {
    memset(memoria, 0x00, TAM_LINHA);
    carregar_memoria("entrada.txt");

        for (int impressao = 0; impressao < 154; impressao++) {
            printf("%3d: 0x%02x\t", impressao, memoria[impressao]);
            
            if ((impressao + 1) % 10 == 0) {
                printf("\n");
            }
        }

    return 0;
}

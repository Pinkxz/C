#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_LINHA 154

// Define dos opcodes
#define HLT   0b00000
#define NOP   0b00001
#define LDR   0b10101
#define STR   0b10110
#define ADD   0b00010
#define SUB   0b00011
#define MUL   0b00100
#define DIV   0b00101
#define CMP   0b00110
#define MOVR  0b00111
#define AND   0b01000
#define OR    0b01001
#define XOR   0b01010
#define NOT   0b01011
#define JE    0b01100
#define JNE   0b01101
#define JL    0b01110
#define JLE   0b01111
#define JG    0b10000
#define JGE   0b10001
#define JMP   0b10010
#define LD    0b10011
#define ST    0b10100
#define MOVI  0b10111
#define ADDI  0b11000
#define SUBI  0b11001
#define MULI  0b11010
#define DIVI  0b11011
#define LSH   0b11100
#define RSH   0b11101

unsigned char memoria[TAM_LINHA];
unsigned int MBR;
unsigned short int MAR;
unsigned char IR;
unsigned char R0;
unsigned char R1;
unsigned int IMM;
unsigned short int PC;
unsigned char E, L, G;
unsigned short int reg[4];


void limpaEspacosEsquerda(char *s) {
    int i = 0;
    while (isspace((unsigned char)s[i])) i++;
    if (i > 0) memmove(s, s + i, strlen(s + i) + 1);
}

void separaPosicao(char *entrada, char *posicao) {
    sscanf(entrada, "%[^;]", posicao);
    limpaEspacosEsquerda(posicao);
}

int hexaParaInt(const char *hexa) {
    return (int)strtol(hexa, NULL, 16);
}

int proxInstrucao(const char *entrada, int ini, char div) {
    char *p = strchr(entrada + ini, div);
    return p ? (int)(p - entrada) + 1 : strlen(entrada);
}

char tipoInstrucao(char *entrada, int ini) {
    char temp[10];
    sscanf(entrada + ini, "%[^;]", temp);
    limpaEspacosEsquerda(temp);
    return temp[0];
}

void limpaVetor(char *v, int tam) {
    memset(v, '\0', tam);
}

void separaInstrucao(char *entrada, char *instrucao, int ini) {
    int i = 0;
    while (entrada[ini + i] && entrada[ini + i] != '/') {
        instrucao[i] = entrada[ini + i];
        i++;
    }
    if (entrada[ini + i] == '/') instrucao[i++] = '/';
    instrucao[i] = '\0';
    limpaEspacosEsquerda(instrucao);
}

int extraiValor(char *entrada, int ini) {
    char valorHex[6];
    sscanf(entrada + ini, "%5s", valorHex);
    limpaEspacosEsquerda(valorHex);
    return hexaParaInt(valorHex);
}


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
    char op[10], arg1[10], arg2[10] = "";
    int opcode = -1, reg1 = 0, reg2 = 0, valor_imm = 0;
    unsigned short cod = 0;

    sscanf(instrucao, "%s %[^,], %s", op, arg1, arg2);
    opcode = getOpcode(op);
    if (opcode == -1) return;

    if (arg1[0] == 'r' || arg1[0] == 'R') reg1 = atoi(arg1 + 1);

    if (arg2[0] == 'r' || arg2[0] == 'R') {
        reg2 = atoi(arg2 + 1);
        cod = (opcode << 11) | (reg1 << 9) | (reg2 << 7);
        mem[pos] = (cod >> 8) & 0xFF;
        mem[pos + 1] = cod & 0xFF;

    } else if (strlen(arg2) > 0) {
        valor_imm = (int)strtol(arg2, NULL, 16);
        cod = (opcode << 11) | (reg1 << 9);
        mem[pos] = (cod >> 8) & 0xFF;
        mem[pos + 1] = 0x00;               // Zera o segundo byte
        mem[pos + 2] = valor_imm & 0xFF;   // Armazena o imediato na terceira posição
    }
}


void decodificaStringEGuardaNaMemoria(char *entrada, unsigned char *memoria) {
    char posicao[6], instrucao[50];
    int ini = 0;

    limpaVetor(posicao, sizeof(posicao));
    limpaVetor(instrucao, sizeof(instrucao));

    separaPosicao(entrada, posicao);
    int pos = hexaParaInt(posicao);
    ini = proxInstrucao(entrada, ini, ';');

    char tipo = tipoInstrucao(entrada, ini);
    ini = proxInstrucao(entrada, ini, ';');

    if (tipo == 'i') {
        separaInstrucao(entrada, instrucao, ini);
        if (pos >= TAM_LINHA - 1) return;
        guardaInstrucao(instrucao, pos, (char *)memoria);

    } else if (tipo == 'd') {
        int valor = extraiValor(entrada, ini);
        if (pos >= TAM_LINHA - 1) return;
        memoria[pos] = (valor >> 8) & 0xFF;
        memoria[pos + 1] = valor & 0xFF;
    }
}



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

int main() {
    memset(memoria, 0x00, TAM_LINHA);
    carregar_memoria("entrada.txt");

    for (int i = 0; i < TAM_LINHA; i++) {
        printf("%d:\t\t0x%02x\n", i, memoria[i]);
    }

    return 0;
}



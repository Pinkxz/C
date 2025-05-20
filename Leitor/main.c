#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MEM_SIZE 154
#define MAX_LINHA 154
#define NUM_INSTS 30

// Memória principal
unsigned char memoria[MEM_SIZE];

// Lista de instruções e seus opcodes
const char *INSTS[NUM_INSTS] = {
    "hlt", "nop", "ldr", "str", "add", "sub", "mul", "div",
    "cmp", "movr", "and", "or", "xor", "not", "je", "jne",
    "jl", "jle", "jg", "jge", "jmp", "ld", "st", "movi",
    "addi", "subi", "muli", "divi", "lsh", "rsh"
};

const int OPCODES[NUM_INSTS] = {
    0b00000, 0b00001, 0b10101, 0b10110, 0b00010, 0b00011, 0b00100, 0b00101,
    0b00110, 0b00111, 0b01000, 0b01001, 0b01010, 0b01011, 0b01100, 0b01101,
    0b01110, 0b01111, 0b10000, 0b10001, 0b10010, 0b10011, 0b10100, 0b10111,
    0b11000, 0b11001, 0b11010, 0b11011, 0b11100, 0b11101
};

void limpaEspacosEsquerda(char *s) {
    while (isspace((unsigned char)*s)) s++;
    memmove(s - (s - s), s, strlen(s) + 1);
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

void separaPosicao(char *entrada, char *posicao) {
    sscanf(entrada, "%[^;]", posicao);
    limpaEspacosEsquerda(posicao);
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

void guardaInstrucao(const char *instrucao, int pos, unsigned char *mem) {
    char op[10], arg1[10], arg2[10] = "";
    int opcode = -1, reg1 = 0, reg2 = 0, valor_imm = 0;
    unsigned short cod = 0;

    sscanf(instrucao, "%s %[^,], %s", op, arg1, arg2);

    for (int i = 0; i < NUM_INSTS; i++) {
        if (strcmp(op, INSTS[i]) == 0) {
            opcode = OPCODES[i];
            break;
        }
    }

    if (opcode == -1) return;

    if (arg1[0] == 'r' || arg1[0] == 'R')
        reg1 = (int)strtol(arg1 + 1, NULL, 10);

    if (arg2[0] == 'r' || arg2[0] == 'R') {
        reg2 = (int)strtol(arg2 + 1, NULL, 10);
        cod = (opcode << 11) | (reg1 << 8) | (reg2 << 5);
    } else if (strlen(arg2) > 0) {
        valor_imm = (int)strtol(arg2, NULL, 16);
        cod = (opcode << 11) | (reg1 << 8) | (valor_imm & 0xFF);
    }

    mem[pos]     = (cod >> 8) & 0xFF;
    mem[pos + 1] = cod & 0xFF;
}

void decodificaStringEGuardaNaMemoria(char *entrada, unsigned char *memoria) {
    char posicao[6], instrucao[50];
    int ini = 0;

    memset(posicao, 0, sizeof(posicao));
    memset(instrucao, 0, sizeof(instrucao));

    separaPosicao(entrada, posicao);
    int pos = hexaParaInt(posicao);

    if (pos >= MEM_SIZE - 1) {
        printf("Erro: posição %d fora dos limites da memória.\n", pos);
        return;
    }

    ini = proxInstrucao(entrada, ini, ';');
    char tipo = tipoInstrucao(entrada, ini);
    ini = proxInstrucao(entrada, ini, ';');

    if (tipo == 'i') {
        separaInstrucao(entrada, instrucao, ini);
        guardaInstrucao(instrucao, pos, memoria);
    } else if (tipo == 'd') {
        int valor = extraiValor(entrada, ini);
        memoria[pos]     = (valor >> 8) & 0xFF;
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

    char linha[MAX_LINHA];
    while (fgets(linha, sizeof(linha), arquivo)) {
        decodificaStringEGuardaNaMemoria(linha, memoria);
    }

    fclose(arquivo);
}

int main() {
    memset(memoria, 0x00, sizeof(memoria));
    carregar_memoria("entrada.txt");

    for (int i = 0; i < MEM_SIZE; i++) {
        printf("%3d:\t0x%02X\n", i, memoria[i]);
    }

    return 0;
}

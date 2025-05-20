#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_LINHA 154

unsigned char memoria[TAM_LINHA];

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

void guardaInstrucao(const char *instrucao, int pos, char *mem) {
    const char *insts[] = {"hlt", "nop", "ldr", "str", "add", "sub", "mul", "div",
                           "cmp", "movr", "and", "or", "xor", "not", "je", "jne",
                           "jl", "jle", "jg", "jge", "jmp", "ld", "st", "movi",
                           "addi", "subi", "muli", "divi", "lsh", "rsh"};

    char op[10] = "", arg1[10] = "", arg2[10] = "";
    int opcode = 0, reg1 = 0, reg2 = 0, imm = 0;
    int is_immediate = 0;

    sscanf(instrucao, "%s %[^,], %s", op, arg1, arg2);

    for (int i = 0; i < 32; i++) {
        if (strcmp(op, insts[i]) == 0) {
            opcode = i;
            break;
        }
    }

    if (arg1[0] == 'r' || arg1[0] == 'R')
        reg1 = atoi(arg1 + 1);

    if (arg2[0] == 'r' || arg2[0] == 'R') {
        reg2 = atoi(arg2 + 1);
        is_immediate = 0;
    } else {
        imm = (int)strtol(arg2, NULL, 16);
        is_immediate = 1;
    }

    unsigned short cod;

    if (is_immediate)
        cod = (opcode << 11) | (reg1 << 8) | (imm & 0xFF);
    else
        cod = (opcode << 11) | (reg1 << 8) | (reg2 << 5);

    mem[pos] = (cod >> 8) & 0xFF;
    mem[pos + 1] = cod & 0xFF;
}

void decodificaStringEGuardaNaMemoria(char *entrada, unsigned char *memoria) {
    char posicao[6], instrucao[50], operacao[10], endereco[10];
    int ini = 0;

    limpaVetor(posicao, sizeof(posicao));
    limpaVetor(instrucao, sizeof(instrucao));
    limpaVetor(operacao, sizeof(operacao));
    limpaVetor(endereco, sizeof(endereco));

    separaPosicao(entrada, posicao);
    int pos = hexaParaInt(posicao);
    ini = proxInstrucao(entrada, ini, ';');

    char tipo = tipoInstrucao(entrada, ini);
    ini = proxInstrucao(entrada, ini, ';');

    if (tipo == 'i') {
        separaInstrucao(entrada, instrucao, ini);

        if (pos >= TAM_LINHA - 1) {
            printf("Erro: posição %d fora dos limites da memória.\n", pos);
            return;
        }

        guardaInstrucao(instrucao, pos, (char *)memoria);

    } else if (tipo == 'd') {
        int valor = extraiValor(entrada, ini);
        if (pos >= TAM_LINHA - 1) {
            printf("Erro: posição %d fora dos limites da memória.\n", pos);
            return;
        }

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

    if (fclose(arquivo) != 0) {
        perror("Erro ao fechar arquivo");
        exit(1);
    }
}

int main() {
    memset(memoria, 0x00, TAM_LINHA);

    carregar_memoria("entrada.txt");

    for (int i = 0; i < TAM_LINHA; i++) {
        printf("%d:\t\t0x%02x\n", i, memoria[i]);
    }

    return 0;
}

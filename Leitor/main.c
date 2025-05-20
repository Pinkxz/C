#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


unsigned char memoria[154];
#define TAM_LINHA 154;

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

void separaOpEndereco(char *instrucao, char *op, char *end) {
    sscanf(instrucao, "%s %s", op, end);
}

int extraiValor(char *entrada, int ini) {
    char valorHex[6];
    sscanf(entrada + ini, "%s", valorHex);
    limpaEspacosEsquerda(valorHex);
    return hexaParaInt(valorHex);
}

void decodificaStringEGuardaNaMemoria(char *entrada, char *memoria) {
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

    if (tipo == 'I') {
        separaInstrucao(entrada, instrucao, ini);
        separaOpEndereco(instrucao, operacao, endereco);
        int endInt = endereco[0] == '/' ? atoi(endereco + 1) : hexaParaInt(endereco);
        guardaInstrucao(operacao, endInt, pos, memoria);
    } else if (tipo == 'D') {
        int valor = extraiValor(entrada, ini);
        memoria[pos] = (valor >> 8) & 0xFF;
        memoria[pos + 1] = valor & 0xFF;
    }
}

void guardaInstrucao(const char *op, int end, int pos, char *mem) {
    const char *insts[] = {"hlt", "nop", "add", "sub", "mul", "div", "cmp", "xchg",
                           "nad", "or", "xor", "not", "je", "jne", "jl", "jle",
                           "jg", "jge", "jmp", "lda", "ldb", "sta", "stb", "ldrb",
                           "movial", "moviah", "addia", "subia", "mulia", "divia", "lsh", "rsh"};

    int opcode = 0;
    if (op && *op) {
        for (int i = 0; i < 32; i++) {
            if (strcmp(op, insts[i]) == 0) {
                opcode = i;
                break;
            }
        }
    }

    unsigned short cod = (opcode << 11) | (end & 0x7FF);
    mem[pos] = cod >> 8;
    mem[pos + 1] = cod & 0xFF;
}

void carregar_memoria(const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    char linha[154];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        decodificaStringEGuardaNaMemoria(linha, memoria);
    }

    if (fclose(arquivo) != 0) {
        perror("Erro ao fechar arquivo");
        exit(1);
    }

    fclose(arquivo);
}



int main(){
    int impressao = 0;
    // Zerando a memoria
    for (int zero = 0; zero < 154; zero++) {
        memoria[zero] = 0x00;
    }
    for (impressao = 0; impressao < 154; impressao++) {
      printf("%d:\t\t0x%02x\n", impressao, memoria[impressao]);
    }
    impressao = 0;

    carregar_memoria("entrada.txt");


    return 0;
}
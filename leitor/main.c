#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *arquivo;
    char linha[100];
    unsigned char memoria[154];
    char *token;

    // Abre o arquivo para leitura
    arquivo = fopen("arquivo.txt", "r");

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


        //limpando o vetor das strings
        for(int i = 0; i < 50; i++){
            enderecoInicial[i] = '';
            tipo[i] = '';
            conteudo[i] = '';
        }

        //Processamento de cada linha
        for (int i = 0; linha[i] != '\0'; i++) {
            //tokens
            token = strtok(linha, ";");
            int j = 0;

            while(token != NULL && j < 3){
                if(j == 0)
                    strcpy(enderecoInicial, token);
                else if(j == 1)
                    strcpy(tipo, token);
                else if(j == 2)
                    strcpy(conteudo, token);

                token = strtok(NULL, ";");
                j++;

            }

            //Se for dados
            if(tipo == "d")
                int palavra = (int)strtol(conteudo, NULL, 16);

            //Se for instrução
            else if(tipo == "i"){

                //1 token
                token = strtok(conteudo, " ");

                if (token == "hlt"){
                    int opcode = hlt;
                    int palavra = opcode;
                }
                else if (token == "nop"){
                    int opcode = nop;
                    int palavra = opcode;
                }
                else if(token =="not"){
                    int opcode = not;
                    token = strtok(NULL, " ");
                    conteudo = token;
                    int rx = atoi(conteudo);
                    int palavra = (opcode << 27) | rx;
                }
                else if(token =="movr"){
                    int opcode = movr;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | ry;
                }
                else if(token =="cmp"){
                    int opcode = cmp;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | ry;
                }
                else if(token =="ldbo"){
                    int opcode = ldbo;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int mar = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | mar;
                }
                else if(token =="stbo"){
                    int opcode = stbo;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int mar = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | mar;
                }
                else if(token =="add"){
                    int opcode = add;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int rz = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
                }
                else if(token =="sub"){
                    int opcode = sub;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int rz = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
                }
                else if(token =="mul"){
                    int opcode = mul;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int rz = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
                }
                else if(token =="div"){
                    int opcode = div;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int rz = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
                }
                else if(token =="and"){
                    int opcode = and;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int rz = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
                }
                else if(token =="or"){
                    int opcode = or;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int rz = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
                }
                else if(token =="xor"){
                    int opcode = xor;

                    int i = 0;
                    while(token != NULL && i < 3){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int ry = atoi(conteudo);
                        }
                        else if(i == 2){
                            strcpy(conteudo, token);
                            int rz = atoi(conteudo);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | (ry << 15) | rz;
                }
                else if(token =="ld"){
                    int opcode = ld;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int mar = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | mar;
                }
                else if(token =="st"){
                    int opcode = st;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int mar = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | mar;
                }
                else if(token =="movil"){
                    int opcode = movil;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="movih"){
                    int opcode = movih;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="addi"){
                    int opcode = addi;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="subi"){
                    int opcode = subi;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="muli"){
                    int opcode = muli;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="divi"){
                    int opcode = divi;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="lsh"){
                    int opcode = lsh;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="rsh"){
                    int opcode = rsh;

                    int i = 0;
                    while(token != NULL && i < 2){
                        if(i == 0){
                            strcpy(conteudo, token);
                            int rx = atoi(conteudo);
                        }
                        else if(i == 1){
                            strcpy(conteudo, token);
                            int imm = (int)strtol(conteudo, NULL, 16);
                        }
                    }
                    int palavra = (opcode << 27) | (rx << 19) | imm;
                }
                else if(token =="je"){
                    int opcode = je;

                    token = strtok(NULL, " ");
                    conteudo = token;
                    int mar = (int)strtol(conteudo, NULL, 16);
                    int palavra = (opcode << 27) | mar;
                }
                else if(token =="jne"){
                    int opcode = jne;

                    token = strtok(NULL, " ");
                    conteudo = token;
                    int mar = (int)strtol(conteudo, NULL, 16);
                    int palavra = (opcode << 27) | mar;
                }
                else if(token =="jl"){
                    int opcode = jl;

                    token = strtok(NULL, " ");
                    conteudo = token;
                    int mar = (int)strtol(conteudo, NULL, 16);
                    int palavra = (opcode << 27) | mar;
                }
                else if(token =="jle"){
                    int opcode = jle;

                    token = strtok(NULL, " ");
                    conteudo = token;
                    int mar = (int)strtol(conteudo, NULL, 16);
                    int palavra = (opcode << 27) | mar;
                }
                else if(token =="jg"){
                    int opcode = jg;

                    token = strtok(NULL, " ");
                    conteudo = token;
                    int mar = (int)strtol(conteudo, NULL, 16);
                    int palavra = (opcode << 27) | mar;
                }
                else if(token =="jge"){
                    int opcode = jge;

                    token = strtok(NULL, " ");
                    conteudo = token;
                    int mar = (int)strtol(conteudo, NULL, 16);
                    int palavra = (opcode << 27) | mar;
                }
                else if(token =="jmp"){
                    int opcode = jmp;

                    token = strtok(NULL, " ");
                    conteudo = token;
                    int mar = (int)strtol(conteudo, NULL, 16);
                    int palavra = (opcode << 27) | mar;
                }
            }// Fim do tipo == i

            memoria[enderecoInicial] = (palavra & 0xFF) >> 24;
            memoria[enderecoInicial] = (palavra & 0xFF) >> 16;
            memoria[enderecoInicial] = (palavra & 0xFF) >> 08;
            memoria[enderecoInicial] = (palavra & 0xFF);
        }

    }

    // Fecha o arquivo
    fclose(arquivo);

    return EXIT_SUCCESS;
}

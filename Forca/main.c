#include <stdio.h>
#include <string.h>
void imprime(int correto, int chances){
    if(correto == 0){
        if(chances == 6){
          printf("----|");
          printf("    0");
          printf("     ");
          printf("     ");
        }
      if(chances == 5){
          printf("----|");
          printf("    0");
          printf("    |");
          printf("     ");

        }
      if(chances == 4){
          printf("----|");
          printf("    0");
          printf("   /|");
          printf("     ");
        }
      if(chances == 3){
          printf("----|");
          printf("    0");
          printf("   /|>");
          printf("     ");
        }
      if(chances == 2){
          printf("----|");
          printf("    0");
          printf("   /|>");
          printf("   /");

        }
      if(chances == 1){
          printf("----|");
          printf("    0");
          printf("   /|>");
          printf("   /|");

        }
    }

int main() {
    char palavra[100];
    char palavraOculta[100];
    char letrasUsadas[26];
    int tentativas = 6;
    int acertos = 0;
    int i, tamanho, encontrou, letraValida;

    printf("Jogo da Forca\n");
    printf("Digite a palavra a ser adivinhada: ");
    scanf("%s", palavra);

    tamanho = strlen(palavra);

    // Inicializa a palavra oculta com '_' e coloca o caractere nulo no final
    memset(palavraOculta, '_', tamanho);
    palavraOculta[tamanho] = '\0';

    while (tentativas > 0 && acertos < tamanho) {
        printf("\nPalavra: %s\n", palavraOculta);
        printf("Tentativas restantes: %d\n", tentativas);
        printf("Letras usadas: ");

        for (i = 0; i < strlen(letrasUsadas); i++) {
            printf("%c ", letrasUsadas[i]);
        }

        printf("\nDigite uma letra: ");
        scanf(" %c", &letrasUsadas[strlen(letrasUsadas)]);

        letraValida = 0;
        encontrou = 0;

        // Verifica se a letra já foi usada antes
        for (i = 0; i < strlen(letrasUsadas) - 1; i++) {
            if (letrasUsadas[i] == letrasUsadas[strlen(letrasUsadas) - 1]) {
                printf("Você já usou essa letra antes. Tente outra.\n");
                letraValida = 1;
                break;
            }
        }

        if (!letraValida) {
            // Verifica se a letra digitada está presente na palavra
            for (i = 0; i < tamanho; i++) {
                if (palavra[i] == letrasUsadas[strlen(letrasUsadas) - 1]) {
                    palavraOculta[i] = palavra[i];
                    acertos++;
                    encontrou = 1;
                }
            }

            if (!encontrou) {
                printf("Letra incorreta!\n");
                tentativas--;
            } else {
                printf("Letra correta!\n");
            }
        }
    }

    if (acertos == tamanho) {
        printf("\nParabéns! Você acertou a palavra: %s\n", palavra);
    } else {
        printf("\nGame over! A palavra era: %s\n", palavra);
    }

    return 0;
}

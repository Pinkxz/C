#include <stdio.h>
#include <stdlib.h>

void enforcando(int correto, char letra, int chances){
    if(correto > 0){
        printf("Voce acertou!!!");
        printf("_ _ _ _ _ _ _ _ _");
        printf("%d chances restantes", chances);
        imprime(correto, chances);
    }else if (correto = 0){
        printf("Voce errou!");
        printf("_ _ _ _ _ _ _ _ _");
        printf("%d chances restantes", chances);
        imprime(correto, chances);
    }
}

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


}
int main()
{
    char palavra[9] = {'a' , 'b', 'o', 'b', 'r', 'i', 'n', 'h', 'a'}, letra;
    int pedaco = 0, correto = 0, chances = 6;

    printf("Digita o caractere: ");
    scanf("%c", &letra);

    //Verificando caractere
    for(int i = 0; i < 10; i++){
        correto = 0;
        if(letra == palavra[i]){
            enforcando(correto, letra, chances);
            correto = i;
        }
    }
        enforcando(correto, letra, chances);
    return 0;
}


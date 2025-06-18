#include<stdio.h>
#include<stdlib.h>
int main()
{
 int comp = 0, jog = 0, imparpar = 0, soma = 0;

 srand(time(0));
 comp = rand() % 10;

 printf("Digite um valor de 1 a 9: ");
 scanf("%d,", &jog);
 fflush(stdin);

 printf("\nAperte 1 para impar, 2 para par: ");
 scanf("%d", &imparpar);

 printf("\nA maquina escolheu %d", comp);

 soma = jog + comp;

 if(imparpar == 1)
 {
    if(soma%2 == 1)
    {
        printf("\n%d.Parabens, voce ganhou!", soma);
    }else{
        printf("\%d. nVoce perdeu!", soma);
    }
 }
 if(imparpar == 2)
 {
    if(soma%2==0)
    {
        printf("\n%d. Parabens voce ganhou!", soma);
    }else{
        printf("\n%d. Voce perdeu!", soma);
    }
 }

 return 0;
}

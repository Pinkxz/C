#include<stdio.h>
int main()
{
    float sal, emp, trinta = 0;

    printf("Digite o valor do salario: ");
    scanf("%f", &sal);

    printf("Escreva o empretismo desejado: ");
    scanf("%f", &emp);

    trinta = (sal/100)*30;

    if (emp <= trinta){
        printf("Empretismo liberado!");
    }else{
        printf("Empretismo negado!");
    }
 return 0;
}

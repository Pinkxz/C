#include<stdio.h>
int main(){
    int x1, x2, soma =0;

    printf("Digite x1: ");
    scanf("%d", &x1);

    printf("Digite x2: ");
    scanf("%d", &x2);

    soma = x1 + x2;
    if(soma > 20){
    printf("Resultado e: %d", soma+8);
    }else{
    printf("O resultado e: %d", soma-5);
    }
 return 0;
}

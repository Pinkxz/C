#include<stdio.h>


int main (){

int x1, x2, flag = 0, resultado = 0;
char op;

    printf("Digite a operação desejada:(+, -, / ou *) ");
    scanf("%c", &op);

    printf("Digite dois numeros:");
    scanf("%d", &x1);
    fflush(stdin);

    scanf("%d", &x2);
    fflush(stdin);

    if(op == '+'){
        resultado = x1 + x2;
        flag = 1;
    }
    else if(op == '-'){
        resultado = x1 - x2;
        flag = 1;
    }
    else if(op == '/')
    {
        if(x2==0){
        resultado = 0;
        }else{
        resultado = x1 / x2 ;
        }
        flag = 1;
    }
    else if(op == '*'){
      resultado = x1 * x2;
        flag = 1;
    }
    if(flag == 0){
        printf("Resultado inválido. Digite um operador válido.");
    }else{
        printf("O resultado e: %d", resultado);
    }
}

#include <stdio.h>
#include <stdlib.h>
/*A gerente do cabeleireiro “Sempre Bela” tem uma tabela em que registra os serviços de “pés”,
“mãos” e podologia de cinco funcionários. Sabendo que cada um ganha 50% do que faturou ao mês,
criar um programa que possa calcular e imprimir quanto cada um vai receber, uma vez que não têm
carteiras assinadas. Os valores dos serviços são respectivamente R$ 10,00, R$ 15,00 e R$ 30,00.*/

int main()
{
    int matriz[5][4], count = 1;
    for(int i = 0; i < 5;i++){
            int j = 0;
            matriz[i][0] = count++;
            printf("\nPreencha quantos servicoe de pes, maos e podologias ele realizou(EX: 1 2 3) : ");
                scanf("%d %d %d", &matriz[i][j+1], &matriz[i][j+1], &matriz[i][j+1]);
    }

    for(int i = 0; i < 5; i++){
        int j = 0;
            int total = ((matriz[i][j+1]*10)  + (matriz[i][j+1]*15) + (matriz[i][j+1])*30)*0.50;
            printf("\nO funcionario %d vai receber: %d", matriz[i][j], total);
    }
    return 0;
}

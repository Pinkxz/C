#include <stdio.h>
#include <stdlib.h>
/*A gerente do cabeleireiro “Sempre Bela” tem uma tabela em que registra os serviços de “pés”,
“mãos” e podologia de cinco funcionários. Sabendo que cada um ganha 50% do que faturou ao mês,
criar um programa que possa calcular e imprimir quanto cada um vai receber, uma vez que não têm
carteiras assinadas. Os valores dos serviços são respectivamente R$ 10,00, R$ 15,00 e R$ 30,00.
*/

typedef struct{
    float tomaos;
    float topes;
    float topodo;
}total;

typedef struct{
    char nome[100];
    int pes;
    int maos;
    int podologia;

    total total1;

}func;
int main()
{
    func funcionario;

    printf("Digite o nome: ");
    gets(funcionario.nome);

    printf("Digite a pes feitas: ");
    scanf("%d", &funcionario.pes);

    printf("Digite a maos feitas: ");
    scanf("%d", &funcionario.maos);

    printf("Digite a podologia feitas: ");
    scanf("%d", &funcionario.podologia);

    funcionario.total1.topes = (funcionario.pes * 10) * 0.50;
    funcionario.total1.tomaos = (funcionario.maos * 15) * 0.50;
    funcionario.total1.topodo = (funcionario.podologia * 30) * 0.50;

    printf("O funcionario %s vai receber a soma de %.2f por pes, %.2f por maos e %.2f por podologias", funcionario.nome, funcionario.total1.topes, funcionario.total1.tomaos, funcionario.total1.topodo);
    return 0;
}

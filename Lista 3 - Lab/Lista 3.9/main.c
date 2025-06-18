#include <stdio.h>
#include <stdlib.h>

int bissexto(ano){
    if (ano % 400 == 0){
        return 1;
    }
    else if (ano % 100 == 0){
        return 0;
    }
    else if (ano % 4 == 0){
        return 1;
    }
        return 0;
}

int diasnomes(int mes, int ano){
    if(mes == 2) {
        if(bissexto(ano))
            return 29;
        else
            return 28;
    }else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            return 30;
    }else{
            return 31;
    }
}

int main(){

    int diaNas, mesNasc, anoNasc, diaAtual, mesAtual, anoAtual, diasVividos = 0, anoC, mes;

    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &diaNas, &mesNasc, &anoNasc);

    printf("Digite a data atual (dia mes ano): ");
    scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);

     for (anoC = anoNasc + 1; anoC< anoAtual; anoC++) {
        if (bissexto(anoC)){
            diasVividos += 366;
        }
        else{
            diasVividos += 365;
        }
     }

    // Calcula os dias vividos no ano de nascimento
    for (mes = mesNasc + 1; mes <= 12; mes++){
        diasVividos += diasnomes(mes, anoNasc);
    }
    diasVividos += (diasnomes(mesNasc, anoNasc) - diaNas);

    // Calculando os dias vividos no ano atual
    for (mes = 1; mes < mesAtual; mes++){
        diasVividos += diasnomes(mes, anoAtual);
    }
    diasVividos += diaAtual;

    printf("Dias vividos: %d\n", diasVividos);

    return 0;
}


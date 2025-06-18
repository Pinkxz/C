#include <stdio.h>
#include <stdlib.h>

float menor(float temperatura[], float maisFrio, int i){
    if(temperatura[i] < maisFrio){
        maisFrio = temperatura[i];
    }
    return maisFrio;
}

float maior(float temperatura[], float maisQuente, int i){
        if(temperatura[i] > maisQuente){
            maisQuente = temperatura[i];
        }
    return maisQuente;
}

float mediaA(int media, float temperatura[], int i){
        media = media + temperatura[i];
    return media;
}

int diasAcima(float media, float temperatura[], int dias){
for(int j = 0; j < 5; j++){
        if(temperatura[j] > media){
            dias++;
        }
    }
    return dias;
}
int main()
{
    float temperatura[5], media, maisQuente = 0, maisFrio = 100;
    int dias = 0;

    for(int i = 0; i < 5; i++){
        printf("Digite a temperatura do dia %d: ", i + 1);
        scanf("%f", &temperatura[i]);

        maisFrio = menor(temperatura, maisFrio, i);
        maisQuente = maior(temperatura, maisQuente, i);
        media =  mediaA(media, temperatura, i);

    }
    media = media/5;
    dias = diasAcima(media, temperatura, dias);

    printf("Menor temperatura: %f\n", maisFrio);
    printf("Maior temperatura: %f\n", maisQuente);
    printf("Media anual: %f\n", media);
    printf("Dias acima da media: %d\n", dias);
    return 0;
}

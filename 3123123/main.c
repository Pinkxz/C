#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cig, ano;
    printf("cigarros");
    scanf("%d", &cig);
    printf("dias");
     scanf("%d", &ano);

     cig = cig * 365;
     cig = cig * ano;
     cig = cig * 10;
     ano = cig / 1440;

     printf("dias perdodos %d", ano);
    return 0;
}

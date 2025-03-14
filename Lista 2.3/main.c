#include <stdio.h>
#include <stdlib.h>
int main()
{
 int segu, hrs, min;

 printf("\nInforme os segundos do evento ocorrido na fabrica: ");
 scanf("%d", &segu);

 hrs = segu/3600;
 min = (segu%3600)/60;
 segu = (segu%3600);

 printf("\nHoras: %d", hrs);
 printf("\nMinutos: %d", min);
 printf("\nSegundos: %d", segu);
 return 0;
}

#include<stdio.h>

int main()
{
 int diassa, ano = 0, meses = 0, dias = 0;

 printf("Ha quantos dias sem acidente? ");
 scanf("%d", &diassa);

 ano = diassa/365;
 meses = (diassa - ano*365)/30;
 dias = diassa - ano*365-meses*30;

 printf("Anos sem acidente: %d, meses: %d, dias: %d", ano, meses, dias);
 return 0;
}

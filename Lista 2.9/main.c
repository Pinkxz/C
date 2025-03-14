#include<stdio.h>
#include<math.h>
int main()
{
  int catetoa, catetob;
  float hipo;

  printf("Qual o cateto A? ");
  scanf("%d", &catetoa);
  printf("O cateto B? ");
  scanf("%d", &catetob);

  hipo = (catetoa*catetoa+catetob*catetob);
  hipo = hipo/2;

  printf("A hipotenusa e: %f", hipo);

 return 0;
}

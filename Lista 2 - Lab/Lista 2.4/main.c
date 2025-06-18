#include <stdio.h>
#include <stdlib.h>
int main()
{
 int a, b, c, d, e, f;
 float x, y;
 printf("\nEscreva os valores a, b, c, d, e, f: ");
 scanf("%d", &a);
 fflush(stdin);

 scanf("%d", &b);
 fflush(stdin);

 scanf("%d", &c);
 fflush(stdin);

 scanf("%d", &d);
 fflush(stdin);

 scanf("%d", &e);
 fflush(stdin);

 scanf("%d", &f);
 fflush(stdin);

 x = (c*e-b*f)/(a*e-b*d);
 y = (a*f-c*d)/(a*e-b*d);

 printf("\nO valor de x e: %f", x);
 printf("\nO valor de y e: %f", y);
 return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1 = 0,x2 = 0, y1 = 0, y2 = 0, distancia = 0, x= 0, y = 0;
    printf("Escreva os pontos X e Y: ");
    scanf("%d", &x1);
    scanf("%d", &y1);

    printf("Escreva os pontos X2 e Y2: ");
    scanf("%d", &x2);
    scanf("%d", &y2);

    x = x2 - x1;
    x = pow(x, 2);
    y = y2 - y1;
    y = pow(y, 2);
    distancia = x + y;
    distancia = sqrt(distancia);

    printf("A distancia e: %d", distancia);
    return 0;
}

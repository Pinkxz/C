#include <stdio.h>
#include <stdlib.h>

int main(){
        // Basico de Ponteiro
        int a = 2;
        int *point = &a;

        printf("%d, %d\n", a, &a);
        printf("%d, %d\n", point, &point);

        *point = 6;

        printf("%d, %d\n", a, &a);
        printf("%d, %d\n", point, &point);

        // Fazendo incrementos e decrementos via ponteiro
        int x,y, *p;

        y = 0;
        p = &y;
        x = *p;
        x = 4;

        (*p)++;
        x--;
        (*p)+=x;

        printf("%d, %d, %d\n", x, y, p);

        // Atribuindo endereço diretamente
        int xi, *pp;
         xi = 100;
         p=xi;

         printf("%d", p);

    return 0;
}

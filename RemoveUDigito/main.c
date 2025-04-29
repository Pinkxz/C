#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, prim, meio;
    scanf("%d", &num);

     prim = num/10;
     meio = prim%10;

     printf("%d", meio);
    return 0;
}

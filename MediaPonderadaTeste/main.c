#include <stdio.h>
#include <stdlib.h>

int main()
{
    float media, p1, p2, nl;

    scanf("%f", &p1);
    scanf("%f", &p2);
    scanf("%f", &nl);

    nl = nl * 0.8333333;
    media = (p1 * 0.3 + p2 * 0.4 + nl * 0.3);
    printf("%f", media);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **x, *y, z;
    int v[2] = {80, 90};
    z = *(v+1);
    z = z + 1;
    y = v;
    x = &y;
    **x = 1;
    printf("x: %d, y: %d, v[0]: %d, v[1]: %d, z: %d", **x, *y, v[0], v[1], z);
    return 0;
}

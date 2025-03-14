#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[10][10];
    mat[0][0] = 1;
    mat[1][1] = 1;
    mat[2][2] = 1;
    mat[3][3] = 1;
    mat[4][4] = 1;
    mat[5][5] = 1;
    mat[6][6] = 1;
    mat[7][7] = 1;
    mat[8][8] = 1;
    mat[9][9] = 1;
    mat[10][10] = 0;

    int i = 0;

    while(i < 10){
        if(i < 10){
            mat[i][i] = mat[i][i] + mat[i+1][i+1];
        }
        i = i + 1;
    }
    printf("%d", mat[i][i]);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int reg0 = 0b0010;
    int reg1 = 0b0100;
    int reg2 = 0b1111;
    int reg[16];

    for(int i = 0; i < 16; i++){
       reg[i] = 0x00;
    }
    reg[reg0] = 0xA;
    reg[reg1] = 0xC;
    reg[0] = reg[reg0] + reg[reg1];
    reg[reg2] = 0xABC;

    for(int i = 0; i < 16; i++){
        printf("\n%x", reg[i]);
    }
    return 0;
}

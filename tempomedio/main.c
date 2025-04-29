#include <stdio.h>
#include <stdlib.h>

int main()
{
   		float tempom;
		float result = 0;

		for(int i = 0; i < 5; i++) {
            scanf("%f", &tempom);
            fflush(stdin);
			result = result + tempom;
		}
		result = result/5;
		printf("%f",result);
    return 0;
}

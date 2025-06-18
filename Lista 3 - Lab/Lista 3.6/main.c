#include <stdio.h>
int main() {
  int a, b, c, d;

  printf("Escreva os valores a, b, c, d: ");
  scanf("%d", &a);
  fflush(stdin);

  scanf("%d", &b);
  fflush(stdin);

  scanf("%d", &c);
  fflush(stdin);

  scanf("%d", &d);

  if (b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0) {
    printf("Valores aceitos!");
  } else {
    printf("Valores recusados!");
  }
  return 0;
}

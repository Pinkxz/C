#include <stdio.h>
int main() {
  int x1, x2, flag = 0, resultado = 0;
  char op;

  printf("Digite a operação desejada:(>, <, = ou !) ");
  scanf("%c", &op);

  printf("Digite dois numeros:");
  scanf("%d", &x1);
  fflush(stdin);

  scanf("%d", &x2);
  fflush(stdin);

  if (op == '>') {
    if (x1 > x2) {
      printf("%d e maior que %d", x1, x2);
    } else {
      printf("%d e maior que %d", x2, x1);
    }
    flag = 1;
  }
  if (op == '<') {
    if (x1 < x2) {
      printf("%d e menor que %d", x1, x2);
    } else {
      printf("%d e menor que %d", x2, x1);
    }
    flag = 1;
  }
  if (op == '=') {
    if (x1 == x2) {
      printf("%d e igual a %d", x1, x2);
    } else {
      printf("%d e igual a %d", x2, x1);
    }
    flag = 1;
  }
  if (op == '!') {
    if (x1 != x2) {
      printf("%d e diferente de %d!", x1, x2);
    } else {
      printf("%d e igual a %d", x1, x2);
    }
    flag = 1;
  }
  if (flag == 0) {
    printf("Resultado inválido. Digite um operador valido.");
  }
}

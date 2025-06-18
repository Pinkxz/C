#include <stdio.h>
int main() {
  float nota, freq;

  printf("Qual a nota do aluno? ");
  scanf("%f", &nota);

  printf("Qual a frequência do aluno? ");
  scanf("%f", &freq);

  if (freq < 75) {
    printf("Reprovado!");
  }
  if (freq >= 75 && nota < 3.0) {
    printf("Reprovado!");
  }
  if (freq >= 75 && nota >= 3.0 && nota < 7.0) {
    printf("Exame!");
  }
  if (freq >= 75 && nota >= 7.0) {
    printf("Aprovado!");
  }
  return 0;
}

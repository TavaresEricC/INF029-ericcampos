/*Faça um programa que tenha uma função troca que recebe dois parâmetros inteiros e troque o
valor das variáveis um pelo outro. A função main deve ler do usuário os dois valores, chamar a
função troca, e depois imprimir os valores trocados.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void troca(int *a, int *b){
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

int main(){
  int a, b;
  setlocale(LC_ALL, "Portuguese");
  printf("Digite o primeiro valor: ");
  scanf("%d", &a);
  printf("Digite o segundo valor: ");
  scanf("%d", &b);
  troca(&a, &b);
  printf("O valor %d foi trocado pelo valor %d.\n", a, b);
  return 0;
}
/*Faça um programa que leia a idade de duas pessoas e imprima a soma das idades*/

#include <stdio.h>

int main(){
  int a, b;
  printf("Digite a idade da primeira pessoa: ");
  scanf("%d", &a);

  printf("\nDigite a idade da outra pessoa: ");
  scanf("%d", &b);

  printf("\nA soma das idades é igual a: %d\n", a+b);
}
/*Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas*/
#include <stdio.h>

int main(){
  int a, b, aux;
  printf("Informe o primeiro valor: ");
  scanf("%d", &a);

  printf("\nInforme o segundo valor: ");
  scanf("%d", &b);

  aux=a;
  a=b;
  b=aux;

  printf("\nOs números digitados, após inversão, são: %d e %d", a, b);
  
}
/*Faça um programa que calcula o fatorial de um número*/
#include <stdio.h>

int main(){
  int n, fat, i=1;
  printf("Digite um número: ");
  scanf("%d", &n);

  for(fat=1;i<=n;i++){
    fat = fat*i;
  }
  printf("O fatorial de %d é: %d.\n", n, fat);
}
/*Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int subtrai(int a, int b, int c){
  int res;
  res = a-b;
  res = res-c;
  return res;
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  int a, b, c;
  printf("SUBTRAÇÃO DE TRÊS NÚMEROS.\n\n");
  
  printf("Digite o primeiro número: ");
  scanf("%d", &a);
  
  printf("Digite o segundo número: ");
  scanf("%d", &b);
  
  printf("Digite o terceiro número: ");
  scanf("%d", &c);

  printf("\n\nO resultado da subtração é: %d.\n", subtrai(a,b,c));
}
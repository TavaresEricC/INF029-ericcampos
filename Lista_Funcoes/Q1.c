/*Crie um programa que tenha uma função soma e a função main. A função main deve ler dois
valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A
Função main deve imprimir o resultado da soma.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int a, int b){
  int soma;
  soma = a + b;
  return soma;
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  int a, b;
  printf("SOMA DE DOIS NÚMEROS\n\n");
  printf("Digite o primeiro número: ");
  scanf("%d", &a);
  printf("Digite o segundo número: ");
  scanf("%d", &b);
  
  printf("\nA soma dos dois números digitado é: %d.\n", soma(a,b));
  
}